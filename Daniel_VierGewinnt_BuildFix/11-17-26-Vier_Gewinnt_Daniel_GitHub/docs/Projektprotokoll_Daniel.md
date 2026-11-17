
# Vier Gewinnt in C++

Projektprotokoll | Daniel Wroblewski | Dr. Michael Litera

## Projektziel

Ein verständliches Konsolenspiel entwickeln und erklären. Die Spielregeln, der objektorientierte Aufbau und nachvollziehbare Tests stehen im Mittelpunkt. Die Unterlagen orientieren sich an der vorhandenen DW28-Projektmappe und der Aufgabenstellung.

## Dokumentstand

Überarbeitet am 14.11.2026. KI-Unterstützung, Quellen und tatsächlich ausgeführte Prüfungen sind ausgewiesen. Die Skizzen wurden für diese Fassung neu erstellt. Persönliche Test- und Reflexionsfelder bleiben zum Ergänzen offen.


# 01 · Orientierung und Auftrag




Seiten | Inhalt
3–5 | Recherche, Anforderungen und Ideenentscheidung
6–9 | Scribbles, Menü, Ablauf und Klassen
10–13 | Daten, Fallbewegung, Gewinnprüfung und Eingaben
14–16 | Umsetzung und Prüfungen
17–18 | Scrum, Backlog und Zeitplanung
19–21 | Visual Studio, GitHub und KI-Nutzung
22–24 | Ausblick, Reflexion und Quellen


## Lehrerauftrag

Aufgabenblatt 51 verlangt ein C++-Konsolenspiel, zunächst für zwei, später für bis zu vier Spieler. Zum Abschluss gehören Speichern/Laden, Highscore, GitHub, Präsentation, Handout und KI-Prompts. Die Gesamtbewertung gewichtet Programm 60 %, Präsentation 20 % und Handout 20 %.

## Schwerpunkt am 19.11.

Die zusätzliche Unterrichtsnotiz betont: Welche Herausforderungen gab es, wie wurden sie gelöst und was sind die nächsten Schritte? Dazu sollen Code, Entwicklung, Kommentare, Prompts und die Prüfung der Richtigkeit gezeigt werden. Der Monatsplan nennt zusätzlich den 26.11. als Meilenstein.


# 02 · Recherche und Lernmethode



## Daniels Aussage aus dem Scrum

Im Originalprotokoll vom 12.11.2026 ist bei Daniel W. festgehalten, dass er aus IT-Communitys, YouTube-Fachvideos und fertigen Protokollen lernt. Die dort genannte „Kunst der Rekonstruktion“ bedeutet, Lösungswege und Fehler nachzuvollziehen und daraus eigene Ansätze zu entwickeln.

## Was das für dieses Projekt bedeutet

Eine fremde Lösung zuerst in Schritte zerlegen: Welche Daten werden gespeichert? Wie fällt ein Stein? Wie wird der Gewinner erkannt? Anschließend prüfen, welche Idee zum Schulstoff passt. Die Umsetzung in C++ muss unabhängig von einer fremden Oberfläche erklärt werden können.

## C# ist nicht C++

Der Screenshot zeigt C#-Code und eine grafische Oberfläche. Das dient der Orientierung am Spielprinzip. C#-Oberflächencode, WPF und komplexe Entwurfsmuster werden nicht als C++-Code übernommen. Die weiteren Screenshots zeigen eine Serie mit Klassen, Tests und WPF; ihre konkreten Video-URLs sind nicht eindeutig belegt.

## Community-Quellen sauber benennen

Konkrete Beiträge aus Daniels früherer Recherche sind nicht angegeben. C++-Community und Stack Overflow werden auf Seite 24 deshalb als zusätzliche Lernangebote verlinkt, nicht als behauptete bereits benutzte Quellen. Eigene besuchte Beiträge können später mit URL und Lernpunkt ergänzt werden.


# 03 · Anforderungen und Grenzen




