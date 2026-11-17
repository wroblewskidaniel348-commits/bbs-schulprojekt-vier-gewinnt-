# Rote Gewinnsteine in VS Code und Visual Studio

Sobald vier gleiche Steine in einer Linie liegen, werden genau diese vier Zeichen **rot und fett** angezeigt. Das funktioniert waagerecht, senkrecht und in beiden Diagonalrichtungen.

Die Funktion `Spielfeld::gewinnPositionen()` liefert die vier Koordinaten. `Spielfeld::anzeigen(gewinnerSymbol)` faerbt diese Positionen mit ANSI-Farbcodes. Unter Windows wird dafuer der Virtual-Terminal-Modus der Konsole aktiviert. Bei Konsolen ohne Farbunterstuetzung werden die Zeichen unveraendert ausgegeben.

**VS Code:** Den Ordner `02_Endversion` oeffnen. Mit `Strg+Shift+B` das Programm neu bauen, anschliessend mit `F5` starten. Die rote Markierung erscheint nach dem Gewinn, nicht waehrend der laufenden Partie.

**Visual Studio Community:** `VierGewinnt.sln` oeffnen, Projekt neu erstellen und `Strg+F5` starten. Die Ausgabe-Konsole muss ANSI-Sequenzen unterstuetzen.

## Verbesserte Markierung der vier Gewinnzeichen

Jetzt werden die **vier tatsaechlichen Gewinnzeichen einzeln** mit rotem Hintergrund und heller Schrift hervorgehoben. Jedes Gewinnzeichen steht zusaetzlich in eckigen Klammern (`[X]`, `[O]`, `[A]` oder `[B]`). Die Klammern erhalten die Spaltenbreite und machen den Sieg auch in Terminals ohne Farbdarstellung sichtbar. Andere Spielsteine werden nicht markiert.
