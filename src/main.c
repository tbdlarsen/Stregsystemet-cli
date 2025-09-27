#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "api/endpoints.h"
#include "api/call_api.h"
#include "api/sale_body.h"
#include "commands/user_info.h"
#include "commands/commands.h"
#include "environment/environment.h"
#include "file_interaction/get_file_content.h"
#include "file_interaction/overwrite_file_content.h"

enum COMMANDS{
	USER,
	BUY,
	BALANCE,
	QR_CODE,
	ROOM,
	ACTIVE_PRODUCTS,
	PREV_SALES,
	HELP,
};
	
static char* commands[] = {
	"-u",
	"-p",
	"-bal",
	"-qr",
	"-room",
	"-a",
	"-prev",
	"-h",
	
};





int main(int argc, char* argv[]){
	environment();
	
	if (argc == 1){
		fprintf(stderr, "Missing arguments arguments\n");
		return -1;
	}

	char* user_id = get_file_content("data/user_id.txt");
	char* user_info = get_user_info(user_id);
	free(user_id);
	free(user_info);

	//endpoints 
	//run all arguments;
	for(int i = 1; i < argc; i++){
		if (strcmp(argv[i], commands[USER]) == 0){
			if(i+1 < argc && argv[i+1][0] != '-'){
				overwrite_user(argv[i+1]);
				i++;
			} 
			user_command();
		}
		if(strcmp(argv[i], commands[BALANCE]) == 0){
			balance_command();	
		}
		if(strcmp(argv[i], commands[ROOM]) == 0){
			if(i+1 < argc && argv[i+1][0] != '-'){
				overwrite_file_content(argv[i+1], "data/room_number.txt", 0, strlen(argv[i+1]));
			}

			room_command();
		}
		if(strcmp(argv[i], commands[ACTIVE_PRODUCTS]) == 0){
			items_command();
		}
		if(strcmp(argv[i], commands[BUY]) == 0){
			char* items = malloc(1);
			items[0] = '\0';
			
			for(int j = i+1; j < argc; j++){
				if(argv[j][0] == '-'){
					i = j-1;
					break;
				}
				items = (char*)realloc(items, strlen(items) + strlen(argv[j])*1+2);
				strcat(items, argv[j]);
				strcat(items, " ");
			}
			
			buy_command(&items);

		}
		if(strcmp(argv[i], commands[PREV_SALES]) == 0){
			recent_command();
		}
		if(strcmp(argv[i], commands[HELP]) == 0){
			help_command();
		}
	}

	return 0;
}
