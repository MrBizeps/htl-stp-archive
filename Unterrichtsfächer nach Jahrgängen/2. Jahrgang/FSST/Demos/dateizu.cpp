/* ----------------------------------------------------------------------
	 program name  :       DATEIZU.CPP
	 autor         :       w.alfery
	 ----------------------------------------------------------------------
	 Beschreibung :
	 Beispiel f�r direkten Datei-Zugriff auf eine Textdatei
 */

 #include <stdio.h>
 #include <conio.h>
 #include <bse_console.h>
 #include <ctype.h>

//--------------------  Ersatztexte f�r Steuerzeichen -------------------

 #define ESC   27
 #define ENTER 13
 #define LF    10

 //---------------------- globale Definitionen --------------------------

 char dateiname[] = "text.txt";        // DOS-Dateiname
 char text[1000];                      // Textbuffer

 //--------------------- Funktions Prototypen  --------------------------

 int  text_eingabe(char *b);                     // Texteingabe in Textbuffer
 int  datei_neu(char *b, int n);                 // Neuanlegen einer Datei
 int  datei_lesen(char *b, int pos, int n);      // direkter Zugriff lesend
 int  datei_schreiben(char *b, int pos, int n);  // direkter Zugriff schreibend
 int  datei_anhang(char *b, int n);              // Anh�ngen an Dateiende
 int  datei_einfuegen(char *b, int pos, int n);  // Einf�gen an Position

 //--------------------------- main -------------------------------------

