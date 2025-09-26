#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void list_all_items(char* items){

    char* name_string = "\"name\": \"";
    char* name_end_string = "\"";
    char* price_string = "\"price\": ";

    char* start = items;
    printf("List of all products:\n");

    while (!(start< items)){
        char* name = strstr(start, name_string);
        if(!name){
            return;
        }
    
    name += strlen(name_string);

    char* name_end = strstr(name, name_end_string);
    if(!name_end){
        printf("name end not found (list all) \n");
        exit(EXIT_FAILURE);
    }
    start = name_end;
    

    size_t len = name_end-name; 

    char* product_name = malloc(len+1);
    strncpy(product_name,name,len);
    product_name[len] = '\0';

    printf("%s \n", product_name);
    free(product_name);
    }
    
    return;

}