Funktion | Dieser Stand
Menschen und Spielfeld | 2–4 Menschen; 7×6, 9×8 und 11×10
Namen und Symbole | Eindeutige Namen, X/O/A/B
Spielzug | Unterste freie Zelle; Wechsel nur nach gültigem Zug
Spielende | Vier waagerecht, senkrecht, diagonal oder Remis
Ungültige Eingaben | Erneut fragen; Feld und Spieler nicht falsch verändern
Speichern/Laden, Highscore | Integriert; separate Dateioperationen
Darstellung | Schlichte Konsole, keine Grafikbibliothek


## Bewusste Vereinfachung

Keine 3D-Darstellung, kein Computergegner, keine Musik und kein Online-Modus. Dadurch bleiben die Pflichtfunktionen und ihre Erklärung überschaubar. Ein sichtbares Feld mit X und O genügt der Erkennbarkeit als Vier Gewinnt.

## Abgleich mit dem Buch

Arrays, Schleifen, Funktionen, Zeiger/Referenzen und Klassen gehören zu den Themen bis Kapitel 10. Dateioperationen beginnen erst in Kapitel 11. Diese Erweiterung ist für die vollständige Aufgabenstellung erforderlich und ausdrücklich als Zusatzstoff markiert.


# 04 · Ideen sammeln und auswählen




Idee | Entscheidung | Begründung
Konsole mit X/O | Umsetzen | Erkennbar, einfach und gut erklärbar
Drei einfache Klassen | Umsetzen | Daten und Aufgaben sinnvoll trennen
Fehlertexte | Umsetzen | Bedienung bleibt verständlich
Farben und Animation | Weglassen | Kein zusätzlicher Nutzen für Pflichtregeln
3–4 Spieler | Umsetzen | Explizite Abschlussanforderung
Speichern und Highscore | Umsetzen | Dateioperationen als weiterer Lernschritt
3D, Netzwerk, KI-Gegner | Außerhalb des Umfangs | Zu viel Zusatztechnik für die Aufgabe


## Vom Brainstorming zur Entscheidung

Die Auswahl folgt drei Fragen: Fordert der Lehrer die Funktion? Kann sie mit überschaubarem Code umgesetzt werden? Kann Daniel den Lösungsweg erklären und prüfen? Eine Zusatzidee wird nur übernommen, wenn sie diese Bedingungen erfüllt.

## Erfolgskriterium

Eine Funktion ist nicht allein deshalb fertig, weil Code vorhanden ist. Sie muss starten, das erwartete Ergebnis liefern und an einer konkreten Stelle im Code erläutert werden können.


# 05 · Scribble: Spielbrett und Bedienung

Neu erstellter Konzeptentwurf auf Grundlage der Aufgabenstellung

## So soll die Ausgabe wirken

Ein gleichmäßiges Raster zeigt alle Zellen. Unter dem Raster stehen die Spaltennummern. Ein Punkt ist frei, X oder O ist belegt. Die aktuelle Person und ihr Spielzeichen werden vor der Eingabe genannt. Die Skizze zeigt das Grundprinzip, nicht einen Screenshot des Programms.

## Weshalb keine Bilddateien im Spiel?

Die Konsole benötigt keine Bilder, kein spezielles Fenster und keine zusätzliche Installation. Das erleichtert die Vorführung auf dem Schulrechner. Die Grafiken gehören zur Erklärung in den Unterlagen.

## Eigene Ergänzung

Welche Beschriftung hilft beim Spielen? ______________________
Welche Information war in der Demo unklar? _________________


# 06 · Scribble: Menü und Rückmeldungen



## Fehlermeldungen

„Ungültige Eingabe“ fordert eine passende Zahl. „Spalte voll. Du bleibst dran.“ erklärt, warum derselbe Spieler erneut wählen darf. Eine Fehlermeldung soll beim Beheben helfen und nicht nur melden, dass etwas falsch ist.

## Bedeutung von 0

In der Endversion führt 0 im Spiel zum Menü und hält die Partie im Speicher. 7 setzt sie fort. 0 im Hauptmenü beendet das Programm.

## Hinweis zur Skizze

Der Menüentwurf ist neu gezeichnet. Die tatsächliche Konsolenausgabe steht separat als Demo-Nachweis bereit.


# 07 · Ablauf einer Runde



## Die Reihenfolge ist wichtig

Gewinn wird vor Remis geprüft: Auch der letzte freie Platz kann noch einen Sieg erzeugen. Erst wenn beide Prüfungen negativ sind, wird der nächste Spieler ausgewählt.


