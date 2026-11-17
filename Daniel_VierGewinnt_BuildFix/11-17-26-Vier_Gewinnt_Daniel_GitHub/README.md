# Vier Gewinnt | Daniel Wroblewski

Endversion: zwei bis vier menschliche Spieler, Speichern/Laden und Highscore.
Programmiertechnik bei Dr. Michael Litera. Schlichtes C++-Konsolenspiel nach Aufgabenblatt 51.

## Schnellstart mit VS Code (Windows + MSYS2)

**Für diese GitHub-Version zuerst [`START_HIER_VSCODE.md`](START_HIER_VSCODE.md) lesen.**
Die passende Arbeitsbereichsdatei heißt `VierGewinnt.code-workspace`.
Mit **Strg + Umschalt + B** wird das gesamte Programm gebaut; mit **F5** wird `Vier Gewinnt debuggen (GDB)` gestartet.
`docs/KI_Originalauftrag.txt` ist nur Dokumentation und darf nicht als C++-Programm kompiliert werden.
Für den erneuten Upload siehe [`GITHUB_UPLOAD_ANLEITUNG.md`](GITHUB_UPLOAD_ANLEITUNG.md).

## Öffnen und starten (Visual Studio Community 2026, alternativ)
1. Gesamten Ordner entpacken und `VierGewinnt.sln` mit Visual Studio Community öffnen. Es ist nicht dasselbe Programm wie VS Code.
2. **VierGewinnt.sln** mit **Visual Studio Community 2026** öffnen.
3. **Strg + F5** drücken.

Voraussetzung: Im Visual Studio Installer ist **Desktopentwicklung mit C++** installiert. Das Projekt verwendet das VS-2026-Toolset v145 und das installierte Windows-SDK. Keine externen Bibliotheken, kein Bash, keine BAT-Dateien, keine Schriftinstallation.

## Dateien
- `VierGewinnt.sln`: diese Datei öffnen.
- `VierGewinnt.vcxproj` und `.filters`: Projekteinstellungen; nicht manuell bearbeiten.
- `src/`: C++-Programmcode.
- `include/`: Klassendeklarationen.
- `docs/`: Protokoll, Quellen, KI-Nutzung und Anleitungen.
- `tests/Regeltests.sln`: freiwillige separate Projektmappe für die Regeltests; genauso mit Strg + F5 starten.
- `data/`: lokale Spielstände und Demo-Dateien.

## Bedienung
Menü 1: neues Spiel; 2: Spieleranzahl; 3: Namen; 4: speichern; 5: laden; 6: Highscore; 7: fortsetzen; 0: beenden. Im Spiel führt 0 ins Menü, die Partie bleibt erhalten. Vor dem Beenden bei Bedarf speichern.

Das Konsolenmenü ist in `src/Spiel.cpp` gestaltet: blaue Überschrift, einfache Textgruppen und rote Beenden-Option. Es benötigt keine Grafikbibliothek oder komplizierte ASCII-Bilder. Falls Terminalfarben nicht unterstützt werden, bleibt das Menü als normaler Text lesbar. Die vier Gewinnsteine werden beim Sieg weiterhin rot und mit `[X]` bzw. `[O]` markiert.

## Schulstoff
Klassen, einfache Funktionen, feste Arrays, Schleifen, Bedingungen und Zeichenketten. Keine Grafikbibliothek, Templates, Vererbung oder komplexen Entwurfsmuster im Anwendungscode. Dateien.cpp verwendet zusätzlich Dateioperationen aus Kapitel 11, da das vollständige Aufgabenblatt diese fordert.

## Herkunft und Nachweise
KI-unterstützte Umsetzung und Überarbeitung, Stand 14.11.2026. Daniels Aussage zum Lernen aus YouTube, IT-Communitys und vorhandenen Lösungen wird in der Dokumentation aufgegriffen. Fremde Quellen, automatisch geprüfte Funktionen und persönliche Beiträge werden getrennt ausgewiesen. Kommentare in Ich-Form sind Formulierungshilfen, die Daniel selbst nachvollziehen soll.

Die sechs C++-Quelldateien und die Regeltests wurden am 17.11.2026 mit Linux-GCC 14.2 erneut erfolgreich gebaut und geprüft. Die Visual-Studio-Projektdateien wurden strukturell geprüft; ein tatsächlicher MSVC-/Windows-Lauf war hier nicht möglich. Den Start am eigenen Rechner einmal durchführen und dokumentieren. PowerPoint verwendet die Standardschrift Arial; keine zusätzlichen Schriften installieren.

## GitHub
In Visual Studio **Git > Git-Repository erstellen**, GitHub auswählen und als lokalen Pfad **diesen Ordner** verwenden. Eine .gitignore ist vorbereitet. Danach eigene Änderungen über Git-Änderungen committen und pushen. Es wurde hier nichts veröffentlicht. Für den **aktuellen** GitHub-Upload siehe `GITHUB_UPLOAD_ANLEITUNG.md`. Die bestehende PDF beschreibt teilweise einen früheren Abgabeprozess.

## Grenzen
Namen bis 40 Bytes, keine Rand-Leerzeichen; Groß-/Kleinschreibung ist relevant. Maximal 1.000 Highscore-Namen. Dateispeicherung ist für eine lokale Instanz gedacht, nicht für parallele Zugriffe oder Manipulationsschutz. Automatische Speicherung beim Beenden gibt es nicht.

## Visual Studio Code + MSYS2
Fuer VS Code liegen Konfigurationen unter `.vscode/` bereit. Siehe `docs/VSCode_MSYS2_Start.md`.

## Neue Konsolengestaltung
Klares Hauptmenue, gut sichtbare Spaltennummern, Symbolfarben und vier rot markierte Gewinnsteine. Details: `docs/Konsolendesign_und_Barrierefreiheit.md`.
