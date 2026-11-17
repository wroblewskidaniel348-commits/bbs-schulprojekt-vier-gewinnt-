# START HIER: Vier Gewinnt in VS Code

**Wichtig:** Öffne immer den kompletten Projektordner, nicht `main.cpp` oder eine `.txt`-Datei einzeln.

## In 5 Schritten

1. Diese ZIP **vollständig entpacken**. Danach liegen direkt `src/`, `include/`, `.vscode/` und `VierGewinnt.code-workspace` im selben Ordner.
2. In **Visual Studio Code**: **Datei > Arbeitsbereich aus Datei öffnen...** und `VierGewinnt.code-workspace` wählen. Alternativ **Datei > Ordner öffnen...** und den Ordner mit `src`, `include` und `.vscode` auswählen.
3. Die Microsoft-Erweiterung **C/C++** installieren (falls noch nicht vorhanden).
4. **Strg + Umschalt + B** drücken. Die Standardaufgabe `C++ Build (Vier Gewinnt)` kompiliert **alle sechs `.cpp`-Dateien**.
5. **F5** drücken und `Vier Gewinnt debuggen (GDB)` auswählen. Alternativ **Terminal > Aufgabe ausführen > Vier Gewinnt spielen (Build + Start)**.

## Voraussetzungen (Windows)

- [MSYS2](https://www.msys2.org/) im Standardordner `C:\msys64`.
- In **MSYS2 UCRT64** die GCC-/GDB-Toolchain installieren:
  `pacman -Syu` (gegebenenfalls Terminal schließen/neu öffnen und Befehl erneut ausführen), danach
  `pacman -S --needed mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-gdb`.
- Die Dateien `C:\msys64\ucrt64\bin\g++.exe` und `C:\msys64\ucrt64\bin\gdb.exe` müssen tatsächlich existieren.
- Wenn MSYS2 woanders installiert ist, Pfade in `.vscode/tasks.json`, `.vscode/launch.json`, `.vscode/c_cpp_properties.json` und gegebenenfalls `.vscode/settings.json` anpassen.

## Die Fehlermeldung aus dem Screenshot

`KI_Originalauftrag.txt:1: syntax error` bedeutet: VS Code hat eine **Textdatei** als C++-Quellcode behandelt.
`preLaunchTask 'build' terminated with exit code 1` bedeutet: Eine **fremde/alte Build-Aufgabe** wurde verwendet.
`launch: program ... does not exist` ist ein **Folgefehler**: Es entstand keine ausführbare Datei.

Die Projekteinstellungen verwenden deshalb **feste Dateipfade** nach `src/`; die aktuell geöffnete `.txt`-Datei spielt für den Build keine Rolle mehr.

### Falls weiterhin `preLaunchTask 'build'` erscheint

- VS Code komplett schließen und **diesen Arbeitsbereich** `VierGewinnt.code-workspace` öffnen.
- In **Ausführen und Debuggen** ausdrücklich `Vier Gewinnt debuggen (GDB)` auswählen. Diese Konfiguration ruft `C++ Build (Vier Gewinnt)` auf, **nicht** `build`.
- Unter `.vscode` müssen die mitgelieferten `tasks.json` und `launch.json` sichtbar sein.
- Prüfen, ob in den **persönlichen VS-Code-Einstellungen** (JSON) ältere Einträge namens `"tasks"` und `"launch"` stecken. Diese nicht für dieses Projekt verwenden; Projektkonfigurationen gehören in `.vscode/tasks.json` und `.vscode/launch.json`.
- Nicht **Debug Anyway** wählen und nicht **Run Code** von Code Runner für eine `.txt`-Datei klicken.

## Andere Wege und Tests

- **Regeltests:** `Terminal > Aufgabe ausführen > Regeltests ausfuehren (Build + Test)`.
- **Visual Studio Community:** `VierGewinnt.sln` öffnen und mit **Strg + F5** starten; dafür wird die C++-Desktopentwicklung benötigt. Das ist ein anderes Programm als Visual Studio Code.
- **GitHub:** `GITHUB_UPLOAD_ANLEITUNG.md` lesen.

**Prüfgrenze:** Das Projekt wurde mit Linux-GCC gebaut und getestet; ein tatsächlicher Lauf mit MSYS2 und VS Code auf Windows muss am Zielrechner bestätigt werden.
