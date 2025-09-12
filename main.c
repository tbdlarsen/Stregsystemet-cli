#include <stdio.h>
#include <string.h>
#include <stdlib.h>



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



char* get_user(char endpoint[], char user[]){



	//allocate size + '\0' termination (1)
	const unsigned int SIZE = strlen(endpoint)+ strlen(user) + 1;
	printf("allocated size: %d \n", SIZE);
	char* result = malloc(SIZE);
	if (!result){
		printf("allocation error in username API");
	}

	strcpy(result, endpoint);
	strcat(result, user);
	return result;

	
	
}



int main(int argc, char* argv[]){
			
	//username
	char* user = "-u";

	//product
	char* product = "-p";

	char* qr = "qr";

	//endpoints 
	if (strcmp(argv[1], user) == 0){
		char* username = get_user(endpoint_string[GET_ID], argv[2]);
		printf("username: %s \n", username);		
		free(username);
	}
	
	
	


	return 0;
}
