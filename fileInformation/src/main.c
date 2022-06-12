/**
 * @file main.c
 * @authors Brachetta Matteo (matteo.brachetta@studenti.unicam.it)
 *          Maiellaro Giuseppe (giuseppe.maiellaro@studenti.unicam.it)
 * @version 0.2
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "fileInformation.h"

int main(int argc, char const *argv[])
{
    if (argc == 2)
    {
        configurazioneDefault((char*) argv[1]);
    }

    else
    {
        if (argc == 3)
        {
            configurazioneParametri((char*)argv[2],(char**) argv);
        }
    }

    return 0;
}
