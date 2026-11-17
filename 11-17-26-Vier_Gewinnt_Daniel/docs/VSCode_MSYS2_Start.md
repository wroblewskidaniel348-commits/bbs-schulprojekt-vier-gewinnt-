# Vier Gewinnt in VS Code mit MSYS2 UCRT64

1. MSYS2 unter https://www.msys2.org installieren (Standardordner `C:\msys64`).
2. In **MSYS2 UCRT64** ausführen: `pacman -Syu` und anschließend `pacman -S --needed mingw-w64-ucrt-x86_64-toolchain`.
3. VS Code mit den Microsoft-Erweiterungen **C/C++** öffnen.
4. In VS Code **Datei > Ordner öffnen** und **02_Endversion** wählen (den Ordner mit `src`, `include` und `.vscode`). Nicht nur `main.cpp` öffnen.
5. Mit **Strg + Umschalt + B** das ganze Spiel kompilieren. Start mit **F5** (Debugging) oder im Terminal mit `./VierGewinnt.exe` (PowerShell: `.\VierGewinnt.exe`).
6. Zum Testen: **Terminal > Aufgabe ausführen > C++ Build (Regeltests)**. Danach `Regeltests.exe` starten oder die zweite Debug-Konfiguration auswählen.

Wichtig: Es werden alle sechs Quelldateien aus `src/` zusammengebaut. Der Arbeitsordner ist absichtlich die Projektwurzel, damit `data/` für Spielstände gefunden wird. `launch.json` und `tasks.json` gehören in `.vscode/`, nicht in `settings.json`. Für den MSYS2-GCC-Compiler ist `MIMode: gdb` korrekt.

Diese Einstellungen gelten für Windows mit **MSYS2 UCRT64 im Standardpfad**. Die vorhandene Visual-Studio-Community-Projektmappe bleibt unverändert nutzbar. Ein echter Windows-Test ist weiterhin am eigenen Rechner erforderlich.
