# Nur die drei aeusseren VS-Code-Konfigurationsdateien werden angepasst.
# Alle C++-Quelltexte, Header, Tests, Assets und die inneren .vscode-Dateien bleiben unveraendert.
$ErrorActionPreference = 'Stop'
$projekt = '11-17-26-Vier_Gewinnt_Daniel_GitHub'
$basis = Split-Path -Parent $MyInvocation.MyCommand.Path
if (-not (Test-Path -LiteralPath (Join-Path $basis "$projekt\src\main.cpp"))) {
    throw 'Projektordner nicht gefunden. Lege das Skript direkt ins Wurzelverzeichnis des GitHub-Repositories.'
}
$pfade = @('.vscode\tasks.json', '.vscode\launch.json', '.vscode\c_cpp_properties.json')
$aenderungen = @()
foreach ($relativ in $pfade) {
    $datei = Join-Path $basis $relativ
    if (-not (Test-Path -LiteralPath $datei)) { throw "Datei fehlt: $relativ" }
    $original = [System.IO.File]::ReadAllText($datei)
    if ($relativ -like '*c_cpp_properties.json') {
        $alt = '"${workspaceFolder}/include"'
        $neu = '"${workspaceFolder}/' + $projekt + '/include"'
    } else {
        $alt = '${workspaceFolder}'
        $neu = '${workspaceFolder}\\' + $projekt
        # Wenn die Datei schon korrigiert ist, kein zweites Mal praefixieren.
        if ($original.Contains($neu)) { Write-Host "Bereits korrigiert: $relativ"; continue }
    }
    if (-not $original.Contains($alt)) {
        if ($original.Contains($neu)) { Write-Host "Bereits korrigiert: $relativ"; continue }
        throw "Erwarteter Originalpfad fehlt in $relativ. Nichts wird geschrieben."
    }
    $inhalt = $original.Replace($alt,$neu)
    $null = $inhalt | ConvertFrom-Json
    $aenderungen += @{Pfad=$datei; Inhalt=$inhalt; Relativ=$relativ}
}
# Erst nach erfolgreicher Vorpruefung aller Dateien schreiben.
$utf8 = New-Object System.Text.UTF8Encoding($false)
foreach ($eintrag in $aenderungen) {
    [System.IO.File]::WriteAllText($eintrag.Pfad, $eintrag.Inhalt, $utf8)
    Write-Host "Buildpfad korrigiert: $($eintrag.Relativ)"
}
Write-Host 'Fertig. Spiellogik und alle Dateien im Projektunterordner sind unveraendert.'
Write-Host 'In VS Code das GitHub-Repository als Ordner oeffnen, dann Strg+Umschalt+B.'
