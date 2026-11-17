// Projekt: Vier Gewinnt | Daniel Wroblewski | KI-Unterstuetzung dokumentiert in docs/KI_Protokoll.md
#include "Eingabe.h"
#include <iostream>
bool zeileLesen(char text[], int groesse) {
    while (true) {
        std::cin.getline(text, groesse);
        if (!std::cin.fail()) return true;
        if (std::cin.eof()) return false;
        std::cin.clear();
        // Den Rest einer zu langen Zeile entfernen, damit er keine neue Eingabe wird.
        char rest;
        while (std::cin.get(rest) && rest != '\n') {}
        if (std::cin.eof()) return false;
        std::cout << "Eingabe zu lang. Bitte erneut: ";
    }
}
bool zahlLesen(const char frage[], int minimum, int maximum, int& ergebnis) {
    char text[80];
    while (true) {
        std::cout << frage;
        if (!zeileLesen(text, 80)) return false;
        int wert = 0;
        bool ok = text[0] != '\0';
        for (int i = 0; text[i] != '\0'; i++) {
            if (text[i] < '0' || text[i] > '9' || wert > maximum) { ok = false; break; }
            wert = wert * 10 + (text[i] - '0');
        }
        if (ok && wert >= minimum && wert <= maximum) { ergebnis = wert; return true; }
        std::cout << "Ungueltige Eingabe. Erlaubt: " << minimum << " bis " << maximum << ".\n";
    }
}
bool nameGueltig(const char text[]) {
    bool inhalt = false;
    int i = 0;
    for (; text[i] != '\0'; i++) {
        if (i >= 40 || static_cast<unsigned char>(text[i]) < 32) return false;
        if (text[i] != ' ') inhalt = true;
    }
    return inhalt && text[0] != ' ' && text[i-1] != ' ';
}
