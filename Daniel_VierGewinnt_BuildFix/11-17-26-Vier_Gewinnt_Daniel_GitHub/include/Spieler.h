// Daniel Wroblewski | Schnittstelle; Erklaerungen im Projektprotokoll
#ifndef SPIELER_H
#define SPIELER_H
// Kapitel 7 und 10: Eine Klasse fasst Name und Spielzeichen zusammen.
// Kommentare sind KI-gestuetzte Erklaerhilfen, keine bestaetigte Eigenleistung.
class Spieler {
private:
    char name[41]; // 40 Zeichen plus abschliessendes Nullzeichen.
    char symbol;
public:
    Spieler();
    void setzen(const char neuerName[], char neuesSymbol);
    const char* getName() const;
    char getSymbol() const;
};
#endif