# 08 · Klassen und Zuständigkeiten




Klasse / Datei | Verantwortung
Spieler | Name und Symbol kapseln; Getter geben Werte zurück
Spielfeld | Feld leeren, Stein setzen, Gewinn und Remis prüfen
Spiel | Menü und Reihenfolge steuern; Spieler verwalten
Eingabe.cpp | Zusätzliche Funktionen zum sicheren Lesen


## Kapselung in einfachen Worten

Das Feld ist private. Die Spielsteuerung ändert es über einwerfen() und nicht durch beliebige Zugriffe von außen. Die Klassendeklaration steht in der .h-Datei, die Ausführung der Methoden in der .cpp-Datei.


# 09 · Daten und Unterrichtsstoff



```cpp

char feld[10][11];
char name[41];
int aktuell = 0;
// Ein Punkt markiert eine freie Zelle.

```


Thema | Konkrete Nutzung
Kap. 2–3: Ein-/Ausgabe | cout, cin.getline, Variablen und Kommentare
Kap. 4: Operatoren | Vergleich, logische Bedingungen, Modulo
Kap. 5–6: Ablauf / Funktionen | if, for, while; Parameter und Rückgaben
Kap. 7: Arrays / Zeichenketten | Zweidimensionales Feld, Namen als char-Array
Kap. 8: Zeiger / Referenzen | const char* und int& beim Ergebnisparameter
Kap. 10: Klassen | Konstruktor, private/public, get-Methoden


## Feste Kapazität, klarer Index

Die Zellen werden ab 0 nummeriert. Eine vom Menschen eingegebene Spalte 1 wird deshalb zu Index 0. Die Endversion reserviert 10×11 Zellen und verwendet abhängig von der Spieleranzahl nur die nötigen Reihen und Spalten.

## Zeichenketten

Die 41. Stelle im Namensarray ist für das Nullzeichen reserviert. Daher sind höchstens 40 Bytes Inhalt erlaubt. Zusätzliche Bibliothekshelfer werden erklärt; ein Inhaltsverzeichnis belegt nicht, dass jede einzelne Funktion im Unterricht vorkam.


# 10 · Herausforderung: Stein fallen lassen



## Problem

Die Spielsteine müssen unten beginnen und auf bereits vorhandenen Steinen aufliegen. Ein falscher Schleifenstart würde die Regel verletzen.

```cpp

for (int r = reihen - 1; r >= 0; r--) {
    if (feld[r][spalte] == '.') {
        feld[r][spalte] = symbol;
        return true;
    }
}
return false;

```

## Lösung

Die Suche startet bei der letzten Reihe und geht nach oben. Bei der ersten freien Zelle wird der Stein gesetzt. true bedeutet: Zug erfolgreich. Wenn keine Zelle frei ist, bleibt das Feld unverändert und die Methode meldet false.

## Nachweis

Eine Spalte mit sechs abwechselnden Steinen füllen. Der siebte Versuch muss abgewiesen werden. Der aktuelle Spieler darf erneut wählen. Im Test werden zusätzlich Spalten außerhalb des gültigen Bereichs geprüft.

## Erklären können

Warum steht reihen - 1 statt reihen? Warum wird r kleiner? Warum beendet return true die Suche sofort? Diese drei Fragen müssen anhand des Codes beantwortbar sein.


# 11 · Herausforderung: Gewinn erkennen




Richtung | dr | ds
Waagerecht | 0 | 1
Senkrecht | 1 | 0
Diagonal rechts unten | 1 | 1
Diagonal links unten | 1 | -1


```cpp

int endeR = r + 3 * dr[richtung];
int endeS = s + 3 * ds[richtung];
// Erst pruefen, ob der Endpunkt im Feld liegt.
// Dann die vier Zeichen vergleichen.

```

## Lösung

Jede Zelle wird als möglicher Beginn einer Vierergruppe geprüft. Pro Richtung werden vier Zeichen verglichen. Der Endpunkt muss innerhalb des Feldes liegen, bevor das Array gelesen wird. Eine Lücke oder ein anderes Spielzeichen verhindert einen Sieg.

