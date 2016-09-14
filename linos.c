/*
* Author : Micah Kangogo
  e-mail : kangogomicah@gmail.com
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"
#include "cJSON.h"

int consult_payment(char * ticket_id, char * foreign_key );
void json_parser(char * ret_val);
char ** create_menu(char **menu_item, char *menu_capt, int i);
int db_connection(char *sql, char * DB );
char * calculate_time_difference(char *entry_time, char *exit_time);
int read_db(char *sql, char *Db);
char * sys_time(void);
char * sys_time();
void file_operations(char * content, char * file_name);
char * client_socket(char * end_point_file, char * param);
void read_config(char * file_name);
void init(char *);
void upper_string(char s[]);
void data_capture();
int lcd_menu(char ** menu,char * str, int j);
int login();
char * user_details( char *end_point_file, char * param);
void payment_system();
char * key_board(char * str,char * buffer);
void remove_new_line(char* string);
char * transaction_socket(char * end_point_file, char * param1, char *param2);


int selected;


char *menu[]={
				  "SYSTEM PROGRAMS", // 1. REVENUE COLLECTION 2. PAYMENTS 3. DATA CAPTURE
				  "SYSTEM SERVICES", // 1. LOAD CARD 2. REGISTER USER 3. 
				  "SYSTEM UPDATES", //  1. TARRIF SETTING 2. NEW PROGRAMS 3. NEW SERVICES 4. 
				  "SYSTEM SETTINGS",//  1. NETWORK SETTINGS 2. 
				  "USER LOGOUT",    // 	1.  NEW USER LOGIN
				  "CLOSE SYSTEM",	// 	COMPLETETELY EXIT FROM SYSYTEM
		};
char *menu1[]={
				  "VEHICLE ENTRY",
				  "VEHICLE EXIT",
				  "SYTSEM REPORTS",
	 			  "SYTSEM UPDATES",
				  "QUIT !",
		};

char *menu2[]={
				  "REVENUE SYSTEM",
				  "PAYMENT SYSTEM",
				  "MOBILE CANTEEN",
				  "DATA CAPTURE",
	 			  "DEVICE CONTROL",
				  "QUIT !",
		};
	
char *menu_report[]={
				  "X REPORT",
				  "Z REPORT",
				  "QUIT !",
		};

int main()

{
	//int selected;
	db = "demo.db";
	
	str=malloc(100);
	sql=malloc(1000);

//printf("System time = %s\n",system_time);
	
	// generate databases
	
	//sql_statement(sql,db);
	
	//insert into txn_table (user_id,name,device_date,txn_id,payment_channel,payment_variable,amount,device_id) values('0','Micah Kangogo','2016:09:02:15:14:31','123456789','CASH PAYMENT','TICKET NUMBER','1234','1234567');
	
	
	/*
		1. create login screan
		2. create start menu
	*/
	init(db);
	
	LOGIN:
	lios_login = 0;
	ret=login();
	//printf("\n username: %s  password: %s  \n",username,password);

	lios_login =1;
	
	if(lios_login){
	while(1){
		// begining of everything
		PROGRAMS:
		selected = lcd_menu(menu,"\tPAYTECH DEMO",6);
		
		switch(selected){
				
			case 0:
				
				/*
				Programs
				1. REVENUE SYSTEM
				2. PAYMENT SYSTEM
				3. DATA CAPTURE
				4. DEVICE CONTROL
				5. QUIT !
				*/
				// Where is my transport --- south african system
				
				while(1){
					selected = lcd_menu(menu2,"\tPROGRAMS",6);
					switch(selected){
					case 0:
						//revenue system
						payment_system();
						printf("\nrevenue system\n");
						//return;
					break;
					
					case 1:
						//payment system
						payment_system();
						printf("\npayment system\n");
					break;
					
							
					case 2:
						//mobile canteen
						/*
						1. Register customer --- card personalising
						2. upadte card --- first card load
						3. verify card
						3. load ---- purchase ---- balance
						4. update card
						5. close
						
						*/
						printf("\nmobile canteen\n");
					break;		
					
					case 3:
						//data capture
						data_capture();	
					break;
						
					case 4:
						//device control
						printf("\ndevice control\n");
					break;
					
					case 5:
						//quit
							printf("\nquit\n");
						goto PROGRAMS;
					 	//selected = 5;
					break;
				
					}
				}
			
				break;
			case 1:
				
				break;
			case 2:
				printf("\nNo System Settings yet !!\n");
				sleep(1);
				break;
				
			case 3:
				//goto LOGIN;
				break;
				
			case 4:
				goto LOGIN;
				break;
				
			case 5:
				printf("\nSystem is exiting in 3 seconds. Byee--->>>\n");
				sleep(3);
			exit(0);
				break;
				
				
		}
		//read_config("config.cfg");
	
	}
}
	printf("\nInvalid login !!");
	goto LOGIN;

