#include "commands.h"
#include "file_interaction/get_file_content.h"
#include "user/user_info.h"
#include "api/sale_body.h"
#include "api/call_api.h"
#include "api/endpoints.h"
#include <stdlib.h>
#include <stdio.h>

void user_command(){
    char* user_id = get_file_content("user_id.txt");
   
    char* user_info = get_user_info(user_id);
    free(user_info);
    free(user_id);

    char* username = get_file_content("user_username.txt");


    printf("Username: %s \n",username);
    balance_command();
    
    
    return;
}
void room_command(){
    char* room_id = get_file_content("room_number.txt");
    printf("room id: %s \n", room_id);
    free(room_id);
}

void balance_command(){
    double balance = balance_converted();
    printf("Balance: %.2fkr \n", balance);
    return;
}

void items_command(){
    char* room_id = get_file_content("room_number.txt");
    char* api_url = get_api_url(endpoint_string[GET_ACTIVE_PRODUCTS], room_id);
    free(room_id);
    char* response = call_api(api_url, NULL);
    free(api_url);
    printf("%s \n", response);
    free(response);
    return;
}

void buy_command(char** itemlist){

    char* buystring = assemble_sale_body(*itemlist);
    free(*itemlist);
    char* response = call_api(endpoint_string[POST_BUY], buystring);
    free(buystring);

    printf("%s \n", response);
    free(response);



}

double balance_converted(){
    char* bal = get_file_content("user_balance.txt");
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