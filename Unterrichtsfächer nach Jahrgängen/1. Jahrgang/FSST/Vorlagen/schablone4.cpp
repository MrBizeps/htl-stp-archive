/////////////////////////////////////////////////////////////////////////////
//   Programmname : schablone4.cpp
//
//   Autor   :  W. Alfery
//   Datum   :  01.09.2011
//   Version :  2
//
//   Aufgabe :  Programmaufbau eines C/C++-Programms
//              mit Programmwiederholung
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Headerdateien
/////////////////////////////////////////////////////////////////////////////

 #include <stdio.h>                  //  f�r printf(), scanf()
 #include <stdlib.h>                 //  f�r system()
 #include <conio.h>                  //  f�r getch()

 #define ESC 27                      //  ESC - Ersatztext definieren


/////////////////////////////////////////////////////////////////////////////
//    Hauptprogramm
/////////////////////////////////////////////////////////////////////////////

int main()
{  char antwort;
   int i=0;

   do                                  // Wiederholung mit do-while-Schleife
   {   /*  ...   ab hier den Programmteil einf�gen
	       ...   dieser Programmteil wird solange wiederholt,
	       ...   bis die ESC - Taste gedr�ckt wird.
	   */
       system("CLS");                  // Bildschirm l�schen
       printf(" Programmwiederholung ");
       printf(" ->  %5d -mal",i++);







	   printf("\n\n\n\n");
	   printf(" Programm Ende mit [Esc]      ");
 	   antwort=getch();
   } while (antwort!=ESC);

}

/////////////////////////////////////////////////////////////////////////////

