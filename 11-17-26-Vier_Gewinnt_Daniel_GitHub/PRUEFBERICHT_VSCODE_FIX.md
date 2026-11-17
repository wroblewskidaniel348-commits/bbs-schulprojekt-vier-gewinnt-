# Technischer Prüfbericht – VS-Code-Fix

**Datum:** 17.11.2026  
**Projekt:** Vier Gewinnt | Daniel Wroblewski

## Behobene Konfigurationsprobleme

- `.vscode/tasks.json`: Alle sechs C++-Quelldateien werden gezielt kompiliert, statt `${file}` zu verwenden.
- `.vscode/launch.json`: Das Spiel wird unter dem festen Pfad `VierGewinnt.exe` gestartet; die passende Build-Aufgabe ist verknüpft.
- `VierGewinnt.code-workspace`: Eindeutiger Einstiegspunkt für den korrekten Projektordner.
- Erweiterungsempfehlung für Microsoft C/C++ ergänzt; eine zusätzliche Aufgabe zum Starten und eine zum Ausführen der Regeltests eingerichtet.
- MSYS2-UCRT64-Laufzeitpfad im Debug- und Task-Kontext berücksichtigt.
- Dokumentation für den GitHub-Upload und Fehlerfälle aktualisiert; der fehlerhafte Verweis auf `02_Endversion` ist korrigiert.

## Tatsächlich ausgeführte Prüfungen

- Linux-GCC 14.2: Alle sechs Quelldateien mit C++17 und `-Wall -Wextra -Wpedantic` ohne Fehlermeldungen übersetzt.
- Linux-GCC 14.2: Regeltest-Programm übersetzt und ausgeführt (`Board-, Namen- und Spielertests bestanden.`).
- Linux-GCC 14.2: Konsolenprogramm mit Eingabe `0` gestartet; Startmenü erschien.
- JSON-Struktur, Task-zu-Debug-Verknüpfungen, Programmpfade und ZIP-Archiv technisch geprüft.

## Nicht hier überprüfbar

Ein tatsächlicher VS-Code-, GDB- oder MSYS2-Start unter Windows war in dieser Umgebung nicht möglich. Vor der Schulabgabe sollte Daniel oder eine andere Person auf dem Zielrechner **Strg + Umschalt + B**, **F5** und einen interaktiven Spieldurchlauf prüfen.

## Unverändert erhalten

Die C++-Quellen (`src/`), Header (`include/`), Regeln (`tests/test_regeln.cpp`), Visual-Studio-Community-Projektdateien und vorhandenen PDF-/Präsentationsdateien wurden nicht inhaltlich verändert. Die alten PDF-Anleitungen werden nicht als aktuellster GitHub-Upload-Guide ausgewiesen.

## Absichtlich nicht enthalten

`VierGewinnt.exe` und lokale Spieldaten (`data/spielstand.txt`, `data/highscore.txt`), weil es sich um generierte bzw. private Dateien handelt. Beide Datendateien werden beim Verwenden des Spiels bei Bedarf lokal erzeugt.
