/*****************************************************************************
Name: Jorge E. Valbuena S.
Date: February 10, 2014
Assignment #: Assignment 2 - Question 8
General description of what your code does:
	This code converts the temperature from fahrenheit to celcius
General description of the variables used in your code:
	WIDTH to hold the width of the frame
    HEIGHT to hold the height of the frame
    frame to hold the JFrame object
    mainPanel holds object of JPanel
    OkButton and CancelButton allows the user submit the input or to close the program
    inputLabel, outputLabel, resultLabel and footerLabel holds display text and input of the program 
Expected good results:
	This code will print ==> The converted temperature from Fahrenheit to Celcius
Anticipated bad results:
	This program allows user interaction, which may cause to throw some exceptions that are not supported
******************************************************************************/

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class tempCon extends JFrame{
     
   private int WIDTH = 350; // Window width
   private int HEIGHT = 165; // Window heigt
   private JFrame frame; // Jframe object
   private JPanel mainPanel; // JPanel object
   private JButton ok, cancel; // adding Ok and Cancel buttons
   private JLabel inputLabel, outputLabel, resultLabel, footerLabel; // JLabel objects
   private JTextField fahrenheit; // JTextFrield Object
   private String COPYRIGHT = "\u00a9"; // Copyright symbol
   
    public tempCon(){
       super("My JAC444 - Temperature Conversion"); // header program
       Container container = getContentPane(); // getting content pane
              
       inputLabel = new JLabel ("Enter Fahrenheit temperature:"); // creating display to request input to the user
       outputLabel = new JLabel ("Temperature in Celcius:        "); // creating display of result 
       resultLabel = new JLabel ("----"); 
       footerLabel = new JLabel (COPYRIGHT + "JorgeDeveloper.com"); // creating program footer
       
       ok = new JButton("OK"); // creating OK button 
       ok.addActionListener(new TempListener()); // initialazing listener for button OK

       cancel = new JButton("CANCEL"); // creating Cancel button 
       cancel.addActionListener(new TempListener()); // initialazing listener for button Cancel

       fahrenheit = new JTextField (5); // field input size
       fahrenheit.addActionListener (new TempListener()); // initialazing listener for the input
       fahrenheit.setHorizontalAlignment(JTextField.CENTER); // assignment allignment
       
       // creating vertical box
       Box box1 = Box.createVerticalBox();
       JPanel mssg1Panel = new JPanel();
       JPanel mssg2Panel = new JPanel();
       
       // creating button panel and setting layout
       JPanel buttonPanel = new JPanel();
       buttonPanel.setLayout(new GridLayout(1,1,5,5));
       buttonPanel.setBorder(BorderFactory.createEmptyBorder(13, 5, 0, 5)); 
       
       // creating vertical box
       Box box2 = Box.createVerticalBox();
       JPanel footerPanel = new JPanel();
       
       // adding text, field input and output
       mssg1Panel.setLayout(new FlowLayout());
       mssg2Panel.setLayout(new FlowLayout());
       mssg1Panel.add(inputLabel);
       mssg1Panel.add(fahrenheit);
       mssg2Panel.add(outputLabel);
       mssg2Panel.add(resultLabel);
       
       // setting up text, input and output
       box1.add(mssg1Panel);
       box1.add(mssg2Panel);
       
       // setting up the buttons
       buttonPanel.add(ok);
       buttonPanel.add(cancel);
       
       // setting up program footer
       footerPanel.add(footerLabel);
       box2.add(footerPanel);
       
       // adding everything to the container
       container.setLayout(new FlowLayout());
       container.add(box1);
       container.add(buttonPanel);
       container.add(footerPanel);
    }
    
    // All display functionalities
    public void display()
    {
       setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE); // close window
       setLocationRelativeTo(null); // Window appears center
       setVisible(true); // Shows the Window
       toFront(); // brings this Window to the front and may make it the focused Window
       setSize(WIDTH, HEIGHT); // size of the frame
    }

    //  The action listener for the temperature input field
    private class TempListener implements ActionListener
    {
        public void actionPerformed (ActionEvent event)
        {
           if(event.getSource() == ok) { // executing calculation when ok button pressed
                int fahrenheitTemp, celciusTemp;
                String text = fahrenheit.getText();
                fahrenheitTemp = Integer.parseInt (text);
                celciusTemp = (fahrenheitTemp-32)*5/9; // Temperature Conversation
                resultLabel.setText (Integer.toString (celciusTemp));
           }
           else if(event.getSource() == cancel){ // closing the program when Cancel button pressed
                System.exit(0);
           }
        }
    }
    
      //  Creates and displays the Application 
      public static void main (String[] args)
      {
         tempCon tempConverter = new tempCon(); // creating tempConverter object
         tempConverter.display();
      }
}
    

