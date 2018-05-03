/* GuiContainer.java
   w.alfery 
    
   Panels als Container (Beh�lter) f�r Komponenten 
   mit jeweils eigenen Layouts 
   
*/ 

import java.awt.*;                             	// AWT Packages importieren
import java.awt.event.*;                        

// Hauptfensterklasse GuiContainer
public class GuiContainer extends Frame            // Hauptfenster  
                     
{  
  // Komponenten 
  Label title;  
  Label textlabel; 
  TextField text; 
  Button enter; 
  Button clear;
  Button quit; 
      
  
  // Konstruktor definieren   
  GuiContainer()                          
  {
     view();                                    	// View ausf�hren (Oberfl�che)                    
       
     addWindowListener( new WindowAdapter()      	// Fenster Schlie�schalter    
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
     title     = new Label(" Container ");                // Beschriftungen  
     textlabel = new Label(" Texteingabe ");    
     text      = new TextField(" Eingabe bitte ... ",20); // Textfeld 
     enter     = new Button(" Enter ");                   // Buttons
     clear     = new Button(" Clear ");    
     quit      = new Button(" Quit  ");      
  	 
  	 // Komponenten Formatierungen 
     title.setFont(new Font("Arial", Font.BOLD,14));     // Formatierungen f�r title  
     title.setForeground(new Color(50,150,50));      
     title.setAlignment(Label.CENTER);
     
     textlabel.setFont(new Font("Arial", Font.PLAIN,12)); // Formatierungen f�r textlabel 
     textlabel.setForeground(new Color(150,50,50));    
     textlabel.setBackground(new Color(250,250,250));  
     textlabel.setAlignment(Label.CENTER);
     
     text.setFont(new Font("Arial", Font.PLAIN,12));      // Formatierungen f�r text  
     text.setForeground(new Color(50,50,150));      

     // Layout mit Panels                  
     Panel p1 = new Panel();                     // Panels erstellen (als Container)   	
     Panel p2 = new Panel();                     
     Panel p3 = new Panel();                     
     
     p1.setLayout(new FlowLayout());             // Panel f�r Beschriftung (oben)         
     p1.add(title);                              // Komponente einf�gen 
    
     p2.setLayout(new GridLayout(1,2));          // Panel f�r Label u. Textfeld (Mitte)        
     p2.add(textlabel);
     p2.add(text);
     
     p3.setLayout(new GridLayout(1,3));          // Panel f�r Buttons (unten) 
     p3.add(enter);      
     p3.add(clear);      
     p3.add(quit);      

     setLayout(new GridLayout(3,1));             // Hauptfenster mit 3 Reihen  
     add(p1);                                    // Panels einf�gen 
     add(p2);
     add(p3);

  }
	

  // Methode main 
  public static void main(String[] args)
  {
     GuiContainer view = new GuiContainer();    // Fensterklasse instanzieren
     view.setVisible(true);                     // Fenster darstellen   
 
  }
  
 
}
