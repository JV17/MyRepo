/*****************************************************************************
Name: Jorge E. Valbuena S.
Date: March 17, 2014
Assignment #: Assignment 3
General description of what your code does:
	This code create a virtual keyboard and helps the user to learn how to type without
	looking at the keyboard
General description of the variables used in your code:
	firstRow hold the string for the the first row of button for the keyboard
	secondRow hold the string for the the second row of button for the keyboard
	thirdRow hold the string for the the third row of button for the keyboard
	fourthRow hold the string for the the fourth row of button for the keyboard
	fifthRow hold the string for the the fifth row of button for the keyboard
    strText hold a string of text
    noShift hold the whole characters
    specialChars hold the special characters
    keycode to hold the virtual keycode values
Expected good results:
	This code will change the background button of the keyboard pressed in the screen and
	display all characters typed by the user.
Anticipated bad results:
	This program allows user interaction, which may cause to throw some exceptions that are not supported
******************************************************************************/

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GradientPaint;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.RenderingHints;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import java.util.HashMap;
import java.util.Map;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;

public class typeTutor extends JFrame implements KeyListener {
    
    private static final long serialVersionUID = 1L;
    
    // creating map for buttons
    Map<Integer, JButton> map = new HashMap<>();

    // Individual keyboard rows
    String firstRow[] = { "~", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "+", "fill",
                          "BackSpace" };
    String secondRow[] = { "Tab", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]", "\\" };
    String thirdRow[] = { "Caps", "A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "\"", "fill",
            	          "fill", "Enter" };
    String fourthRow[] = { "Shift", "Z", "X", "C", "V", "B", "N", "M", ",", ".", "?", "blank", "^" };
    String fifthRow[] = { "blank", "blank", "fill", "fill", "fill", "fill", "fill", "fill", "fill",
                          "fill", "", "<", "v", ">" };
    String strText = "";
    // all keys without shift key press
    String noShift = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    // special characters on keyboard that has to be addressed during key press
    String specialChars = "~-+[]\\;',.?";
    int keycode;
    JTextArea text = new JTextArea();

    // Jbuttons corresponding to each individual rows
    JButton first[];
    JButton second[];
    JButton third[];
    JButton fourth[];
    JButton fifth[];

