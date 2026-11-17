// Daniel Wroblewski | Schnittstelle; Erklaerungen im Projektprotokoll
#ifndef EINGABE_H
#define EINGABE_H
// false bedeutet Eingabeende (z.B. Strg+Z unter Windows), nicht Endlosschleife.
bool zeileLesen(char text[], int groesse);
bool zahlLesen(const char frage[], int minimum, int maximum, int& ergebnis);
bool nameGueltig(const char text[]);
#endif
