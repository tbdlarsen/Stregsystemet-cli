#include "user_info.h"
#include "overwrite_id.h"
#include "../api/endpoints.h"
#include "../api/call_api.h"
#include <stdlib.h>
#include <stdio.h>

void overwrite_user(char* username){

    char* endpoint = get_api_url(endpoint_string[GET_ID], username);
	printf("api url: %s \n", endpoint);		


    char* response = call_api(endpoint);
    printf("api response: %s \n", response);

    overwrite_id(response);

    
    free(endpoint);
    free(response);


    return;
}