## Warum diese Variante?

Die frühere DW28-Mappe beschreibt Zählen vorwärts und rückwärts vom letzten Stein. Hier wird das ganze kleine Feld geprüft. Das ist für die Feldgröße ausreichend und mit den bekannten Schleifen und Arrays gut nachvollziehbar.

## Nachweis

Horizontale und vertikale Viererreihen, beide Diagonalen und eine unterbrochene Reihe testen. Der Negativtest ist wichtig: Vier Steine mit einer Lücke dürfen nicht gewinnen.


# 12 · Herausforderung: Eingaben und Wechsel




Fall | Verhalten
abc oder 2abc | Gesamte Eingabe als ungültig behandeln
Spalte außerhalb des Feldes | Erneut fragen, Feld nicht verändern
Volle Spalte | Gleicher Spieler bleibt dran
Name leer, doppelt oder mit Rand-Leerzeichen | Neuen eindeutigen Namen verlangen
Überlange Zeile | Rest entfernen und erneut fragen
Eingabeende | Ablauf kontrolliert verlassen


```cpp

if (!feld.einwerfen(spalte - 1, symbol)) {
    continue; // Derselbe Spieler versucht erneut.
}
// Gewinn und Remis werden vorher geprueft.
aktuell = (aktuell + 1) % anzahl;

```

## Modulo verständlich erklärt

Bei zwei Spielern wird aus 0 die 1 und aus 1 wieder die 0. Der Rest einer Division durch 2 ist entweder 0 oder 1. In der Endfassung wird durch die gewählte Spieleranzahl geteilt.

## Hinweis zum Ausschnitt

Der Ausschnitt verkürzt die Darstellung. Im vollständigen Code kommt das Symbol aus spieler[aktuell].getSymbol(). Ein ungültiger Zug erreicht den Spielerwechsel nicht.


# 13 · Erweiterung: Speichern und Laden



## Zusatzstoff aus Kapitel 11

Die Dateioperationen liegen gesammelt in Dateien.cpp. Sie sind für das vollständige Aufgabenblatt erforderlich. Die bekannte Spiellogik wird dafür nicht durch ein neues Framework ersetzt.

```cpp

VG1
2 0 6 7 2
Daniel
X
Alex
O
.......
.......
.......
.......
.......
XO.....
0 1

```

## Was gespeichert wird

Version, Spieleranzahl, aktueller Index, Reihen, Spalten und Zugzahl; anschließend Namen, Symbole, Feld und Zugliste. Die letzte Zeile enthält 0-basierte Spalten. Die Zugliste erlaubt, den Zustand beim Laden nachzuspielen.

## Laden ohne Verlust des bisherigen Spiels

Werte zuerst in eine lokale Kopie einlesen und prüfen. Züge auf einem leeren Feld nachspielen und die Zellen vergleichen. Ungültige Daten oder bereits beendete Partien ablehnen. Erst danach wird die Kopie übernommen.


# 14 · Erweiterung: Highscore und Dateien



## Highscore

Für jeden Namen wird eine Siegzahl gespeichert. Nach einem Sieg erhöht sich genau ein Eintrag. Ein einfaches Auswahlsort ordnet nach Siegen absteigend; bei Gleichstand entscheidet der byteweise Namensvergleich. Das ist keine vollständige deutsche Wörterbuchsortierung.


Schutz | Wirkung
Laufende Partien speichern | Kein erneuter Highscore durch Fortsetzen einer abgeschlossenen Partie
Dateiversion und Werte prüfen | Unpassende oder beschädigte Daten ablehnen
Temporäre Datei und Rückfallkopie | Normale Schreib-/Umbenennungsfehler melden und alte Daten möglichst erhalten
Grenzen festlegen | 1.000 Namen, 40 Bytes je Name, maximal 1.000.000.000 Siege


## Bekannte Grenzen

Die Anwendung ist lokal für eine Instanz gedacht. Kein Schutz gegen absichtliches Austauschen gültiger Spielstände; keine vollständige Absicherung bei Stromausfall. Ein Sieg kann bei Schreibfehlern ungespeichert bleiben. Vor dem Beenden selbst speichern.

## Kommentare und Erklärung

