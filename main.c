#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "api/endpoints.h"
#include "api/call_api.h"
#include "user/overwrite_id.h"
#include "user/user_info.h"

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

	int argument_nr = 1;
	//endpoints 
	//run all arguments; 
	char* user = NULL;
	for(int i = 1; i < argc; i+=2){
		if (strcmp(argv[argument_nr], commands[USER]) == 0){
			user = argv[argument_nr+1];
			if(argc == 2){
				user = get_user_id();
				
			} else {
				user = overwrite_user(user);
			}
			
			
			
		}


	}

	printf("user: %s \n", user);
	


	
	free(user);
	return 0;
}
