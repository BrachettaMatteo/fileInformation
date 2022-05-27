#include "fileInformation.h"

int main(int argc, char const *argv[])
{
    char fp[MAX_SIZE_FILEPATH];

    char *pathFile = fp;
    printf("inserire path file: ");
    scanf(" %s", pathFile);
    if (checkPath(pathFile) == 1)
    {
        printf("pathfile: %s \n", pathFile);
        printf("numero caratteri: %d \n", numeroCaratteri(pathFile));
        printf("nome prorpietario: %s \n", nomeProprietario(pathFile));
        time_t ddd = dataUltimaModifica(pathFile);
        struct tm *dataCreazione;
        dataCreazione = localtime(&ddd);
        /*
        - aggiungo 1 al mese perchè il conteggio parte da 0, ovvero gennaio=0:
        - aggiungo 1900 al anno perchè nella documntazione sottrae 1900;
        -
         */
        printf("data ultima modifica:%d/%d/%d %d:%d \n", dataCreazione->tm_mday, dataCreazione->tm_mon + 1, dataCreazione->tm_year + 1900, dataCreazione->tm_hour + 1, dataCreazione->tm_min);
    }
    return 0;
}

int numeroCaratteri(char *pathFile)
{
    FILE *fp;
    int numeChar = 0;
    if (fp = fopen(pathFile, "r"))
    {
        while (!feof(fp))
        {
            getc(fp);
            numeChar = numeChar + 1;
        }
    }
    else
        printf("Errore file");
    return numeChar;
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
    FILE *fp;
    if (fp = fopen(pathfFile, "r"))
    {
        fclose(fp);
        return 1;
    }
    else
        return 0;
}