Dateien.cpp erläutert, warum erst eine Kopie geprüft wird und wofür die Zugliste nötig ist. Die Highscore-Datensätze nutzen eine einfache Struktur. Die Sortierung knüpft an das Array-Kapitel an.


# 15 · Testfälle und Nachweise




Test | Erwartung / Ergebnis
Horizontal, vertikal, beide Diagonalen | Sieg erkannt; direkte Regeltests bestanden
Reihe mit Lücke | Kein falscher Sieg; bestanden
Volle Spalte / ungültiger Index | Zug abgelehnt; bestanden
Volles Feld ohne Sieger | Remis erkannt; direkter Feldtest bestanden
Namen und Eingaben | Leere/doppelte Namen, Text und lange Eingaben behandelt
Compilerprüfung | Linux: g++ 14.2.0, Warnungen als Fehler, bestanden
Visual-Studio-Dateien | XML und Dateiverweise geprüft; Windows-Lauf noch offen


## Reproduzierbar in Visual Studio

Optional tests/Regeltests.sln öffnen und Strg + F5 drücken. Die Tests verwenden assert: Ist eine Erwartung falsch, bricht der Test ab. Diese Testprojektmappe ist getrennt vom eigentlichen Spiel, damit es keine zweite main()-Funktion im Spielprojekt gibt.

## Grenzen des Nachweises

Kein tatsächlicher MSVC-Lauf in dieser Umgebung. Regeltests zusätzlich mit ASan/UBSan geprüft, Leak-Prüfung wegen der Umgebung ausgeschaltet. Für die Endversion wurden auch Dateirundläufe für 2/3/4 Spieler, beschädigte Dateien und Highscore geprüft.


# 16 · Scrum und dokumentierter Ausgangspunkt



## Beleg vom 12.11.2026

Das gelieferte Scrum-Protokoll nennt Daniel Wroblewski als Protokollführer und Dr. Michael Litera als Aufsicht. Bei Daniel W. wird das Lernen aus IT-Communitys, YouTube-Fachvideos und fertigen Protokollen beschrieben. Fehlende Angaben zu Dauer oder vollständiger Anwesenheit werden hier nicht ergänzt.

## Aussage in eigenen Worten, als Formulierungsvorschlag

„Ich schaue mir an, wie andere ein Problem aufbauen und lösen. Dabei möchte ich nicht einfach Code kopieren. Ich versuche die Schritte und Fehler zu verstehen und auf meine eigene C++-Lösung zu übertragen.“ Diese Formulierung fasst den belegten Ansatz zusammen und ist kein wörtliches Sitzungszitat.


Lehrerhinweis | Konsequenz für das Projekt
Spiel muss erkennbar sein | Schlichte Konsole reicht; Pflichtfunktionen zuerst
Meilensteine sind verbindlich | Konkrete Zwischenstände mit Nachweisen vorbereiten
Übernommener Code muss verstanden werden | Wichtige Methoden erklären und sinnvoll kommentieren
Austausch ist erwünscht | Fragen gezielt stellen und erhaltene Hilfe dokumentieren


## Eigenes nächstes Daily

Datum: __________  Seit dem letzten Termin erledigt: __________
Nächste Aufgabe: ________________________________________
Hindernis / benötigte Hilfe: ________________________________


# 17 · Backlog und Zeitplan




Termin | Ziel laut Auftrag
19.11.2026 | Praktischer Zwischenvortrag laut Zusatznotiz
26.11.2026 | Zwei-Spieler-Grundversion laut Monatsplan
17.12.2026 | Stabile Regeln und Tests
28.01.2027 | 2–4 Spieler, Speicherung und Highscore
11.02.2027 | Generalprobe
18.02.2027 | Abschlussvorführung, etwa 30 Minuten



Aufgabe | Status dieser Fassung
Zwei-Spieler-Regeln und Fehlerbehandlung | Technisch umgesetzt und unter Linux geprüft
Visual-Studio-Projektmappe | Vorbereitet; lokal öffnen und prüfen
3–4 Spieler, Speicherung, Highscore | Umgesetzt und gezielt geprüft
Persönliche Erklärung und GitHub | Noch individuell durchzuführen


## Definition of Done

