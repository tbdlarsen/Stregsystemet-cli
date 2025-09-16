#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "api/endpoints.h"
#include "api/call_api.h"
#include "user/overwrite_id.h"
#include "user/user_info.h"
#include "api/sale_body.h"

enum COMMANDS{
	USER,
	BUY,
	BALANCE,
	QR_CODE,
};
	
static char* commands[] = {
	"-u",
	"-p",
	"-bal"
	"-qr"
};





int main(int argc, char* argv[]){
	
	if (argc == 1){
		fprintf(stderr, "Missing arguments arguments\n");
		return -1;
	}

	
	//endpoints 
	//run all arguments; 
	char* user_id = NULL;
	for(int i = 1; i < argc; i+=2){
		if (strcmp(argv[i], commands[USER]) == 0){
			if(argc != 2){
				overwrite_user(argv[i+1]);
				
			} 
			user_id = get_user_id();

			char* user_info = get_user_info(user_id);
			printf("user_info: %s \n", user_info);
			free(user_info);

		}


	}

	
	


	
	free(user_id);
	return 0;
}
