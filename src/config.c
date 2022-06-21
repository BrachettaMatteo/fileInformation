#include "config.h"

char *configurazioneParametri(char *filepath, char **opzione)
{
    int opt;
    while ((opt = getopt(3, opzione, "c:o:d:l:s:p:r:a")) != -1)
    {
        switch (opt)
        {
        case NUMERO_CARATTERI:
        {
            return opzioneC(filepath);
        };
        case PROPRIETARIO:
        {

            return opzioneO(filepath);
        };
        case ULTIMA_MODIFICA:
        {

            return opzioneD(filepath);
        };
        case NUMERO_RIGHE:
        {

            return opzioneL(filepath);
        };
        case DIMENSIONE:
        {

            return opzioneS(filepath);
        };
        case PERMESSI:
        {
            return opzioneP(filepath);
        };
        case CARTELLARICORSIVA:
        {

            return opzioneA(filepath);
        };
        case REPORT:
        {
            return opzioneR(filepath);
        };

        default:
        {
            return aiuto();
        }
        }
    }
}

char *configurazioneDefault(char *pathFile)
{
    if (!verificaCartella(pathFile) && verificaPercorso(pathFile))
    {
        // creo var per testo output
        char *out = malloc(sizeof(char) * MAX_BUFFER);
        // creo var di lavoro per testo
        char lavorazione[MAX_BUFFER];
        // aggiungo intestazione
        strcat(out, "\n\t FILEINFORMATION \n\n");
        // aggiungo elementi al testo
        sprintf(lavorazione, "PATHFILE: %s \n", pathFile);
        strcat(out, lavorazione);
        sprintf(lavorazione, "%s", opzioneC(pathFile));
        strcat(out, lavorazione);
        sprintf(lavorazione, "%s", opzioneO(pathFile));
        strcat(out, lavorazione);
        sprintf(lavorazione, "%s", opzioneL(pathFile));
        strcat(out, lavorazione);
        sprintf(lavorazione, "%s", opzioneS(pathFile));
        strcat(out, lavorazione);
        sprintf(lavorazione, "%s", opzioneD(pathFile));
        strcat(out, lavorazione);
        sprintf(lavorazione, "%s \n", opzioneP(pathFile));
        strcat(out, lavorazione);
        return out;
    }
    return "ERRORE configurazione default \n";
}
