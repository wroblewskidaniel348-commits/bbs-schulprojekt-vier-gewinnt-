// Projekt: Vier Gewinnt | Daniel Wroblewski | KI-Unterstuetzung dokumentiert in docs/KI_Protokoll.md
#include "Spielfeld.h"
#include "KonsolenDesign.h"
#include <iostream>
#include <iomanip>
#ifdef _WIN32
#include <windows.h>
#endif
Spielfeld::Spielfeld() { leeren(); }
void Spielfeld::leeren(int spieleranzahl) {
    if (spieleranzahl < 2 || spieleranzahl > 4) spieleranzahl = 2;
    reihen = 6 + 2 * (spieleranzahl - 2);
    spalten = 7 + 2 * (spieleranzahl - 2);
    for (int r = 0; r < 10; r++)
        for (int s = 0; s < 11; s++) feld[r][s] = '.';
}
bool Spielfeld::einwerfen(int spalte, char symbol) {
    // Die Eingabe wird vorher von 1..Spalten auf 0..Spalten-1 umgerechnet.
    if (spalte < 0 || spalte >= spalten || symbol == '.') return false;
    for (int r = reihen - 1; r >= 0; r--) {
        // Ich suche von unten: Der Stein darf nicht ueber einem freien Feld liegen.
        if (feld[r][spalte] == '.') {
            feld[r][spalte] = symbol;
            return true;
        }
    }
    return false; // Volle Spalte: Der aufrufende Code wechselt den Spieler nicht.
}
bool Spielfeld::gewonnen(char symbol) const {
    int r[4], s[4];
    return gewinnPositionen(symbol, r, s);
}
bool Spielfeld::gewinnPositionen(char symbol, int reihe[4], int spalte[4]) const {
    if (symbol == '.') return false;
    const int dr[4] = {0, 1, 1, 1};
    const int ds[4] = {1, 0, 1, -1};
    for (int r = 0; r < reihen; r++) {
        for (int s = 0; s < spalten; s++) {
            for (int richtung = 0; richtung < 4; richtung++) {
                int endeR = r + 3 * dr[richtung];
                int endeS = s + 3 * ds[richtung];
                if (endeR < 0 || endeR >= reihen || endeS < 0 || endeS >= spalten)
                    continue;
                bool vier = true;
                for (int k = 0; k < 4; k++) {
                    if (feld[r + k * dr[richtung]][s + k * ds[richtung]] != symbol) {
                        vier = false;
                        break;
                    }
                }
                if (vier) {
                    for (int k = 0; k < 4; k++) {
                        reihe[k] = r + k * dr[richtung];
                        spalte[k] = s + k * ds[richtung];
                    }
                    return true;
                }
            }
        }
    }
    return false;
}
bool Spielfeld::voll() const {
    // Wegen der Schwerkraft reicht die oberste Reihe aus.
    for (int s = 0; s < spalten; s++) if (feld[0][s] == '.') return false;
    return true;
}
// Zeichnet das aktuelle Spielfeld. Die vier Gewinnzellen bekommen [X]/[O].
// Die Klammern bleiben auch bei ausgeschalteten Farben sichtbar.
void Spielfeld::anzeigen(char gewinnerSymbol) const {
    int gewinnR[4] = {}, gewinnS[4] = {};
    bool hatGewonnen = gewinnPositionen(gewinnerSymbol, gewinnR, gewinnS);
    const bool farbeMoeglich = farbenAktiv();
    std::cout << "\n";
    // Einheitliche feste Zeichenbreite, damit alle Spalten gerade bleiben.
    std::cout << "  SPIELFELD\n";
    std::cout << "  ";
    for (int s = 1; s <= spalten; s++) std::cout << std::setw(3) << s;
    std::cout << "\n  +";
    for (int s = 0; s < spalten; s++) std::cout << "---";
    std::cout << "+\n";
    for (int r = 0; r < reihen; r++) {
        std::cout << "  |";
        for (int s = 0; s < spalten; s++) {
            bool gewinnStein = false;
            if (hatGewonnen) {
                for (int k = 0; k < 4; k++) {
                    if (gewinnR[k] == r && gewinnS[k] == s) gewinnStein = true;
                }
            }
            // Die vier Gewinnzeichen werden einzeln hervorgehoben.
            // [X] bleibt auch sichtbar, wenn das Terminal keine Farben unterstuetzt.
            if (gewinnStein) {
                if (farbeMoeglich) std::cout << "\033[1;37;41m"; // Weiss auf Rot
                std::cout << '[' << feld[r][s] << ']';
                if (farbeMoeglich) std::cout << "\033[0m";
            } else {
                std::cout << ' ' << spielsteinFarbe(feld[r][s], farbeMoeglich) << feld[r][s] << farbe(farbeMoeglich, "\033[0m") << ' ';
            }
        }
        std::cout << " |\n";
    }
    std::cout << "  +";
    for (int s = 0; s < spalten; s++) std::cout << "---";
    std::cout << "+\n";
    // Die Symbole funktionieren auch bei ausgeschalteten Terminalfarben.
    if (hatGewonnen) std::cout << "  [ ] markiert die vier Gewinnsteine.\n";
}
int Spielfeld::getReihen() const { return reihen; }
int Spielfeld::getSpalten() const { return spalten; }
char Spielfeld::getZelle(int r, int s) const {
    if (r < 0 || r >= reihen || s < 0 || s >= spalten) return '?';
    return feld[r][s];
}
