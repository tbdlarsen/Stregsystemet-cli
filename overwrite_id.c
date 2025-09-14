#include "overwrite_id.h"
#include <stdio.h>
#include <string.h>


void overwrite_id(char* user_id){
FILE *fptr;

fptr = fopen("user_id.txt", "w");



//print only number to file not {"member_id :" }
int id_start = 14;
for (int i = id_start; i < strlen(user_id)-1; i++){
    
    fprintf(fptr,"%c",user_id[i]);
   
}

fclose(fptr);
}