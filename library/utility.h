/**
 * @file fileInformation.h
 * @authors Brachetta Matteo (matteo.brachetta@studenti.unicam.it)
 *          Maiellaro Giuseppe (giuseppe.maiellaro@studenti.unicam.it)
 * @version 0.2
 * @brief libreria che contiene tutte le funzioni del fileInfomration
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <time.h>

#include <pwd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <string.h>

#include <stdlib.h>

#include <errno.h>

#include <dirent.h>

#define MAX_DIM_FILEPATH 200
#define MAX_BUFFER 10000
#define MAX_DIM_PERMESSI 30

#define PERCORSOREPORTCARTELLA "./reportAnalisi.txt"

/**
 * @brief determina la dimensione del file in byte
 *
 * @param pathFile percorso del file
 * @return dimensione del file
 */
int dimensioneFile(char *pathFile);
/**
 * @brief determina il numero di righe
 *
 * @param pathFile percorso del file
 * @return il numero di righe, se il file è vuoto ritorna 0
 */
int numeroRighe(char *pathFile);
/**
 * @brief determina il nome del proprietario
 *
 * @param pathFile percorso del file
 * @return  nome del proprietario
 */
char *nomeProprietario(char *pathFile);
/**
 * @brief permette di detreminare il numero dei caratteri del file
 *
 * @param pathFile percorso del file
 * @return numero dei caratteri
 */
int numeroCaratteri(char *pathFile);
/**
 * @brief retituisce i permessi del file
 *
 * @param pathFile percorso del file
 * @return l'elenco dei permessi
 */
char *permessi(char *pathFile);
/**
 * @brief determina l'ultima modifica fatta
 *
 * @param pathFile
 * @return la data di ultima modifica
 */
time_t dataUltimaModifica(char *pathFile);
/**
 * @brief determina se il percorso è corretto, ovvero verifica se il file esiste o meno
 *
 * @param pathFile percorso del file
 * @return -1 se il file on esiste altrimenti un valore diverso da -1
 */
int checkPath(char *pathFile);

/**
 * @brief permette di ottenre informazioni su tutti i file di un cartella
 *
 * @param filePath  percorso del file
 * @return int
 */
int visitaRicorsiva(char *filePath);
/**
 * @brief permette di verificare se il pathFile è un acartella
 *
 * @param filePath percorso del file
 * @return 1 se è una cartella altrimeneti -1
 */
int verificaCartella(char *filePath);
int creaReportAnalisi();
int scriviNelFile(char* filePath, char *testo);