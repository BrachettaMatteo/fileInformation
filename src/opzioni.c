#include "opzioni.h"

char *opzioneC(char *pathfile)
{
    if (!verificaCartella(pathfile))
    {
        char *out = (char *)malloc(sizeof(char) * MAX_BUFFER);
        sprintf(out, "NUMERO CARATTERI: %d \n", numeroCaratteri(pathfile));

        return out;
    }
    return MESSAGGIOERROREPERCOSOFILE;
}

char *opzioneO(char *pathfile)
{
    if (!verificaCartella(pathfile))
    {
        char *out = (char *)malloc(sizeof(char) * MAX_BUFFER);
        sprintf(out, "NOME PROPRIETARIO: %s \n", nomeProprietario(pathfile));

        return out;
    }
    return MESSAGGIOERROREPERCOSOFILE;
}

char *opzioneD(char *pathfile)
{
    if (!verificaCartella(pathfile))
    {
        time_t ddd = dataUltimaModifica(pathfile);
        struct tm *dataCreazione;
        dataCreazione = localtime(&ddd);
        char *out = (char *)malloc(sizeof(char) * MAX_BUFFER);

        sprintf(out, "DATA ULTIMA MODIFICA:%d/%d/%d %d:%d \n", dataCreazione->tm_mday, dataCreazione->tm_mon + 1,
                dataCreazione->tm_year + 1900, dataCreazione->tm_hour + 1, dataCreazione->tm_min);

        return out;
    }
    return MESSAGGIOERROREPERCOSOFILE;
}

char *opzioneL(char *pathfile)
{
    if (!verificaCartella(pathfile))
    {
        char *out = (char *)malloc(sizeof(char) * MAX_BUFFER);
        sprintf(out, "NUMERO RIGHE: %d \n", numeroRighe(pathfile));

        return out;
    }
    return MESSAGGIOERROREPERCOSOFILE;
}

char *opzioneS(char *pathfile)
{
    if (!verificaCartella(pathfile))
    {
        char *out = (char *)malloc(sizeof(char) * MAX_BUFFER);
        sprintf(out, "DIMENSIONE FILE: %d  bytes\n", dimensioneFile(pathfile));

        return out;
    }
    return MESSAGGIOERROREPERCOSOFILE;
}

char *opzioneP(char *pathfile)
{
    if (!verificaCartella(pathfile))
    {
        char *out = (char *)malloc(sizeof(char) * MAX_BUFFER);
        sprintf(out, "PERMESSI: %s \n", permessi(pathfile));

        return out;
    }
    return MESSAGGIOERROREPERCOSOFILE;
}

char *opzioneR(char *pathfile)
{
    if (!verificaCartella(pathfile))
    {
        if (verificaPercorso(pathfile) != -1)
        {
            int fd;
            if ((fd = open(PERCORSOREPORTFILE, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU)) != -1)
            {

                char text[MAX_BUFFER];
                strcat(text, INTESTAZIONE_REPORT);
                time_t t = time(NULL);
                char buf[100];
                struct tm tm = *localtime(&t);

                char work[MAX_BUFFER];

                sprintf(work, "DATA REPORT: %02d-%02d-%d %02d:%02d:%02d \n \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

                strcat(text, work);
                sprintf(work, "FILEPATH: %s \n", pathfile);
                strcat(text, work);

                strcat(text, opzioneC(pathfile));

                strcat(text, opzioneO(pathfile));

                strcat(text, opzioneD(pathfile));

                strcat(text, opzioneL(pathfile));

                strcat(text, opzioneS(pathfile));

                strcat(text, opzioneP(pathfile));

                // scrivo nel file

                write(fd, text, strlen(text));
                close(fd);

                return "Report Creato \n";
            }
            else
            {
                perror("ERRORE file \n");
            }
        }
    }
    return MESSAGGIOERROREPERCOSOFILE;
}
char *opzioneA(char *filePath)
{
    if (verificaCartella(filePath) == 1)
    {
        // creo report
        int fd = creaReportAnalisi();

        // richiamo analisi cartella
        visitaRicorsiva(filePath);

        return "Report creato \n";
    }
    else
    {

        perror("ERRORE apertura cartella:");
    }
}
char *aiuto()
{
    return MESSAGGIOAIUTO;
}