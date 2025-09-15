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
		fprintf(stderr, "Missing arguments arguments: -m \n");
		return -1;
	}

	printf("arguments: %d", argc);
	//endpoints 
	if (strcmp(argv[1], commands[USER]) == 0){

		overwrite_user(argv[2]);
		
	}
	
	
	return 0;
}
