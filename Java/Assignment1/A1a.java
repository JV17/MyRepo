/*****************************************************************************
Name: Jorge E. Valbuena S.
Date: January 25, 2014
Assignment #: Assignment 1 - Question 1
General description of what your code does:
	This code asks the user to input two integer and then
    calculates the sum, product, difference and quotient of
    both integers.
General description of the vaiables used in your code:
	total to hold the results of the calculations
    num1 to hold the value of the first integer inputted
    num2 to hold the second value of the last integer inputted by the user
Expected good results:
	This code will print ==> The results of each calculations of both integers
Anticipated bad results:
	Only handles integers as correct inputs
******************************************************************************/
import java.util.Scanner;

public class A1a {
    
    public static void main(String[] args) {
        // TODO code application logic here
        
        Scanner input = new Scanner(System.in);
        int total; // will hold the result of the caculations
        int num1; // integer value from the first user input
        int num2; // integer value from the second user input
        
        // Greeting message
        System.out.println("***Welcome to my 1st program of my Assignment#1 for JAC444***\n");
        
        
        System.out.println("Enter first integer: "); //Asking user input
        num1 = input.nextInt(); //getting user input
        System.out.print("\n");
        System.out.println("Enter second integer: "); //Asking user input
        num2 = input.nextInt(); //getting user input
        System.out.print("\n");
        
        // sum the two integers
        total = num1 + num2;
        System.out.printf("The Sum of both integers: %d\n", total);
        
        // product of the two integers
        total = num1 * num2;
        System.out.printf("The Product of both integers: %d\n", total);
        
        // difference of the two integers
        if(num1 > num2){ // no preference of between inputs grater or less than one to another
            total = num1 - num2;
        } else {
            total = num2 - num1;
        }
        System.out.printf("The Difference of both integers: %d\n", total);
        
        // quotient of the two integers
        total = num1 / num2;
        System.out.printf("The Quotient of both integers: %d\n\n", total);
        
        System.out.println("***Thanks for running my program!***");
        
        System.exit( 0 );
    }
}
