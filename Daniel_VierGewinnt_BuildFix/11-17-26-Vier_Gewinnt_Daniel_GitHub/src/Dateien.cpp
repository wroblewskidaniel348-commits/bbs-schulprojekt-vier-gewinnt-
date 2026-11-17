// Projekt: Vier Gewinnt | Daniel Wroblewski | KI-Unterstuetzung dokumentiert in docs/KI_Protokoll.md
// ERWEITERUNG: fstream gehoert laut Inhaltsverzeichnis zu Kapitel 11.
// Diese Datei wird fuer die vollstaendige Aufgabenstellung benoetigt.
#include "Spiel.h"
#include "Eingabe.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cerrno>

// Erst die temporaere Datei fertig schreiben. Dann das Original ersetzen.
// Portable C++11-Loesung mit Rueckfallkopie; keine Garantie bei Stromausfall.
static bool ersetzen(const char ziel[], const char temp[]) {
    char backup[100];
    std::snprintf(backup, sizeof backup, "%s.bak", ziel);
    std::ifstream alt(ziel);
    bool vorhanden = alt.good(); alt.close();
    if (vorhanden) {
        std::remove(backup);
        if (std::rename(ziel, backup) != 0) return false;
    }
    if (std::rename(temp, ziel) != 0) {
        if (vorhanden) std::rename(backup, ziel);
        return false;
    }
    if (vorhanden) std::remove(backup);
    return true;
}
void Spiel::speichern() {
    if (!aktiv) { std::cout << "Keine laufende Partie zu speichern.\n"; return; }
    std::ofstream datei("data/spielstand.tmp");
    datei << "VG1\n" << anzahl << ' ' << aktuell << ' ' << feld.getReihen() << ' '
          << feld.getSpalten() << ' ' << zugzahl << '\n';
    for (int i = 0; i < anzahl; i++) datei << spieler[i].getName() << '\n' << spieler[i].getSymbol() << '\n';
    for (int r = 0; r < feld.getReihen(); r++) {
        for (int s = 0; s < feld.getSpalten(); s++) datei << feld.getZelle(r,s);
        datei << '\n';
    }
    for (int i = 0; i < zugzahl; i++) datei << zuege[i] << ' ';
    datei << '\n'; datei.close();
    if (!datei || !ersetzen("data/spielstand.txt", "data/spielstand.tmp"))
        std::cout << "Speichern fehlgeschlagen. Ordner data und Schreibrechte pruefen.\n";
    else std::cout << "Spiel gespeichert.\n";
}
void Spiel::laden() {
    std::ifstream datei("data/spielstand.txt");
    if (!datei) { std::cout << "Spielstand nicht lesbar.\n"; return; }
    // In eine lokale Kopie einlesen. Ein Fehler darf die aktuelle Partie nicht zerstoeren.
    Spiel neu;
    char version[20], name[41], symbol, zeile[20];
    int reihen, spalten;
    datei.getline(version, 20);
    bool ok = datei.good() && std::strcmp(version, "VG1") == 0;
    if (!(datei >> neu.anzahl >> neu.aktuell >> reihen >> spalten >> neu.zugzahl)) ok = false;
    if (!ok || neu.anzahl < 2 || neu.anzahl > 4 || neu.zugzahl < 0 || neu.zugzahl > 110) {
        std::cout << "Ungueltiger Spielstand.\n"; return;
    }
    if (reihen != 6 + 2*(neu.anzahl-2) || spalten != 7 + 2*(neu.anzahl-2)
        || neu.aktuell != neu.zugzahl % neu.anzahl) ok = false;
    datei.ignore(10000, '\n');
    char symbole[4] = {'X','O','A','B'};
    for (int i = 0; i < neu.anzahl && ok; i++) {
        datei.getline(name,41);
        datei.getline(zeile,20); symbol = zeile[0];
        if (!datei || !nameGueltig(name) || zeile[1] != '\0' || symbol != symbole[i]) ok = false;
        for (int j = 0; j < i; j++) if (std::strcmp(name,neu.spieler[j].getName()) == 0) ok = false;
        neu.spieler[i].setzen(name,symbol);
    }
    char gelesen[10][11];
    for (int r = 0; r < reihen && ok; r++) {
        datei.getline(zeile,20);
        if (!datei || static_cast<int>(std::strlen(zeile)) != spalten) { ok = false; break; }
        for (int s = 0; s < spalten; s++) gelesen[r][s] = zeile[s];
    }
    neu.feld.leeren(neu.anzahl);
    for (int i = 0; i < neu.zugzahl && ok; i++) {
        if (!(datei >> neu.zuege[i])) { ok = false; break; }
        char stein = symbole[i % neu.anzahl];
        if (!neu.feld.einwerfen(neu.zuege[i],stein)) { ok = false; break; }
        // Beendete Partien werden nicht geladen: Kein doppelter Highscore durch Wiederladen.
        if (neu.feld.gewonnen(stein) || neu.feld.voll()) ok = false;
    }
    for (int r = 0; r < reihen && ok; r++)
        for (int s = 0; s < spalten; s++) if (gelesen[r][s] != neu.feld.getZelle(r,s)) ok = false;
    char extra;
    if (datei >> extra) ok = false;
    if (!ok) { std::cout << "Ungueltiger Spielstand. Aktuelle Partie unveraendert.\n"; return; }
    neu.aktiv = true; neu.namenGesetzt = true;
    *this = neu; // Kapitel 10: Die gepruefte Kopie wird jetzt erst uebernommen.
    std::cout << "Spiel geladen. Mit 7 fortsetzen.\n";
}
void Spiel::highscore(const char sieger[]) {
    // Kapitel 9: Ein Datensatz besteht aus Name und Anzahl Siege.
    struct Eintrag { char name[41]; int siege; };
    Eintrag liste[1000];
    int anzahlEintraege = 0;
    std::ifstream datei("data/highscore.txt");
    if (datei) {
        char version[20]; datei.getline(version,20);
        if (std::strcmp(version,"VGS1") != 0 || !(datei >> anzahlEintraege)
            || anzahlEintraege < 0 || anzahlEintraege > 1000) {
            std::cout << "Highscore beschaedigt; nicht veraendert.\n"; return;
        }
        datei.ignore(10000,'\n');
        for (int i = 0; i < anzahlEintraege; i++) {
            datei.getline(liste[i].name,41);
            bool ok = nameGueltig(liste[i].name);
            if (!(datei >> liste[i].siege) || liste[i].siege < 0 || liste[i].siege > 1000000000) ok = false;
            datei.ignore(10000,'\n');
            for (int j = 0; j < i; j++) if (std::strcmp(liste[i].name,liste[j].name) == 0) ok = false;
            if (!ok || !datei) { std::cout << "Highscore beschaedigt; nicht veraendert.\n"; return; }
        }
        char extra;
        if (datei >> extra) { std::cout << "Highscore beschaedigt; nicht veraendert.\n"; return; }
    } else {
        // Nur bei einer wirklich fehlenden Datei mit einer leeren Liste beginnen.
        // errno/ENOENT sind kleine Hilfsmittel fuer die Fehlerbehandlung (Zusatzstoff).
        errno = 0;
        std::FILE* pruefung = std::fopen("data/highscore.txt", "r");
        int fehler = errno;
        if (pruefung) std::fclose(pruefung);
        if (pruefung || fehler != ENOENT) {
            std::cout << "Highscore nicht lesbar; nicht veraendert.\n"; return;
        }
    }
    datei.close();
    if (sieger[0] != '\0') {
        int index = -1;
        for (int i = 0; i < anzahlEintraege; i++) if (std::strcmp(liste[i].name,sieger) == 0) index = i;
        if (index == -1) {
            if (anzahlEintraege == 1000) { std::cout << "Highscore voll. Sieg nicht gespeichert.\n"; return; }
            index = anzahlEintraege++;
            std::strcpy(liste[index].name,sieger); liste[index].siege = 0;
        }
        if (liste[index].siege == 1000000000) { std::cout << "Sieggrenze erreicht.\n"; return; }
        liste[index].siege++;
    }
    // Kapitel 7.3: einfacher Auswahlsort. Viele Siege zuerst, bei Gleichstand Name.
    for (int i = 0; i < anzahlEintraege; i++) {
        int bester = i;
        for (int j = i+1; j < anzahlEintraege; j++) {
            if (liste[j].siege > liste[bester].siege ||
               (liste[j].siege == liste[bester].siege && std::strcmp(liste[j].name,liste[bester].name) < 0)) bester = j;
        }
        Eintrag temp = liste[i]; liste[i] = liste[bester]; liste[bester] = temp;
    }
    if (sieger[0] != '\0') {
        std::ofstream aus("data/highscore.tmp");
        aus << "VGS1\n" << anzahlEintraege << '\n';
        for (int i = 0; i < anzahlEintraege; i++) aus << liste[i].name << '\n' << liste[i].siege << '\n';
        aus.close();
        if (!aus || !ersetzen("data/highscore.txt","data/highscore.tmp"))
            std::cout << "Sieg erkannt, aber Highscore konnte nicht gespeichert werden.\n";
    }
    std::cout << "\nHIGHSCORE\n";
    for (int i = 0; i < anzahlEintraege; i++) std::cout << i+1 << ". " << liste[i].name << ": " << liste[i].siege << '\n';
    if (anzahlEintraege == 0) std::cout << "Noch keine Siege.\n";
}
