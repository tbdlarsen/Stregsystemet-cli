
#ifndef ENDPOINT_H
#define ENDPOINT_H

char* get_api_url(char endpoint[], char user[]);



enum API_ENDPOINTS{
	GET_MEMBER_INFO,
	GET_BALANCE,
	GET_PREV_SALES,
	GET_ID,
	GET_QR,
	GET_ACTIVE_PRODUCTS,
	POST_BUY,
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


#endif

