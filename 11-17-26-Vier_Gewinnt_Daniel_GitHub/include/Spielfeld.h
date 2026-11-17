// Daniel Wroblewski | Schnittstelle; Erklaerungen im Projektprotokoll
#ifndef SPIELFELD_H
#define SPIELFELD_H
class Spielfeld {
private:
    char feld[10][11];
    int reihen;
    int spalten;
public:
    Spielfeld();
    void leeren(int spieleranzahl = 2);
    bool einwerfen(int spalte, char symbol);
    bool gewonnen(char symbol) const;
    bool gewinnPositionen(char symbol, int reihe[4], int spalte[4]) const;
    bool voll() const;
    void anzeigen(char gewinnerSymbol = '.') const;
    int getReihen() const;
    int getSpalten() const;
    char getZelle(int reihe, int spalte) const;
};
#endif
