#include "utility.h"
#include "config.h"

char *nomeProprietario(char *pathFile){
    struct stat buf;
    struct passwd *pwd;
    // ottengo informazioni file
    stat(pathFile, &buf);
    // convero l'id in nome utente
    pwd = getpwuid(buf.st_uid);

    return pwd->pw_name;
}

int numeroCaratteri(char *pathFile){
    // file descriptor
    int fd;
    // buffer per read
    char buffer[MAX_BUFFER] = "\0";
    // contatore caratteri
    int caratteri = 0;
    if (verificaPercorso(pathFile))
    {
        // apertura file
        fd = open(pathFile, O_RDONLY);
        // lettura file
        read(fd, buffer, MAX_BUFFER);
        close(fd);
    }
    /*
 la var buffer conterra tutti i caratteri
 del file.
 */
    return strlen(buffer);
}

char *permessi(char *pathFile){
    char *permessi;

    permessi = malloc(MAX_DIM_PERMESSI * sizeof(int));
    // controllo se la var contiene elementi in casi
    // di risposta affermativa elimino il contenuto
    if (strlen(permessi) > 0){
        free(permessi);
        permessi = malloc(MAX_DIM_PERMESSI * sizeof(int));
    }

    if (verificaPercorso(pathFile)){
        if (access(pathFile, 01) == 0)
            strcat(permessi, "ESECUZIONE ");

        if (access(pathFile, 02) == 0)
            strcat(permessi, "SCRITTURA ");

        if (access(pathFile, 04) == 0)
            strcat(permessi, "LETTURA ");
    }
    return permessi;
}

time_t dataUltimaModifica(char *pathFile){
    struct stat buf;
    stat(pathFile, &buf);
    struct tm dataCreazione;
    // ottengo data ultima modifica del file
    dataCreazione = *(gmtime(&buf.st_mtim));
    // trasformo type tm in type time_t
    return mktime(&dataCreazione);
}

int verificaPercorso(char *pathfFile){
    int fd;
    if ((fd = open(pathfFile, O_RDONLY)) != -1)
    {
        close(fd);
        return 1;
    }
    else
    {
        perror("ERRORE apertura file: ");
        return -1;
    }
}

int dimensioneFile(char *pathFile){

    int fd, size;
    if (verificaPercorso(pathFile))
    {
        fd = open(pathFile, O_RDONLY);
        // punto all'ultimo byte del file
        // così da ottenere la dimensione
        size = lseek(fd, 0, SEEK_END);
        close(fd);
    }
    return size;
}

int numeroRighe(char *pathFile){
    int fd, i, righe;
    char buffer[MAX_BUFFER];
    if (verificaPercorso(pathFile)){
        fd = open(pathFile, O_RDONLY);
        read(fd, buffer, MAX_BUFFER);
        close(fd);
        righe = 0;
        i = 0;
        // scorro fino alla fine del file
        while (buffer[i] != '\0')
        {
            // conto righe
            if (buffer[i] == '\n')
                righe++;
            i++;
        }
    }
    return righe;
}

int visitaRicorsiva(char *filePath){
    struct dirent *dp;
    DIR *dir;
    char percorsoAggiuntivo[MAX_DIM_FILEPATH];
    // controllo che la cartella viene aperta correttamente
    if ((dir = opendir(filePath)) != NULL)
    {
        // leggo tutti gli elementi della cartella
        while ((dp = readdir(dir)) != NULL)
        {
            // controllo che non siano cartelle "speciali"
            if (dp->d_name[0] != '.')
            {
                // azzero pathfile
                strcpy(percorsoAggiuntivo, "");
                // creo nuovo percorso
                // aggiungo la posizione attuale
                strcat(percorsoAggiuntivo, filePath);
                // aggiungo il nome della cartellao del file da analizzare
                strcat(percorsoAggiuntivo, "/");
                strcat(percorsoAggiuntivo, dp->d_name);
                // verifico se è una cartella
                if (verificaCartella(percorsoAggiuntivo))
                {
                    //è una cartella richiamo la funzione sulla sottocartella
                     
                    visitaRicorsiva(percorsoAggiuntivo);
                }
                else
                {
                    // è un file richiamo la configuraione di default per ottenre tutte l'informazioni
                    scriviNelFile(PERCORSOREPORTCARTELLA, configurazioneDefault(percorsoAggiuntivo));
                }
            }
        }
        closedir(dir);
    }
    return -1;
}

int creaReportAnalisi(){
    int fd;
    if ((fd = open(PERCORSOREPORTCARTELLA, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU)) != -1)
    {
        close(fd);
        return 1;
    }
    perror("ERRORE creazione report");
    return -1;
}

int verificaCartella(char *filePath){
    DIR *dir;
    if ((dir = opendir(filePath)) != NULL)
    {
        closedir(dir);
        return 1;
    }
    else
        return 0;
}

int scriviNelFile(char *pathFile, char *testo){
    int fd;
    if ((fd = open(pathFile, O_WRONLY | O_APPEND, S_IRWXU)) != -1)
    {
        if (write(fd, testo, strlen(testo)) != -1)
        {
            close(fd);
            return 1;
        }
        else
            perror("ERRORE scrittura fila:");
            return -1;
    }
    else
    {
        perror("ERRORE apertura file:");
        return -1;
    }
}