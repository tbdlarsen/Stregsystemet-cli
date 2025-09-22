
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void recent_bought(const char* input){
    
    const char* time_string = "\"timestamp\": \"";
    const char* prod_string = "\"product\": \"";
    const char* price_string = "\"price\": ";
    const char* end_string = "\"";
    

    
    char product[100] = {0};
    char price[6] = {0};
    
    //get time of purchase
    char* time_start = strstr(input, time_string);
    if(!time_start){
        printf("purchase time not found");
        exit(EXIT_FAILURE);
    }
    time_start += strlen(time_string);
    int mon, day, hour, min;
    if (sscanf(time_start, "%*4d-%2d-%2dT%2d:%2d", &mon, &day, &hour, &min) != 4) {
    printf("timestamp parse failed\n");
    exit(EXIT_FAILURE);
}
   


    //get product name
    char* prod_start = strstr(input, prod_string);
    if(!prod_start){
        printf("purchase not found");
        exit(EXIT_FAILURE);
    }
    prod_start += strlen(prod_string);

    char* prod_end = strstr(prod_start, end_string);

    size_t prod_len = prod_end - prod_start;
    strncpy(product, prod_start, prod_len);
    product[prod_len] = '\0';

   
  
    //get price of product
    char* price_start = strstr(input, price_string);
    if(!price_start){
        printf("purchase price not found\n");
        exit(EXIT_FAILURE);
    }
    price_start += strlen(price_string);

    double balance = 0;

    if(sscanf(price_start, "%lf", &balance) != 1){
        printf("balance conversion failed");
        exit(EXIT_FAILURE);
    }

    balance /= 100;

    printf("Most recent purchase: \n");
    printf("    Time of purchase: %02d:%02d %02d-%02d \n", hour, min, day, mon);
    printf("    Product: %s \n", product);
    printf("    Price: %.2lf kr \n", balance);


    return;

}
