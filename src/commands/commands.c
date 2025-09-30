#include "api/sale_body.h"
#include "api/call_api.h"
#include "api/endpoints.h"
#include "commands/commands.h"
#include "commands/user_info.h"
#include "commands/recent_bought.h"
#include "commands/list_all_items.h"
#include "file_interaction/get_file_content.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void user_command(){
    char* user_id = get_file_content("/user_id.txt");
    
   
    char* user_info = get_user_info(user_id);
    free(user_info);
    free(user_id);

    char* username = get_file_content("/user_username.txt");


    printf("Username: %s \n",username);
    balance_command();
    recent_command();    
    
    return;
}
void room_command(){
    char* room_id = get_file_content("/room_id.txt");
    printf("room id: %s\n", room_id);
    free(room_id);
}

void balance_command(){
    double balance = balance_converted();
    printf("Balance: %.2fkr \n", balance);
    return;
}

void items_command(){
    char* room_id = get_file_content("/room_number.txt");
    char* api_url = get_api_url(endpoint_string[GET_ACTIVE_PRODUCTS], room_id);
    free(room_id);
    char* response = call_api(api_url, NULL);
    free(api_url);

    list_all_items(response);
    free(response);
    return;
}

void buy_command(char** itemlist){

    char* buystring = assemble_sale_body(*itemlist);
    free(*itemlist);
    char* response = call_api(endpoint_string[POST_BUY], buystring);
    free(buystring);
    char* bal_string_start = " \"member_balance\": \"";
    
    char* price_start = strstr(response, bal_string_start);
    if(!price_start){
        printf("purchase price not found\n");
        exit(EXIT_FAILURE);
    }
    price_start += strlen(bal_string_start);

    double remaining_balance = 0;

    if(sscanf(price_start, "%lf", &remaining_balance) != 1){
        printf("balance conversion failed (buy)");
        exit(EXIT_FAILURE);
    }

    free(response);

    printf("Purchase successful \nRemaining balance: %.2lfkr \n", remaining_balance);
    



}

void recent_command(){
    char* userid = get_file_content("/user_id.txt");
    char* api_url = get_api_url(endpoint_string[GET_PREV_SALES], userid);
    char* recent = call_api(api_url, NULL);
    free(api_url);
    free(userid);

    recent_bought(recent);
    

    free(recent);
    return;
}

void help_command(){
    char* help_page = get_file_content("/help_file.txt");
    printf("%s", help_page);
    free(help_page);
    return;
}

double balance_converted(){
    char* bal = get_file_content("/user_balance.txt");
    char* end;

    double balance = strtod(bal, &end);

    if(bal == end){
        printf("balance conversion failed");
        exit (EXIT_FAILURE);
    }
    free(bal);

    balance /= 100;
    return balance;

}