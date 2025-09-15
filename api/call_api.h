#include <stddef.h>

#ifndef CALL_API_H
#define CALL_API_H


size_t write_callback(void* data, size_t size, size_t nmemb, void *userdata);
char* call_api(char api_url[]);



#endif
