// Daniel Wroblewski | Schnittstelle; Erklaerungen im Projektprotokoll
#ifndef SPIEL_H
#define SPIEL_H
#include "Spieler.h"
#include "Spielfeld.h"
class Spiel {
private:
    Spieler spieler[4];
    Spielfeld feld;
    int anzahl, aktuell;
    bool aktiv, namenGesetzt;
    int zuege[110];
    int zugzahl;
    bool namenEingeben();
    bool spielen();
    bool aenderungBestaetigen();
    void speichern();
    void laden();
    void highscore(const char sieger[]); // Leerer Text bedeutet nur anzeigen.
public:
    Spiel();
    void starten();
};
#endif
