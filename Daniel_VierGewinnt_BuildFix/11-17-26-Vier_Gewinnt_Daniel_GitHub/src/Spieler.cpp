// Projekt: Vier Gewinnt | Daniel Wroblewski | KI-Unterstuetzung dokumentiert in docs/KI_Protokoll.md
#include "Spieler.h"
Spieler::Spieler() { name[0] = '\0'; symbol = 'X'; }
void Spieler::setzen(const char neuerName[], char neuesSymbol) {
    int i = 0;
    while (i < 40 && neuerName[i] != '\0') {
        name[i] = neuerName[i];
        i++;
    }
    name[i] = '\0'; // Ohne Abschluss weiss die Ausgabe nicht, wo der Name endet.
    symbol = neuesSymbol;
}
const char* Spieler::getName() const { return name; }
char Spieler::getSymbol() const { return symbol; }
