#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "environment/environment.h"

char* get_file_content(char path[]){

    char* env_path = get_environment();
    int len = strlen(env_path) + strlen(path);
    char* full_path =(char*) malloc(len +1);
    if(!full_path){
        printf("cannot find file path");
        exit(EXIT_FAILURE);

    }
    strcpy(full_path, env_path);
    strcat(full_path, path);

    free(env_path);
    
    
    FILE* fptr;
    fptr = fopen(full_path, "rb");
    if(!fptr){
        printf("unable to find filesize for file: %s", full_path);
    }
    fseek(fptr, 0, SEEK_END);
    int size = ftell(fptr) + 1;
    char* content = malloc(size);
    fclose(fptr);

    
    //get username
    fptr = fopen(full_path, "r");
    if(!fptr){
        printf("unable to get content from file: %s", full_path);
    }
    size_t read = fread(content, 1 , size, fptr);
    fclose(fptr);
    
    content[read] = '\0';
    if(strcmp(content, "") == 0 && strcmp(path, "/help_file.txt") != 0){
        printf("No prior user found, please provide username\n");
        return content;
    }

    free(full_path);

  


    return content;


}