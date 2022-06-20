/**
 * @file config.h
 * @authors Brachetta Matteo (matteo.brachetta@studenti.unicam.it)
 *          Maiellaro Giuseppe (giuseppe.maiellaro@studenti.unicam.it)
 * @version 0.2
 * @brief libreria che si occupa della gestione della configurazione iniziale, ovvero esamina l'input e lo dirige per arrivare all'otput desiderato
 * @copyright Copyright (c) 2022
 *
 */
#include "utility.h"
#include "opzioni.h"

/**
 * @brief configurazione con parametri, permette di gestire la richiesta dei paramteri:
 *
 * @param filepath file da analizzare
 * @param opzione opzione scelta
 * @return data l'opzione restituisce:
 *           -c restituisce il numero di caratteri;
 *           -o restituisce il nome del proprietario;
 *           -d restituisce la data dell'ultima modifica;
 *           -l restituisce il numero di righe;
 *           -s restituisce la dimensione del file;
 *           -p restituisce i permessi del file;
 *           -r crea un report con tutti i dettagli  su un nuovo file chiamato report.txt
 * se l'opzione non corrisponde alle opzione elenecate segnera un messaggio di errore
 *
 */
char* configurazioneParametri(char *filepath, char **opzione);
/**
 * @brief configurazione con di deafult
 *
 * @param pathFile fila da analizzare
 * @return restituira il restituisce il numero di caratteri;
 *            il nome del proprietario;
 *            la data dell'ultima modifica;
 *            il numero di righe;
 *            la dimensione del file;
 *            i permessi del file;
 */
char *configurazioneDefault(char *pathFile);