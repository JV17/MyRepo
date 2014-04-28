/*****************************************************************************
Name: Jorge E. Valbuena S.
Date: January 25, 2014
Assignment #: Assignment 1 - Question 2
General description of what your code does:
	This code calculates the possibles Square and Cubes in 
    the range of 0 - 10
General description of the vaiables used in your code:
	square holds the total of squares possible
    cubes holds the total of cubes possible
    num holds the value of range from 0 - 10
Expected good results:
	This code will print ==> The results of the possible squares and cubes 
    in the range of 0 - 10
Anticipated bad results:
	No bad results are anticipated since this program is not interactive and does not require user interaction
******************************************************************************/

public class A1b {

    public static void main(String[] args) {

        int square; // Total of squares possibles in rage of 0 - 10
        int cubes; // Total of cubes possibles in rage of 0 - 10
        int i=0; // integer counter for for loop
        
        System.out.println("***Welcome to my 2nd program of my Assignment#1 for JAC444***\n"); // displaying program header 
        
        System.out.println("Numbers\tSquares\tCubes");
        for(; i <= 10; i++){ // for loop to calculate the possible squares/cubes whitin 0-10
            square = i * i;
            cubes = i * i * i;
            System.out.printf("   %d\t   %d\t  %d\n", i, square, cubes);
        }
        
        System.out.println("***Thanks for running my program!***"); // displaying program footer 
        
        System.exit( 0 );
    }
    
}
