#!/usr/bin/perl

# This is e10_4.cgi
# It is a CGI program to process the light bulb sales form
# This is a solution to Exercise 10.4

# Initialize total price and total number of purchased items

$total_price = 0;
$total_items = 0;

# Produce the header part of the HTML return value

print "Content-type: text/html\n\n";
print "<html><head>\n";
print "<title> CGI-Perl Lightbulb Sales Form  </title></head> \n";
print "<body>\n";

# Determine the request method and get the query string

$request_method = $ENV{'REQUEST_METHOD'};
if ($request_method eq "GET") {
    $query_string = $ENV{'QUERY_STRING'};
}
elsif ($request_method eq "POST") {
    read(STDIN, $query_string, $ENV{'CONTENT_LENGTH'});
}

# Split the query string into the name/value pairs

@name_value_pairs = split(/&/, $query_string);

# Loop to process the array of item names and quantities

foreach $name_value (@name_value_pairs) {

# Split the pairs into names and values and translate the values
# into text by decoding the hex characters

    ($name, $value) = split (/=/, $name_value);
    $value =~ tr/+/ /;
    $value =~ s/%([\dA-Fa-f][\dA-Fa-f])/pack("C", hex($1))/eg;

# Add the number of these items to the total items ordered, 
#  compute the cost of the item, and add its cost to the total price, 

# Get the customer number into local variables

    if ($name eq "name") {
        $cust_name = $value;
    } elsif ($name eq "payment") {
        $payment = $value;
    } elsif ($name eq "four100") {
        $four100 = $value;
        $cost = 2.39 * $value;
        $total_price += $cost;
        $total_items += $value;
    } elsif ($name eq "eight100") {
        $eight100 = $value;
        $cost = 4.29 * $value;
        $total_price += $cost;
        $total_items += $value;
    } elsif ($name eq "fourll") {
        $fourll = $value;
        $cost = 3.95 * $value;
        $total_price += $cost;
        $total_items += $value;
    } elsif ($name eq "eightll") {
        $eightll = $value;
        $cost = 7.49 * $value;
        $total_price += $cost;
        $total_items += $value;
    }  ##- end of if
}  ##- end of foreach

# Compute the sales tax and the total

   $tax = 0.062 * $total_price;
   $total_cost = $total_price + $tax;

# Produce the result information to the browser and finish the page

print "Customer: $cust_name<br/>\n";
print "Payment method: $payment <br /><br />\n";
print "<table border = 'border'><caption>Items ordered</caption>\n";
print 
  "<tr><th>Item</th><th>Price</th><th>Quantity</th></tr>\n";
print 
  "<tr><th>4 100-watt reg.</th><td> \$2.39</td><td>$four100</td><tr>\n";
print 
  "<tr><th>8 100-wat reg.</th><td> \$4.29</td><td>$eight100</td></tr>\n";
print 
  "<tr><th>4 long life</th><td> \$3.95</td><td>$fourll</td></tr>\n";
print 
  "<tr><th>8 long life</th><td> \$7.49</td><td>$eightll</td></tr>\n";
print "</table> <h4> Thankyou for your order </h4>\n";
print "The total cost of the items you ordered is: \$ $total_price <br /> \n";
print "The tax on this order is: \$ $tax <br />\n";
print "The total bill is: \$ $total_cost <br />\n";
print "</body> </html> \n";


<!DOCTYPE html PUBLIC "-//w3c//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html>
