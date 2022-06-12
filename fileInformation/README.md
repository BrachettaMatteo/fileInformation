# fileInformation
Sistema opartivo: Linux/Unix
## CMake (execute file)
Digitare i comandi sotto elencati per eseguire il progetto:

*Preparazione*[Posizione di partenza `./So2022`]
``` bash
cd fileInformation/
mkdir build
cd build
cmake ..
cmake --build .
```
*Esecuzione* [Posizione attuale `./So2022/fileInformation/build`]
``` bash
./fileInformation  [option]... [filepath]...
```
## Command Line Option
``` bash
./fileInformation [option]... [filepath]...
```
- `-c` restituisce il numero di caratteri;
- `-o` restituisce il nome del proprietario;
- `-d` restituisce la data dell'ultima modifica;
- `-l` restituisce il numero di righe;
- `-s` restituisce la dimensione del file;
- `-p` restituisce i permessi del file;
- `-r` crea un report con tutti i dettagli  su un nuovo file chiamato report.txt
## Esempio di report
nome del file: `report.txt`
```
!--REPORT--!
DATA REPORT: 08-06-2022 09:38:10 
 
FILEPATH: /So2022/fileInformation/FileXTest/prova1.txt 
NUMERO CARATTERI: 88 
PROPRIETARIO: root 
DATA ULTIMA MODIFICA: 8/6/2022 9:14 
NUMERO RIGHE: 7 
DIMENSIONE: 88 bytes 
PERMESSI: WRITE READ
```
