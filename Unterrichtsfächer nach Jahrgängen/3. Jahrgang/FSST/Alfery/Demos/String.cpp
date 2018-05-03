/////////////////////////////////////////////////////////////////////
//	program name  :   String.cpp                                   //
//	Autor         :   w.alfery                                 //
//                                                                 //
//	Themen		  :   Stringklasse String                          //
//                    mit dynamischer Speicherverwaltung und       //
//                    mit �berladenen Operatoren = + == !=         //
//                                                                 //
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
//                    Include Dateien                              //
/////////////////////////////////////////////////////////////////////

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <iostream>

 using namespace std;

/////////////////////////////////////////////////////////////////////
//                    Klassendefinition String                     //
/////////////////////////////////////////////////////////////////////

class String
{	private:
	char *ps;                          // Zeiger auf dyn. String
	int l;                             // Stringl�nge

	public:
	String( );                         // Konstruktoren
	String( const char* );
	String( const String &s );

	virtual ~String();                 // Destruktor

	int length(){return(l);}           // Stringl�nge zur�ckgeben
	void in();                         // String eingeben
	void out(){puts(ps);}              // String ausgeben
	int charat(int i);                 // i-tes Zeichen ausgeben
	int stringtoa(char *s);            // auf C-String umwandeln

	String& operator = (const String&);      // = Operator f�r Zuweisung
	String& operator = (const char * );      // = Operator f�r Zuweisung C-String
	String& operator += (const String&);     // += Operator

    friend String operator + (const String&,const String&);// + Operator f�r Verkettung
	friend int operator == (const String&,const String&);// == Operator f�r Vergleich
	friend int operator != (const String&,const String&);// != Operator f�r Vergleich

};


/////////////////////////////////////////////////////////////////////
//                    String Methoden Definitionen                 //
/////////////////////////////////////////////////////////////////////

String::String( )                      // 1.Konstruktor
//
//  Konstruktor zur Instanzierung eines leeren Strings
//  Bsp.:  String s;
//
{   l  = 0;                            // L�nge zuweisen
	ps = new char[l+1];                // dyn. Speicherplatz reservieren
	ps[0] = '\0';                      // Leerstring initialisieren
}

String::String(const char *s )         // 2.Konstruktor
//
//  Konstruktor zur Instanzierung eines Strings mit C-String
//  Bsp.:  String s("Hallo");
//
{   l  = strlen(s);                    // L�nge zuweisen
	ps = new char[l+1];                // dyn. Speicherplatz reservieren
	strcpy(ps,s);                      // String s auf ps kopieren
}

String::String(const String& s )       // Copy-Konstruktor
//
//  Kopier-Konstruktor f�r die Zuweisung eines String-Objekts
//  Bsp.:  String s2=s1;
//
{   l  = s.l;                          // L�nge zuweisen
	ps = new char[l+1];                // dyn. Speicherplatz reservieren
	strcpy(ps,s.ps);                   // String s kopieren
}

String::~String()                      // Destruktor
//
//  Destruktor zum korrekten Freigeben des dyn. reservierten Speichers
//
{  delete[] ps;
}

void String::in()	                   // String einlesen
//
//  Methode zum Einlesen eines Strings
//
{   char *pnew;                        // Zeiger auf String
	delete[] ps;                       // alten Speicherplatz freigeben
	pnew = new char[256];              // neuen Hilfsspeicher f�r max. 256 Zeichen
    fgets(pnew,256,stdin);             // String einlesen
	l = strlen(pnew);                  // L�nge bestimmen
	ps = new char[l+1];                // neuen dyn. Speicherplatz reservieren
	strcpy(ps,pnew);                   // String kopieren
	delete[] pnew;                     // Hilfsspeicher freigeben
}

int String::charat(int i)              // i-tes Zeichen ausgeben
//
//  Methode f�r die Ausgabe des i-ten Zeichens
//
{   if ((i>=0)&&(i<l)) return ps[i];   // wenn g�ltiger Index
	else return 0;
}

int String::stringtoa(char *s)         // auf C-String umwandeln
//
//  Methode f�r die Umwandlung auf C-String s
//
{   int i,len;
	strcpy(s,ps);                      // String kopieren
	return l;
}

String& String::operator = (const String& s) // = Operator
//
//  Operator f�r Stringzuweisung mit =
//  Bsp.:  s2 = s1;
//
{   l  = s.l;                          // L�nge von s zuweisen
	delete[] ps;                       // Speicherplatz freigeben
	ps = new char[l+1];                // neuen Speicherplatz reservieren
	strcpy(ps,s.ps);                   // String s kopieren
	return (*this);                    // Objekt zur�ckgeben
}