Eine Aufgabe ist abgeschlossen, wenn sie kompiliert, einen passenden Test besteht, kommentiert ist und erklärt werden kann. Der tatsächliche Commit und das persönliche Review werden nach der eigenen Arbeit ergänzt.


# 18 · Visual Studio: öffnen und starten



## 1. Alles entpacken

Die ZIP im Explorer mit Rechtsklick und „Alle extrahieren“ entpacken. Einzelne Dateien nicht direkt aus der ZIP starten. Die Unterordner müssen zusammenbleiben.

## 2. Richtige Datei öffnen

VierGewinnt.sln doppelt anklicken. Sie öffnet die vorbereitete Projektmappe in Visual Studio Community 2026. Nicht nur main.cpp öffnen und kein neues leeres Projekt anlegen.

## 3. Kompilieren und spielen

Strg + F5 drücken. Visual Studio übersetzt die C++-Dateien, verbindet sie und startet das Konsolenprogramm. Dafür sind keine BAT-Datei, kein Bash und keine Terminalbefehle nötig.

## Wenn C++ noch fehlt

Im Visual Studio Installer auf „Ändern“ gehen und „Desktopentwicklung mit C++“ installieren. Die Projektmappe verwendet v145 und das installierte Windows-SDK. Danach erneut öffnen.

## Code ansehen

Im Projektmappen-Explorer „Quelldateien“ und „Headerdateien“ aufklappen. main.cpp startet das Spiel. Spielfeld.cpp enthält die Spielregeln. Spiel.cpp führt durch die Partie. Ein Doppelklick öffnet die jeweilige Datei.

## Technische Einordnung

Die Projektdatei enthält bereits Headerpfad, Konsolenmodus, C++14 und Arbeitsverzeichnis. Der Anwendungscode verwendet überwiegend Grundlagen. C++14 ist die gewählte MSVC-Einstellung, kein Auftrag zur Nutzung zusätzlicher Sprachfeatures.


# 19 · GitHub ohne Terminal



## Vor dem Hochladen

Zuerst die gewünschte Fassung lokal öffnen und starten. Für den Zwischenstand nur dessen Ordner wählen. Den übergeordneten Gesamtordner mit der Endversion nicht versehentlich veröffentlichen.

## Repository erstellen

In Visual Studio „Git > Git-Repository erstellen“ öffnen. GitHub auswählen, mit Daniels eigenem Konto anmelden, einen Namen wie vier-gewinnt-daniel eingeben und den lokalen Projektordner prüfen. Dann die gewünschte Sichtbarkeit wählen und „Erstellen und Pushen“ verwenden. Es wird hier nichts automatisch hochgeladen.

## Eigene Änderungen festhalten

Nach einer tatsächlichen Änderung im Fenster „Git-Änderungen“ die Dateien prüfen, eine kurze Nachricht schreiben, committen und pushen. Gute Beispiele sind „Erklärung zum Spielerwechsel ergänzt“ oder „Test für volle Spalte hinzugefügt“. Das sind Vorschläge für künftige Arbeit, keine behaupteten bisherigen Commits.

## Was die .gitignore erledigt

Visual-Studio-Zwischendateien, bin/obj, lokale Benutzeroptionen und persönliche Spielstände werden ausgeschlossen. Quellcode, Projektmappe, Tests und die benötigte Dokumentation bleiben im Repository.

## Später zur Endversion wechseln

Die Endversion separat ausprobieren. Erst zum passenden Zeitpunkt den Stand bewusst in das Repository übernehmen und die tatsächlichen Änderungen dokumentieren. Ein ZIP-Paket ersetzt keine echte Entwicklungshistorie.


# 20 · KI-Nutzung und Promptprotokoll



## Tatsächliche Anweisung, wörtlicher Auszug

„Der Lehrer will die Prompt sehen!“
„Wie stelle ich sicher ob es richtig ist“
„Kommentare müssen drinnen sein“

## Tatsächliche Korrektur, wörtlicher Auszug

„Mach es dann in Ordnung, damit ich es auf GitHub hochladen kann.“
„Mach einfach Ding, dass du es einfach ganz normal mit Visual Studio Community kompilieren kannst.“

