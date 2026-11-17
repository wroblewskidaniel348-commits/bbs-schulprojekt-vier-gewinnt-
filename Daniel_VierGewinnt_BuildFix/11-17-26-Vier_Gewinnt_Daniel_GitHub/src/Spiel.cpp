// Projekt: Vier Gewinnt | Daniel Wroblewski | KI-Unterstuetzung dokumentiert in docs/KI_Protokoll.md
#include "Spiel.h"
#include "Eingabe.h"
#include "KonsolenDesign.h"
#include <iostream>
#include <cstring>
#ifdef _WIN32
#include <windows.h>
#endif
Spiel::Spiel() { anzahl = 2; aktuell = 0; aktiv = false; namenGesetzt = false; zugzahl = 0; }
bool Spiel::aenderungBestaetigen() {
    if (!aktiv) return true;
    int antwort;
    return zahlLesen("Laufende Partie verwerfen? 1 Ja / 0 Nein: ", 0, 1, antwort) && antwort == 1;
}
bool Spiel::namenEingeben() {
    Spieler neu[4];
    char symbole[4] = {'X','O','A','B'};
    char name[41];
    for (int i = 0; i < anzahl; i++) {
        while (true) {
            std::cout << "Name Spieler " << i + 1 << ": ";
            if (!zeileLesen(name, 41)) return false;
            bool ok = nameGueltig(name);
            for (int j = 0; j < i; j++) if (std::strcmp(name, neu[j].getName()) == 0) ok = false;
            if (ok) break;
            std::cout << "Name ungueltig oder doppelt (max. 40 Bytes, keine Rand-Leerzeichen).\n";
        }
        neu[i].setzen(name, symbole[i]);
    }
    for (int i = 0; i < anzahl; i++) spieler[i] = neu[i];
    namenGesetzt = true;
    return true;
}
// Hauptmenue: Jeder Durchlauf zeichnet die Menueauswahl an derselben Stelle.
void Spiel::starten() {
    const bool farbe = farbenAktiv();
    const char* blau = farbe ? "\033[1;94m" : "";
    const char* grau = farbe ? "\033[90m" : "";
    const char* rot  = farbe ? "\033[91m" : "";
    const char* normal = farbe ? "\033[0m" : "";

    while (true) {
        bildschirmLeeren(); // Vor dem Menue alte Bildschirmausgaben entfernen.
        // Klare Gruppen und Zahlenauswahl, auch ohne Farben gut lesbar.
        std::cout << "\n\n";
        std::cout << blau << "  ========================================\n"
                  << "                VIER GEWINNT\n"
                  << "  ========================================" << normal << "\n";
        std::cout << "  Spieler: " << anzahl << "  |  Partie: "
                  << (aktiv ? "laeuft" : "keine laufende Partie") << "\n";
        std::cout << grau << "  ----------------------------------------" << normal << "\n";
        std::cout << blau << "  SPIEL" << normal << "\n"
                  << "   [1] Neues Spiel\n"
                  << "   [2] Anzahl Spieler aendern\n"
                  << "   [3] Spielernamen eingeben\n\n";
        std::cout << blau << "  VERWALTUNG" << normal << "\n"
                  << "   [4] Spiel speichern\n"
                  << "   [5] Spiel laden\n"
                  << "   [6] Highscore anzeigen\n"
                  << "   [7] Partie fortsetzen\n\n";
        std::cout << rot << "   [0] Spiel beenden" << normal << "\n";
        std::cout << grau << "  ----------------------------------------" << normal << "\n";
        std::cout << "  Bedienung: Zahl eingeben + Enter.\n";
        int wahl;
        if (!zahlLesen("  Deine Auswahl (0-7): ", 0, 7, wahl) || wahl == 0) return;
        if (wahl == 1) {
            if (!aenderungBestaetigen()) continue;
            if (!namenGesetzt && !namenEingeben()) return;
            feld.leeren(anzahl); aktuell = 0; zugzahl = 0; aktiv = true;
            if (!spielen()) return;
        } else if (wahl == 2) {
            if (!aenderungBestaetigen()) continue;
            int neu;
            if (!zahlLesen("Anzahl 2-4: ", 2, 4, neu)) return;
            anzahl = neu; aktiv = false; namenGesetzt = false;
            std::cout << "  Spieleranzahl wurde angepasst.\n";
            aufEnterWarten();
        } else if (wahl == 3) {
            if (!aenderungBestaetigen()) continue;
            if (!namenEingeben()) return;
            aktiv = false;
            std::cout << "  Spielernamen gespeichert.\n";
            aufEnterWarten();
        } else if (wahl == 4) {
            speichern();
            aufEnterWarten();
        } else if (wahl == 5) {
            if (aenderungBestaetigen()) laden();
            aufEnterWarten();
        } else if (wahl == 6) {
            bildschirmLeeren();
            highscore("");
            aufEnterWarten();
        } else if (wahl == 7) {
            if (aktiv) { if (!spielen()) return; }
            else {
                std::cout << "  Keine laufende Partie.\n";
                aufEnterWarten();
            }
        }
    }
}
// Spielschleife: Anzeigen, Spalte lesen, Spielzug setzen und Gewinn pruefen.
// Durch bildschirmLeeren() wird das Brett nicht untereinander gestapelt.
bool Spiel::spielen() {
    // Hinweis bleibt nach einer ungueltigen Eingabe im naechsten Bild sichtbar.
    const char* hinweis = "";
    while (aktiv) {
        bildschirmLeeren(); // Dasselbe Brett wird nach jedem Zug neu angezeigt.
        std::cout << "\n  VIER GEWINNT  |  Zug " << zugzahl + 1 << "\n";
        feld.anzeigen();
        std::cout << "  Am Zug: " << spielsteinFarbe(spieler[aktuell].getSymbol(), farbenAktiv())
                  << spieler[aktuell].getName() << " [" << spieler[aktuell].getSymbol() << "]"
                  << farbe(farbenAktiv(), "\033[0m") << "\n";
        if (hinweis[0] != '\0') std::cout << "  Hinweis: " << hinweis << "\n";
        hinweis = "";
        std::cout << "  Waehle eine Spalte von 1 bis " << feld.getSpalten()
                  << ". Mit 0 kommst du zum Menue zurueck.\n";
        int spalte;
        if (!zahlLesen("  Deine Spalte: ", 0, feld.getSpalten(), spalte)) return false;
        if (spalte == 0) return true;
        if (!feld.einwerfen(spalte - 1, spieler[aktuell].getSymbol())) {
            hinweis = "Diese Spalte ist voll. Bitte andere Spalte waehlen.";
            continue;
        }
        zuege[zugzahl++] = spalte - 1; // Verlauf erlaubt spaeter eine strenge Ladepruefung.
        if (feld.gewonnen(spieler[aktuell].getSymbol())) {
            bildschirmLeeren();
            feld.anzeigen(spieler[aktuell].getSymbol());
            std::cout << "\n  ========================================\n";
            std::cout << "  " << spieler[aktuell].getName() << " gewinnt!\n";
            std::cout << "  Vier markierte Steine: [" << spieler[aktuell].getSymbol()
                      << "] [" << spieler[aktuell].getSymbol()
                      << "] [" << spieler[aktuell].getSymbol()
                      << "] [" << spieler[aktuell].getSymbol() << "]\n";
            std::cout << "  ========================================\n";
            aktiv = false;
            highscore(spieler[aktuell].getName());
            aufEnterWarten(); // Sieg und Highscore koennen in Ruhe gelesen werden.
        } else if (feld.voll()) {
            bildschirmLeeren();
            feld.anzeigen();
            std::cout << "\n  Unentschieden.\n";
            aktiv = false;
            aufEnterWarten();
        } else aktuell = (aktuell + 1) % anzahl;
    }
    return true;
}
