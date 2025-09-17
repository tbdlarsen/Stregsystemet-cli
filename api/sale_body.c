#include "../file_interaction/get_file_content.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char* assemble_sale_body(char buystring[]){

    char* member_id = get_file_content("user_id.txt"); 
    char* username = get_file_content("user_username.txt");
    char* room_id = get_file_content("room_number.txt");

    char* boilerplate = "{\"member_id\" : %s , \"buystring\" : \"%s %s\", \"room\" : %s}";
    int len = strlen(boilerplate)-8 + strlen(member_id) + strlen(username) + strlen(buystring) + strlen(room_id) + 1;
    char* full_buystring = malloc(len);
    if (!full_buystring){
        printf("unable to produce buy string");
        exit(EXIT_FAILURE);
    }
    snprintf(full_buystring, len, boilerplate, member_id, username, buystring, room_id);
    printf("%s \n", full_buystring);
    free(full_buystring);


    return buystring;

}