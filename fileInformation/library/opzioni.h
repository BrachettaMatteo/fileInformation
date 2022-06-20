/**
 * @file opzioni.h
 * @authors Brachetta Matteo (matteo.brachetta@studenti.unicam.it)
 *          Maiellaro Giuseppe (giuseppe.maiellaro@studenti.unicam.it)
 * @version 0.2
 * @brief libreria che si occupa della gestione delle opzioni dei comandi (-l,-o,,,)
 * @copyright Copyright (c) 2022
 *
 */
#include "utility.h"

// dechiariazione delle opzioni
#define NUMERO_CARATTERI 'c'
#define PROPRIETARIO 'o'
#define ULTIMA_MODIFICA 'd'
#define NUMERO_RIGHE 'l'
#define DIMENSIONE 's'
#define PERMESSI 'p'
#define REPORT 'r'
#define CARTELLARICORSIVA 'a'

// dichiarazione dei pecorsi
#define PERCORSOREPORTFILE "./report.txt"

// dichiarazione intestazione del report
#define INTESTAZIONE_REPORT " \t  !--REPORT  FILE--!\n"

// dichiarazione messsaggio aiuto
#define MESSAGGIOAIUTO "\nLista comandi opzione\n\t-c restituisce il numero di caratteri; \n\t -o restituisce il nome del proprietario; \n\t -d restituisce la data dell'ultima modifica;\n -l restituisce il numero di righe;\n\t -s restituisce la dimensione del file;\n -p restituisce i permessi del file;\n\t -a analizza tutti i file di una cartella\n\t -r  crea un report con tutti i dettagli  su un nuovo\n\t -a  crea un report con i dettagli di tutti i file contenenti nella cartella\n";

//dichiarazione messaggio di errore percorso 
#define MESSAGGIOERROREPERCOSOFILE "ERRORE inserire un percorso ad un file\n"
/**
 * @brief gestisce l'opzione -c, quindi stampera il numero di caratteri
 *
 * @param pathfile  file da analizzare
 */
char *opzioneC(char *pathfile);
/**
 * @brief gestisce l'opzione -o, quindi stampera il nome del proprietario
 * @param pathfile  file da analizzare
 */
char *opzioneO(char *pathfile);
/**
 * @brief gestisce l'opzione -d, quindi stampera la data dell'ultima modifica;
 *
 * @param pathfile  file da analizzare
 */
char *opzioneD(char *pathfile);
/**
 * @brief gestisce l'opzione -l, quindi stampera il numero di righe;
 *
 * @param pathfile  file da analizzare
 */
char *opzioneL(char *pathfile);
/**
 * @brief gestisce l'opzione -s, quindi stampera  la dimensione del file;
 *
 * @param pathfile  file da analizzare
 */
char *opzioneS(char *pathfile);
/**
 * @brief gestisce l'opzione -p, quindi stampera  i permessi del file;;
 *
 * @param pathfile  file da analizzare
 */
char *opzioneP(char *pathfile);
/**
 * @brief gestisce l'opzione  -r crea un report con tutti i dettagli  su un nuovo file chiamato report.txt

 *
 * @param pathfile  file da analizzare
 */
char *opzioneR(char *pathfile);
/**
 * @brief gestisce l'opzione  -a crea un report con tutti i dettagli  dei file della cartella. La locazione della cartella è dichiarata nella costante PERCORSOREPORTFILE.
 *
 * @param pathfile percorso del file
 */
char *opzioneA(char *pathfile);
/**
 * @brief gestisce l'opzione di aiuto. In questo caso restituirà l'elenco dei comandi.
 *
 * @return lista dei comandi
 */
char *aiuto();