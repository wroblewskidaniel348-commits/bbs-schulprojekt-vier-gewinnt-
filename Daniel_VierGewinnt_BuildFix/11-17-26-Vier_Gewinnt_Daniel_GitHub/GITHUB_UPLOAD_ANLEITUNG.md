# Neue Projektversion auf GitHub hochladen

Diese ZIP ist **für die Veröffentlichung des Quellprojekts** vorbereitet. Sie enthält absichtlich **keine** `VierGewinnt.exe`, `Regeltests.exe`, `data/highscore.txt` und `data/spielstand.txt`. Das Spiel kompiliert die `.exe` selbst, und persönliche Spielstände entstehen lokal. Die Beispieldateien `data/beispiel_*.txt` bleiben enthalten.

## Variante A: Mit Git und VS Code (für bestehendes Repository empfohlen)

1. Öffne deine **vorhandene lokale Kopie** des GitHub-Repositories in VS Code.
2. Kopiere den **Inhalt** dieser entpackten ZIP **in genau diesen Repository-Ordner** (nicht einen zusätzlichen verschachtelten Ordner anlegen). Vorhandene Dateien dürfen nach einer eigenen Sichtprüfung ersetzt werden.
3. Prüfe unter **Quellcodeverwaltung**, dass die Änderungen in `.vscode/tasks.json`, `.vscode/launch.json`, `README.md` und `START_HIER_VSCODE.md` auftauchen.
4. Commit-Nachricht z. B. `VS Code Build und Debug Konfiguration korrigiert` eingeben, **Commit** und **Push/Synchronisieren** wählen.

Nicht den versteckten Git-Ordner `.git` überschreiben oder löschen. Die ZIP enthält selbst **keinen** `.git`-Ordner.

## Variante B: Über github.com hochladen

1. ZIP **entpacken**, nicht einfach die ZIP als Einzeldatei ins Repository legen.
2. Dein **bestehendes Repository** auf GitHub öffnen.
3. **Add file > Upload files** auswählen, den **Inhalt** des entpackten Ordners ins Upload-Feld ziehen. Die Ordner `src`, `include`, `.vscode`, `docs`, `tests`, `data` müssen auf Root-Ebene bleiben.
4. In der Dateiübersicht prüfen, ob **`.vscode/tasks.json`** und **`.vscode/launch.json`** mit hochgeladen werden. Ansonsten diese Dateien ergänzen.
5. Änderungen als Commit speichern und den Standard-Branch wählen, sofern du dort die Version aktualisieren möchtest.

### Nach dem Hochladen prüfen

In deinem Repository sollten auf oberster Ebene stehen:

- `src/`, `include/`, `.vscode/`, `tests/`, `docs/`, `data/`
- `README.md`, `START_HIER_VSCODE.md`, `VierGewinnt.code-workspace`
- `VierGewinnt.sln` (für Visual Studio Community)

**Nicht nötig:** `VierGewinnt.exe` und persönliche Spielstände. Diese Dateien werden mit `.gitignore` ausgeblendet.

**Wichtig:** Änderungen auf GitHub allein reparieren eine bereits geöffnete lokale Kopie nicht automatisch. Daniel muss die aktualisierte Version **pullen** oder frisch **klonen/herunterladen** und den richtigen Ordner/Arbeitsbereich öffnen.
