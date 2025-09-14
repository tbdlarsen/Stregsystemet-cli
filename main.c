#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "endpoints.h"
#include "call_api.h"
#include "overwrite_id.h"
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
	
	if (argc == 1){
		fprintf(stderr, "Missing arguments arguments: -m \n");
		return -1;
	}

	//username
	char* user = "-u";

	//product
	char* product = "-p";

	char* qr = "-qr";


	//endpoints 
	if (strcmp(argv[1], user) == 0){
		char* endpoint = get_api_url(endpoint_string[GET_ID], argv[2]);
		printf("api url: %s \n", endpoint);		


		char* response = call_api(endpoint);
		printf("api response: %s \n", response);

		overwrite_id(response);



		free(response);
		free(endpoint);
	}
	
	
	return 0;
}
