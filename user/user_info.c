#include "user_info.h"
#include "overwrite_id.h"
#include "../api/endpoints.h"
#include "../api/call_api.h"
#include <stdlib.h>
#include <stdio.h>

void overwrite_user(char* username){

    char* endpoint = get_api_url(endpoint_string[GET_ID], username);
    char* response = call_api(endpoint);

    overwrite_id(response);

    
    free(endpoint);
    free(response);
    return;
}

char* get_user_id(){

    //get file size
    FILE* fptr;
    fptr = fopen("user_id.txt", "rb");
    if(!fptr){
        printf("unable to get user_id file size");
    }
    fseek(fptr, 0, SEEK_END);
    int size = ftell(fptr) + 1;
    char* user = malloc(size);
    fclose(fptr);


    //get username
    fptr = fopen("user_id.txt", "r");
    if(!fptr){
        printf("unable to get username from user_id file");
    }
    fgets(user, size, fptr);
    fclose(fptr);

    return user;


}

char* get_user_info(char* user_id){

    
    char* real_url = get_api_url(endpoint_string[GET_MEMBER_INFO], user_id);
    
    char* response = call_api(real_url);


    return response;


}