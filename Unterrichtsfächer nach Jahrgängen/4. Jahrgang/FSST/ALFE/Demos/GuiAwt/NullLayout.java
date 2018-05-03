/* NullLayout.java
   w.alfery 
    
   Null Layout 
   f�r die Positionierung �ber absolute Koordinatenangaben 
   mit setBounds, setLocation u. setSize 
   
*/ 

import java.awt.*;                             				// AWT Packages importieren
import java.awt.event.*;                        

// Hauptfensterklasse NullLayout
public class NullLayout extends Frame            			// Hauptfenster  
                     
{  
  // Komponenten 
  Label title;  
  Label textlabel; 
  TextField text; 
  Button enter; 
  Button clear;
  Button quit; 
      
  
  // Konstruktor definieren   
  NullLayout()                          
  {
     view();                                    			// View ausf�hren (Oberfl�che)                    
       
     addWindowListener( new WindowAdapter()      			// Fenster Schlie�schalter    
     {  public void windowClosing(WindowEvent event)
        { System.exit(0);}          
     } );
    
  }


  // View     
  private void view()	                    
  {  
     
     // Fenster Einstellungen 
     setTitle( " Layout mit Panels " );
     setBackground(Color.lightGray);            	      
     setSize(400,140);
     setLocation(200,100);
     setResizable(false);                    
     
  	 // Komponenten erzeugen
     title     = new Label(" Container ");          		// Beschriftungen  
     textlabel = new Label(" Texteingabe ");    
     text      = new TextField(" Eingabe bitte ... ",20); 	// Textfeld 
     enter     = new Button(" Enter ");                   	// Buttons
     clear     = new Button(" Clear ");    
     quit      = new Button(" Quit  ");      
  	
  	 // Komponenten Formatierungen 
     title.setFont(new Font("Arial", Font.BOLD,14));     	// Formatierungen f�r title  
     title.setForeground(new Color(50,150,50));      
     title.setAlignment(Label.CENTER); 
     
     // Null Layout setzen        
     setLayout(null);                                    	// Null Layout f�r Hauptfenster   
  	 
  	 title.setBounds(100,20,200,40); 				   		// Gr��e u. Position f�r "title" zuweisen  
  	 add(title);                            				// Komponente "title" einf�gen 
    
  	 textlabel.setBounds(10,60,190,20);  			   		// Gr��e u. Position f�r "textlabel" zuweisen  
     add(textlabel);										// Komponente "textlabel" einf�gen 
     
 	 text.setBounds(200,60,190,20);   	 			   		// Gr��e u. Position f�r "text" zuweisen       
     add(text);												// Komponente "text" einf�gen 
     
     enter.setSize(120,30);         	 			   		// Gr��e f�r "enter" u.                            
     enter.setLocation(10,100);  	 			   		    // Position zuweisen 
     add(enter); 											// Button "enter" einf�gen 

     clear.setSize(120,30);         	 			   		// Gr��e f�r "clear" u.                            
     clear.setLocation(140,100);		   					// Position zuweisen 
     add(clear);  											// Button "clear" einf�gen 
	
     quit.setSize(120,30);         	 			   			// Gr��e f�r "quit" u.                            
     quit.setLocation(270,100);  	 			   			// Position zuweisen
     add(quit);  											// Button "quit" einf�gen 
  
  }
	

  // Methode main 
  public static void main(String[] args)
  {
     NullLayout view = new NullLayout();    				// Fensterklasse instanzieren
     view.setVisible(true);                     			// Fenster darstellen   
 
  }
  
 
}
