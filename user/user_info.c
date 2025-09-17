#include "user_info.h"
#include "../api/endpoints.h"
#include "../api/call_api.h"
#include "../file_interaction/overwrite_file_content.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void overwrite_user(char* username){

    char* endpoint = get_api_url(endpoint_string[GET_ID], username);
    char* body = NULL;
    char* response = call_api(endpoint, body);

    char path[] = "user_id.txt";
    int start_pos = 14;
    int end_pos = strlen(response)-1;

    overwrite_file_content(response, path, start_pos,end_pos);

    
    free(endpoint);
    free(response);
    return;
}


char* get_user_info(char* user_id){

    
    char* real_url = get_api_url(endpoint_string[GET_MEMBER_INFO], user_id);
    char* body = NULL;
    char* response = call_api(real_url, body);





    return response;


}