/*****************************************************************************
Name: Jorge E. Valbuena S.
Date: January 25, 2014
Assignment #: Assignment 1 - Question 4
General description of what your code does:
	This code will calculate the factorial# of integers from 1 - 5
General description of the variables used in your code:
	factorial holds the factorial value of each integer
    x holds the integer value
Expected good results:
	This code will print ==> The factorial of integers 1 - 5
Anticipated bad results:
	No bad results are anticipated since this program is not interactive and does not require user interaction
******************************************************************************/

//package a1d;
import java.util.Scanner;
/**
 *
 * @author      Jorge E. Valbuena S.
 * 
 */
public class A1d {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here 
        
        int factorial;
        
        System.out.println("***Welcome to my 4rd program of my Assignment#1 for JAC444***\n"); // displaying program header
        System.out.println("Factorial of integers from 1 - 5:"); 
        System.out.println("Int\tFact");
      
        for ( int x = 1; x <= 5; x++ ){ // caculation the factorial of integer from 1-5
           factorial = 1;
           
           for ( int i = 1; i <= x; i++ )
              factorial *= i;
           
           System.out.printf("%d\t%d\n", x, factorial); // displaying the result
        }
        
        System.out.println("\n***Thanks for running my program!***"); // displaying program footer

        System.exit( 0 );
    }
    
}
