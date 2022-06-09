#include "fileInformation.h"

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