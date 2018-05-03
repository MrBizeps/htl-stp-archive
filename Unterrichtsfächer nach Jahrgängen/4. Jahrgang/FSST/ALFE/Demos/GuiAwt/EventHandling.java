/* EventHandling.java
   w.alfery 
    
   GUI mit Event-Handling
 
*/ 

import java.awt.*;                               // AWT Packages importieren
import java.awt.event.*;                         // Listener Interfaces importieren 

// Hauptfensterklasse  
public class EventHandling extends Frame         
                     
{  

   // Komponenten 
  Label      label1, label2;  
  TextField  textinput, textoutput; 
  Button     enter, clear;
 
  
  // Konstruktor   
  EventHandling()                          
  {
     view();                                   	 // GUI aufbauen    
          
     addWindowListener( new WindowAdapter()      // Listener f�r Grafikfenster schlie�en  
     {  public void windowClosing(WindowEvent event)
        { System.exit(0);}          
     } );
     
     enter.addActionListener(new on_enter_click()); // Listener f�r Buttons registrieren  
     clear.addActionListener(new on_clear_click()); 
     	
  }

  // Methode main 
  public static void main(String[] args)
  {
     EventHandling view = new EventHandling();     // Fensterklasse instanzieren
     view.setVisible(true);                        // Fenster darstellen   
 
  }
  
  
  // View     
  private void view()	                    
  { 
      // Fenster Einstellungen 
     setTitle( " Event Handling " );
     setBackground(Color.lightGray);            	      
     setSize(400,140);
     setLocation(200,100);
     setResizable(false);         
   
     
 	 // Komponenten erzeugen
     label1     = new Label(" Texteingabe ");  	// Beschriftungen  
     label2     = new Label(" Textausgabe ");    
     textinput  = new TextField("",20); 	 	// Textfelder 
     textoutput = new TextField("",20); 

     enter  = new Button(" Enter ");        	// Buttons
     clear  = new Button(" Clear "); 
  

     // Layout                 
     setLayout(new GridLayout(3,2));             // Layout f�r Hauptfenster  
     
     add(label1);    							 // Komponenten anordnen 
     add(label2);
     add(textinput);
     add(textoutput);
     add(enter);      
     add(clear);      

  }
	
  
  
  // Event-Handling (Control)   
  class on_enter_click implements ActionListener         // Listener Klasse f�r "Enter Button Click" 
  {  
     public void actionPerformed( ActionEvent event )    // Methode "actionPerformed" implementieren 
     {  String text; 
     
        text = textinput.getText();                      // Text von Textfeld "textinput" holen  
        textoutput.setText(text);                        // Text auf Textfeld "textoutput" ausgeben   
        textinput.setText("");                           // Text in "textinput" l�schen  
        textinput.requestFocus();                        // Focus auf "textinput" setzen
     }     
  }

  class on_clear_click implements ActionListener         // Listener Klasse f�r "Clear Button Click" 
  {  
     public void actionPerformed( ActionEvent event )
     {                                         			
        textinput.setText("");                           // Textfelder l�schen  
        textoutput.setText("");
     }     
  }


 
}
