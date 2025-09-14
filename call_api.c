#include "call_api.h"
#include <curl/curl.h>



void call_api(char api_url[]){

    //setup curl
    CURL* curl;
	CURLcode result;

	curl = curl_easy_init();
	if(curl == NULL){
		fprintf(stderr, "HTTP request failed\n");
		return;
	}

    //set option
    curl_easy_setopt(curl, CURLOPT_URL, api_url);


    //consume api
    result = curl_easy_perform(curl);
	
	if(result != CURLE_OK){
		fprintf(stderr, "Error: %s \n", curl_easy_strerror(result));
		return;
	}

    //cleanup
	curl_easy_cleanup(curl);

}