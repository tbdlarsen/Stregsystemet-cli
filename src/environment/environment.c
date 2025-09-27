#include "environment/environment.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define TXT_FILES 5
#define LINUX_FOLDER_NAME "/.local/share/sclien"

const char* files[] = {
    "help_file.txt",
    "room_id.txt",
    "user_balance.txt",
    "user_id.txt",
    "user_name.txt",
};

char* environment(){
    const char* home = getenv("HOME");
    if(!home){
        printf("$HOME envionment not found");
        exit(EXIT_FAILURE);
    }
    
    
    char folder_path[512];
    snprintf(folder_path, sizeof(folder_path), "%s%s", home, LINUX_FOLDER_NAME);
    int len = strlen(home) + strlen(LINUX_FOLDER_NAME);
    folder_path[len] = '\0';
    printf("environment: %s \n", folder_path);

    struct stat st = {0};
    if (stat(folder_path, &st) == -1){
        if(mkdir(folder_path, 0700) == -1){
            printf("could not create folder");
            exit(EXIT_FAILURE);
        }

    }

    for(int i = 0; i< TXT_FILES; i++){
        char file_path[1024];
        snprintf(file_path, sizeof(file_path), "%s/%s", folder_path, files[i]);

        if(access(file_path, F_OK) != 0){
            FILE* fp = fopen(file_path, "w");
            if(!fp){
                printf("could not create txt file");
                exit(EXIT_FAILURE);

            }
            fclose(fp);

        }

    }




    return folder_path;



}