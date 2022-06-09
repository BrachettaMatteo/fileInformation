/**
 * @file main.c
 * @authors Brachetta Matteo (matteo.brachetta@studenti.unicam.it)
 *          Maiellaro Giuseppe (giuseppe.maiellaro@studenti.unicam.it)
 * @version 0.1
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "fileInformation.h"

int main(int argc, char const *argv[])
{
    if (argc == 2)
    {
        configurazioneDefault(argv[1]);
    }

    else
    {
        if (argc == 3)
        {
            configurazioneParametri(argv[2], argv);
        }
    }

    return 0;
}
