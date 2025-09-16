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


char* get_user_info(char* user_id){

    
    char* real_url = get_api_url(endpoint_string[GET_MEMBER_INFO], user_id);
    
    char* response = call_api(real_url);


    return response;


}