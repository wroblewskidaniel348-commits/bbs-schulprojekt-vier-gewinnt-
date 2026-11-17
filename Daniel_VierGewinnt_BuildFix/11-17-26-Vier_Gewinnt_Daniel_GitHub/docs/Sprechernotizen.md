# Sprechernotizen

Als Vorbereitung verwenden und in eigenen Worten erklären.


## Folie 1

Daniel Wroblewski. Abschlussvortrag als Entwurf für etwa 30 Minuten inklusive etwa 10 Minuten Live-Demo. Stand der technischen Ausarbeitung: 14.11.2026. Kein tatsächlich bereits gehaltener Abschlussvortrag und keine vorweggenommene persönliche Abnahme.

Quellen: Aufgabenblatt 51, Vier Gewinnt.pdf; DW28-Projektmappe und Original-Scrum-Protokoll 12.11.2026. Umsetzung und Tests: 14.11.2026. Persönliche Erfahrungen vor dem Vortrag ergänzen.

## Folie 2

Aufgabenblatt 51, Seiten 2–4 und 13: 2–4 Spieler, pro zusätzlichem Spieler zwei Reihen und Spalten, Hauptmenü, Namen, Spielstand und Highscore. Die Konsole ist bewusst einfach. Keine externen Bibliotheken oder Grafikoberfläche.

Quellen: Aufgabenblatt 51, Vier Gewinnt.pdf; DW28-Projektmappe und Original-Scrum-Protokoll 12.11.2026. Umsetzung und Tests: 14.11.2026. Persönliche Erfahrungen vor dem Vortrag ergänzen.

## Folie 3

Spiel besitzt ein Spielfeld und ein Array für bis zu vier Spieler. Spieler hält Name und Symbol. Spielfeld stellt Methoden bereit. Dateien.cpp implementiert zusätzliche Methoden von Spiel; es ist keine vierte Klasse. Eingabe.cpp ist ein kleines Hilfsmodul.

Quellen: Aufgabenblatt 51, Vier Gewinnt.pdf; DW28-Projektmappe und Original-Scrum-Protokoll 12.11.2026. Umsetzung und Tests: 14.11.2026. Persönliche Erfahrungen vor dem Vortrag ergänzen.

## Folie 4

Formel aus dem Aufgabenblatt: Spalten=7+2*(Anzahl-2); Reihen=6+2*(Anzahl-2). Das Array hat maximal 10×11 Zellen; nur der benötigte Bereich wird verwendet. Dies ist größenabhängige Nutzung eines festen Arrays, keine dynamische Heap-Allokation.

Quellen: Aufgabenblatt 51, Vier Gewinnt.pdf; DW28-Projektmappe und Original-Scrum-Protokoll 12.11.2026. Umsetzung und Tests: 14.11.2026. Persönliche Erfahrungen vor dem Vortrag ergänzen.

## Folie 5

Code in Spielfeld.cpp. Parameter spalte ist bereits 0-basiert. Vor diesem Ausschnitt werden ungültige Spalten abgefangen. Bei einer vollen Spalte liefert die Methode false, und die Steuerung wechselt den Spieler nicht.

Quellen: Aufgabenblatt 51, Vier Gewinnt.pdf; DW28-Projektmappe und Original-Scrum-Protokoll 12.11.2026. Umsetzung und Tests: 14.11.2026. Persönliche Erfahrungen vor dem Vortrag ergänzen.

## Folie 6

Jede Zelle als Beginn betrachten; vier Richtungen. Der vierte Endpunkt muss innerhalb des Feldes sein, bevor die vier Zellzugriffe erfolgen. Die Prüfung sucht Vierergruppen im ganzen kleinen Feld. Eine Lücke darf keinen Sieg ergeben.

Quellen: Aufgabenblatt 51, Vier Gewinnt.pdf; DW28-Projektmappe und Original-Scrum-Protokoll 12.11.2026. Umsetzung und Tests: 14.11.2026. Persönliche Erfahrungen vor dem Vortrag ergänzen.

## Folie 7

Eingaben vollständig prüfen. Bei Ladefehlern bleibt die bisherige Partie unverändert. Änderungen von Namen oder Spielerzahl während einer laufenden Partie erfordern eine Verwerfungsbestätigung. Ende der Eingabe beendet kontrolliert.

Quellen: Aufgabenblatt 51, Vier Gewinnt.pdf; DW28-Projektmappe und Original-Scrum-Protokoll 12.11.2026. Umsetzung und Tests: 14.11.2026. Persönliche Erfahrungen vor dem Vortrag ergänzen.

## Folie 8

Dateien.cpp verwendet fstream aus Kapitel 11, als Zusatzstoff gekennzeichnet. Format VG1. Kopf: Anzahl, aktueller Index, Reihen, Spalten, Zugzahl. Dann Namen und Symbole, Feldreihen, Zugliste. Die temporäre Datei wird geschlossen und anschließend mit Rückfallkopie an die Zielstelle gesetzt. Stromausfälle und mehrere Instanzen sind nicht abgesichert.

