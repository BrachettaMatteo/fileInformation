#include <stdio.h>
#include <time.h>

#include <pwd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <string.h>

#include <stdlib.h>

#include <locale.h>

#include "utility.h"

#define MAX_SIZE_FILEPATH 200
#define MAX_BUFFER 10000
#define MAX_SIZE_PERMISSIONS 30

configurazioneParametri(char *filepath, char** option);
configurazioneDefault(char* pathFile);