#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[]){

//username
char* user = "-u";

//product
char* product = "-p";

//qr generation
char* qr = "-qr";

//endopoints 


	
	for (int i = 1; i < argc; i++){

		

		if (strcmp(argv[i], user) == 0){
			printf("Username: %s \n", argv[i+1]);
		}
		if (strcmp(argv[i], product) == 0){
			printf("Product: %s \n", argv[i+1]);
		}
	
	
	}


	return 0;
}
