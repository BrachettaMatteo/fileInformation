/**
 * @file main.c
 * @authors Brachetta Matteo (matteo.brachetta@studenti.unicam.it)
 *          Maiellaro Giuseppe (giuseppe.maiellaro@studenti.unicam.it)
 * @version 0.2
 * @date 22/06/2022
 * @copyright Copyright (c) 2022
 *
 */
#include "fileInformation.h"

int main(int argc, char const *argv[])
{
    // primo controllo in base al numero di elementi inseriti
    switch (argc)
    {
    case 2:
        printf("%s", configurazioneDefault((char *)argv[1]));
        break;
    case 3:
        printf("%s", configurazioneParametri((char *)argv[2], (char **)argv));
        break;
    default:
        printf("ERRORE FORMATO i formati acettati sono: \n\t configurazione default: ./fileInformation [percorsoFile] \n\t configurazione con parametri: ./fileInformation <opzioni> [percorsoFile]\n ");
        break;
    }
    return 0;
}
