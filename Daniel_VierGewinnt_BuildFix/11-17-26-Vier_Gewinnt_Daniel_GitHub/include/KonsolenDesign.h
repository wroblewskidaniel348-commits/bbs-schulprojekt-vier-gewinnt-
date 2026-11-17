#ifndef KONSOLENDESIGN_H
#define KONSOLENDESIGN_H

// Einfache Konsolenfarben. Das Spiel bleibt auch ohne Farben bedienbar.
#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Prueft die Farbunterstuetzung des Terminals und aktiviert sie unter Windows.
inline bool farbenAktiv() {
#ifdef _WIN32
    HANDLE ausgabe = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD modus = 0;
    return ausgabe != nullptr && ausgabe != INVALID_HANDLE_VALUE
        && GetConsoleMode(ausgabe, &modus)
        && SetConsoleMode(ausgabe, modus | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#else
    return isatty(STDOUT_FILENO) != 0;
#endif
}
// Gibt an, ob wir mit einem sichtbaren Terminal arbeiten.
// Bei Tests mit umgeleiteter Ausgabe wird der Bildschirm NICHT geloescht.
inline bool istInteraktivesTerminal() {
#ifdef _WIN32
    DWORD modus = 0;
    HANDLE ausgabe = GetStdHandle(STD_OUTPUT_HANDLE);
    return ausgabe != INVALID_HANDLE_VALUE && ausgabe != nullptr
        && GetConsoleMode(ausgabe, &modus);
#else
    return isatty(STDOUT_FILENO) != 0;
#endif
}

// Loescht die aktuelle Ansicht, statt bei jeder Auswahl neue Textbloecke
// untereinander zu schreiben. Wichtig: VS Code benutzt unter Windows haeufig
// ein Pseudoterminal, bei dem GetConsoleMode() fehlschlagen kann.
inline void bildschirmLeeren() {
#ifdef _WIN32
    HANDLE ausgabe = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD modus = 0;
    if (ausgabe != nullptr && ausgabe != INVALID_HANDLE_VALUE
            && GetConsoleMode(ausgabe, &modus)) {
        // Echtes Windows-Konsolenfenster: ANSI einschalten, falls moeglich.
        if (SetConsoleMode(ausgabe, modus | ENABLE_VIRTUAL_TERMINAL_PROCESSING)) {
            std::cout << "\033[H\033[2J\033[3J" << std::flush;
            return;
        }
        // Alte Windows-Konsole ohne ANSI: Bildschirm ueber Windows API leeren.
        CONSOLE_SCREEN_BUFFER_INFO info;
        if (!GetConsoleScreenBufferInfo(ausgabe, &info)) return;
        COORD anfang = {0, 0};
        DWORD geschrieben = 0;
        DWORD anzahl = static_cast<DWORD>(info.dwSize.X) * info.dwSize.Y;
        FillConsoleOutputCharacterA(ausgabe, ' ', anzahl, anfang, &geschrieben);
        FillConsoleOutputAttribute(ausgabe, info.wAttributes, anzahl, anfang, &geschrieben);
        SetConsoleCursorPosition(ausgabe, anfang);
        return;
    }
    // VS Code / Windows Terminal: oft per Pseudoterminal angebunden.
    // ANSI direkt ausgeben, selbst wenn GetConsoleMode() kein Handle erkennt.
    std::cout << "\033[H\033[2J\033[3J" << std::flush;
#else
    // Bei automatisierten Tests (umgeleitete Ausgabe) nichts loeschen.
    if (isatty(STDOUT_FILENO))
        std::cout << "\033[H\033[2J\033[3J" << std::flush;
#endif
}

// Wartet nach Meldungen, damit sie nicht sofort vom Menue ueberschrieben werden.
inline void aufEnterWarten() {
#ifndef _WIN32
    if (!istInteraktivesTerminal()) return;
#endif
    std::cout << "\n  Weiter mit Enter ... " << std::flush;
    std::string eingabe;
    std::getline(std::cin, eingabe);
}

inline const char* farbe(bool an, const char* code) { return an ? code : ""; }
inline const char* spielsteinFarbe(char symbol, bool an) {
    if (!an) return "";
    if (symbol == 'X') return "\033[1;94m";  // Blau
    if (symbol == 'O') return "\033[1;93m";  // Gelb, gut auf dunklem Grund
    if (symbol == 'A') return "\033[1;96m";  // Cyan
    if (symbol == 'B') return "\033[1;95m";  // Magenta
    return "";
}
#endif