return 0;
}


void data_capture(){
	
	
char *system_time;
char time[20];
char *time_difference;


system_time=sys_time();
char reg[10];
//int selected;

	while(selected!=5){
	selected = lcd_menu(menu1, "\tDATA CAPTURE", 5);
	
	
	
		switch(selected){

	
		case 0:
				
			//printf("\nEntering Vehicle:");
			printf("\nEnter Vehicle registration number :");
			fgets(reg, sizeof(reg), stdin);
			strip_extra_spaces(reg);
			printf("\nEntering Vehicle:");
			system_time=sys_time();
			// check period of the day
			upper_string(reg);
			//sprintf(sql,"SELECT entry_time_lpn from inventory_table where lpn = '%s';",reg);
			printf("\n sql %s ",sql);
			db_connection(sql, db);
				
			if(!count){
			period=calculate_time_difference(system_time,"0-0-0-0-0-0");
			printf("\n %s is period \n",period);
			printf("\n %s is system_time \n",system_time);
			printf("\n %s is reg \n",reg);
			//sql=malloc(300);
			
			sprintf(sql,"INSERT into inventory_table(entry_time,entry_time_lpn,exit_time,lpn,entry_period) values('%s','%s','%s','%s','%s');",system_time,system_time,"0",reg,period);
			//printf("\n sql %s ",sql);
			db_connection(sql, db);
			strcpy(reg,"");
			}
			else{
			printf("Vehicle already registered. Please try again.\n");
			strcpy(reg,"");
			//printf("Please try again");
			sleep(2);
			}
			break;
			
		case 1:

			printf("\nExiting Vehicle:");
			printf("\nEnter Vehicle registration number :");
			
			fgets(reg, sizeof(reg), stdin);
			strip_extra_spaces(reg);
			//gets(reg);
			upper_string(reg);
			strcpy(entry_time_lpn,"");
			sprintf(sql,"SELECT entry_time_lpn , exit_time from inventory_table where lpn = '%s' and exit_time = '%s';",reg,"0");
			//printf("\n sql %s ",sql);
			db_connection(sql, db);
			
			printf("\n entry_time_lpn  %s  exit_time_lpn  %s",entry_time_lpn,exit_time_lpn);
			
			
			if(count){
			printf("\n entry_time_lpn %s ",entry_time_lpn);
			system_time=sys_time();
			period=calculate_time_difference(system_time,"0-0-0-0-0-0");
			duration=calculate_time_difference(entry_time_lpn,system_time);
			sprintf(sql,"UPDATE inventory_table set exit_time = '%s', exit_period='%s', duration = '%s' , entry_exit = '1' where lpn = '%s';",system_time,period,duration,reg);
			printf("\n sql %s ",sql);
			db_connection(sql, db);
			
			// create csv file
			
			sprintf(sql,"SELECT entry_time_lpn,exit_time,entry_period,exit_period,duration from inventory_table where lpn = '%s';",reg);
			//printf("\n sql %s ",sql);
			db_connection(sql, db);
			
			printf("\nentry_time_lpn : %s exit_time : %s entry_period : %s exit_period : %s duration : %s\n",entry_time_lpn,exit_time_lpn,entry_period,exit_period,duration);
			
			sprintf(sql,"%s,%s,%s,%s,%s,%s#",reg,entry_time_lpn,exit_time_lpn,entry_period,exit_period,duration);
			
			printf("\n csv %s ",sql);
			
			strcpy(reg,"");
			printf("\n now->year %s ",now->year);
			printf("\n now->month %s ",now->month);
			printf("\n now->day %s ",now->day);
			
			sprintf(str,"%s:%s:%s.csv",now->year,now->month,now->day);
			
			file_operations(sql,str);
			ret_val = NULL;
			ret_val = client_socket("config.cfg",str);
			printf("ret_val :%s\n",ret_val);
			
			// Process JSON file
			json_parser(ret_val);
				
			}
			
			else{
				
				printf("\n Exiting vehicle was not registered or \n already exited");
				printf("\n Please try again");
				strcpy(reg,"");
				sleep(2);
			}
				
			break;
		
		case 2:
				
			//choice="";
			//printf("\n %s is chosen \n",choice);
			//strcpy(choice,"");
			
			selected = lcd_menu(menu_report, "\tREPORTS",3);
			
			//printf("\nChoose an option and press ENTER:");
			
			//gets(choice);
			
			while(selected<2){
			switch(selected){
				case 0:
				
				/*
					print data snapshot
					1. Select lpn, period, duration from inventory where entry_exit =1
					2. Print results
				
				*/
				
				lpn=0;
				entry_time=0;
				lpn_duration=0;
				
				sprintf(sql,"%s","SELECT lpn, duration from inventory_table where entry_exit = '1';");
				printf("\n sql %s ",sql);
				db_connection(sql, db);
				printf("\n count %d \n",count);
				for(i=0;i<count;i++){
					printf("\n lpn :%s lpn_duration :%s \n",lpn[i],lpn_duration[i]);
				}

				break;
		
				case 1:
			
				lpn=0;
				entry_time=0;
				
				sprintf(sql,"%s","SELECT exit_time, lpn from inventory_table;");
				printf("\n sql %s ",sql);
				db_connection(sql, db);
				printf("\n count %d \n",count);
				
				for(i=0;i<count;i++){
					printf("\n lpn :%s exit time :%s \n",lpn[i],exit_time[i]);
				}
			
				/*
					POST data
					1. Select Protocol,IP,PORT,endpoint
						1. Read config file
					2. Prepare request
					3. Post data
				
				*/
			
				//read_config("config.cfg");
			
				printf("\n network method : %s\n",def_public->method);
				printf("\n network protocol : %s\n",def_public->protocol);
				printf("\n network ip : %s\n",def_public->ip);
				printf("\n network port : %s\n",def_public->port);
				printf("\n network endpoint : %s\n\n\n",def_public->endpoint);
			
				period=calculate_time_difference(system_time,"0-0-0-0-0-0");
				sprintf(str,"%s:%s:%s.csv",now->year,now->month,now->day);
				ret_val = client_socket("config.cfg",str);
				
				break;
				case 2:
					
				break;
			
				}
			break;	
			}	
				
			break;
		
		case 3:
		
			printf("No System updates now.\nPlease try again later");
			printf("\n ");
			sleep(3);
	
			break;
		case 4:
				//selected = 5;
				//printf("\nSystem is exiting. ---> Byee --->>>\n");
				//sleep(3);
				//exit(0);
				return;
			
			break;
				
		case 5:
			printf("\n %s is chosen \n",choice);
			strcpy(choice,"");
		
			break;
		
		default:
			printf("\n %s is chosen \n",choice);
			strcpy(choice,"");
				
			break;
		}
	}
	selected= 5;
}

