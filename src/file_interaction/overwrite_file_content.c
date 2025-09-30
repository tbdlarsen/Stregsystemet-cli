#include "environment/environment.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void overwrite_file_content(char content[], char path[], int start_pos, int end_pos){

    char* env_path = get_environment();
    int len = strlen(env_path) + strlen(path);
    char* full_path =(char*) malloc(len +1);
    if(!full_path){
        printf("cannot find file path");
        exit(EXIT_FAILURE);

    }
    strcpy(full_path, env_path);
    strcat(full_path, path);
    //printf("this is path %s \n", path);
    free(env_path);

    //printf("this is full path %s", full_path);
    FILE *fptr;

    fptr = fopen(full_path, "w");
    if (!fptr){
        printf("unable to open overwrite file: %s\n ", full_path);
    }
    

    for (int i = start_pos; i < end_pos; i++){
        fprintf(fptr,"%c",content[i]);
    
    }
    free(full_path);
    fclose(fptr);
}


