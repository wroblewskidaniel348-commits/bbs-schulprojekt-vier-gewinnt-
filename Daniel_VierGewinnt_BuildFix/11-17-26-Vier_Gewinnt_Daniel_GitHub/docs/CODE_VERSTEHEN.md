# Code erklären, nicht nur vorlesen

## Reihenfolge zum Lernen
1. main.cpp: Ein Spiel-Objekt wird angelegt. starten() führt den Ablauf aus.
2. Spieler.h/.cpp: private Name und Symbol; public setzen() und get-Methoden. Kapselung schützt den Zustand vor beliebigem Zugriff.
3. Spielfeld.h: Das zweidimensionale Array gehört zum Objekt. Eine Zelle enthält '.' oder ein Spielzeichen.
4. Spielfeld::einwerfen(): Grenzen prüfen, von unten nach oben suchen, erste freie Zelle belegen. true bedeutet Erfolg, false bedeutet ungültige oder volle Spalte.
5. Spielfeld::gewonnen(): Jede Startzelle in vier Richtungen betrachten. Erst das vierte Zielfeld prüfen. Wenn es innerhalb des Feldes liegt, auch die vier Zeichen vergleichen.
6. Spiel::neuesSpiel() bzw. spielen(): Nur nach erfolgreichem Zug Gewinn und Remis prüfen. Erst danach den Spieler wechseln.
7. Eingabe.cpp: Die ganze Zeile lesen. Nur Ziffern akzeptieren. So wird 2abc nicht still als 2 angenommen.

## Begriffe mit Beispiel
- Arrayindex: Für Menschen heißt die erste Spalte 1, für das Array 0. Daher spalte - 1.
- Schleife: r beginnt bei reihen - 1 und wird kleiner, bis eine freie Zelle gefunden wird.
- Modulo: (0+1)%2 = 1, (1+1)%2 = 0. Bei vier Spielern folgt auf 3 wieder 0.
- const hinter einer Methode: Diese Methode verändert das Objekt nicht.
- const char*: Ein Zeiger auf Zeichen, die über diesen Zeiger nicht verändert werden sollen.
- int& ergebnis: Eine Referenz lässt zahlLesen() das Ergebnis an den Aufrufer zurückgeben; bool meldet zusätzlich, ob die Eingabe beendet wurde.
- Header: Deklariert, welche Methoden eine Klasse besitzt. Die .cpp-Datei enthält deren Umsetzung.
- Nullzeichen: '\0' markiert das Ende einer C-Zeichenkette. Es ist nicht die Ziffer '0'.

## Gewinnprüfung am Beispiel
Start r=5, s=0; waagerecht dr=0, ds=1. Die vier Zellen sind (5,0), (5,1), (5,2), (5,3). Das Ende liegt bei r+3*dr und s+3*ds. Bei ds=-1 muss zusätzlich verhindert werden, dass die Spalte negativ wird.
Das Verfahren durchsucht das ganze kleine Feld. Maximal 10*11*4*4 = 1.760 Zellvergleiche in der Endversion, vorzeitige Abbrüche nicht eingerechnet. Für ein Konsolenspiel ist das überschaubar und einfacher zu erklären als eine optimierte Lösung.

## Fragen für deine eigene Prüfung
Warum wird bei einer vollen Spalte continue ausgeführt? Warum steht der Spielerwechsel darunter? Warum zuerst Gewinn und erst dann Remis? Warum darf der Arrayzugriff nicht vor der Grenzprüfung erfolgen? Warum endet eine C-Zeichenkette mit '\0'? Was bedeutet private?

## Eigene Kommentierung ergänzen
Wähle drei Stellen. Erkläre jede ohne Vorlage, vergleiche mit dem Code und schreibe dann deinen eigenen Kommentar. Notiere einen tatsächlich beobachteten Fehler und deinen Lösungsweg. Keine erfundenen Erlebnisse eintragen.
