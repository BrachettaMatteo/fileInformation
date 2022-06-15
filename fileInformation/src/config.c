#include "config.h"

int configurazioneParametri(char *filepath, char **opzione)
{
    if (checkPath(filepath))
    {
        int opt;

        while ((opt = getopt(3, opzione, "c:o:d:l:s:p:r:a")) != -1)
        {
            switch (opt)
            {
            case NUMERO_CARATTERI:
            {
                printf("%s", opzioneC(filepath));
                break;
            };
            case PROPRIETARIO:
            {

                printf("%s", opzioneO(filepath));
                break;
            };
            case ULTIMA_MODIFICA:
            {

                printf("%s", opzioneD(filepath));
                break;
            };
            case NUMERO_RIGHE:
            {

                printf("%s", opzioneL(filepath));
                break;
            };
            case DIMENSIONE:
            {

                printf("%s", opzioneS(filepath));
                break;
            };
            case PERMESSI:
            {
                printf("%s", opzioneP(filepath));
                break;
            };
            case CARTELLARICORSIVA:
            {
                opzioneA(filepath);
                break;
            };
            case REPORT:
            {
                opzioneR(filepath);
                break;
            };

            default:
            {
                printf("Lista comandi opzione\n -c restituisce il numero di caratteri; \n -o restituisce il nome del proprietario; \n -d restituisce la data dell'ultima modifica;\n -l restituisce il numero di righe;\n -s restituisce la dimensione del file;\n -p restituisce i permessi del file;\n -r  crea un report con tutti i dettagli  su un nuovo\n");
                return -1;
            }
            }
            return 0;
        }
    }
    return -1;
}

int configurazioneDefault(char *pathFile)
{
    if (checkPath(pathFile))
    {
        printf("\n\t FILEINFORMATION \n\n");
        printf("PATHFILE: %s \n", pathFile);
        printf("%s", opzioneC(pathFile));
        printf("%s", opzioneO(pathFile));
        printf("%s", opzioneL(pathFile));
        printf("%s", opzioneS(pathFile));
        printf("%s", opzioneD(pathFile));
        printf("%s", opzioneP(pathFile));
        return 0;
    }
    return -1;
}