void data_analysis(){

}
int login(){
	cJSON * jLogin;
	char * outputstring = 0;
	char * string = 0;
	
	/*
	
	// For offline login
	
	printf("\n username: %s  password: %s  \n",username,password);
	sprintf(sql,"SELECT username , password from users_table where username = '%s' and password = '%s'",username,password);
	printf("\n sql %s ",sql);
	ret=sql_statement(sql,db);
	
	*/
	
	// For online login
	jLogin = cJSON_CreateObject();
	//cJSON_AddStringToObject (jLogin,"deviceId",serial_num);
	string = key_board("Username",string);
	cJSON_AddStringToObject (jLogin,"userName",string);
	string = key_board("Password",string);
	cJSON_AddStringToObject (jLogin,"userPwd",string);
	outputstring=cJSON_PrintUnformatted(jLogin);
	printf("%s\n", outputstring);
	//http://127.0.0.1:8080/rest/login?login_id={"userName":"jason","userPwd":"jason"}
	ret_val=0;
	strip_extra_spaces(outputstring);
	
	ret_val = user_details("login.cfg",outputstring);

	return 0;
}

void payment_system(){
	
	char *menu2[]={
				  "CASH PAYMENT",
				  "MOBILE PAYMENT",
				  "SMART CARD",
				  "BITCOINS",
		};
	
	char *menu4[]={
				  "MPESA MONEY",
				  "AIRTEL MONEY",
				  "e-WALLET",
		};
	
	char *menu3[]={
				  "TICKET NUMBER",
				  "LPN",
				  "QR / BARCODE",
		};
	
	
	char *string = 0;
	cJSON * jLogin = 0;
	char * outputstring =0;
	char * system_time =0;
	char ticket_number[20];
	char amount[20];
	char lpn[20];
	char barcode_qr[20];
	char payment_variable[20];
	char payment_channel[20];
	char phone_number[20];
	char str[300];
	char card_number[20];
	char ini_bal[20];
	char final_bal[20];
	char bal[20];
	char service_provider[20];
	int ret;
	
	system_time=sys_time();
	jLogin = cJSON_CreateObject();
	cJSON_AddStringToObject (jLogin,"userId","0");
	cJSON_AddStringToObject (jLogin,"name","Micah Kangogo");
	cJSON_AddStringToObject (jLogin,"device_id","1");
	cJSON_AddStringToObject (jLogin,"device_date",system_time);
	cJSON_AddStringToObject (jLogin,"program_id","1");
	
	//while (1){
	selected = lcd_menu(menu3, "\tPAYMENT VARIABLE", 3);
	strcpy(payment_variable,menu3[selected]);
	cJSON_AddStringToObject (jLogin,"PAYMENT VARIABLE",payment_variable);
	
	//while (selected < 4){
	switch(selected){
	
		case 0:
			
			//printf("\nEnter ticket number\n");
			string = key_board("Enter ticket number",string);
			printf("\n string %s \n",string);
			strcpy(ticket_number,string);
			cJSON_AddStringToObject (jLogin,"TicketNumber",ticket_number);
			selected = lcd_menu(menu2, "\tPAYMENT CHANNELS",4);
			strcpy(payment_channel,menu2[selected]);
			printf("menu2[selected]  %s\n",menu2[selected]);
			
			if (strcmp(payment_channel,"MOBILE PAYMENT") == 0){
				printf("start mobile payment api\n");
				selected = lcd_menu(menu4, "\tSERVICE PROVIDER",3);
				strcpy(service_provider,menu4[selected]);
				if (strcmp(service_provider,"MPESA MONEY") == 0){
				
						printf("start mpesa api\n");
					// consult endpoint
					// payment endpoint
					// send command to rasperry --- json or xml string
					// rasperry to grant access
					// listen for loop transition
					// update db
					// close session
				}
				
				if (strcmp(service_provider,"AIRTEL MONEY") == 0){
				
						printf("start airtel api\n");
					// consult endpoint
					// payment endpoint
					// send command to rasperry --- json or xml string
					// rasperry to grant access
					// listen for loop transition
					// update db
					// close session
				}
				
				if (strcmp(service_provider,"e-WALLET") == 0){
				
						printf("start e-wallet api\n");
					
					// consult endpoint
					// payment endpoint
					// send command to rasperry --- json or xml string
					// rasperry to grant access
					// listen for loop transition
					// update db
					// close session
				
				}
				
				string = key_board("Enter phone number",string);
				strcpy(phone_number,string);
				cJSON_AddStringToObject (jLogin,"PAYMENT CHANNEL",payment_channel);
				cJSON_AddStringToObject (jLogin,"PHONENUMBER",phone_number);
				cJSON_AddStringToObject (jLogin,"XXXXX",amount); // return from service provider engine
				cJSON_AddStringToObject (jLogin,"TXN_ID","123456789");
				outputstring=cJSON_PrintUnformatted(jLogin);
				printf("%s\n", outputstring);
				sprintf(str,"insert into txn_table (user_id,name,device_date,txn_id,payment_channel,payment_variable,ticket_number,phone_number,amount,program_id,device_id) values('%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s');","0","Micah Kangogo",system_time,"123456789",payment_channel,payment_variable,ticket_number,phone_number,"XXXXX","123456789","1234567");
				printf("str %s\n",str);
				db_connection(str, db);
				strip_extra_spaces(outputstring);
				transaction_socket("config.cfg",NULL,outputstring);
			}
			else if (strcmp(payment_channel,"BITCOINS") == 0){
				printf("start barcode scanner and api\n");
				printf("start smartcard scanner and api\n");
				string = key_board("Scan Card",string);
				strcpy(barcode_qr,string);
				
				// send command to rasperry --- json or xml string
				// rasperry to grant access
				// listen for loop transition
				// update db
				// close session
				
				cJSON_AddStringToObject (jLogin,"PAYMENT CHANNEL",payment_channel);
				cJSON_AddStringToObject (jLogin,"BARCODE","242324");
				outputstring=cJSON_PrintUnformatted(jLogin);
				printf("%s\n", outputstring);
				strip_extra_spaces(outputstring);
				transaction_socket("config.cfg",NULL,outputstring);
			}
			else if(strcmp(payment_channel,"SMART CARD") == 0){
				printf("start smartcard scanner and api\n");
				string = key_board("Insert Card",string);
				// Read card
				// Update card
				// 
				strcpy(card_number,string);
				strcpy(ini_bal,string);
				strcpy(final_bal,string);
				strcpy(bal,string);
				
				
				// send command to rasperry --- json or xml string
				// rasperry to grant access
				// listen for loop transition
				// update db
				// close session
				
				cJSON_AddStringToObject (jLogin,"CARDNUMBER",card_number);
				cJSON_AddStringToObject (jLogin,"INI_BALANCE",ini_bal);
				cJSON_AddStringToObject (jLogin,"FINAL_BALANCE",final_bal);
				cJSON_AddStringToObject (jLogin,"BALANCE",bal);
				
				cJSON_AddStringToObject (jLogin,"PAYMENT CHANNEL",payment_channel);
				outputstring=cJSON_PrintUnformatted(jLogin);
				printf("%s\n", outputstring);
				strip_extra_spaces(outputstring);
				transaction_socket("config.cfg",NULL,outputstring);
			}
			else if(strcmp(payment_channel,"CASH PAYMENT") == 0){
				printf("start cash payment api\n");
				string = key_board("Enter Amount to pay",string);
				strcpy(amount,string);
				
				
				// send command to rasperry --- json or xml string
				// rasperry to grant access
				// listen for loop transition
				// update db
				// close session
				
				
				cJSON_AddStringToObject (jLogin,"Amount",amount);
				cJSON_AddStringToObject (jLogin,"PAYMENT CHANNEL",payment_channel);
				outputstring=cJSON_PrintUnformatted(jLogin);
				printf("%s\n", outputstring);
				strip_extra_spaces(outputstring);
				sprintf(str,"insert into txn_table (user_id,name,device_date,txn_id,payment_channel,payment_variable,ticket_number,amount,program_id,device_id) values('%s','%s','%s','%s','%s','%s','%s','%s','%s','%s');","0","Micah Kangogo",system_time,"123456789",payment_channel,payment_variable,ticket_number,amount,"123456789","1234567");
				db_connection(str, db);
				printf("str %s\n",str);
				transaction_socket("config.cfg",NULL,outputstring);
			}
			else{
				printf("No payment channel selected\n");
			}
			break;
		case 1:
			//printf("\nEnter lpn number\n");
			//jLogin = cJSON_CreateObject();
			string = key_board("Enter lpn number",string);
			strcpy(lpn,string);
			printf("\n string %s \n",string);
			
			
			// send command to rasperry --- json or xml string
			// rasperry to grant access
			// listen for loop transition
			// update db
			// close session
			
			
			cJSON_AddStringToObject (jLogin,"LPN",lpn);
			selected = lcd_menu(menu2, "\tPAYMENT CHANNELS",4);
			strcpy(payment_channel,menu2[selected]);
			cJSON_AddStringToObject (jLogin,"PAYMENT VARIABLE",menu3[selected]);
			//cJSON_AddStringToObject (jLogin,"TICKETNUMBER","EWSDEWSWW");
			printf("menu2[selected]  %s\n",menu2[selected]);
			
			if (strcmp(payment_channel,"MOBILE PAYMENT") == 0){
				printf("start mobile payment api\n");
				selected = lcd_menu(menu4, "\tSERVICE PROVIDER",3);
				strcpy(service_provider,menu4[selected]);
				if (strcmp(service_provider,"MPESA MONEY") == 0){
				
						printf("start mpesa api\n");
					
					// consult endpoint
					// payment endpoint
					// send command to rasperry --- json or xml string
					// rasperry to grant access
					// listen for loop transition
					// update db
					// close session
				}
				if (strcmp(service_provider,"AIRTEL MONEY") == 0){
				
						printf("start airtel api\n");
					// consult endpoint
					// payment endpoint
					// send command to rasperry --- json or xml string
					// rasperry to grant access
					// listen for loop transition
					// update db
					// close session
				
				}
				if (strcmp(service_provider,"e-WALLET") == 0){
				
						printf("start e-wallet api on lpn : %s\n",lpn);
					
					// consult endpoint
					// payment endpoint
					// send command to rasperry --- json or xml string
					// rasperry to grant access
					// listen for loop transition
					// update db
					// close session
					strcpy(lpn,"0719070926");
				if(!consult_payment(lpn,NULL)){
					
						printf("consult_payment not successful %d \n",consult_payment(lpn,"foreign_key"));
					
						break;
					}
				
				}
				string = key_board("Enter phone number",string);
				strcpy(phone_number,string);
				cJSON_AddStringToObject (jLogin,"PAYMENT CHANNEL",payment_channel);
				cJSON_AddStringToObject (jLogin,"PHONENUMBER",phone_number);
				cJSON_AddStringToObject (jLogin,"AMOUNT","XXXX"); // return from service provider engine
				cJSON_AddStringToObject (jLogin,"TXN_ID","123456789");
				outputstring=cJSON_PrintUnformatted(jLogin);
				printf("%s\n", outputstring);
				sprintf(str,"insert into txn_table (user_id,name,device_date,txn_id,payment_channel,payment_variable,ticket_number,phone_number,amount,program_id,device_id) values('%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s');","0","Micah Kangogo",system_time,"123456789",payment_channel,payment_variable,ticket_number,phone_number,"XXXXX","123456789","1234567");
				printf("%s\n", outputstring);
				printf("str %s\n",str);
				db_connection(str, db);				
				strip_extra_spaces(outputstring);
				transaction_socket("config.cfg",NULL,outputstring);
			}
			else if (strcmp(payment_channel,"BITCOINS") == 0){
				printf("start barcode scanner and api\n");
				cJSON_AddStringToObject (jLogin,"PAYMENT CHANNEL",payment_channel);
			}
			else if(strcmp(payment_channel,"SMART CARD") == 0){
				printf("start smartcard scanner and api\n");
				// Read card
				// Update card
				// 
				strcpy(card_number,string);
				strcpy(ini_bal,string);
				strcpy(final_bal,string);
				strcpy(bal,string);
				
				
				// send command to rasperry --- json or xml string
				// rasperry to grant access
				// listen for loop transition
				// update db
				// close session
				
				
				cJSON_AddStringToObject (jLogin,"CARDNUMBER",card_number);
				cJSON_AddStringToObject (jLogin,"INI_BALANCE",ini_bal);
				cJSON_AddStringToObject (jLogin,"FINAL_BALANCE",final_bal);
				cJSON_AddStringToObject (jLogin,"BALANCE",bal);
				
				cJSON_AddStringToObject (jLogin,"PAYMENT CHANNEL",payment_channel);
				outputstring=cJSON_PrintUnformatted(jLogin);
				printf("%s\n", outputstring);
				strip_extra_spaces(outputstring);
				transaction_socket("config.cfg",NULL,outputstring);
			}
			else if(strcmp(payment_channel,"CASH PAYMENT") == 0){
				printf("start cash payment api\n");
				string = key_board("Enter Amount to pay",string);
				strcpy(amount,string);
				
				
				// send command to rasperry --- json or xml string
				// rasperry to grant access
				// listen for loop transition
				// update db
				// close session
				
				
				cJSON_AddStringToObject (jLogin,"Amount",amount);
				cJSON_AddStringToObject (jLogin,"PAYMENT CHANNEL",payment_channel);
				outputstring=cJSON_PrintUnformatted(jLogin);
				printf("%s\n", outputstring);
				strip_extra_spaces(outputstring);
				sprintf(str,"insert into txn_table (user_id,name,device_date,txn_id,payment_channel,payment_variable,amount,program_id,lpn,device_id) values('%s','%s','%s','%s','%s','%s','%s','%s','%s','%s');","0","Micah Kangogo",system_time,"123456789",payment_channel,payment_variable,amount,"123456789",lpn,"1234567");
				printf("str %s\n",str);
				db_connection(str, db);
				transaction_socket("config.cfg",NULL,outputstring);
			} 
			else{
				printf("No payment channel selected\n");
			}
			break;
		case 2:
			//printf("\nScan card\n");
			//jLogin = cJSON_CreateObject();
			//printf("\nEnter ticket number\n");
			string = key_board("Scan card",string);
			strcpy(barcode_qr,string);
			printf("\n string %s \n",barcode_qr);
			cJSON_AddStringToObject (jLogin,"BARCODE_QR",barcode_qr);
			selected = lcd_menu(menu2, "\tPAYMENT CHANNELS",4);
			strcpy(payment_channel,menu2[selected]);
			cJSON_AddStringToObject (jLogin,"PAYMENT VARIABLE",menu3[selected]);
			printf("menu2[selected]  %s\n",menu2[selected]);
			
			if (strcmp(payment_channel,"MOBILE PAYMENT") == 0){
				printf("start mobile payment api\n");
				selected = lcd_menu(menu4, "\tSERVICE PROVIDER",3);
				strcpy(service_provider,menu4[selected]);
				if (strcmp(service_provider,"MPESA MONEY") == 0){
				
						printf("start mpesa api\n");
					// consult endpoint
					// payment endpoint
					// send command to rasperry --- json or xml string
					// rasperry to grant access
					// listen for loop transition
					// update db
					// close session
				}
				if (strcmp(service_provider,"AIRTEL MONEY") == 0){
				
						printf("start aitel api\n");
					// consult endpoint
					// payment endpoint
					// send command to rasperry --- json or xml string
					// rasperry to grant access
					// listen for loop transition
					// update db
					// close session
				
				}
				if (strcmp(service_provider,"e-WALLET") == 0){
				
						printf("start e-wallet api\n");
					
					// consult endpoint
					// payment endpoint
					
					
					
					if(!consult_payment(barcode_qr,"foreign_key")){
						printf("consult_payment not successful %d \n",consult_payment(barcode_qr,"foreign_key"));
						break;
					}
					else{
						// send command to rasperry --- json or xml string
						// rasperry to grant access
						// listen for loop transition
						// update db
						// close session
					}
				}
			
				string = key_board("Enter phone number",string);
				strcpy(phone_number,string);
				cJSON_AddStringToObject (jLogin,"PAYMENT CHANNEL",payment_channel);
				cJSON_AddStringToObject (jLogin,"PHONENUMBER",phone_number);
				cJSON_AddStringToObject (jLogin,"XXXXX",amount); // return from service provider engine
				cJSON_AddStringToObject (jLogin,"TXN_ID","123456789");
				sprintf(str,"insert into txn_table (user_id,name,device_date,txn_id,payment_channel,payment_variable,ticket_number,phone_number,amount,program_id,device_id) values('%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s');","0","Micah Kangogo",system_time,"123456789",payment_channel,payment_variable,ticket_number,phone_number,"XXXXX","123456789","1234567");
				printf("%s\n", outputstring);
				printf("str %s\n",str);
				db_connection(str, db);
				outputstring=cJSON_PrintUnformatted(jLogin);
				strip_extra_spaces(outputstring);
				transaction_socket("config.cfg",NULL,outputstring);
			}
			else if(strcmp (payment_channel,"BITCOINS") == 0){
				printf("start barcode scanner and api\n");
				
				
				// send command to rasperry --- json or xml string
				// rasperry to grant access
				// listen for loop transition
				// update db
				// close session
				
				
				cJSON_AddStringToObject (jLogin,"BARCODE_QR","EWSDEWSWW");
				cJSON_AddStringToObject (jLogin,"PAYMENT CHANNEL",payment_channel);
				outputstring=cJSON_PrintUnformatted(jLogin);
				printf("%s\n", outputstring);
				strip_extra_spaces(outputstring);
				transaction_socket("config.cfg",NULL,outputstring);
			}
			else if(strcmp(payment_channel,"SMART CARD") == 0){
				printf("start smartcard scanner and api\n");
				// Read card
				// Update card
				// 
				strcpy(card_number,string);
				strcpy(ini_bal,string);
				strcpy(final_bal,string);
				strcpy(bal,string);
				
				
				// send command to rasperry --- json or xml string
				// rasperry to grant access
				// listen for loop transition
				// update db
				// close session
				
				
				cJSON_AddStringToObject (jLogin,"CARDNUMBER",card_number);
				cJSON_AddStringToObject (jLogin,"INI_BALANCE",ini_bal);
				cJSON_AddStringToObject (jLogin,"FINAL_BALANCE",final_bal);
				cJSON_AddStringToObject (jLogin,"BALANCE",bal);
				
				
				cJSON_AddStringToObject (jLogin,"PAYMENT CHANNEL",payment_channel);
				outputstring=cJSON_PrintUnformatted(jLogin);
				printf("%s\n", outputstring);
				strip_extra_spaces(outputstring);
				transaction_socket("config.cfg",NULL,outputstring);
			}
			else if(strcmp(payment_channel,"CASH PAYMENT") == 0){
				printf("start cash payment api\n");
				string = key_board("Enter Amount to pay",string);
				strcpy(amount,string);
				
				
				// send command to rasperry --- json or xml string
				// rasperry to grant access
				// listen for loop transition
				// update db
				// close session
				
				
				cJSON_AddStringToObject (jLogin,"Amount",amount);
				cJSON_AddStringToObject (jLogin,"PAYMENT CHANNEL",payment_channel);
				outputstring=cJSON_PrintUnformatted(jLogin);
				printf("%s\n", outputstring);
				strip_extra_spaces(outputstring);
				sprintf(str,"insert into txn_table (user_id,name,device_date,txn_id,payment_channel,payment_variable,amount,program_id,qrcode,device_id) values('%s','%s','%s','%s','%s','%s','%s','%s','%s','%s');","0","Micah Kangogo",system_time,"123456789",payment_channel,payment_variable,amount,"123456789",barcode_qr,"1234567");
				printf("str %s\n",str);
				db_connection(str, db);
				transaction_socket("config.cfg",NULL,outputstring);
			}
			else{
				printf("No payment channel selected\n");
			}
			break;
		default:
			//selected = 0;
			break;
	}
}
