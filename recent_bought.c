
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void recent_bought(const char* input){
    
    const char* time_string = "\"timestamp\": \"";
    const char* prod_string = "\"product\": \"";
    const char* price_string = "\"price\": ";
    const char* end_string = "\"";
    

    char hour[3], minute[3], day[3], month[3];
    char product[100] = {0};
    char price[6] = {0};
    
    //get time of purchase
    char* time_start = strstr(input, time_string);
    if(!time_start){
        printf("purchase time not found");
        exit(EXIT_FAILURE);
    }
    time_start += strlen(time_string);
    sscanf(time_start, "%*4d-%2s-%2sT%2s:%2s", month, day, hour, minute);

   


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
        printf("purchase price not found");
        exit(EXIT_FAILURE);
    }
    price_start += strlen(price_string);
    char* price_end = strstr(price_start, "}");
    size_t price_len = price_end-price_start;
    strncpy(price, price_start, price_len);
    price[price_len] = '\0';

    char* end;

    double balance = strtod(price, &end);

    if(price == end){
        printf("balance conversion failed");
        exit (EXIT_FAILURE);
    }


    balance /= 100;

    printf("Most recent purchase: \n");
    printf("    Time of purchase: %s:%s %s-%s \n", hour, minute, day, month);
    printf("    Product: %s \n", product);
    printf("    Price: %.2lf kr \n", balance);


    return;

}
