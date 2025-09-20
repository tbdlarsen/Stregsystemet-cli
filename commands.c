#include "commands.h"
#include "file_interaction/get_file_content.h"
#include "user/user_info.h"
#include <stdlib.h>
#include <stdio.h>

void user_command(){
    char* user_id = get_file_content("user_id.txt");
    char* user_info = get_user_info(user_id);
    printf("user_info: %s \n", user_info);
    free(user_info);
    free(user_id);
    return;
}
void room_command(){
    char* room_id = get_file_content("room_number.txt");
    printf("room id: %s \n", room_id);
    free(room_id);
}

void balance_command(){
    char* bal = get_file_content("user_balance.txt");
    char* end;

    double balance = strtod(bal, &end);

    if(bal == end){
        printf("balance conversion failed");
        exit (EXIT_FAILURE);
    }
    free(bal);

    balance /= 100;
    char* username = get_file_content("user_username.txt");
    printf("Balance available for user %s: %.2fkr \n",username, balance);
    
    free(username);

    return;
}