
# Vier Gewinnt | Daniel Wroblewski

Endversion

## Ziel

Ein einfaches C++-Konsolenspiel nach Aufgabenblatt 51. Zwei bis vier Spieler, variable Feldgröße, Speichern/Laden und Highscore.


Herausforderung | Lösung | Nachweis
Fallbewegung | Von unten erste freie Zelle suchen | Volle Spalte wird abgelehnt
Gewinnprüfung | Vier Richtungen; Endpunkt vor Zugriff prüfen | Vier Richtungen und Lücke testen
Ungültige Eingaben | Ganze Zeile prüfen; kein Spielerwechsel | Text, Bereichsfehler, lange Zeile


## Klassen

Spieler hält Name und Symbol. Spielfeld verwaltet Zellen und Regeln. Spiel steuert Menü und Zugfolge. Die Funktionen in Eingabe.cpp prüfen Benutzereingaben.

## Start

VierGewinnt.sln in Visual Studio Community 2026 öffnen und Strg + F5 drücken. Voraussetzung: Desktopentwicklung mit C++ ist installiert. Keine Startskripte und keine Schriftinstallation nötig.

## Demo

Daniel und Alex als Namen. Spalten 1, 2, 1, 2, 1, 2, 1: Daniel gewinnt senkrecht. Vorher abc und eine zu große Spalte als Fehlerfälle zeigen.


# Prüfung, Quellen und nächste Schritte



## Wie wird Richtigkeit geprüft?

Direkte C++-Regeltests und simulierte Eingaben; Linux-Build ohne Warnungen. Visual-Studio-Projektdateien strukturell geprüft. Der Start unter MSVC und die eigene Erklärung müssen noch persönlich bestätigt werden. tests/Regeltests.sln ermöglicht eine eigene Regelprüfung ohne Terminal.

## Recherche und Scrum

Daniels Scrum-Aussage vom 12.11.2026: aus IT-Communitys, YouTube-Fachvideos und vorhandenen Protokollen lernen, Lösungen und Fehler nachvollziehen. Im Screenshot ist Matt Hias’ C#-Video zu Vier Gewinnt erkennbar. Die Sprach- und Oberflächentechnik wird nicht als C++ übernommen.

## KI transparent verwenden

KI unterstützte Code, Kommentare, Tests, Projektdateien und Unterlagen. Prompt-Auszüge stehen in docs/KI_Protokoll.md. Daniel ergänzt eigene Änderungen, Tests und verstandene Codeabschnitte.

## Nächste Schritte

Eigene Windows-Abnahme und Erklärung, echte GitHub-Commits und Abschlussdemo vorbereiten.

## Grundlagen

Aufgabenblatt 51; Unterrichtsnotiz zum 19.11.; Buchthemen Kapitel 1–10; DW28-Projektmappe und Original-Scrum-Protokoll. Details und zusätzliche Lernlinks stehen im 24-seitigen Projektprotokoll.