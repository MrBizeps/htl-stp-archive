/////////////////////////////////////////////////////////////////////////////
//   Programmname  : figuren.cpp
//   Programmierer : w.alfery
//   Datum         :
//
//   Aufgabe :  Figuren �ber geschachteltete Schleifen
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////

 #include <stdio.h>                  //  f�r printf(), scanf()
 #include <stdlib.h>                 //  f�r system()
 #include <conio.h>                  //  f�r getch()
 #include <iostream>

 using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////

int main()
{
   int i,j,x,y,l,I;

   printf(" Figuren \n\n");
   printf(" allg. Seitenl\x84nge = ");
   cin >> l;

   printf("\n 1) Rechteck : \n");


   x=l;
   y=l/2;

   for ( j=1;j<=y;j=j+1 ) 	      // Hauptschleife f�r H�he y
   {
      for ( i=1;i<=x;i=i+1 ) 	  // Unterschleife f�r Breite x
      {  printf("%c ",(char) 254);
      }
      printf("\n");
   }

   printf("\n\n 2) Zahlen - Quadrat : \n");

   for ( j=1;j<=l;j=j+1 ) 	      // Hauptschleife f�r H�he x2
   {
      for ( i=1;i<=l;i=i+1 ) 	  // Unterschleife f�r Breite x2
      {  cout << j;               // Zahl ausgeben
      }
      printf("\n");
   }

   printf("\n\n 3) Zahlen- Dreieck \n");

   for ( j=1;j<=l;j=j+1 ) 	      // Hauptschleife f�r H�he y
   {
      for ( i=1;i<=j;i=i+1 ) 	  // Unterschleife f�r Breite x
      {  cout << i;
      }
      printf("\n");
      i=1;
   }

   printf("\n\n 4) Baum \n");
   printf("\n Zeichen = ");
   char zeichen;
   cin >> zeichen;
   for(int i=l/2-1,j=1;i>=0;i--,j+=2)
    {
        for(int f=0;f<l;f++)
        {
            if(f<=i)
            {
                cout << " ";
            }
            else if(f<=i+j)
            {
                cout << zeichen;
            }
            else
            {
                cout << " ";
            }
        }
        printf("\n");
    }



   printf("\n\n");
   system("PAUSE");
   return 0;

}

