/****************************************************************************
 * @file funktionen.h
 *
 * Projektname : Mastermind
 * Autor:
 * Alexander Hofst�tter
 *
 * Funktions Prototypen f�r Mastermind
 *
 * � 2012 Alexander Hofst�tter
 *
 ***************************************************************************/

 #ifndef _FUNKTIONEN_H_
 #define _FUNKTIONEN_H_

void farbewechseln( int farbe[], int xpos, int startx, int abstand);
/**
 *  Wechseln der Farbe eines einzelnes Feldes.*/
/*  Import (Eingabedaten): int farbe[]    ... Array dessen Farbe gewechselt wird
 *                         int xpos       ... Wert f�r die momentane X-Position
 *                         int startx     ... Wert f�r die X-Position des ersten Feldes
 *                         int abstand    ... Wert f�r den Abstand der Felder
 */

void farbausgabe ( int farbe[], int ypos, int abstand );
/**
 *  Gibt alle Farben eines Arrays in Bl�cken aus.*/
/*  Import (Eingabedaten): int farbe[]    ... Array dessen Farbe ausgegebn wird
 *                         int ypos       ... Wert f�r die momentane Y-Position
 *                         int abstand    ... Wert f�r den Abstand der Felder
 */

void zufallsfarbe ( int farbe[]);
/**
 *  Wei�t dem Array eine zuf�llige Farbe zu.*/
/*  Import (Eingabedaten): int farbe[]    ... Array dessen Werte zugewiesen werden
 */

void trennlinie (int laenge, int x, int y, char zeichen, int zeilen, int color);
/**
 *  Gibt eine Trennlinie mit variablen Daten aus.*/
/*  Import (Eingabedaten): int laenge      ... Wert f�r die L�nge
 *                         int x           ... Wert f�r die X-Position
 *                         int y           ... Wert f�r die Y-Position
 *                         char zeichen    ... Charakter f�r das Symbol
 *                         int zeilen      ... Wert f�r Anzahl der Zeilen
 *                         int color       ... Wert f�r die Farbe
 */

void array_init ( int array[], int wert, int max );
/**
 *  Initialisiert ein Arrays.*/
/*  Import (Eingabedaten): int array[]     ... Gibt das Array an
 *                         int wert        ... Wert f�r die Initialisierung
 *                         int max         ... Wert f�r das letzte Feldelement
 */

int einstellungen (int ypos, int starty, string menue_name, string fehler, int max_wert, int wert);
/**
 *  Lest neue Werte f�r beliebige Variablen ein.*/
/*  Import (Eingabedaten): int ypos              ... Wert f�r die Platzierung in Y-Position
 *                         int starty            ... Wert f�r die 1. Y-Position
 *                         string menue_name     ... String f�r den Namen des Men�eintrages
 *                         string fehler         ... String f�r die Fehlerausgabe
 *                         int max_wert          ... Wert f�r die Bedingung
 *                         int wert              ... Wert f�r die Farbe
 *  Return (R�ckgabewert): Wert der ge�nderten Variable
 */

void setze_hintergrund(int x_max, int y_max, int color);
/**
 *  �berschreibt das komplette Fenster mit einem neuem Hintergrund.*/
/*  Import (Eingabedaten): int x_max     ... Wert f�r die Fensterbreite
 *                         int y_max     ... Wert f�r die Fensterbreite
 *                         int color     ... Wert f�r die Hintergrundfarbe
 */

void goto_printf(int x, int y, string ausgabe);
/**
 *  Platziert den Cursor und gibt �ber printf einen string aus.*/
/*  Import (Eingabedaten): int x              ... Wert f�r die X-Position
 *                         int y              ... Wert f�r die Y-Position
 *                         string ausgabe     ... String f�r die Ausgabe
 */

int menue_start(int art_color, int breite, string menue_name);
/**
 *  Erste Funtkion in jedem Men� oder Untermen�.*/
/*  Import (Eingabedaten): int art_color         ... Wert f�r die Farbe der Ascii_art
 *                         int breite            ... Wert f�r die Fensterbreite
 *                         string menue_name     ... String f�r den Men�namen
 *  Return (R�ckgabewert): Aktuelle Y-Position
 */

int vergleichen(int array_1[], int array_2[], int xpos, int ypos);
/**
 *  Pr�ft die direkten und indirekten Treffer und gibt die Hilfestellung aus.*/
/*  Import (Eingabedaten): int array_1[]     ... Wert f�r die Platzierung in Y-Position
 *                         int array_2[]     ... Wert f�r die 1. Y-Position
 *                         int xpos          ... Wert f�r die X-Position der Hilfestellung
 *  Return (R�ckgabewert): Wert der direkten Treffer
 */

int datei(char *dateiname);
/**
 *  �ffnet eine Datei zum lesen und gibt sie 1:1 am Bildschirm aus.*/
/*  Import (Eingabedaten): char *dateiname   ... Charakter f�r den Dateiname inkl. Pfad
 *  Return (R�ckgabewert): Fehler beim lesen: 1
                           Alles OK: 0
 */

#endif /* _FUNKTIONEN_H_ */