int main()
 { char menue;
	 int pos,n;

	 do
	 {
		 textcolor(BLUE);textbackground(LIGHTGRAY);clrscr();
																			 // Titel Zeile
		 textcolor(LIGHTGRAY);textbackground(BLUE);
		 gotoxy(30,2);cprintf(" Direkter Dateizugriff ");
		 textcolor(BLUE);textbackground(LIGHTGRAY);
																			 // Men� Darstellung
		 gotoxy(20,4);printf (" [1]  Datei anlegen  ");
		 gotoxy(20,5);printf (" [2]  von Datei lesen  ");
		 gotoxy(20,6);printf (" [3]  auf Datei schreiben ");
		 gotoxy(20,7);printf (" [4]  an  Datei anh�ngen ");
		 gotoxy(20,8);printf (" [5]  in  Datei einf�gen ");
		 gotoxy(20,9);printf (" [Q]  uit  ");

		 menue=toupper(getch());           // Men� Auswahl

		 switch(menue)                     // Men� Verzweigung
		 {	case '1' :  clrscr();
										gotoxy(10,5);
										printf("Text Eingabe (Abbruch mit [ESC]) : \n");
										n=text_eingabe(text);      // Text Eingabe �ber Tastatur
										n=datei_neu(text,n);       // Datei neu anlegen
										gotoxy(10,5);
										printf(" %d Zeichen gespeichert ",n);
										getch();
										break;

				case '2' :  clrscr();
										gotoxy(10,5);
										printf("Position = ");scanf("%d",&pos);
										gotoxy(10,6);
										printf("Anzahl von Zeichen = ");scanf("%d",&n);
										n=datei_lesen(text,pos,n); // n-Zeichen ab Position pos lesen
										text[n]=0;
										puts(text);                // auf Bildschirm ausgeben
										gotoxy(10,6);
										printf("tats�chlich gelesene Zeichen = %d",n);
										getch();
										break;
				case '3' :  clrscr();
										gotoxy(10,5);
										printf("Position = ");scanf("%d",&pos);
										gotoxy(10,6);
										printf("Text Eingabe (Abbruch mit [ESC]) : \n");
										n=text_eingabe(text);      // Text Eingabe �ber Tastatur
										n=datei_schreiben(text,pos,n); // n-Zeichen auf Position pos schreiben
										gotoxy(10,6);
										printf("geschriebene Zeichen = %d",n);
										break;
				case '4' :  clrscr();
										gotoxy(10,5);
										printf("Text Eingabe (Abbruch mit [ESC]) : \n");
										n=text_eingabe(text);       // Text Eingabe �ber Tastatur
										n=datei_anhang(text,n);     // n-Zeichen anh�ngen
										gotoxy(10,5);
										printf("angeh�ngte Zeichen = %d",n);
										getch();
										break;
				case '5' :  clrscr();
										gotoxy(10,5);
										printf("Position = ");scanf("%d",&pos);
										gotoxy(10,6);
										printf("Text Eingabe (Abbruch mit [ESC]) : \n");
										n=text_eingabe(text);       // Text Eingabe �ber Tastatur
										n=datei_einfuegen(text,pos,n); // n-Zeichen auf Position pos einf�gen
										gotoxy(10,6);
										getch();
										break;
		 }

	 } while (menue!='Q');


	 textcolor(WHITE);textbackground(BLACK);
	 clrscr();

 }

 //----------------------- Funktions Definitionen -----------------------

 int text_eingabe(char *b)
 /* Text Eingabe �ber Tastatur
		mit  b     ...  Datenbuffer f�r Zeichen
		Returnwert ...  Anzahl der eingegebenen Zeichen
 */
 { char zeichen;
	 int i;

	 i=0;
	 do
	 {  zeichen=getche();                 // Zeichen einlesen und am Bildschirm ausgeben
			if (zeichen==ESC) break;          // wenn ESC Taste, dann Abbruch
			if(zeichen==ENTER)                // wenn Enter Taste, dann
			{  zeichen=LF;putchar(LF);        // Line Feed ausgeben !
			}
			b[i]=zeichen;                     // Zeichen in den Textbuffer b zuweisen
			i++;
	 }  while (zeichen!=ESC);             // wiederholen bis ESC gedr�ckt
	 return i;                            // R�ckgabewert=Anzahl der Zeichen

 }


 int  datei_neu(char  *b, int n)
 /* Datei anlegen
		mit  b     ...  Datenbuffer f�r Zeichen
				 n     ...  Anzahl von Bytes
		Returnwert ...  0 =Fehler
 */
 {   FILE *d;                          // File Pointer
		 int anz;

		 d=fopen(dateiname,"w");	         // neue Datei anlegen
		 if (d==NULL)  return 0;           // Fehler bei �ffnen ?

		 anz=fwrite(b,1,n,d);              // schreiben auf Datei

		 fclose(d);                        // Datei schlie�en
		 return anz;                       // Returnwert=Anzahl der Bytes
 }


 int  datei_lesen(char *b, int pos, int n)
 /* Datei lesen mit direktem Zugriff
		mit  b     ...  Datenbuffer f�r Zeichen
				 pos   ...  Position des Dateizeigers
				 n     ...  Anzahl von Bytes
		Returnwert ...  0 =Fehler
 */

 {   FILE *d;                          // File Pointer
		 int anz;

		 d=fopen(dateiname,"r");	         // Datei zum Lesen �ffnen
		 if (d==NULL)  return 0;           // Fehler bei �ffnen ?

		 if (fseek(d,pos,0)) 		           // Fehler bei Positionieren ?
		 { fclose(d); return 0;
		 }

		 anz=fread(b,1,n,d);               // lesen von n-Bytes

		 fclose(d);
		 return anz;                       // Returnwert=Anzahl der Bytes
 }


 int  datei_schreiben(char *b, int pos, int n)
 /* Datei schreiben mit direktem Zugriff
		mit  b     ...  Datenbuffer f�r Zeichen
				 pos   ...  Position des Dateizeigers
				 n     ...  Anzahl von Bytes
		Returnwert ...  0 =Fehler
 */

 {   FILE *d;                          // File Pointer
		 int anz;

		 d=fopen(dateiname,"r+");	         // Datei zum Lesen u. Schreiben �ffnen
		 if (d==NULL)  return 0;           // Fehler bei �ffnen ?

		 if (fseek(d,pos,0))               // Fehler bei Positionieren ?
		 { fclose(d); return 0;
		 }

		 anz=fwrite(b,1,n,d);              // schreiben auf Position von n-Bytes

		 fclose(d);
		 return anz;                       // Returnwert=Anzahl der Bytes
 }

 int  datei_anhang(char *b, int n)
 /* an Datei anh�ngen
		mit  b     ...  Datenbuffer f�r Zeichen
				 n     ...  Anzahl von Bytes
		Returnwert ...  0 =Fehler
 */

 {   FILE *d;                          // File Pointer
		 int anz;

		 d=fopen(dateiname,"a");	         // Datei zum Anh�ngen �ffnen
		 if (d==NULL)  return 0;           // Fehler bei �ffnen ?

		 anz=fwrite(b,1,n,d);              // anh�ngen von n-Bytes ans Dateiende

		 fclose(d);
		 return anz;                       // Returnwert=Anzahl der Bytes
 }

 int  datei_einfuegen(char *b, int pos, int n)
 /* Daten einf�gen mit direktem Zugriff
		mit  b     ...  Datenbuffer f�r Zeichen
				 pos   ...  Position des Dateizeigers
				 n     ...  Anzahl von Bytes
		Returnwert ...  0 =Fehler
 */

 {   FILE *d,*temp;                    // File Pointer
		 int anz,laenge;
		 char *tempbuffer;                 // Zeiger f�r tempor�ren Buffer
		 char  tempdatei[12]="DATEIZU.TMP";// Dateiname f�r tempor�re Datei

		 d=fopen(dateiname,"r");	         // Datei zum Lesen �ffnen
		 temp=fopen(tempdatei,"w");        // tempor�re Datei �ffnen
		 if (d==NULL)  return 0;           // Fehler bei �ffnen ?
		 if (temp==NULL)  return 0;

		 fseek(d,0,SEEK_END);              // Dateiende positionieren
		 laenge=ftell(d);                  // Dateil�nge bestimmen
		 fseek(d,0,0);                     // zur�ck auf Dateianfang positionieren

		 tempbuffer=new char[pos];         // Buffer f�r pos-Bytes erzeugen
		 pos=fread(tempbuffer,1,pos,d);    // lesen von pos-Bytes
		 pos=fwrite(tempbuffer,1,pos,temp);// schreiben auf tempor�re Datei
		 delete tempbuffer;                // Buffer freigeben

		 anz=fwrite(b,1,n,temp);           // schreiben auf Position von n-Bytes
																			 // auf die temp. Datei

		 tempbuffer=new char[laenge-pos];  // Buffer f�r laenge-pos-Bytes erzeugen
		 fread(tempbuffer,1,laenge-pos,d); // lesen der restlichen Bytes
		 fwrite(tempbuffer,1,laenge-pos,temp); // schreiben der restlichen Bytes
																			 // auf die temp. Datei
		 delete tempbuffer;                // Buffer freigeben

		 fclose(d);
		 fclose(temp);

		 unlink(dateiname);                // Original Datei l�schen
		 rename(tempdatei,dateiname);      // temp. Datei auf Dateinamen umbenennen

		 return anz;                       // Returnwert=Anzahl der Bytes
 }
