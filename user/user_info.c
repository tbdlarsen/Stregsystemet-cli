#include "user_info.h"
#include "overwrite_id.h"
#include "../api/endpoints.h"
#include "../api/call_api.h"
#include <stdlib.h>
#include <stdio.h>

char* overwrite_user(char* username){

    char* endpoint = get_api_url(endpoint_string[GET_ID], username);
	printf("api url: %s \n", endpoint);		


    char* response = call_api(endpoint);
    printf("api response: %s \n", response);

    overwrite_id(response);

    
    free(endpoint);
    


    return response;
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
