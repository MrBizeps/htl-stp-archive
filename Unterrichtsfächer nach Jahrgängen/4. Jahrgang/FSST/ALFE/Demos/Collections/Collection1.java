 /*  Collection1.java
     progr. w.alfery
     
     Collections (Sammlungen) verwenden :  
     
     Arraylist (�hnlich der Klasse Vector) - 
          f�r eine geordnete Sammlung von Objekten mit definierter Reihenfolge, 
          der Zugriff auf die Elemente erfolgt �ber Index,
          Elemente k�nnen beliebig eingef�gt und gel�scht werden, 
          Werte der Elemente k�nnen auch mehrfach vorkommen (im Gegensatz zu Set)
          gute Performance bei �berwiegend lesenden Zugriffen 
          ist typsicher im Vergleich zur Klasse "Vector", "Vektor" jedoch rascher 
          und eine "LinkedList" ist bei h�ufigem Einf�gen und L�schen performanter.  
                
 */

 import java.io.*;
 import java.util.*;
 
 public class Collection1	            
 {  

   public static void main( String[] args ) 
   { 

      System.out.println(" ArrayList des Collection-Frameworks verwenden \n" ); 

      // Liste erstellen
      System.out.print(" ArrayList : " ); 
      List<String> coll = new ArrayList<String>(); // Liste f�r Strings (typisiert) erstellen

      coll.add("eins");                  // 1.Element in die Liste eintragen (Index=0) 
      coll.add("zwei");                  // 2.Element 
      coll.add("drei");                  //  ...
      coll.add("los"); 
      for ( int i = 0; i < 5; i++ ) 
          coll.add( "A" + i );           

      // Liste ausgeben 
      System.out.println( coll );        // gesamte Liste ausgeben -> [A0,A1,...] 
      System.out.println( " Anzahl="+coll.size()); // Anzahl der Elemente bestimmen 
      
      System.out.print( " Elemente einzeln abfragen: ");
      for ( int i = 0; i < coll.size(); i++ )  
          System.out.print(coll.get(i)+","); // Zugriff �ber Index     
      
      // Elemente suchen  
      boolean b=coll.contains("los");    // Element suchen    
      System.out.print( "\n\n ist das Element \"los\" vorhanden? : " + b );   
      int i=coll.indexOf("los");         // Position(Index) bestimmen     
      System.out.println( " -> an der Position = " + i );   

      // Liste erweitern u. �ndern   
      System.out.print(" erweitern und �ndern : " ); 
      coll.set(i,"vier");                // neuen Wert setzen     
      coll.add(i+1,"los");               // neues Element an bestimmter Pos. eintragen     
      System.out.println( coll );        // gesamte Liste ausgeben -> [A0,A1,...] 
      
      // Liste sortieren 
      Collections.sort(coll);            // alph. sortieren    
      System.out.println(" \n sortieren :"+coll);     
       
      // Elemente l�schen    
      coll.remove(3);                    // Element �ber Index l�schen
      coll.remove("los");                // Element �ber Wert l�schen
      System.out.println("\n Elemente l�schen :"+ coll );      

      // Teillisten erstellen     
      List part = new ArrayList();       // Teilliste erstellen 
      part=coll.subList(4,6);            // von Index=4 bis 6 
      System.out.println( "\n Teilliste erstellen : " + part );      
      
      // Liste l�schen 
      coll.clear();                      // Liste l�schen 
      System.out.println( "\n Liste l�schen :" + coll );      
      
   } 
}