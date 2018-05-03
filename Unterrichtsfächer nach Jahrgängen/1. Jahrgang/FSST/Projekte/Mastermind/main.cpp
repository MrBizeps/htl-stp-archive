/****************************************************************************
 * @file main.cpp
 *
 * Projektname : Mastermind
 * Autor:
 * Alexander Hofst�tter
 *
 * Mastermind
 *
 * � 2012 Alexander Hofst�tter
 *
 * Anmerkung f�r den Lehrer: Eigentlich is des Programm voi afoch zu versteh,
 *                           die Kommentare san nur f�r Trotteln, oba des is
 *                           EHH KLOAA!
 *
 ***************************************************************************/


/*----------- Header-Dateien ----------------------------------------------*/

 using namespace std;               // Namensraum f�r Standardbibliothek definieren

 #include <stdio.h>
 #include <time.h>
 #include <windows.h>               // F�r SetConsoleTitle
 #include <string>                  // F�r Strings
 #include "conio2.h"                // F�r Bildschirmsteuerung und Farben

 #include "funktionen.h"            // Funktionsprototypen
 #include "funktionen.cpp"          // Funktionsdefinitionen
 #include "deklarationen.h"         // Globale Variablen und Pr�prozesser-Direktiven



int main()
{   /*---------- lokale Variablen --------------------------------------------*/
    // Feldergr��e: Maximale Anzahl an Farben
    int code[16];                   // Feld f�r den zuf�lligen generierten Farbcode
    int erraten[16];                // Feld f�r die vom Spieler eingegeben L�sung
    int runde;                      // Z�hlvariable f�r die momentane Runde
    int xpos,ypos;                  // Variable f�r die momentane X- und Y- Position
    int abstand;                    // Variable f�r den Abstand zwischen zwei Feldern
    bool aktives_spiel = FALSE;     // Variable f�r logische Werte True und False f�r die Abfrage ob gespielt wird oder nicht
    char key;                       // Variable f�r diverse Men�abfragen

    srand(time(NULL));                                                  // Zufallsfolge initialisieren
    _setcursortype(100);                                                // Cursor auf volle Gr��e einstellen
    SetConsoleTitle(" Mastermind :: Hack the Code, \270 2012 by A. Hofst\204tter");   // Konsolen Titel setzen
    do                                                                  // Programmwiederholung
    {   if (aktives_spiel == FALSE)                                     // Wenn das Spiel nicht l�uft kommt man ins Men�
        {   /**---------- Men�bereiche ------------------------------------------------*/
            system("mode con cols=80 lines=25");                        // Konsolengr��e unter Windows auf 80 x 25 skalieren
            const int starty = menue_start(SCHWARZ,80,"Startmen\201");   // Konstante Variable f�r die vertikale Startposition
            printf ("      [1]   ... Neues Spiel starten\n");
            printf ("      [2]   ... Modus w\204hlen\n");
            printf ("      [3]   ... Einstellungen\n");
            printf ("      [ESC] ... Programmende\n");

            key = getch();
            if (key == '1')
            {   /*----------- Neues Spiel starten -----------------------------------------*/
                system("mode con cols=110 lines=250");          // Konsolengr��e unter Windows auf 150 x 250 f�r das Men� skalieren
                setze_hintergrund(110,250,hintergrund);         /**kompletten*/// Konsolenhintergrund setzen

                /*---------- Berechnungen f�r X- und Y- Positionen ------------------------*/
                abstand = feld_breite + 2;
                xpos = startx = fenster_breite/2 - (felder_max * abstand)/2 + abstand/2;
                endx = (felder_max - 1) * abstand + startx;
                ypos = wherey() + feld_hoehe + 2;

                array_init(erraten,SCHWARZ,felder_max);         // Initialisierung des Array loesung
                zufallsfarbe(code);                             // Erzeugt einen zuf�lligen Farbcode f�r das Array erraten
                aktives_spiel = TRUE;                           // aktives Spiel auf True setzen
                runde = 1;                                      // und die Runde auf 1
            }

            if (key == '2')
            {   /*----------- Modus w�hlen ------------------------------------------------*/
                do
                {   menue_start(SCHWARZ,80,"Startmen\201 >> Modus w\204hlen");
                    printf ("      [1] ... Mastermind easy   (4 Felder, 4 Farben) \n");   // Mastermind easy = Standardeinstellung
                    printf ("      [2] ... Mastermind        (4 Felder, 6 Farben) \n");
                    printf ("      [3] ... Super Mastermind  (5 Felder, 8 Farben) \n");
                    printf ("      [4] ... Benutzerdefinierter Modus  \n");
                    printf ("      [<] ... Zur\201ck ins Hauptmen\201 \n");

                    /*---------- Pr�ft welche der o.g. Option zur Zeit aktiv ist, -------------*/
                    /*---------- und gibt ein rotes "aktiviert" neben der aktiven Option aus --*/
                    textcolor(ROT);
                    if      (felder_max == 4 && farben_max == 4 )
                        goto_printf(58,starty+2,"...     aktiviert");
                    else if (felder_max == 4 && farben_max == 6 )
                        goto_printf(58,starty+3,"...     aktiviert");
                    else if (felder_max == 5 && farben_max == 8 )
                        goto_printf(58,starty+4,"...     aktiviert");
                    else
                        goto_printf(58,starty+5,"...     aktiviert");

                    /*---------- �ndert die jeweiligen Werte ----------------------------------*/
                    key=getch();                // fragt die Taste ab
                    if (key == '1')
                    {   farben_max = 5; felder_max = 4;            // Setze auf Mastermind easy
                    }
                    if (key == '2')
                    {   farben_max = 6; felder_max = 4;            // Setze auf Mastermind
                    }
                    if (key == '3')
                    {   farben_max = 8; felder_max = 5;            // Setze auf Super Mastermind
                    }
                    if (key == '4')                                // Benutzerdefinierter Modus
                    {   goto_printf(2,24,"Die Einstellungen f\201r den benutzerdefinierten Modus m\201ssen unter");
                        goto_printf(2,25,"Startmen\201 >> Einstellungen angepasst werden");
                        getch();                                   // Warte auf Tastendruck
                    }
                    textcolor(menuefarbe);
                }while(key != BACKSPACE && key != LINKS && key != ENTER);
            }

            if (key == '3')
            {   /*----------- Einstellungen -----------------------------------------------*/
                do
                {   menue_start(SCHWARZ,80,"Startmen\201 >> Einstellungen");
                    printf ("      [1] ... Anzahl an Farben      ...   %4d\n",farben_max);
                    printf ("      [2] ... Anzahl an Feldern     ...   %4d\n",felder_max);
                    printf ("      [3] ... Maximale Runden       ...   %4d\n",runden_max);
                    printf ("      [4] ... H\224he eines Feldes     ...   %4d\n",feld_hoehe);
                    printf ("      [<] ... Zur\201ck ins Hauptmen\201 \n");
                    key=getch();
                    textcolor(ROT);
                    if (key == '1')
                    {   farben_max = einstellungen (1,starty,"Anzahl an Farben","Fehler: Es stehen nur 9 Farben zur Verf\201gung !",9,farben_max);
                        while(farben_max < felder_max)      // Pr�ft ob alle Vorgaben f�r die Variable eingehalten worden sind
                        {   farben_max++;                   // Solange �ndern bis passt
                            goto_printf(2,25," Um Fehler zu vermdeiden wurde die Anzahl an Farben angepasst!");
                            getch();
                        }
                    }
                    if (key == '2')
                        felder_max = einstellungen (2,starty,"Anzahl an Feldern","Fehler: Die Anzahl der Felder muss kleiner gleich der Anzahl der Farben sein!",farben_max,felder_max);
                    if (key == '3')
                        runden_max = einstellungen (3,starty,"Maximale Runden","Fehler: Mehr als 40 Runden sind leider nicht m\224glich!",40,runden_max);
                    if (key == '4')
                        feld_hoehe = einstellungen (4,starty,"H\224he eines Feldes","Fehler: Ein Farbfeld kann nicht h\224her als 15 Zeichen sein!",15,feld_hoehe);

                }while(key != BACKSPACE && key != LINKS && key != ENTER);
            }
        }
        else
        {   /**---------- eigentliches Spiel ------------------------------------------*/
            if (runde <= runden_max)                                    // Solange maximal nicht Runden �berschritten
                farbausgabe(erraten,ypos,abstand);                      // N�chste Ratel�sung vom Spieler ausgeben
            gotoxy(xpos,ypos);                                          // Zur letzten X- und Y- Position springen
            key = getch();
            if (key == ENTER)                                           // Option ENTER (Ratel�sung wird abgeschickt und verglichen)
            {   /*----------- Vergleichsalgorithmus ---------------------------------------*/
                int direkt = vergleichen(code,erraten,endx+feld_breite/2);

                /*----------- Gewinnabfrage -----------------------------------------------*/
                if (runde == runden_max || direkt == felder_max)        // maximal Anzahl an Runden erreicht, oder Code geknackt?
                {   trennlinie(endx-startx+15,fenster_breite,ypos + feld_hoehe - feld_hoehe/4,'=',2,LIGHTRED);  // 2 Trennlinien ausgeben
                    farbausgabe(code,ypos + feld_hoehe + feld_hoehe + 2,abstand);      // Computerl�sung ausgeben zur Kontrolle
                    ypos = wherey() + feld_hoehe;                       // Ypos um die H�he eines Feldes erh�hen
                    textcolor(menuefarbe);

                    if (direkt == felder_max)
                    {   gotoxy(fenster_breite/2-25,ypos);
                        printf("Gl\201ckwunsch, du hast das Spiel in %d Runden gewonnen\n",runde);
                    }
                    else
                        goto_printf(fenster_breite/2-35,ypos,"Du hast leider verloren! Du solltest den Schwierigkeitsgrad verringern!");

                    trennlinie(endx-startx+15,fenster_breite,ypos+2,'=',1,LIGHTRED);
                    aktives_spiel = FALSE;                              // aktives Spiel auf FALSE setzen
                    goto_printf(fenster_breite/2-16,ypos+4," [1]    ...  Nochmal spielen\n");
                    goto_printf(fenster_breite/2-16,ypos+5," [<]    ...  Zur\201ck ins Hauptmen\201\n");
                    goto_printf(fenster_breite/2-16,ypos+6," [ESC]  ...  Programmende\n");

                    key = getch();
                    if (key == '1')
                    {   /*----------- Neues Spiel starten -----------------------------------------*/
                        system("mode con cols=110 lines=250");          // Konsolengr��e unter Windows auf 150 x 250 f�r das Men� skalieren
                        setze_hintergrund(110,250,hintergrund);         // kompletten Konsolenhintergrund setzen

                        /*---------- Berechnungen f�r X- und Y- Positionen ------------------------*/
                        abstand = feld_breite + 2;
                        xpos = startx = fenster_breite/2 - (felder_max * abstand)/2 + abstand/2;
                        endx = (felder_max - 1) * abstand + startx;
                        ypos = wherey() + feld_hoehe + 2;

                        array_init(code,SCHWARZ,felder_max);            // Initialisierung des Arrays code bis felder_max
                        //array_init(erraten,SCHWARZ,felder_max);
                        for ( int i=0; i<felder_max; i++)   // durchl�uft das ganze Array
                        erraten[i]=0;           // und wei�t jedem Feldelement einen Wert zu
                        zufallsfarbe(code);                             // Erzeugt einen zuf�lligen Farbcode f�r das Array
                        aktives_spiel = TRUE;                           // aktives Spiel auf True setzen
                        runde = 1;
                    }
                }
                else if (runde < runden_max)                            // Wenn noch nicht gewonnen, runde und Y-Position erh�hen
                {   runde++;
                    ypos += feld_hoehe + 2;
                }
            }
            gotoxy(xpos,ypos);
            /*----------- Linke Pfeiltaste: X-Position verringern ---------------------*/
            if (key == LINKS  && wherex() > startx)   gotoxy(wherex()-abstand,wherey());
            /*----------- Rechte Pfeiltaste: X-Position vergr��ern --------------------*/
            if (key == RECHTS && wherex() <   endx)   gotoxy(wherex()+abstand,wherey());
            /*----------- Leertaste: Farbe des aktuellen Feldes �ndern ----------------*/
            if (key == SPACE)   farbewechseln(erraten, wherex(), startx, abstand );
            xpos=wherex();                                              // X-Position merken
            ypos=wherey();
        }
    }while(key!=ESC);                                                   // Abbruch bei ESC Taste
    return 0;                                                           // Programm fehlerfrei ausgef�hrt
}
