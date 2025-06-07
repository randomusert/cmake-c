#include <stdlib.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>

#include "./lib/file.h"
#include "./lib/http.h"

#define BUFFER_SIZE 104857600
#define SRC_DIR "./src/"