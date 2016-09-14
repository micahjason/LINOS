/*
  Author : Micah Kangogo
  e-mail : kangogomicah@gmail.com
*/

#include "head.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int consult_payment(char * ticket_id, char * foreign_key );
char * transaction_socket(char * end_point_file, char * params, char *outputstring);
int curl_client(char * end_point_file, char * param1, char * param2, char * output_fd);
int xml_parser(char * file_path );
char * receipt_number(char * str);

int consult_payment(char * ticket_id, char * foreign_key ){
	bool pay;
	char * ret;
	int selected;
	char * str =NULL;
	
	str = malloc(300);
	
	char *menu[]={
				  "YES",
				  "NO",
		};
	
	//curl_client
	if (!curl_client("consult_payment.cfg",ticket_id,NULL,"consult_response.xml")){
	// 1. process xml reponse
	// 2. determine amount
	// 3. Display response to customer
	// 4. confirm payment
	
		printf("curl_client successful   \n");//,curl_client("consult_payment.cfg",ticket_id,NULL,"consult_response.xml"));
		sprintf(str,"/home/jason/Documents/Research/Demo/%s.xml","consult_response");
		printf("%s\n",str);
		if(xml_parser(str))
		{
		printf ("TicketID : %s\n",s_b->TicketID);
		printf ("Epan : %s\n",s_b->Epan);
		printf ("ParkingName : %s\n",s_b->ParkingName);
		printf ("EntryFacility : %s\n",s_b->EntryFacility);
		printf ("EntryTime : %s\n",s_b->EntryTime);
		printf ("Duration : %s\n",s_b->Duration);
		printf ("Amount : %s\n",s_b->Amount);
		}
		else{
			return 0;
		}
		
	}
	else{
		//printf("transaction_socket not successful  %d \n",curl_client("consult_payment.cfg",ticket_id,NULL,NULL,NULL));
		
		return 0;
	}
	
	//if(strcmp())
	
	if(!lcd_menu(menu, "\tProceed for Payment ?",2)){
		//consult_payment.cfg
		// Fetch foreign key --- receipt number
		char * string = NULL;
		string = receipt_number(string);
		sprintf(foreign_key,"%s",string);
		if(!curl_client("consult_payment.cfg",ticket_id,foreign_key,"payment_response.xml")){
			
			sprintf(str,"/home/jason/Documents/Research/Demo/%s.xml","payment_response");
			printf("%s\n",str);
			if(xml_parser(str)){
			//xml_parser("/home/jason/Documents/Research/Demo/payment_response.xml");
			printf ("TicketID : %s\n",s_b->TicketID);
			printf ("Epan : %s\n",s_b->Epan);
			printf ("ParkingName : %s\n",s_b->ParkingName);
			printf ("EntryFacility : %s\n",s_b->EntryFacility);
			printf ("EntryTime : %s\n",s_b->EntryTime);
			printf ("Duration : %s\n",s_b->Duration);
			printf ("Amount : %s\n",s_b->Amount);
			printf ("Errorcode : %s\n",s_b->Errorcode);
			printf ("Description : %s\n",s_b->Description);
			return 1;
			}
			else{
			}
		}
		else
			return 0;
		
	}
	else
	{
	 return 0;
	}
	
	return 1;
}