    // default color of the button to be repainted when key released
    Color cc = new JButton().getBackground();

    
    // Driver main method to start the application
    public static void main(String[] args) {
        
        // launch typing tutor
    	typeTutor a = new typeTutor();
      
    }// end of main 

    
    // No argument constructor to create frame
    public typeTutor() {
 
    	// program label
        super("Type Tutor - My JAC444");
        
        // Calling gradientBg method
        gradientBg();
        
        // calling gradientBg method
        init();
        
    }// end of Constructor

    
    // init function
    public final void init(){
        
        // set the info label on top
        JLabel info = new JLabel(
                "<html>&nbsp;&nbsp;Type some text using your keyboard.The keys "
                 + "you press will be highlighted and text will be displayed."
                 + "<br> &nbsp;&nbsp;Note : Clicking the buttons with your "
                 + "mouse will not perform any action. <br><br> </html>");
        
        // set the bold font for info
        info.setFont(new Font("Verdana", Font.BOLD, 12));

        // set the layout and place component in place and pack it
        setLayout(new BorderLayout());

        // Various panel for the layout
        JPanel jpNorth = new JPanel();
        JPanel jpWest = new JPanel();
        JPanel jpEast = new JPanel();
        JPanel jpCenter = new JPanel();
        JPanel jpKeyboard = new JPanel(new GridBagLayout());
        JPanel jpNote = new JPanel();

        // adding Panels
        add(jpNorth, BorderLayout.NORTH);
        add(jpNote);
        
        // adding Panels
        add(jpWest, BorderLayout.WEST);
        add(jpEast, BorderLayout.EAST);
        
        // adding Panels
        add(jpCenter, BorderLayout.CENTER);
        add(jpKeyboard, BorderLayout.SOUTH);

        // setting layout and adding BorderLayout
        jpNorth.setLayout(new BorderLayout());
        jpNorth.add(info, BorderLayout.SOUTH);

        // setting layout and adding BorderLayout
        jpCenter.setLayout(new BorderLayout());

        //jpCenter.add(text, BorderLayout.WEST);
        jpCenter.add(text, BorderLayout.CENTER);

        // setting preferredsize
        jpCenter.setPreferredSize(new Dimension(200, 140));

        // creating buttons
        first = new JButton[firstRow.length];
        second = new JButton[secondRow.length];
        third = new JButton[thirdRow.length];
        fourth = new JButton[fourthRow.length];
        fifth = new JButton[fifthRow.length];

        // adding buttons
        addKeys(jpKeyboard, 0, firstRow, first);
        addKeys(jpKeyboard, 1, secondRow, second);
        addKeys(jpKeyboard, 2, thirdRow, third);
        addKeys(jpKeyboard, 3, fourthRow, fourth);
        addKeys(jpKeyboard, 4, fifthRow, fifth);

        // setting preferredSize
        jpKeyboard.setPreferredSize(new Dimension(300, 140));
        
        // fixing background and panels overflow
        info.setOpaque(false);
        jpNote.setOpaque(false);
        jpWest.setOpaque(false);
        jpEast.setOpaque(false);
        jpNorth.setOpaque(false);
        jpCenter.setOpaque(false);
        jpKeyboard.setOpaque(false);

        // add listeners
        text.addKeyListener(this);

        // setting default close operation
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // set non re-sizable
        this.setResizable(false);

        // set size of the content pane ie frame
        this.getContentPane().setPreferredSize(new Dimension(700, 310));

        // putting everything together
        pack();
        
        // brings this Window to the front and may make it the focused Window
        this.toFront();

        // Window appears center
        this.setLocationRelativeTo(null);
        
         // setting visible
        this.setVisible(true);
    
    }// end of init 
    
    
    // background gradient function
    public final void gradientBg(){
        
        // Creating gradient background
        JPanel contentPane = new JPanel() {
	    private static final long serialVersionUID = 1L;
            
            @Override
            protected void paintComponent(Graphics grphcs) {
                Graphics2D g2d = (Graphics2D) grphcs;
                Dimension d = this.getSize();
                g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                        RenderingHints.VALUE_ANTIALIAS_ON);

                GradientPaint gp = new GradientPaint(0, 0, getBackground().brighter(),
                        0, d.height, getBackground().darker().darker());

                g2d.setPaint(gp);
                g2d.fillRect(0, 0, d.width, d.height);

                super.paintComponent(grphcs);
            }
        };
        contentPane.setOpaque(false);
        setContentPane(contentPane);
        
    }// end of gradientBg
    
    
    // Invoked when a key has been pressed.
    // @see java.awt.event.KeyListener#keyPressed(java.awt.event.KeyEvent)
    @Override
    public void keyPressed(KeyEvent evt) {
        
        keycode = evt.getKeyCode();
        strText = String.format("%s", KeyEvent.getKeyText(evt.getKeyCode()));

        JButton btn = map.get(keycode);
        if (btn != null) {
             map.get(keycode).setBackground(new Color(135,206,235));
        }
        
    }// end of key pressed


    // Invoked when a key has been released
    @Override
    public void keyReleased(KeyEvent evt) {
        
        keycode = evt.getKeyCode();
        strText = String.format("%s", KeyEvent.getKeyText(evt.getKeyCode()));

        JButton btn = map.get(keycode);
        if (btn != null) {
             map.get(keycode).setBackground(Color.WHITE);
        }
        
    }// end of keyReleased


    // Invoked when a key has been typed
    @Override
    public void keyTyped(KeyEvent evt) {
      
       strText = String.format("%s", evt.getKeyChar());
       
    }// end of key typed


    // adds the buttons to create screen keyboard
    protected final void addKeys(JPanel parent, int row, String[] keys, JButton[] buttons) {

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.gridy = row;
        gbc.gridx = 0;
        gbc.fill = GridBagConstraints.BOTH;

        int gap = 0;
        for (int index = 0; index < keys.length; index++) {
            String key = keys[index];
            if ("blank".equalsIgnoreCase(key)) {
                gbc.gridx++;
            } else if ("fill".equalsIgnoreCase(key)) {
                gbc.gridwidth++;
                gap++;
            } else {
                JButton btn = new JButton(key);
                buttons[index] = btn;
                parent.add(btn, gbc);
                gbc.gridx += gap + 1;
                gbc.gridwidth = 1;
                gap = 0;

                btn.setBackground(Color.WHITE);
                map.put(getKeyCode(key), btn);
            }
        }
    }// end of addKeys


    // checks for virtual key code events
    private int getKeyCode(String key) {
        
        switch (key) {
            case "BackSpace":
                return KeyEvent.VK_BACK_SPACE;
            case "Tab":
                return KeyEvent.VK_TAB;
            case "Caps":
                return KeyEvent.VK_CAPS_LOCK;
            case "Enter":
                return KeyEvent.VK_ENTER;
            case "Shift":
                return KeyEvent.VK_SHIFT;
            case "":
                return KeyEvent.VK_SPACE;
            case "+":
                return KeyEvent.VK_EQUALS;
            case ":":
                return KeyEvent.VK_SEMICOLON;
            case "\"":
                return KeyEvent.VK_QUOTE;
            case "?":
                return KeyEvent.VK_SLASH;
            case "~":
                return KeyEvent.VK_BACK_QUOTE;
            case "^":
                return KeyEvent.VK_UP;
            case "v":
                return KeyEvent.VK_DOWN;
            case "<":
                return KeyEvent.VK_LEFT;
            case ">":
                return KeyEvent.VK_RIGHT;
            default:
                return (int) key.charAt(0);       
        }// end of switch
        
    }// end of getKeyCode
    
}// end of typeTutor class