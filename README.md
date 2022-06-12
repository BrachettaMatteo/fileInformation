# Progetto Sistemi Operativi

Progetto in c per il corso di laboratorio di Sistemi Operativi 2021/2022 presso l'univerisità di Camerino

## Nome Progetto

`FileInformation`

## Descrizione

Progetto sviluppato per sistemi Unix/Linux in grado di rilevare:

- Numero di caratteri;
- Nome del proprietario;
- Data dell'ultima modifica;
- Numero di righe;
- Dimensione del file;
- Permessi del file;

Possibilità di eseguire i comandi in modo singolare oppure stilare un report con tutti i dettagli sopra elencati.

## Struttura

il progetto viene diviso in cartelle:

1. `./fileInformation/library` contiene tutti i file di header nello specifico:
   - `./fileInformation/library/fileInformation.h` conternitore generale
   - `./fileInformation/library/config.h` che illustrerà le funzioni principali della configurazione;
   - `./fileInformation/library/opzioni.h` che conterrà le funzioni riguardante le opzioni create; -`./fileInformation/library/utility.h` che conterrà le funzioni riguardanti i "comandi" per le opzioni create;
2. `./fileInformation/FileXTest` che conterrà file utili per la erifica delle funzioni
3. `./fileInformation/src` conterrà tutte l'implementazione dei rispettive header(.h):
   - `./fileInformation/src/config.c`
   - `./fileInformation/src/utility.c`
   - `./fileInformation/src/main.c`
   - `./fileInformation/src/opzioni.c`

## Componenti gruppo

- Brachetta Matteo [matteo.brachetta@studenti.unicam.it]
- Maiellaro Giuseppe [giuseppe.maiellaro@studenti.unicam.it]

## Date discussione progetto:

- [x] 22/06/2022
- [ ] 03/07/2022
- [ ] 27/07/2022
