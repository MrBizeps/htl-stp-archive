/*  FileReadWrite.java
    w.alfery
        
    Beispiel f�r Textdatei schreiben u.lesen      
 */

import java.io.*;                               


public class FileReadWrite
{
   public static void main(String[] args)  throws IOException
   {
      // Datei Ein- und Ausgabe erfordert IOException handling 

      int x = 10;
      String s = " Java File Test \n";

      /////////////////////////////////////////////////////////////////////////
      // Daten auf Datei schreiben 
      // �ber PrintWriter >> FileWriter >> File 
      //  
      try                                         
      {  
         File datei = new File("test.txt");      // File Objekt erzeugen (�ffnen)
         FileWriter f = new FileWriter(datei);   // Outputstream instanzieren
         PrintWriter aus = new PrintWriter(f);   // Ausgabe �ber PrintWriter

         f.write(s);                             // String s �ber FileWriter ausgeben 
         aus.println("Hallo");                   // Ausgabe �ber PrintWriter 
         aus.print("Zahl =" + x );               // ... Integerwert ausgeben 
         aus.println();                          // ... neue Zeile 
         
         aus.close();                            // FileWriter schlie�en
         f.close();                              // Datei schlie�en

      } 
      catch (IOException e)                      // IOExceptions auffangen  
      {
         System.out.println("\n -> Datei-Schreib-Fehler !");
      }

      /////////////////////////////////////////////////////////////////////////
      // Daten von Datei zeichenweise lesen  
      // �ber FileReader << File 
      //  
      String line;   
      try 
      {      
         FileReader fi = new FileReader("test.txt");// Inputstream instanzieren
         int i;
         line="";
         while((i=fi.read())!=-1)                //  zeichenweise lesen bis Dateiende
         {                                       
            line = line + (char)i;               //  Text zusammenf�gen
         }
         fi.close();                             //  Datei schlie�en
         System.out.println(line);               //  Text auf Konsole ausgeben 

      }
      catch (IOException e) 
      {  
         System.out.println("\n -> Datei-Lese-Fehler ! ");
      }
   
    

      /////////////////////////////////////////////////////////////////////////
      // Daten von Datei zeilenweise lesen  
      // �ber BufferedReader << FileReader << File 
      //  
      try 
      {  FileReader fi = new FileReader("test.txt");// Inputstream instanzieren
         BufferedReader f = new BufferedReader(fi); // einlesen �ber BufferedReader  
         
         while ((line = f.readLine()) != null)   // zeilenweise lesen bis Dateiende   
         {
            System.out.println(line);            // und auf Konsole ausgeben 
         }
       
         fi.close();
      } 
      catch (IOException e) 
      {
         System.out.println("\n -> Datei-Lese-Fehler ! ");
      }

   }
}  
