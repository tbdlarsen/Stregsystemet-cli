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
    "user_username.txt",
};

const char* help_page = 
    "List of commands based on parameter:\n\n\n"
    "-h                      Brings up this page.\n\n"
    "-u <username>           Gets general user information, if username is provided it overwrites the saved user.\n\n"
    "-p <buystring>          Attempts to buy what is provided in the buystring, based on saved user.\n\n"
    "-bal                    Displays the balance available for saved user.\n\n"
    "-room <number>          Displays the room id, if room id is provieded it overwrites the saved room.\n\n"
    "-a                      Lists all available products.\n\n"
    "-prev                   Displays last purchased item.\n\n";



char* get_environment(){
    const char* home = getenv("HOME");
    if(!home){
        printf("$HOME envionment not found");
        exit(EXIT_FAILURE);
    }
    
    int len = strlen(home) + strlen(LINUX_FOLDER_NAME) +1;
    char* folder_path = malloc(len +1);
    snprintf(folder_path, len, "%s%s", home, LINUX_FOLDER_NAME);

    return folder_path;

    }


void create_env(){
    char* folder_path = get_environment();
    struct stat st = {0};
    if (stat(folder_path, &st) == -1){
        if(mkdir(folder_path, 0700) == -1){
            printf("could not create folder");
            exit(EXIT_FAILURE);
        }

    }

    char file_path[1024];
    snprintf(file_path, sizeof(file_path), "%s/%s", folder_path, files[0]);
    FILE* fp = fopen(file_path, "w");
    fprintf(fp, "%s", help_page);
    fclose(fp);    


    for(int i = 1; i< TXT_FILES; i++){
        
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
    free(folder_path);
    return;
}
