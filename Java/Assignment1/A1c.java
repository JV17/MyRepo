/*****************************************************************************
Name: Jorge E. Valbuena S.
Date: January 25, 2014
Assignment #: Assignment 1 - Question 3
General description of what your code does:
	This code will calculate the earnings of salesperson solds last week
    depending on how many items sold and the type of item
General description of the variables used in your code:
	gross holds the total value of items sold
    total holds the total earnings for the salesperson
    item1 holds value of the first item 
    item2 holds value of the second item
    item3 holds value of the third item
    item4 holds value of the forth item
    percentage holds the % of earning per item sold
    weeklyComission holds the value of comissions per week
    select holds user selection of item
    solds hold the number of items sold
Expected good results:
	This code will print ==> The final earnings of a salesperson last week  
    sells including the 200 weekly comissions
Anticipated bad results:
	The program only handles integers numbers as correct inputs
******************************************************************************/

import java.util.Scanner;

public class A1c {

    public static void main(String[] args) {
        
        double gross=0; // total gross
        double total=0; // total earnings
        double item1 = 239.99; // price for item1 final
        double item2 = 129.75; // price for item2 final
        double item3 = 99.95; // price for item3 final
        double item4 = 350.89;  // price for item4 final
        double percentage = 0.09; // percentage of sales final
        int weeklyComission = 200; // weekly comission final
        int select=1; // menu selection
        int solds; // sales person input
        Scanner input = new Scanner(System.in);

        System.out.println("***Welcome to my 3er program of my Assignment#1 for JAC444***\n"); // just making the program more welcoming
        
        while(select != 0){
            
            System.out.print("Plese enter \t1 for item1($239.99),\n\t\t2 for item2($129.75),\n\t\t3 for item3($99.95),\n\t\t4 for item4($350.89),\n\t\t0 to cancel: "); // asking user input
            select = input.nextInt(); //getting user input
            System.out.print("\n");
            
            if(select > 0 && select <= 4){ // if input is whitin the range of 1-4 the program continues
                
                System.out.printf("Plese enter the quantity sold for item%d: ", select);
                solds = input.nextInt(); //getting user input
                System.out.print("\n");

                // caculates total gross for each item sold
                if(select == 1)
                    gross += item1 * solds;
                else if(select == 2)
                    gross += item2 * solds;
                else if(select == 3)
                    gross += item3 * solds;
                else if(select == 4)
                    gross += item4 * solds;
            }
            else if(select < 0 || select > 4){ // if input is less than 0 or grater than 4 an error will be display and the program loops
                System.err.print("Wrong selectiong, please try again...\n\n");
            }
            else if(select == 0){ // if input is equal to 0 the program ends
                total += ((percentage * gross) + weeklyComission); // calculates total earnings for  employee
            }
            else{ // if input is anything else an error will be display and the program loops
                System.err.print("Wrong selectiong, please try again...\n\n");
            }
        }
        
        System.out.printf("Total of earnings for items sold: %.2f\n\n", total); // dispplay total earnings
        
        System.out.println("***Thanks for running my program!***"); // displaying program footer
        
        System.exit( 0 );
    }
    
}
