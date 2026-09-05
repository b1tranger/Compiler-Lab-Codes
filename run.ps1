<#
.SYNOPSIS
    Compiles and runs C/C++ files for the Compiler Lab workspace.

.DESCRIPTION
    Automates compilation using g++ (C++20) or gcc (C17) and executes the resulting
    binary directly in your interactive terminal.
    If no file is passed, it automatically picks the most recently modified .cpp or .c file.

.EXAMPLE
    .\run.ps1 Lab_Codes\2.1.cpp
    .\run.ps1 doc\Assignments\A1\A1.1_xor.cpp
    .\run.ps1
#>

param(
    [Parameter(Position=0, Mandatory=$false)]
    [string]$FilePath
)

if (-not $FilePath) {
    # Find the most recently modified .cpp or .c file in workspace (excluding git/vscode)
    $latest = Get-ChildItem -Recurse -Include *.cpp, *.c |
        Where-Object { $_.FullName -notmatch '\\(\.vscode|\.git|Courtesy|backup)\\' } |
        Sort-Object LastWriteTime -Descending |
        Select-Object -First 1

    if (-not $latest) {
        Write-Error "No C/C++ file specified and none found in workspace."
        exit 1
    }
    $FilePath = $latest.FullName
    Write-Host "[Runner] Auto-detected latest file: $FilePath" -ForegroundColor Cyan
}

if (-not (Test-Path $FilePath)) {
    Write-Error "File not found: $FilePath"
    exit 1
}

$fileItem = Get-Item $FilePath
$dir = $fileItem.DirectoryName
$nameNoExt = [System.IO.Path]::GetFileNameWithoutExtension($fileItem.Name)
$exePath = Join-Path $dir "$nameNoExt.exe"

$ext = $fileItem.Extension.ToLower()

if ($ext -eq ".cpp") {
    $compiler = "g++"
    $flags = @("-Wall", "-Wextra", "-std=c++20", $fileItem.FullName, "-o", $exePath)
} elseif ($ext -eq ".c") {
    $compiler = "gcc"
    $flags = @("-Wall", "-Wextra", "-std=c17", $fileItem.FullName, "-o", $exePath)
} else {
    Write-Error "Unsupported file type '$ext'. Please provide a .cpp or .c file."
    exit 1
}

Write-Host "[Runner] Compiling $($fileItem.Name) with $compiler..." -ForegroundColor Yellow
$process = Start-Process -FilePath $compiler -ArgumentList $flags -NoNewWindow -Wait -PassThru

if ($process.ExitCode -ne 0) {
    Write-Host "[Runner] Compilation failed with exit code $($process.ExitCode)." -ForegroundColor Red
    exit $process.ExitCode
}

Write-Host "[Runner] Compilation succeeded. Running $nameNoExt.exe:`n" -ForegroundColor Green
Write-Host "------------------------------------------------------------" -ForegroundColor DarkGray

& $exePath

$runCode = $LASTEXITCODE
Write-Host "`n------------------------------------------------------------" -ForegroundColor DarkGray
Write-Host "[Runner] Process exited with code $runCode." -ForegroundColor Cyan
