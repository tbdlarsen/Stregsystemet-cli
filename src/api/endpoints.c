
#include "api/endpoints.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



char* get_api_url(char endpoint[], char user[]){

	//allocate size + '\0' termination (1)
	const unsigned int SIZE = strlen(endpoint)+ strlen(user) + 1;
	char* result = malloc(SIZE);
	if (!result){
		printf("allocation error in username API");
	}

	strcpy(result, endpoint);
	strcat(result, user);
	return result;
}


