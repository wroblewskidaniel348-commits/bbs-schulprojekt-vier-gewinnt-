# Konsolendesign und Barrierefreiheit

Die Bedienung bleibt bewusst einfach: 0 bis 7 im Hauptmenue, Enter zum Bestaetigen, 1 bis 7/9/11 fuer eine Spielspalte und 0 zurueck ins Menue. Keine Maus oder Sondertasten erforderlich.

Das Spielfeld nutzt Zeichen mit fester Breite. X/O/A/B benennen die Spieler unabhaengig von der Farbe. Vier Gewinnsteine werden mit `[X]` usw. markiert und bei ANSI-Unterstuetzung weiss auf rot hervorgehoben. Terminalfarben sind nur eine zusaetzliche Orientierung.

Die Farbe wird in `include/KonsolenDesign.h` mit wenigen Funktionen festgelegt. Die Ausgabe nutzt `cout` und vorhandene Schleifen; es gibt keine neue Grafikbibliothek. Am besten VS Code mit dunklem Hintergrund und einer gut lesbaren Monospace-Schrift (z. B. Consolas) nutzen. Die Schriftgroesse kannst du im Terminal mit Strg und + anpassen.

Das ist eine barriereaermere Konsolenoberflaeche, keine vollstaendige Barrierefreiheitszertifizierung. Screenreader-Verhalten und Windows-Terminalfarben wurden hier nicht am Zielsystem verifiziert.
