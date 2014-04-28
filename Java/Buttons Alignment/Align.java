/*****************************************************************************
Name: Jorge E. Valbuena S.
Date: February 10, 2014
Assignment #: Assignment 2 - Question 4
General description of what your code does:
	This code display the align example with three buttons OK, CANCEL, HELP; 
    Also, display some input text fields and two check buttons
General description of the variables used in your code:
	snapToGrip, showGrip to hold check-box object
    xLabel, yLabel to hold JLabel object
    xField, yField to hold JTextField object
    ok, cancel and help to hold buttons for each one
Expected good results:
	This code will print ==> An alignment program showing different types of fields
Anticipated bad results:
	No errors expects because it doesn't has perform interaction with user
******************************************************************************/

import java.awt.*;
import javax.swing.*;

public class Align extends JFrame{
    
    private JCheckBox snapToGrid, showGrid; // declaring JCheckBox object
	private JLabel xLabel, yLabel, footerLabel; // declaring JLabel object
	private JTextField xField, yField; // declaring JTextField object
	private JButton ok, cancel, help; // declaring JButton object
    private String COPYRIGHT = "\u00a9"; // Copyright symbol
    
	public Align(){
        
        super("My JAC444 - Align"); // Displaying program header
        Container container = getContentPane(); // getting content pane

        //Making all the buttons and Labels
        snapToGrid = new JCheckBox("Snap to Grid");
        showGrid = new JCheckBox("Show Grid");

        xLabel = new JLabel("X:");
        yLabel = new JLabel("Y:");
        xField = new JTextField(3); // creating text field
        yField = new JTextField(3); // creating text field
        footerLabel = new JLabel (COPYRIGHT + "JorgeDeveloper.com"); // creating program footer

        ok = new JButton("OK"); // creating buttons
        cancel = new JButton("Cancel");
        help = new JButton("Help");

        // creating vertical box
        Box box1 = Box.createVerticalBox();

        // creating second vertical box
        Box box2 = Box.createVerticalBox();
        JPanel xPanel = new JPanel();
        JPanel yPanel = new JPanel();

        // creating third vertical box
        Box box3 = Box.createVerticalBox();
        JPanel footerPanel = new JPanel();
        
        // creating button panel and setting layout
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(3,1,5,5));

        // adding the x and y labels and textfields together
        xPanel.setLayout(new FlowLayout());
        yPanel.setLayout(new FlowLayout());
        xPanel.add(xLabel);
        xPanel.add(xField);
        yPanel.add(yLabel);
        yPanel.add(yField);

        // setting up the "Show" and "Snap" Grid
        box1.add(snapToGrid);
        box1.add(showGrid);

        // setting up x and y panels
        box2.add(xPanel);
        box2.add(yPanel);

        // setting up the buttons
        buttonPanel.add(ok);
        buttonPanel.add(cancel);
        buttonPanel.add(help);
        
        // setting up program footer
        footerPanel.add(footerLabel);
        box3.add(footerPanel);
        
        // adding everything to the container
        container.setLayout(new FlowLayout());
        container.add(box1);
        container.add(box2);
        container.add(buttonPanel);
        container.add(box3);
        
        setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE); // close window
        setSize(300, 155); // size of the frame
        setLocationRelativeTo(null); // Window appears center
        toFront(); // brings this Window to the front and may make it the focused Window
        setVisible(true); // Shows the Window
    }

        public static void main(String args[])
        {
                Align window = new Align(); // initializing constructor
                window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // close app windown
        }
}
