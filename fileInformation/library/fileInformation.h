#include <stdio.h>
#include <time.h>

//uidd-> name proprietario
#include <pwd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <string.h>

#include<stdlib.h>

#define MAX_SIZE_FILEPATH 200
#define MAX_BUFFER 10000
#define MAX_SIZE_PERMISSIONS 30
/**
 * @brief determina la dimensione del file in byte
 * 
 * @param file percorso del file
 * @return dimensione del file
 */
int dimensioneFile(char *file);
/**
 * @brief detremina il numero di righe
 * 
 * @param file percorso del file
 * @return il numero di righe, se il file è vuoto ritorna 0
 */
int numeroRighe(char *file);
/**
 * @brief determina il nome del proprietario
 * 
 * @param pathFile percorso del file
 * @return char* nome del proprietario
 */
char *nomeProprietario(char *pathFile);
/**
 * @brief determina i link presenti nel file
 * 
 * @param file percorso del file
 * @return numero dei link al file.
 */
int numeroLinkFile(char *file);
/**
 * @brief permette di detreminare il numero dei caratteri del file
 * 
 * @param pathFile percorso del file
 * @return numero dei caratteri
 */
int numeroCaratteri(char *pathFile);
/**
 * @brief retituisce i permessi del file per il determinato ruolo
 * 
 * @param file percorso del file
 * @return restituisce l'elenco dei permessi del file per il ruolo indicato.
 */
char *permessi(char *file);
/**
 * @brief determina l'ultima modifica fatta
 * 
 * @param file 
 * @return la data di ultima modifica
 */
time_t dataUltimaModifica(char *file);
/**
 * @brief determina se il percorso è corretto
 * 
 * @param pathFile percorso del file
 * @return 1 se il percorso è collegato ad un file altrimenti 0 se il percorso non è collegato al file.
 */
int checkPath(char *pathFile);