## Was die KI beigetragen hat

Quellcode und Kommentare, Testfälle, Projektdateien für Visual Studio, Skizzen, Folien und Dokumentation wurden KI-unterstützt erstellt oder überarbeitet. Der Code wurde kompiliert und gezielt geprüft. Die Quellen wurden auf den tatsächlichen Projektumfang bezogen.

## Was Daniel selbst bestätigen muss

Verstandene Methoden, eigene Änderungen, tatsächlich besuchte Quellen und der Start auf dem eigenen Rechner. Die KI kann diese persönlichen Schritte nicht für ihn bestätigen. Sinnvolle Ergänzungen sind ein eigener Kommentar, ein dokumentierter Test und eine konkrete Erklärung.

## Weiterführen

docs/KI_Protokoll.md enthält die Prompt-Auszüge und eine Vorlage für weitere Einsätze: Datum, genauer Prompt, Vorschlag, eigene Prüfung, übernommen/geändert/verworfen. Der vollständige ursprüngliche Auftrag liegt separat im Gesamtpaket, da er beide Fassungen betrifft.


# 21 · Nächste Schritte und Vorführung



## Zuerst: eigener Start und Verständnis

Visual Studio öffnen, Strg + F5, die kurze Demo durchführen. Danach die Fallbewegung, eine diagonale Prüfung und den Spielerwechsel ohne Vorlage erklären. Die eigenen Ergebnisse im Protokoll ergänzen.

## Abschlussdemo

Eine Zwei-Spieler-Partie zeigen, anschließend einen Stand kurz vor einem Sieg laden und den Highscore prüfen. Auf vier Spieler umstellen, das 11×10-Feld erklären, einen Zwischenstand speichern und nach erneutem Programmstart laden.

## Beispielstände

data/beispiel_vor_sieg.txt oder data/beispiel_4_spieler.txt nach data/spielstand.txt kopieren; eigenen Stand vorher sichern. Im Menü 5 laden und 7 fortsetzen. Die Beispiele sind künstlich vorbereitete Demostände.

## Abschlussvortrag

Etwa 30 Minuten laut Aufgabenblatt: Ziel und Regeln, Klassen, Live-Demo, ausgewählte Codeabschnitte, Tests, GitHub, KI-Nutzung und Reflexion. Die tatsächliche Generalprobe für den 11.02.2027 vormerken, nicht als bereits erfolgt ausgeben.


# 22 · Reflexion und eigenes Review



## Was an der Lösung überschaubar ist

Menü, Namensverwaltung und leeres Feld nutzen bekannte Ein-/Ausgaben und Schleifen. Der Spielerwechsel lässt sich mit einer kurzen Restwertrechnung erklären. Das ist eine fachliche Einschätzung, noch keine persönliche Erfolgsgeschichte.

## Was besondere Aufmerksamkeit braucht

Diagonale Feldgrenzen, falsche Eingaben und die Reihenfolge von Zug, Gewinn, Remis und Spielerwechsel. Beim Laden kommen gültige Zustände und der Schutz der bisherigen Partie hinzu.

## Persönlich ergänzen

Das fiel mir leicht: _______________________________________
_______________________________________________________
Hier musste ich genauer nachdenken: _______________________
_______________________________________________________
Diese Hilfe oder Quelle habe ich wirklich verwendet: __________
_______________________________________________________
So habe ich die Lösung selbst geprüft: ______________________
_______________________________________________________
Meine nächste konkrete Verbesserung: ______________________
_______________________________________________________

## Review statt Selbsteinschätzung ohne Beleg

Einen konkreten Test, eine Codezeile oder eine Änderung nennen. Eine Aussage wie „Ich kann erklären, weshalb continue den Spielerwechsel überspringt“ ist überprüfbarer als „Ich habe alles verstanden“.


# 23 · Quellen und Abschlusscheck




Abnahme | Stand
Code und automatische Regeltests | Geprüft; Grenzen auf Seite 16
Projektmappe, Quellen, Prompts, Unterlagen | Vorbereitet
Start unter Visual Studio / eigene Erklärung | Von Daniel persönlich zu ergänzen
Echte GitHub-Commits und Generalprobe | Noch selbst durchzuführen