String& String::operator = (const char *s)    // = Operator f�r C-String
//
//  Operator f�r Stringzuweisung mit =  f�r C-String
//  Bsp.:  s = "hallo";
//
{   l  = strlen(s);                    // L�nge von s zuweisen
	delete[] ps;                       // Speicherplatz freigeben
	ps = new char[l+1];                // neuen Speicherplatz reservieren
	strcpy(ps,s);                      // String s kopieren
	return (*this);                    // Objekt zur�ckgeben
}

String& String::operator += (const String& s)// += Operator
//
//  Operator f�r Stringzuweisung mit +=
//  Bsp.:  s2 += s1;
//
{   char *pnew;                        // Zeiger auf String
	l  += s.l;                         // neue L�nge bestimmen
  	pnew = new char[l+1];              // neuen dyn. Speicherplatz reservieren
    strcpy(pnew,ps);                   // String ps kopieren
    strcat(pnew,s.ps);                 // String s anh�ngen
	delete[] ps;                       // alten Speicherplatz freigeben
	ps = pnew;                         // neuen Speicherplatz �bernehmen
	return (*this);                    // Objekt zur�ckgeben
}

/////////////////////////////////////////////////////////////////////
//                    String friend Operatoren                     //
/////////////////////////////////////////////////////////////////////

String operator + (const String& s1,const String& s2) // + Operator
//
//  Operator f�r Stringverkettung mit +
//  Bsp.:  s3 = s1 + s2;
//
{   String s=s1;              // String s mit s1 initialisieren
  	s += s2;                  // String s2 anh�ngen
	return (s);               // Objekt zur�ckgeben
}


int  operator == (const String& s1,const String& s2) // == Operator
//
//  Operator f�r Stringvergleich auf Gleichheit
//  Bsp.:  if (s1==s2) ;
//
{
	return (strcmp(s1.ps,s2.ps)==0);   // return true bei Gleichheit
}

int  operator != (const String& s1,const String& s2) // != Operator
//
//  Operator f�r Stringvergleich auf Gleichheit
//  Bsp.:  if (s1!=s2) ;
//
{
	return (strcmp(s1.ps,s2.ps)!=0);   // return true bei Ungleichheit
}



/////////////////////////////////////////////////////////////////////
//                    Hauptprogramm                                //
/////////////////////////////////////////////////////////////////////

int main()
{  int i,anz;

   cout << endl << "  eigene String Klasse   " << endl;

   String s1("String1");               // Strings instanzieren
   String s2=s1;
   String s3,s4,s5;

   char cs[256];                       // C-String

   cout << endl << "  Strings instanzieren : " << endl;
   cout << "  s1 = ";
   s1.out();                           // String s1 ausgeben
   s2=" und String2 ";                 // Konstantstring zuweisen
   cout << "  s2 = ";
   s2.out();

   s3=s1;                              // Stringobjekt zuweisen
   cout << endl << "  Stringzuweisung mit Operator = ";
   cout << endl << "  s3 = s1  : ";
   s3.out();

   s3=s1+s2;                           // Strings verketten
   cout << endl << "  Stringverkettung mit Operator + ";
   cout << endl << "  s3=s1+s2 : ";
   s3.out();

   s3+=s1;                             // Strings verketten
   cout << endl << "  Stringverkettung mit Operator + ";
   cout << endl << "  s3+=s1   : ";
   s3.out();

   cout << endl << "  String-Methoden verwenden ";
   cout << endl << "  s4 eingeben : ";
   s4.in();                            // String einlesen

   cout << endl << "  Stringlaenge von s4 = " << s4.length();
   cout << endl << "  erstes Zeichen von s4 = ";
   cout << (char) s4.charat(0);        // Einzelzeichen ausgeben
   cout << endl << "  letztes Zeichen von s4 = ";
   cout << (char) s4.charat(s4.length()-1);

   cout << endl << "  auf C-String cs umwandeln : ";
   s4.stringtoa(cs);                   // auf C-String cs umwandeln
   cout << cs;

   s5 = cs;                            // auf String-Objekt umwandeln
   cout << endl << "  auf String-Objekt umwandeln : ";
   cout << "  s5 = ";
   s5.out();

   cout << endl <<"  Stringvergleich s5==s4 : ";
   if (s5==s4) cout << " Strings gleich "; // Stringvergleich
   else        cout << " Strings ungleich ";

   cout << endl << endl;
   system("PAUSE");
   return 0;
 }
