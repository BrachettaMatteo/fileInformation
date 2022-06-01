
#include "fileInformation.h"

int main(int argc, char const *argv[])
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
        // printf("numero righe: %d \n", numeroRighe(pathFile));
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

    return 0;
}

int numeroCaratteri(char *pathFile)
{
    //file descriptor
    int fd;
    //buffer per read
    char buffer[MAX_BUFFER] = "/0";
    //contatore caratteri
    int caratteri;
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

    FILE *fp;          //puntatore al file
    int cont = 0;      //contatore per le righe
    int carattere = 0; //variabile per la lettura dela carattere contenuto nella riga letta (sottoforma di codice ASCII)
    if (checkPath(pathFile) == 1)
    {
        while (!feof(fp)) //controllo che il file non sia finito
        {
            carattere = fgetc(fp); //prelevo il primo carattere letto nella riga
            if (carattere == '\n') //controllo che non sia un ritorno a capo
            {
                cont++; //conto a che riga sono arrivato
            }
        }
        fclose(fp); //chiusura del file
    }
    else
        printf("Non sono riuscito ad aprire il file\n");
    return cont;
}

int dimensioneFile(char *file)
{

    FILE *fd;
    int size;
    fd = fopen(file, "r"); //apertura file
    if (checkPath(file) != -1)
    {
        fseek(fd, 0, SEEK_END); //determina la dimensione di un file
        size = ftell(fd);
        fclose(fd);
        return size;
    }
    return 0;
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