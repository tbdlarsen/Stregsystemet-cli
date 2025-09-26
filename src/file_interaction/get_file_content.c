#include <stdio.h>
#include <stdlib.h>


char* get_file_content(char path[]){

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