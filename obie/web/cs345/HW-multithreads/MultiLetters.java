
/*
  A program that tests the order of  execution of differentthreads
*/
public class MultiLetters extends Thread {
    // The letters each thread prints
    public static String letters[] = { "A", "B", "C", "D", "E", "F" };
 
/*
 Each thread is given a letter for its name , and simply  prints its name 10 times .
*/
    public void run ( ) { 
        for ( int i = 0 ; i < 10 ; i ++) 
              System.out.print( getName ( ) ) ;}

/* Just make six threads and start them running */
    public static void main (String args[]) {
        System.out.println("Starting");
        for ( int i = 0 ; i < 6 ; i ++) { Thread t = new MultiLetters( ) ;
            t . setName ( letters [ i ] ) ;
            t . start ( ) ; }
} // end main
} // end MultiLetters

