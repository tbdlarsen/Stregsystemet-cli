#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "endpoints.h"

//API enum and array
enum API_ENDPOINTS{
	MEMBER_INFO,
	BALANCE,
	PREV_SALES,
	GET_ID,
	GET_QR,
	ACTIVE_PRODUCTS,
	BUY,
};

static char* endpoint_string[] = {
	//GET based on member ID
	"https://stregsystem.fklub.dk/api/member?member_id=",
	//GET based on member ID
	"https://stregsystem.fklub.dk/api/member/balance?member_id=",
	//GET based on member ID 
	"https://stregsystem.fklub.dk/api/member/sales?member_id=",
	//GET based on username
	"https://stregsystem.fklub.dk/api/member/get_id?username=",
	//GET based on username and amount
	"https://stregsystem.fklub.dk/api/member/payment/qr?username=__&amount=__",
	//Get based on room id
	"https://stregsystem.fklub.dk/api/products/active_products?room_id=",
	//POST based on member id, buystring and room id.
	"https://stregsystem.fklub.dk/api/sale",
	
};







int main(int argc, char* argv[]){
			
	//username
	char* user = "-u";

	//product
	char* product = "-p";

	char* qr = "qr";

	CURL* curl;
	CURLcode result;

	curl = curl_easy_init();
	if(curl == NULL){
		fprintf(stderr, "HTTP request failed\n");
		return -1;
	}


	//endpoints 
	if (strcmp(argv[1], user) == 0){
		char* username = get_api_url(endpoint_string[GET_ID], argv[2]);
		printf("api url: %s \n", username);		
		curl_easy_setopt(curl, CURLOPT_URL, username);
		free(username);
	}
	result = curl_easy_perform(curl);
	
	if(result != CURLE_OK){
		fprintf(stderr, "Error: %s \n", curl_easy_strerror(result));
		return -1;
	}

	curl_easy_cleanup(curl);
	
	return 0;
}
