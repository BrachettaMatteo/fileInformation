
#include "fileInformation.h"

#include <stdio.h>
#include <unistd.h>

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
        while ((opt = getopt(argc, argv, "c:o:d:l:s:p:r")) != -1)
        {
            switch (opt)
            {
            case 'c':
            {
                printf("mum caratteri: %d \n", numeroCaratteri(argv[2]));
                break;
            };
                case 'o':
                {
                    printf("nome prorpietario: %s \n", nomeProprietario(argv[2]));
                    break;
                };
                case 'd':
                {
                    time_t ddd = dataUltimaModifica(argv[2]);
                    struct tm *dataCreazione;
                    dataCreazione = localtime(&ddd);
                    printf("data ultima modifica:%d/%d/%d %d:%d \n", dataCreazione->tm_mday, dataCreazione->tm_mon + 1,
                           dataCreazione->tm_year + 1900, dataCreazione->tm_hour + 1, dataCreazione->tm_min);
                    break;
                };
                case 'l':
                {
                    printf("numero righe: %d \n", numeroRighe(argv[2]);
                    break;
                };
                case 's':
                {
                    printf("dimensione file: %d  bytes\n", dimensioneFile(argv[2]));
                    break;
                };
                case 'p':
                {
                    printf("permessi: %s \n", permessi(argv[2]));
                    break;
                };




            case 'r':
            {
                //cambiare i permessi
                if( checkPath(argv[2])!=-1){
                int fd;
                char path [15]="./report.txt";
                fd=creat(path,O_CREAT);
                write(fd,"REPORT \n",10);
                close(fd);
                }
               
                break;
            };
                default:
                    printf("commando inesistente");
            }
        }
    }

    return 0;
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

int dimensioneFile(char *file)
{

    int fd, size;
    if (checkPath(file) != -1)
    {
        fd = open(file, O_RDONLY);
        //punto all'ultimo byte del file così da ottenere la dimensione
        size = lseek(fd, 0, SEEK_END);
        close(fd);
    }
    return size;
}
char *permessi(char *file)
{ //libero vechia memoria

    char *permessi;

    permessi = malloc(MAX_SIZE_PERMISSIONS * sizeof(int));
    //controllo se la var contiene elementi in casi di risposta affermativa elimino il contenuto
    if (strlen(permessi) > 0)
    {
        free(permessi);
        permessi = malloc(MAX_SIZE_PERMISSIONS * sizeof(int));
    }

    if (checkPath(file) != -1)
    {
        if (access(file, 01) == 0)
        {
            strcat(permessi, "EXECUTE ");
        }
        if (access(file, 02) == 0)
        {
            strcat(permessi, "WRITE ");
        }
        if (access(file, 04) == 0)
        {
            strcat(permessi, "READ ");
        }
    }
    return permessi;
}