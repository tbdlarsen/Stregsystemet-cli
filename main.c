#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "api/endpoints.h"
#include "api/call_api.h"
#include "api/sale_body.h"
#include "user/user_info.h"
#include "file_interaction/get_file_content.h"
#include "file_interaction/overwrite_file_content.h"
#include "commands.h"

enum COMMANDS{
	USER,
	BUY,
	BALANCE,
	QR_CODE,
	ROOM,
};
	
static char* commands[] = {
	"-u",
	"-p",
	"-bal",
	"-qr",
	"-room",
};





int main(int argc, char* argv[]){
	
	if (argc == 1){
		fprintf(stderr, "Missing arguments arguments\n");
		return -1;
	}

	char* user_id = get_file_content("user_id.txt");
	char* user_info = get_user_info(user_id);
	free(user_id);
	free(user_info);

	//endpoints 
	//run all arguments;
	for(int i = 1; i < argc; i++){
		if (strcmp(argv[i], commands[USER]) == 0){
			if(argv[i+1][0] != '-' && i+1 <= argc){
				overwrite_user(argv[i+1]);
				i++;
			} 

			char* user_id = get_file_content("user_id.txt");
			char* user_info = get_user_info(user_id);
			printf("user_info: %s \n", user_info);
			free(user_info);
			free(user_id);

		}
		if(strcmp(argv[i], commands[BUY]) == 0){
		
			char* buystring = assemble_sale_body(argv[i+1]);
			i++;
			char* response = call_api(endpoint_string[POST_BUY], buystring);


			printf("%s", response);
			free(buystring);
			free(response);

		}
		if(strcmp(argv[i], commands[BALANCE]) == 0){
			char* bal = get_file_content("user_balance.txt");
			char* end;

			double balance = strtod(bal, &end);

			if(bal == end){
				printf("balance conversion failed");
				return EXIT_FAILURE;
			}
			free(bal);

			balance *= 0.01;
			char* username = get_file_content("user_username.txt");
			printf("Balance available for user %s: %.2fkr \n",username, balance);
			
			free(username);
		}
		if(strcmp(argv[i], commands[ROOM]) == 0){
			char* room_id = get_file_content("room_number.txt");
			printf("room id: %s \n", room_id);
			free(room_id);
		}


	}

	
	


	
	
	return 0;
}
