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
        char fp[MAX_SIZE_FILEPATH];

        char *pathFile = fp;
        printf("inserire path file: ");
        scanf(" %s", pathFile);
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
    if (argc == 3)
    {
        int opt;
        // put ':' in the starting of the
        // string so that program can
        //distinguish between '?' and ':'
        while ((opt = getopt(argc, (char **)argv, "c:o:d:l:s:p:r")) != -1)
        {
            switch (opt)
            {
            case 'c':
            {
                printf("mum caratteri: %d \n", numeroCaratteri((char *)argv[2]));
                break;
            };
            case 'o':
            {
                printf("nome prorpietario: %s \n", nomeProprietario((char *)argv[2]));
                break;
            };
            case 'd':
            {
                time_t ddd = dataUltimaModifica((char *)argv[2]);
                struct tm *dataCreazione;
                dataCreazione = localtime(&ddd);
                printf("data ultima modifica:%d/%d/%d %d:%d \n", dataCreazione->tm_mday, dataCreazione->tm_mon + 1,
                       dataCreazione->tm_year + 1900, dataCreazione->tm_hour + 1, dataCreazione->tm_min);
                break;
            };
            case 'l':
            {
                printf("numero righe: %d \n", numeroRighe((char *)argv[2]));
                break;
            };
            case 's':
            {
                printf("dimensione file: %d  bytes\n", dimensioneFile((char *)argv[2]));
                break;
            };
            case 'p':
            {
                printf("permessi: %s \n", permessi((char *)argv[2]));
                break;
            };

            case 'r':
            {
                if (checkPath((char *)argv[2]) != -1)
                {
                    int fd;
                    //destinazione file
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
                    sprintf(work, "FILEPATH: %s \n", (char *)argv[2]);
                    strcat(text, work);

                    sprintf(work, "NUMERO CARATTERI: %d \n", numeroCaratteri((char *)argv[2]));
                    strcat(text, work);

                    sprintf(work, "PROPRIETARIO: %s \n", nomeProprietario((char *)argv[2]));
                    strcat(text, work);

                    time_t ddd = dataUltimaModifica((char *)argv[2]);
                    struct tm *dataCreazione;
                    dataCreazione = localtime(&ddd);
                    sprintf(work, "DATA ULTIMA MODIFICA: %d/%d/%d %d:%d \n", dataCreazione->tm_mday, dataCreazione->tm_mon + 1,
                            dataCreazione->tm_year + 1900, dataCreazione->tm_hour + 1, dataCreazione->tm_min);
                    strcat(text, work);

                    sprintf(work, "NUMERO RIGHE: %d \n", numeroRighe((char *)argv[2]));
                    strcat(text, work);

                    sprintf(work, "DIMENSIONE: %d bytes \n", dimensioneFile((char *)argv[2]));
                    strcat(text, work);

                    sprintf(work, "PERMESSI: %s \n", permessi((char *)argv[2]));
                    strcat(text, work);

                    //scrivo nel file

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

    return 0;
}

int dimensioneFile(char *pathFile)
{

    int fd, size;
    if (checkPath(pathFile) != -1)
    {
        fd = open(pathFile, O_RDONLY);
        //punto all'ultimo byte del file così da ottenere la dimensione
        size = lseek(fd, 0, SEEK_END);
        close(fd);
    }
    return size;
}

int numeroRighe(char *pathFile)
{

    int fd, i, righe;
    char buffer[MAX_BUFFER];
    if (checkPath(pathFile) != -1)
    {
        fd = open(pathFile, O_RDONLY);
        read(fd, buffer, MAX_BUFFER);
        close(fd);
        righe = 0;
        i = 0;
        //scorro fino alla fine del file
        while (buffer[i] != '\0')
        {
            //conto righe
            if (buffer[i] == '\n')
            {
                righe++;
            }
            i++;
        }
    }
    return righe;
}
char *nomeProprietario(char *pathFile)
{
    struct stat buf;
    struct passwd *pwd;
    //ottengo informazioni file
    stat(pathFile, &buf);
    //convero l'id in nome utente
    pwd = getpwuid(buf.st_uid);

    return pwd->pw_name;
}

int numeroCaratteri(char *pathFile)
{
    //file descriptor
    int fd;
    //buffer per read
    char buffer[MAX_BUFFER] = "/0";
    //contatore caratteri
    int caratteri = 0;
    if (checkPath(pathFile) != 1)
    {
        //apertura file
        fd = open(pathFile, O_RDONLY);
        //lettura file
        read(fd, buffer, MAX_BUFFER);
        //chiusura file;
        close(fd);
    }
    /*
    la var buffer conterra tutti i caratteri
    del file.
    */
    return strlen(buffer);
}

char *permessi(char *pathFile)
{ //libero vechia memoria

    char *permessi;

    permessi = malloc(MAX_SIZE_PERMISSIONS * sizeof(int));
    //controllo se la var contiene elementi in casi di risposta affermativa elimino il contenuto
    if (strlen(permessi) > 0)
    {
        free(permessi);
        permessi = malloc(MAX_SIZE_PERMISSIONS * sizeof(int));
    }

    if (checkPath(pathFile) != -1)
    {
        if (access(pathFile, 01) == 0)
        {
            strcat(permessi, "EXECUTE ");
        }
        if (access(pathFile, 02) == 0)
        {
            strcat(permessi, "WRITE ");
        }
        if (access(pathFile, 04) == 0)
        {
            strcat(permessi, "READ ");
        }
    }
    return permessi;
}

time_t dataUltimaModifica(char *pathFile)
{
    struct stat buf;
    stat(pathFile, &buf);
    struct tm dataCreazione;
    //ottengo data ultima modifica del file
    dataCreazione = *(gmtime(&buf.st_mtim));
    //trasformo type tm in type time_t
    return mktime(&dataCreazione);
}

int checkPath(char *pathfFile)
{
    int fd = open(pathfFile, O_RDONLY);
    close(fd);
    if (fd == -1)
        printf("ERROR OPEN FILE \n");
    return fd;
}
