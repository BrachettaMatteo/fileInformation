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
// DEFINE OPTION

#define NUMERO_CARATTERI 'c'
#define PROPRIETARIO 'o'
#define ULTIMA_MODIFICA 'd'
#define NUMERO_RIGHE 'l'
#define DIMENSIONE 's'
#define PERMESSI 'p'
#define REPORT 'r'
#define CARTELLARICORSIVA 'a'

#define INTESTAZIONE_REPORT " \t  !--REPORT  FILE--!\n"
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
int opzioneR(char *pathfile);
/**
 * @brief restituisce i dettagli del file presenti nella cartella
 *
 * @param pathfile percorso del file
 */
int opzioneA(char *pathfile);
