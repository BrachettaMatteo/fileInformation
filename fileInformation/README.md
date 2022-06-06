# fileInformation
### CMake (execute file)
comandi linux.

**Posizione di partenza**`./So2022`

digitare i comandi sotto elencati per eseguire il progetto:

``` bash
cd fileInfrmation
cd build
cmake ..
cmake --build .
./fielInformation
```
## Command Line Option
``` bash
./fileInformation [options] filepath
```
- `-c` restituisce il numero di caratteri;
- `-o` restituisce il nome del proprietario;
- `-d` restituisce la data dell'ultima modifica;
- `-l` restituisce il numero di righe;
- `-s` restituisce la dimensione del file;
- `-p` restituisce i permessi del file;
- `-r` crea un report con tutti i dettagli  su un nuovo file chiamato report.txt