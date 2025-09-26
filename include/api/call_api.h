#include <stddef.h>

#ifndef call_api_H
#define call_api_H


size_t write_callback(void* data, size_t size, size_t nmemb, void *userdata);
char* call_api(char api_url[], char* body);



#endif
