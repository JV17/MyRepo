/*****************************************************************************
Name: Jorge E. Valbuena S.
Date: February 10, 2014
Assignment #: Assignment 2 - Question 5
General description of what your code does:
	This code display a calculator with not functionality
General description of the variables used in your code:
	myButtons to hold object of button
    calcTxt to hold object of text field
Expected good results:
	This code will print ==> A Calculator frame with not functionality
Anticipated bad results:
	No errors expects because it doesn't has perform interaction with user
******************************************************************************/

import java.awt.*;
import javax.swing.*;

public class Calculator extends JFrame{
   
   private JPanel myButtons, footerLabel; // creating button object
   private JTextField calcTxt; // creating text field object
   private String COPYRIGHT = "\u00a9"; // Copyright symbol

   public Calculator(){ // program constructor
       super("My JAC444 - Calculator"); // displaying app name
       Container container=getContentPane(); // getting content pane

       myButtons = new JPanel(); // creating new JPanel
       footerLabel = new JPanel();
       myButtons.setLayout(new GridLayout(4,4,2,2)); // setting layout manager

       calcTxt=new JTextField(); // creating text field
      
       myButtons.add(new JButton("7")); // adding new button
       myButtons.add(new JButton("8")); // adding new button
       myButtons.add(new JButton("9")); // adding new button
       myButtons.add(new JButton("/")); // adding new button
       myButtons.add(new JButton("4")); // adding new button
       myButtons.add(new JButton("5")); // adding new button
       myButtons.add(new JButton("6")); // adding new button
       myButtons.add(new JButton("*")); // adding new button
       myButtons.add(new JButton("1")); // adding new button
       myButtons.add(new JButton("2")); // adding new button
       myButtons.add(new JButton("3")); // adding new button
       myButtons.add(new JButton("-")); // adding new button
       myButtons.add(new JButton("0")); // adding new button
       myButtons.add(new JButton(".")); // adding new button
       myButtons.add(new JButton("=")); // adding new button
       myButtons.add(new JButton("+")); // adding new button
       
       footerLabel.add(new JLabel (COPYRIGHT + "JorgeDeveloper.com")); // adding footer program
       
       container.add(myButtons, BorderLayout.CENTER); // setting button alignment
       container.add(calcTxt, BorderLayout.NORTH); // setting text alignment
       container.add(footerLabel, BorderLayout.SOUTH); // setting footer alignment
       
       setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE); // close window
       setSize(265,235); // size of the frame
       setLocationRelativeTo(null); // Window appears center
       toFront(); // brings this Window to the front and may make it the focused Window
       setVisible(true); // Shows the Window
   }
   public static void main (String args[])
   {
       Calculator application = new Calculator(); // initializing constructor
       application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // close app windown
   }
}

