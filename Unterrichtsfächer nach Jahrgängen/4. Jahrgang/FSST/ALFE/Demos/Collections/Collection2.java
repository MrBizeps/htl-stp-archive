 /*  Collection2.java
     progr. w.alfery
     
     Collections (Sammlungen) verwenden :  
     
     Map - 
          f�r einen assoziativen Speicher (Dictionary), der Schl�ssel auf Werte abbildet,
          Schl�ssel und Werte sind Objekte eines beliebigen Typs,
          HashMap ist eine schnelle Implementierung durch Verwendung einer Hash-Tabelle - 
          �ber eine Transformationsfunktion werden Schl�ssel auf Indexpositionen abgebildet,
          TreeMap ist langsamer im Aufbau und rascher im Zugriff, da ein sortierter Bin�rbaum gebildet wird
                
 */

 import java.io.*;
 import java.util.*;
 
 public class Collection2		            
 {  

   public static void main( String[] args ) 
   { 

      System.out.println(" Map des Collection-Frameworks verwenden \n" ); 

      // Map erstellen
      System.out.println(" HashMap : " ); 
      HashMap<String,String> maillist = new HashMap<String,String>(); // HashMap erstellen

      maillist.put("georg","georg@benson.at");        // Schl�ssel-Wert-Paar einf�gen 
      maillist.put("laura","laura@ashley.de");
      maillist.put("paul","paul@cartney.uk");
 
      // Map ausgeben 
      System.out.println( maillist );                 // gesamte Map ausgeben -> {...} 
      System.out.println( " Anzahl="+maillist.size());// Anzahl der Elemente bestimmen 
   
      // Elemente �ber Iterator ausgeben 
      System.out.println( "\n Elemente einzeln �ber Iterator ausgeben : "); 
      Iterator iter = maillist.entrySet().iterator(); // Iterator erstellen   
      while (iter.hasNext())                          //  HashMap durchlaufen   
      {
          Map.Entry entry = (Map.Entry)iter.next();
          System.out.println( (String)entry.getKey()  // Schl�ssel 
                               + " = " + 
                              (String)entry.getValue()// Wert 
                            );
      } 
      
      // Elemente abfragen                           
      String s=maillist.get("laura");                  // �ber Schl�ssel abfragen   
      System.out.println( "\n Abfrage nach \"laura\" = " + s); 
   
      // Elemente l�schen    
      maillist.keySet().remove("laura");              // �ber Schl�ssel l�schen
      maillist.values().remove( "georg@benson.at" );  // �ber Wert l�schen
      System.out.println("\n Elemente l�schen :"+ maillist );      

      // gesamte HashMap l�schen 
      if (maillist.isEmpty()==false) maillist.clear(); 
      System.out.println( "\n Liste l�schen :" + maillist );     

   } 
}