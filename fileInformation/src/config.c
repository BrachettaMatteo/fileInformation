#include "config.h"

configurazioneParametri(char *filepath, char **option)
{
    int opt;
    // put ':' in the starting of the
    // string so that program can
    // distinguish between '?' and ':'
    while ((opt = getopt(3, option, "c:o:d:l:s:p:r")) != -1)
    {
        switch (opt)
        {
        case 'c':
        {
            printf("mum caratteri: %d \n", numeroCaratteri(filepath));
            break;
        };
        case 'o':
        {
            printf("nome prorpietario: %s \n", nomeProprietario(filepath));
            break;
        };
        case 'd':
        {
            time_t ddd = dataUltimaModifica(filepath);
            struct tm *dataCreazione;
            dataCreazione = localtime(&ddd);
            printf("data ultima modifica:%d/%d/%d %d:%d \n", dataCreazione->tm_mday, dataCreazione->tm_mon + 1,
                   dataCreazione->tm_year + 1900, dataCreazione->tm_hour + 1, dataCreazione->tm_min);
            break;
        };
        case 'l':
        {
            printf("numero righe: %d \n", numeroRighe(filepath));
            break;
        };
        case 's':
        {
            printf("dimensione file: %d  bytes\n", dimensioneFile(filepath));
            break;
        };
        case 'p':
        {
            printf("permessi: %s \n", permessi(filepath));
            break;
        };

        case 'r':
        {
            if (checkPath(filepath) != -1)
            {
                int fd;
                // destinazione file
                char path[15] = "./report.txt";
                fd = open(path, O_CREAT | O_WRONLY, S_IRUSR);
                char text[MAX_BUFFER];
                strcat(text, "!--REPORT--!\n");
                time_t t = time(NULL);
                char buf[100];
                struct tm tm = *localtime(&t);

                char work[MAX_BUFFER];
                sprintf(work, "DATA REPORT: %02d-%02d-%d %02d:%02d:%02d \n \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

                strcat(text, work);
                sprintf(work, "FILEPATH: %s \n", filepath);
                strcat(text, work);

                sprintf(work, "NUMERO CARATTERI: %d \n", numeroCaratteri(filepath));
                strcat(text, work);

                sprintf(work, "PROPRIETARIO: %s \n", nomeProprietario(filepath));
                strcat(text, work);

                time_t ddd = dataUltimaModifica(filepath);
                struct tm *dataCreazione;
                dataCreazione = localtime(&ddd);
                sprintf(work, "DATA ULTIMA MODIFICA: %d/%d/%d %d:%d \n", dataCreazione->tm_mday, dataCreazione->tm_mon + 1,
                        dataCreazione->tm_year + 1900, dataCreazione->tm_hour + 1, dataCreazione->tm_min);
                strcat(text, work);

                sprintf(work, "NUMERO RIGHE: %d \n", numeroRighe(filepath));
                strcat(text, work);

                sprintf(work, "DIMENSIONE: %d bytes \n", dimensioneFile(filepath));
                strcat(text, work);

                sprintf(work, "PERMESSI: %s \n", permessi(filepath));
                strcat(text, work);

                // scrivo nel file

                write(fd, text, MAX_BUFFER);
                close(fd);
                printf("Report creato \n");
            }

            break;
        };
        default:
            printf("Lista comandi opzione\n -c restituisce il numero di caratteri; \n -o restituisce il nome del proprietario; \n -d restituisce la data dell'ultima modifica;\n -l restituisce il numero di righe;\n -s restituisce la dimensione del file;\n -p restituisce i permessi del file;\n -r  crea un report con tutti i dettagli  su un nuovo");
        }
    }
}

configurazioneDefault(char *pathFile)
{

    if (checkPath(pathFile) != -1)
    {
        printf("pathfile: %s \n", pathFile);
        printf("numero caratteri: %d \n", numeroCaratteri(pathFile));
        printf("nome prorpietario: %s \n", nomeProprietario(pathFile));
        printf("numero righe: %d \n", numeroRighe(pathFile));
        printf("dimensione file: %d  bytes\n", dimensioneFile(pathFile));
        time_t ddd = dataUltimaModifica(pathFile);
        struct tm *dataCreazione;
        dataCreazione = localtime(&ddd);
        /*
    - aggiungo 1 al mese perchè il conteggio parte da 0, ovvero gennaio=0:
    - aggiungo 1900 al anno perchè nella documntazione sottrae 1900;
    -
     */

        printf("data ultima modifica:%d/%d/%d %d:%d \n", dataCreazione->tm_mday, dataCreazione->tm_mon + 1,
               dataCreazione->tm_year + 1900, dataCreazione->tm_hour + 1, dataCreazione->tm_min);
        printf("permessi: %s \n", permessi(pathFile));
    }
}