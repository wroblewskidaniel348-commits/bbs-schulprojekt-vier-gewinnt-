# Testnachweis des Zwischenstands
Durchgeführt am 14.11.2026 unter Linux mit g++ (Versionsangabe im Paket-Prüfbericht). Übersetzung mit -std=c++11 -Wall -Wextra -Wpedantic; Regeltests zusätzlich -Werror und ASan/UBSan. LeakSanitizer deaktiviert, weil die Ausführungsumgebung ihn nicht unterstützt.

Bestanden: Feldgröße 6×7; ungültige Feldindizes; sechs Steine und volle Spalte; horizontaler Sieg; vertikaler Sieg am rechten Rand; beide Diagonalen; Lücke verhindert falschen Sieg; volles Feld ohne Sieger; leere Namen, reine Leerzeichen und Rand-Leerzeichen; Spieler-Symbol; falsche Menü-/Spaltenwerte; Text statt Zahl; doppelte Namen; überlange Eingabe; Eingabeende (EOF).

Interaktive Stichprobe: 1,2,1,2,1,2,1 führt zu einem Sieg von Daniel. Ein ungültiger Zug wechselt den Spieler nicht. Vollständige Konsolenausgabe siehe Demo_Konsolenausgabe.txt.

Grenzen: Der direkte Remistest konstruiert das volle Feld über die Board-Schnittstelle. Eine vollständige manuelle Remispartie unter Windows wurde nicht durchgeführt. Ein bestandener Test deckt genau seinen Fall ab, nicht alle denkbaren Zustände.

Eigene Abnahme: Datum ___; Windows-/Compiler-Version ___; Programmstart ___; eigener Test ___; beobachtetes Ergebnis ___; Prüfer ___.

Zusätzlich geprüft: Dimensionen bei 3 und 4 Spielern; Speichern/Laden für alle Spielerzahlen mit bytegleichem Roundtrip; fehlerhafte Version, Maße, Feldinhalt, Zugliste, abgeschnittene Datei und unerwartete Zusatzdaten; fehlende Datei; Sieg zählt einmal; Highscore über Neustart; Sortierung; beschädigte Highscore-Datei unverändert. Details: Testergebnisse.json im Gesamtpaket.

Visual-Studio-Projektmappe ergänzt: Toolset v145, Konsolenanwendung, Debug/Release x64, Headerpfad und Arbeitsverzeichnis. Dateiverweise per XML geprüft. MSVC noch lokal abnehmen.
