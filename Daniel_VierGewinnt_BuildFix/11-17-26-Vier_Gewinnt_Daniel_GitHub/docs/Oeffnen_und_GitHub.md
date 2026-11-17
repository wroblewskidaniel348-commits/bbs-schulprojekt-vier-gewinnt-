> **Aktualisierung vom 17.11.2026:** Diese ursprüngliche Anleitung beschreibt Visual Studio Community und einen früheren Abgabestand. Für den aktuellen **VS-Code-Fix und erneuten GitHub-Upload** bitte die Dateien `START_HIER_VSCODE.md` und `GITHUB_UPLOAD_ANLEITUNG.md` im Projektstamm verwenden.


# Das Spiel öffnen

Visual Studio Community 2026 | keine Terminalbefehle nötig

## 1. ZIP vollständig entpacken

Rechtsklick auf die ZIP-Datei, dann „Alle extrahieren“. Den entpackten Ordner öffnen. Dateien nicht einzeln aus dem Archiv ziehen; src, include und die Projektdateien gehören zusammen.

## 2. Projektmappe öffnen

Ein Doppelklick auf VierGewinnt.sln öffnet Visual Studio. Alternativ im Startfenster „Projekt oder Projektmappe öffnen“ wählen und dieselbe Datei auswählen. main.cpp ist nur eine Quelldatei, nicht das gesamte Projekt.

## 3. Strg + F5 drücken

Visual Studio kompiliert und startet das Spiel. Falls gefragt wird, ob erstellt werden soll, bestätigen. Oben kann Debug und x64 ausgewählt bleiben. Zum Testen brauchst du keine BAT-Datei und keinen separaten Compiler.

## Nur falls C++ noch nicht installiert ist

Visual Studio Installer öffnen, bei Community 2026 „Ändern“ wählen und „Desktopentwicklung mit C++“ installieren. Danach die Projektmappe erneut öffnen. Das ist eine einmalige Einrichtung.


# Code ansehen und Fehler einordnen




Du möchtest … | So geht es
Code lesen | Ansicht > Projektmappen-Explorer; Quelldateien aufklappen
Start verstehen | src/main.cpp öffnen
Fallbewegung erklären | src/Spielfeld.cpp, Methode einwerfen()
Spielerwechsel erklären | src/Spiel.cpp öffnen
Header ansehen | Headerdateien aufklappen; .h beschreibt die Klasse
Automatische Regeln prüfen | Optional tests/Regeltests.sln öffnen und Strg + F5 drücken


## Wenn das Programm nicht startet

Die erste Meldung in der Fehlerliste ansehen. Bei fehlendem v145-Toolset oder Windows-SDK die C++-Installation über den Visual Studio Installer ergänzen. Bei einer Meldung zur alten Programmversion nicht einfach den letzten erfolgreichen Build starten.

## Dateien nicht verschieben

Die Projektmappe kennt die relativen Pfade zu src und include. Wird nur die .sln auf den Desktop kopiert, fehlen die übrigen Dateien. Immer den gesamten Projektordner zusammen aufbewahren.

## Was bereits geprüft ist

Quellcode und Regeltests wurden unter Linux geprüft; die Visual-Studio-Dateien wurden auf passende Konfiguration und vorhandene Dateien kontrolliert. Ein tatsächlicher Start unter Microsofts Compiler ist erst auf deinem Windows-Rechner möglich.


# Auf GitHub hochladen



## 1. Den richtigen Ordner wählen

Für den 19.11. nur 01_Stand_19-11-2026 verwenden. Die Endversion bleibt separat. Das Repository soll den ausgewählten Projektordner enthalten, nicht unbemerkt das gesamte Paket.

## 2. Repository erstellen

In Visual Studio „Git > Git-Repository erstellen“ öffnen. GitHub auswählen und mit Daniels Konto anmelden. Einen Namen wie vier-gewinnt-daniel verwenden und den lokalen Pfad prüfen. Gewünschte Sichtbarkeit festlegen und „Erstellen und Pushen“ wählen.

## 3. Künftige Änderungen nachvollziehbar speichern

Nach einer echten Änderung „Git-Änderungen“ öffnen, die Änderungen ansehen, eine passende Commit-Nachricht schreiben und pushen. Beispiel: „Kommentar zur diagonalen Gewinnprüfung ergänzt“. Keine erfundenen oder rückdatierten Entwicklungsschritte hinzufügen.

## Was nicht hochgeladen wird

Die mitgelieferte .gitignore schließt automatisch erzeugte Programmdateien, Benutzereinstellungen und persönliche Spielstände aus. Buchfotos, Klassenlisten und private fremde Unterlagen gehören nicht ins Repository.

## Hinweis

Es wurde kein GitHub-Repository für Daniel erstellt und nichts veröffentlicht. Diese Anleitung führt durch die spätere eigene Veröffentlichung.