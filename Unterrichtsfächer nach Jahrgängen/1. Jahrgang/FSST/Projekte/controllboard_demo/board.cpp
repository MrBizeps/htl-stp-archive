/////////////////////////////////////////////////////////////////////////////
//   Programmname : board.cpp
//   DI W.Alfery
//
//   Control Board -  Steuerungsanzeige
//   mit Verwendung von "controlboard"
//   zur Eingabe u. Anzeige von Ports
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "bse_console.h"              // f�r getch(),kbhit(),Sleep(), ...
#include "controlboard.h"             // f�r grafisches Controlboard


///////////////////////////////////////////////////////////////////////////////
//   globale Definitionen
///////////////////////////////////////////////////////////////////////////////
typedef unsigned char byte;          // Typdefinition f�r Byte (8 Bit)


/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{
   printf("\n    Control Board \n");
   printf("    mit Grafikdisplay der Ports \n");


   int i=0;
   byte p1,p2;                        // Ports p1, p2 definieren
   p1=0;
   p2=1;                             // Anfangswerte f�r p1,p2 setzen

   drawBoard();                       // Control Board anzeigen

   while(1)                           // Endlos Schleife
   {

       if (p1!=0)
       {
           if (i)
          {
              p2=p2>>1;
          }
          else
          {
              p2=p2<<1;
          }


          if (p2==0x01)
          {
              i=0;
          }


          if (p2==0x80)
          {
              i=1;
          }
       }


      updateBoard(&p1,&p2);           // Control Board Pins aktualisieren

      gotoxy(5,5);
      printf("Port p1=%3X hex %3d dez",p1,p1);   // Anzeige im Konsolenfenster
      gotoxy(5,6);
      printf("Port p2=%3X hex %3d dez",p2,p2);

      Sleep(40);                      // 50 ms warten
   }

   clearBoard();                      // Control Board schlie�en

   return 0;
}


