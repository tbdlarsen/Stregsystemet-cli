#include "stdio.h"


void overwrite_file_content(char content[], char path[], int start_pos, int end_pos){

FILE *fptr;

fptr = fopen(path, "w");
if (!fptr){
    printf("unable to open overwrite file: %s", path);
}


for (int i = start_pos; i < end_pos; i++){
    
    fprintf(fptr,"%c",content[i]);
   
}

fclose(fptr);
}


