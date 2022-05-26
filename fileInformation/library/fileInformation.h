#include <stdio.h>
#include<time.h>
/**
 * @brief determina la dimensione del file in byte
 * 
 * @param file percorso del file
 * @return dimensione del file
 */
int dimensioneFile(char* file);
/**
 * @brief detremina il numero di righe
 * 
 * @param file percorso del file
 * @return il numero di righe, se il file è vuoto ritorna 0
 */
int numeroRighe(char* file);
/**
 * @brief determina il nome del proprietario
 * 
 * @param file percorso del file
 * @return char* nome del proprietario
 */
char* nomeProprietario(char* file);
/**
 * @brief determina i link presenti nel file
 * 
 * @param file percorso del file
 * @return numero dei link al file.
 */
int numeroLinkFile(char* file);
/**
 * @brief permette di detreminare il numero dei caratteri del file
 * 
 * @param file percorso del file
 * @return numero dei caratteri
 */
int numeroCaratteri(char* file);
/**
 * @brief retituisce i permessi del file per il determinato ruolo
 * 
 * @param file percorso del file
 * @param ruolo puo essere admin, group o user
 * @return restituisce l'elenco dei permessi del file per il ruolo indicato.
 */
char* permessi(char *file, char ruolo);
/**
 * @brief determina l'ultima modifica fatta
 * 
 * @param file 
 * @return la data di ultima modifica
 */
time_t dataUltimaModifica(char *file);