Quellen: Aufgabenblatt 51, Vier Gewinnt.pdf; DW28-Projektmappe und Original-Scrum-Protokoll 12.11.2026. Umsetzung und Tests: 14.11.2026. Persönliche Erfahrungen vor dem Vortrag ergänzen.

## Folie 9

Die lokale Kopie neu wird erst nach erfolgreicher Prüfung übernommen. Prüfen: Version, Größen, Namen, Symbole, Zugzahl, nächster Spieler. Dann alle Züge ohne Gewinn oder Remis nachspielen. Das rekonstruierte Feld muss genau zum gespeicherten Feld passen. Zusätzliche Dateiinhalte ablehnen.

Quellen: Aufgabenblatt 51, Vier Gewinnt.pdf; DW28-Projektmappe und Original-Scrum-Protokoll 12.11.2026. Umsetzung und Tests: 14.11.2026. Persönliche Erfahrungen vor dem Vortrag ergänzen.

## Folie 10

Struktur Eintrag: Name und Siege. Datei VGS1, maximal 1.000 Einträge. Namen werden exakt verglichen. Nach einem Sieg +1, einfacher Auswahlsort absteigend; bei Gleichstand byteweise strcmp. Keine deutsche Wörterbuchsortierung. Abgeschlossene Partien werden nicht als aktive Stände geladen.

Quellen: Aufgabenblatt 51, Vier Gewinnt.pdf; DW28-Projektmappe und Original-Scrum-Protokoll 12.11.2026. Umsetzung und Tests: 14.11.2026. Persönliche Erfahrungen vor dem Vortrag ergänzen.

## Folie 11

Gezielte Prüfungen vom 14.11.2026 unter Linux, g++ 14.2.0. Direkte Regeln mit ASan/UBSan bestanden; Leak-Prüfung umgebungsbedingt aus. Dateirundlauf für 2/3/4 Spieler, beschädigte Daten, Highscore-Sortierung und genau eine Erhöhung geprüft. Projektdateien per XML und Dateiverweisen kontrolliert. Keine native MSVC-Prüfung behauptet.

Quellen: Aufgabenblatt 51, Vier Gewinnt.pdf; DW28-Projektmappe und Original-Scrum-Protokoll 12.11.2026. Umsetzung und Tests: 14.11.2026. Persönliche Erfahrungen vor dem Vortrag ergänzen.

## Folie 12

Etwa 10 Minuten reservieren. 1: Menü und Names. 2: beispiel_vor_sieg.txt nach spielstand.txt kopieren, 5 laden, 7 fortsetzen und mit Spalte 1 gewinnen. 3: Highscore zeigen. 4: drei oder vier Spieler einstellen, neues Spiel starten und Größe erklären. 5: Zwischenstand speichern, Programm neu starten, laden und fortsetzen. Vor dem Kopieren eigene Spielstände sichern. Einen beschädigten Spielstand nur an einer Kopie testen.

Quellen: Aufgabenblatt 51, Vier Gewinnt.pdf; DW28-Projektmappe und Original-Scrum-Protokoll 12.11.2026. Umsetzung und Tests: 14.11.2026. Persönliche Erfahrungen vor dem Vortrag ergänzen.

## Folie 13

Scrum-Protokoll vom 12.11.2026: Daniel lernt aus Communitys, YouTube und bestehenden Protokollen. Im Screenshot identifiziert: Matt Hias, Visual Studio C# 18 - Vier gewinnt, https://www.youtube.com/watch?v=AYaJa2sxong. Keine C#-Oberfläche übernommen. KI-Hilfe ist in docs/KI_Protokoll.md ausgewiesen. Echte persönliche Änderungen und GitHub-Commits müssen danach dokumentiert werden.

Quellen: Aufgabenblatt 51, Vier Gewinnt.pdf; DW28-Projektmappe und Original-Scrum-Protokoll 12.11.2026. Umsetzung und Tests: 14.11.2026. Persönliche Erfahrungen vor dem Vortrag ergänzen.

## Folie 14

Technischer Umfang umgesetzt. Nicht behaupten: MSVC-Lauf, persönliche vollständige Kenntnis oder Generalprobe bereits absolviert. Grenzen: 40 Bytes je Name, 1.000 Scores, lokale Einzelinstanz, keine automatische Speicherung, kein Schutz gegen absichtliches Austauschen gültiger Stände. Weitere Funktionen sind nicht nötig, um die Aufgabenstellung technisch zu erfüllen.

Quellen: Aufgabenblatt 51, Vier Gewinnt.pdf; DW28-Projektmappe und Original-Scrum-Protokoll 12.11.2026. Umsetzung und Tests: 14.11.2026. Persönliche Erfahrungen vor dem Vortrag ergänzen.