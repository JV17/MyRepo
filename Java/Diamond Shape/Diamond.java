/*****************************************************************************
Name: Jorge E. Valbuena S.
Date: February 10, 2014
Assignment #: Assignment 2 - Question 1
General description of what your code does:
	This code display the shape of a diamond with * character.
General description of the variables used in your code:
	int i to hold first loop value condition
    int j to hold second loop value condition
    int NUM to hold third loop value condition
Expected good results:
	This code will print ==> The shape of diamond with * character
Anticipated bad results:
	No errors expects because it doesn't has perform interaction with user
******************************************************************************/

public class Diamond {

    public static void main(String args[]){
        
        int i = 0, j = 0, NUM = 4; // intigers values which will be using for loop control
        
        for(i=-NUM; i <= NUM; i++){ // first loop condition
            
            for(j=-NUM; j <= NUM; j++){ // second loop conditon
                
                if(Math.abs(i) + Math.abs(j) <= NUM) // codition to print the * and ' ' characters within the for loop conditions
                    System.out.print('*'); // printing the * character
                else
                    System.out.print(' '); // printing the ' ' character
            }
            System.out.println(); // printing the new line
        }
    }
}
