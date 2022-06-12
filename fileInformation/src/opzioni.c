#include "opzioni.h"

char *opzioneC(char *pathfile)
{

    char *out = (char *)malloc(sizeof(char) * MAX_BUFFER);

    sprintf(out, "NUMERO CARATTERI: %d \n", numeroCaratteri(pathfile));
    return out;
}

char *opzioneO(char *pathfile)
{
    // cmake  char text[MAX_BUFFER];
    char *out = (char *)malloc(sizeof(char) * MAX_BUFFER);
    sprintf(out, "NOME PROPRIETARIO: %s \n", nomeProprietario(pathfile));
    return out;
}

char *opzioneD(char *pathfile)
{

    time_t ddd = dataUltimaModifica(pathfile);
    struct tm *dataCreazione;
    dataCreazione = localtime(&ddd);
    char *out = (char *)malloc(sizeof(char) * MAX_BUFFER);

    sprintf(out, "DATA ULTIMA MODIFICA:%d/%d/%d %d:%d \n", dataCreazione->tm_mday, dataCreazione->tm_mon + 1,
            dataCreazione->tm_year + 1900, dataCreazione->tm_hour + 1, dataCreazione->tm_min);
    return out;
}

char *opzioneL(char *pathfile)
{
    char *out = (char *)malloc(sizeof(char) * MAX_BUFFER);

    sprintf(out, "NUMERO RIGHE: %d \n", numeroRighe(pathfile));
    return out;
}

char *opzioneS(char *pathfile)
{
    char *out = (char *)malloc(sizeof(char) * MAX_BUFFER);

    sprintf(out, "DIMENSIONE FILE: %d  bytes\n", dimensioneFile(pathfile));
    return out;
}

char *opzioneP(char *pathfile)
{
    char *out = (char *)malloc(sizeof(char) * MAX_BUFFER);

    sprintf(out, "PERMESSI: %s \n", permessi(pathfile));
    return out;
}

int opzioneR(char *pathfile)
{

    if (checkPath(pathfile) != -1)
    {
        int fd;
        // destinazione file
        char path[15] = "./report.txt";
        if ((fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU)) != -1)
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

            write(fd, text, MAX_BUFFER);
            close(fd);
            printf("Report creato \n");
        }
        else
        {
            perror("Errore file");
        }
    }
}
