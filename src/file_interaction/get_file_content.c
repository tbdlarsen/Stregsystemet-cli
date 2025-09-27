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
    printf("Full path %s \n", full_path);
    free(full_path);

    exit(EXIT_SUCCESS);
    
    FILE* fptr;
    fptr = fopen(path, "rb");
    if(!fptr){
        printf("unable to find filesize for file: %s", path);
    }
    fseek(fptr, 0, SEEK_END);
    int size = ftell(fptr) + 1;
    char* content = malloc(size);
    fclose(fptr);


    //get username
    fptr = fopen(path, "r");
    if(!fptr){
        printf("unable to get content from file: %s", path);
    }
    size_t read = fread(content, 1 , size, fptr);
    fclose(fptr);
    
    content[read] = '\0';

    return content;


}