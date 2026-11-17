# Uebersichtliche Konsolenansicht (Daniel)

## Was wurde geaendert?

- Vor jedem Spielzug wird die vorherige Ausgabe geloescht. Das Spielfeld steht immer an derselben Stelle.
- Vor dem Hauptmenue wird ebenfalls die vorherige Anzeige geloescht.
- Beim Sieg wird das letzte Brett mit vier markierten Steinen angezeigt. Die Anzeige bleibt bis Enter stehen.
- Auch Highscore, Speichern und Laden bleiben bis Enter lesbar.
- Volle Spalten erzeugen einen Hinweis in der naechsten Brettansicht.
- Bei umgeleiteter Ausgabe (z. B. automatisierten Tests) wird nichts geloescht.

## Code einfach erklaert

`bildschirmLeeren()` in `include/KonsolenDesign.h` loescht das alte Bild. Die Zeichenfolge `\033[2J\033[H` ist eine ANSI-Steuerung fuer das Terminal. `aufEnterWarten()` liest eine leere Bestaetigung ein. Beide Funktionen sind kommentiert. Der Spieleablauf in `src/Spiel.cpp` ruft sie an den passenden Stellen auf.

## Bedienung

1. Ordner in VS Code oeffnen, mit F5 starten.
2. Neues Spiel mit 1 starten. Spalte eingeben und Enter druecken.
3. Nach jedem Zug wird das aktuelle Brett neu gezeigt. Mit 0 geht es zum Menue.
4. Nach Sieg oder Highscore Enter druecken, um zum Menue zurueckzukehren.

Eine interaktive Terminalkonsole wird empfohlen. Im Ausgabefenster ohne Terminal-Unterstuetzung wird die Ausgabe nicht geloescht.

## Fehlerbehebung fuer VS Code unter Windows

Wenn sich das Menue trotzdem verlaengert, ist moeglicherweise noch eine alte `VierGewinnt.exe` gestartet. In VS Code den richtigen Projektordner oeffnen und **F5** druecken. Das integrierte **Terminal** verwenden, nicht das Fenster **Debug-Konsole**. Die neue Funktion gibt bei Windows-Pseudoterminals die ANSI-Loeschsequenz direkt aus.
