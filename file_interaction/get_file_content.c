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
    fptr = fopen("user_id.txt", "r");
    if(!fptr){
        printf("unable to get content from file: %s", path);
    }
    fgets(content, size, fptr);
    fclose(fptr);

    return content;


}