#include "call_api.h"
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
	char* data_string;
	size_t size;
} Response;

size_t write_callback(void* data, size_t size, size_t nmemb, void *userdata);

char* call_api(char api_url[]){

    //setup curl
    CURL* curl;
	CURLcode result;
	curl = curl_easy_init();
	if(curl == NULL){
		fprintf(stderr, "HTTP request failed\n");
		return NULL;
	}

    //set URL
    curl_easy_setopt(curl, CURLOPT_URL, api_url);


	//setup response
	Response response;
	response.data_string = malloc(1);
	response.size = 0;

	//set memory address of response struct
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void* ) &response);

	//set callback function
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

	

    //consume api
    result = curl_easy_perform(curl);
	
	// check if response code = 200
	if(result != CURLE_OK){
		fprintf(stderr, "Error: %s \n", curl_easy_strerror(result));
		return NULL;
	}

    //cleanup
	curl_easy_cleanup(curl);

	return response.data_string;
}

size_t write_callback(void* data, size_t size, size_t nmemb, void* userdata){

	size_t real_size = size * nmemb;
	Response *resp = (Response* ) userdata;

	//allocate new data for prev response + current chunk + '0\'
	char *mem_pos = realloc(resp->data_string, resp->size + real_size +1);
	if(!mem_pos){
		fprintf(stderr, "Unable to allocate memory for HTTP response chunk");
		return -1;
	}


	//copy new data chunk right after old response ends
	resp->data_string = mem_pos;
	memcpy(&(resp->data_string[resp->size]), data, real_size);
	resp->size += real_size;
	resp->data_string[resp->size] = 0;



	return real_size;
}

