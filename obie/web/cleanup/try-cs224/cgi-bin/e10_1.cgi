#!/usr/bin/perl

# e10_1.pl - a CGI program to produce one of five
#            five different greetings when called
#          A solution to Exercise 10.1

@greetings = ("Hi there, Web surfer!\n", 
              "Are you lost??? \n",
              "This must be your lucky day, you're here! \n",
              "Top of the day to you! \n",
              "Thanks for thinking of me! \n");

$rand;
$number = int(rand 5);

print "Content-type: text/html\n\n";
print "<html><html>\n";
print "<title> CGI - greeting </title></head> \n";
print "<body>\n";

$greeting = $greetings[$number];
print "$greeting";
print "</body> </html> \n";
