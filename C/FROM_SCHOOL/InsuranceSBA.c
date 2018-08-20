//sort out search error
//seperate total fee i.e print the discount, if monthly fee is paid or not etc seperate in search
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#define string_length 20
#define string_length2 50
#define accidentFee 1000
#define yearly 2000
#define discount 200
struct clientInfo
{
	int id;
	char firstname[string_length];
	char lastname[string_length];
	char vehicleClass[string_length];
	char vehicle[string_length];
	int accidents;
	int totalAccidentFee;
	int totalClientFee;
	char liscenceNum[7];
	char address[string_length2];
	char yearlyFee[4];
};

int MenuChoice()//main menu 
{
    int choice;
    
   	printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("************************************************************************\n");
	printf("		   	  	 OPTION DESCRIPTION        			    \n");
    printf("************************************************************************\n\n");
    
	printf("	1               Create a new file\n");
	printf("	2               Add client info\n");
	printf("        3               View Records\n");
	printf("        4               Search for a specific record\n");
	printf("        5               Update  a client's accident count\n");
	printf("        6               Update a client's address\n");
	printf("        7               Update a client's licence plate number\n");
 	printf("        8               Delete a record\n");
 	printf("        9               Exit program\n");
   	
    printf("************************************************************************\n");
	printf("---------------------------HANSEL CAR INSURANCE-------------------------\n");
    printf("************************************************************************\n\n");

    printf("\n\n");
    printf("\n\n");
    printf("Choice:");
    
    scanf("%d",&choice);
    while((choice<1)||(choice>7))
    {
    	printf("This task is not on the list, please try again: ");
    	scanf("%d",&choice);
	}
    return choice;
}//end of function

void Result1()
{
	FILE*insurPointer;
	int i;
	struct clientInfo client={0,"","","","",0,0,0,"","",""}; 
	if ((insurPointer=fopen("broken", "wb"))==NULL)
    {
        printf("Cannot open file\n");
        exit(1);
	}
	else
	{
		for (i=0;i<=100;i++)
        {
			fwrite(&client,sizeof(struct clientInfo),1,insurPointer);
        }
		fclose(insurPointer);     
	}
	printf("************************************************************\n");
	printf("			FILE CREATED						\n");
    printf("************************************************************\n\n");	
}

void Result2()
{
	FILE*insurPointer;
	struct clientInfo client={0,"","","","",0,0,0,"","",""}; 
	if ((insurPointer=fopen("broken", "rb+"))==NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }
	  
	printf("************************************************************\n");
	printf("		ADDITION OF CLIENT INFO						\n");
    printf("************************************************************\n\n");	
	  
    printf("Enter the client's ID(between 1 and 100): \n");
    scanf("%d",&client.id);
    
    while((client.id<1)||(client.id>100))
    {
    	printf("This task is ID number is not allowed, please try again: ");
    	scanf("%d",&client.id);
	}
    
    printf("Enter the first name of the client: \n");
    scanf("%s",&client.firstname);

    printf("Enter the lastname of the client: \n");
    scanf("%s",&client.lastname);
       
    //to read a string with spaces, an fgets function or a special scanf is required
    //however, scanf is flawed in that it will leave a NEWLINE CHARACTER after reading an input
    //The two functions stated before when placed after a scanf WILL NOT WORK as it takes the newline character as its input, leaving no room for the user to input anything
    //to prevent this from occuring, we need something to eat the newline character in its place
                        
    fgetc(stdin);
    //the function fgetc(stdin) eats a newline character and allows an fgets to be used
                                                                                                
    printf("Enter the address of the client: \n");
    scanf("%[^\n]%*c",&client.address); 
    //this special scanf reads a string with spaces and discards the newline character created afterwards
    
	printf("Enter the vehicle class of the client(public or private): \n");
    scanf("%s",&client.vehicleClass);  
    
    if ((stricmp(client.vehicleClass,"public")!=0)&&(stricmp(client.vehicleClass,"private")!=0))
    {
		while ((stricmp(client.vehicleClass,"public")!=0)&&(stricmp(client.vehicleClass,"private")!=0))
		{
    		printf("This isn't a class, please try again: ");
    		scanf("%s",&client.vehicleClass); 
		}
	}
    printf("Enter the type of vehicle(bus,car,truck,etc): \n");
    scanf("%s",&client.vehicle);

	printf("Enter the liscence number of the client's vehicle: \n");
	scanf("%s",&client.liscenceNum);
        
    printf("Has the client paid the yearly fee of $2000(yes or no)\n");
    scanf("%s",&client.yearlyFee);
    
    client.totalClientFee=0;
    if ((stricmp(client.yearlyFee,"yes")!=0)&&(stricmp(client.yearlyFee,"no")!=0))
    {
		while ((stricmp(client.yearlyFee,"yes")!=0)&&(stricmp(client.yearlyFee,"no")!=0))
		{
    		printf("This isn't an answer, please try again: ");
    		scanf("%s",&client.yearlyFee); 
		}
	}
	else
	{
		if(client.yearlyFee=="no")
		{
			client.totalClientFee=client.totalClientFee+yearly;
		}
	}
        
    printf("Has the client gotten into any accidents for the year?\n");
	printf("If so please enter how many in total,if not enter 0: \n");
    scanf("%d",&client.accidents);
            
    if (client.accidents>0)
    {
		client.totalAccidentFee=client.accidents*accidentFee;
		client.totalClientFee=client.totalClientFee+client.totalAccidentFee;
	}
	else
	{
		if(client.accidents==0)
		{
			printf("This client as earned a 10 percent discount of $200 on this year's yearly fee.\n");
			client.totalClientFee=client.totalClientFee-discount;
		}
	}
	printf("************************************************************\n\n");
	
    fseek(insurPointer,(client.id-1)*sizeof(struct clientInfo),SEEK_SET);
    fwrite(&client,sizeof(struct clientInfo),1,insurPointer);
    fclose(insurPointer);
}

void Result3()
{
	FILE*insurPointer;
	struct clientInfo client={0,"","","","",0,0,0,"","",""}; 
	if ((insurPointer=fopen("broken", "rb+"))==NULL)
    {
        printf("Cannot open file\n");
        exit(1);
	}
    else
    {
    	printf("************************************************************\n");
		printf("			VIEW RECORDS						\n");
    	printf("************************************************************\n\n");
    			
    	while(!feof(insurPointer))
        {   
          	fread(&client,sizeof(struct clientInfo),1,insurPointer);
           	if(client.id!=0)
			{  
        		printf("Client ID: %d\n",client.id);
        		printf("Client's full name: %s %s\n",client.firstname,client.lastname);
        		printf("Client's address: %s\n",client.address);
        		printf("Client's vehicle class: %s\n",client.vehicleClass);
        		printf("Client's vehicle type: %s\n",client.vehicle);
        		printf("Client's vehicle liscence number: %s\n",client.liscenceNum);
        		printf("Client's accident count: %d\n",client.accidents);
        		if (client.accidents>0)
  				{
					printf("The client has not earned a discount.\n");
				}
				
        		if(client.yearlyFee=="no")
				{
					printf("Client has not payed yearly fee.\n");
				}
       			printf("Client's total accident fee so far: $%d\n",client.totalAccidentFee);
        		printf("\n");
        		printf("************************************************************\n\n");
			}
		}
	}
	fclose(insurPointer);
}

void Result4()
{
	FILE*insurPointer;
	int search;
	struct clientInfo client={0,"","","","",0,0,0,"","",""}; 
	if ((insurPointer=fopen("broken", "rb+"))==NULL)
	{
    	printf("Cannot open file\n");
        exit(1);
    }
    else
    {
    	printf("Enter client ID to be searched for(1 to 100): ");
    	scanf("%d",&search);
    	
    	//in the while you were checking for client.id and not the value you entered.
    	while((search<1)||(search>100))
		{
    		printf("This ID number is not allowed, please try again: ");
    		//you had client.id in scanf instead of search
    		scanf("%d",&search);
		}
            	
        printf("************************************************************\n");
		printf("			RECORD SEARCH						\n");
    	printf("************************************************************\n\n");
    			

        	//when searching by an integer or ID you should use fseek
        	fseek(insurPointer,(search-1)*sizeof(struct clientInfo),SEEK_SET);
		 	fread(&client,sizeof(struct clientInfo),1,insurPointer);
           	if (client.id!=0)
        	{
        		printf("Client ID: %d\n",client.id);       
				printf("Client's full name: %s %s\n",client.firstname,client.lastname);
        		printf("Client's address: %s\n",client.address);
        		printf("Client's vehicle class: %s\n",client.vehicleClass);
        		printf("Client's vehicle type: %s\n",client.vehicle);
        		printf("Client's vehicle liscence number: %s\n",client.liscenceNum);
        		printf("Client's accident count: %d\n",client.accidents);
        		if (client.accidents>0)
  				{
					printf("The client has not earned the discount of $200.\n");
				}
				else
				{
					if(client.accidents==0)
					{
						printf("The client has earned the discount of $200.\n");
					}
				}
			
        		if(client.yearlyFee=="no")
				{
					printf("Client has not payed the $2000 yearly fee.\n");
				}
				else
				{
					if(client.yearlyFee=="yes")
					{
						printf("Client has payed the yearly fee of $2000.\n");
					}
				}
       			printf("Client's total accident fee so far: $%d\n",client.totalAccidentFee);
        		printf("\n");
        		printf("************************************************************\n\n");
			}
	}
    fclose(insurPointer);
}

void Result5()
{
	FILE*insurPointer;
	int identification;
	float amount;
	struct clientInfo client={0,"","","","",0,0,0,"","",""}; 
	if ((insurPointer=fopen("broken", "rb+"))==NULL)
	{
        printf("Cannot open file\n");
        exit(1);
    }
    else
    {
       	printf("Enter client ID to be update(1 to 100): ");
      	scanf("%d",&identification);
          	
       	fseek(insurPointer,(identification-1)*sizeof(struct clientInfo),SEEK_SET);
       	fread(&client,sizeof(struct clientInfo),1,insurPointer);
           	
       	if(client.id==0)
       	{
       		printf("************************************************************\n");
			printf("		THERE ARE NO RECORDS FOR THIS ID					\n");
    		printf("************************************************************\n\n");
    	}
        		
    	if(client.id!=0)
    	{
    		printf("Client ID: %d\n",client.id);
    		
    		printf("************************************************************\n");
			printf("			CLIENT INFORMATION TO BE UPDATED					\n");
    		printf("************************************************************\n\n");
        	printf("Client's full name: %s %s\n",client.firstname,client.lastname);
        	printf("Client's address: %s\n",client.address);
        	printf("Client's vehicle class: %s\n",client.vehicleClass);
        	printf("Client's vehicle type: %s\n",client.vehicle);
        	printf("Client's vehicle liscence number: %s\n",client.liscenceNum);
        	printf("Client's accident count: %d\n",client.accidents);
        	if (client.accidents>0)
  			{
				printf("The client has not earned the discount of $200.\n");
			}
			else
			{
				if(client.accidents==0)
				{
					printf("The client has earned the discount of $200.\n");
				}
			}
			
        	if(client.yearlyFee=="no")
			{
				printf("Client has not payed the $2000 yearly fee.\n");
			}
			else
			{
				if(client.yearlyFee=="yes")
				{
				printf("Client has payed the yearly fee of $2000.\n");
				}
			}
       		printf("Client's total accident fee so far: $%d\n",client.totalAccidentFee);
        	printf("\n");
        	printf("************************************************************\n\n");
                	
           	printf("Enter by how much you wish to increase or decrease the accident number: ");
    		scanf("%f",&amount);
                    
            client.accidents=client.accidents+amount;
            client.totalAccidentFee=client.accidents*accidentFee;
			printf("************************************************************\n\n");
               
			printf("************************************************************\n");
			printf("			UPDATED CLIENT INFORMATION					\n");
    		printf("************************************************************\n\n");
			printf("Client ID: %d\n",client.id);        
            printf("Client's full name: %s %s\n",client.firstname,client.lastname);
        	printf("Client's address: %s\n",client.address);
        	printf("Client's vehicle class: %s\n",client.vehicleClass);
        	printf("Client's vehicle type: %s\n",client.vehicle);
        	printf("Client's vehicle liscence number: %s\n",client.liscenceNum);
        	printf("Client's accident count: %d\n",client.accidents);
        	if (client.accidents>0)
  			{
				printf("The client has not earned the discount of $200.\n");
			}
			else
			{
				if(client.accidents==0)
				{
					printf("The client has earned the discount of $200.\n");
				}
			}
			
        	if(client.yearlyFee=="no")
			{
				printf("Client has not payed the $2000 yearly fee.\n");
			}
			else
			{
				if(client.yearlyFee=="yes")
				{
				printf("Client has payed the yearly fee of $2000.\n");
				}
			}
       		printf("Client's total accident fee so far: $%d\n",client.totalAccidentFee);
        	printf("\n");
        	printf("************************************************************\n\n");
               	
            fseek(insurPointer,(client.id-1)*sizeof(struct clientInfo),SEEK_SET);
            fwrite(&client,sizeof(struct clientInfo),1,insurPointer);
            fclose(insurPointer);
		}
	}
}

void Result6()
{
	FILE*insurPointer;
	int identification;
	char addressChange[string_length2];
	char answer[4];
	struct clientInfo client={0,"","","","",0,0,0,"","",""}; 
	if ((insurPointer=fopen("broken", "rb+"))==NULL)
	{
        printf("Cannot open file\n");
        exit(1);
    }
    else
    {
       	printf("Enter client ID to be update(1 to 100): ");
      	scanf("%d",&identification);
          	
       	fseek(insurPointer,(identification-1)*sizeof(struct clientInfo),SEEK_SET);
       	fread(&client,sizeof(struct clientInfo),1,insurPointer);
           	
       	if(client.id==0)
       	{
       		printf("************************************************************\n");
			printf("		THERE ARE NO RECORDS FOR THIS ID					\n");
    		printf("************************************************************\n\n");
    	}
        		
    	if(client.id!=0)
    	{
    		printf("Client ID: %d\n",client.id);
    		
    		printf("************************************************************\n");
			printf("			CLIENT INFORMATION TO BE UPDATED					\n");
    		printf("************************************************************\n\n");
        	printf("Client's full name: %s %s\n",client.firstname,client.lastname);
        	printf("Client's address: %s\n",client.address);
        	printf("Client's vehicle class: %s\n",client.vehicleClass);
        	printf("Client's vehicle type: %s\n",client.vehicle);
        	printf("Client's vehicle liscence number: %s\n",client.liscenceNum);
        	printf("Client's accident count: %d\n",client.accidents);
        	if (client.accidents>0)
  			{
				printf("The client has not earned the discount of $200.\n");
			}
			else
			{
				if(client.accidents==0)
				{
					printf("The client has earned the discount of $200.\n");
				}
			}
			
        	if(client.yearlyFee=="no")
			{
				printf("Client has not payed the $2000 yearly fee.\n");
			}
			else
			{
				if(client.yearlyFee=="yes")
				{
				printf("Client has payed the yearly fee of $2000.\n");
				}
			}
       		printf("Client's total accident fee so far: $%d\n",client.totalAccidentFee);
        	printf("\n");
        	printf("************************************************************\n\n");
            
            printf("Has the client's address changed?(yes or no)\n");
            scanf("%s",&answer);
            
            if ((stricmp(answer,"yes")!=0)&&(stricmp(answer,"no")!=0))
    		{
				while ((stricmp(answer,"yes")!=0)&&(stricmp(answer,"no")!=0))
				{
    				printf("This isn't an answer, please try again: ");
    				scanf("%s",&answer); 
				}
			}
			else
			{
				if(stricmp(answer,"yes")==0)
				{
					fgetc(stdin);
					printf("Enter the new address of the client: \n");
					scanf("%[^\n]%*c",&addressChange);
					 
					strcpy(client.address,addressChange);
				}
			}
			printf("************************************************************\n\n");
               
			printf("************************************************************\n");
			printf("		UPDATED CLIENT INFORMATION					\n");
    		printf("************************************************************\n\n");
			printf("Client ID: %d\n",client.id);        
            printf("Client's full name: %s %s\n",client.firstname,client.lastname);
        	printf("Client's address: %s\n",client.address);
        	printf("Client's vehicle class: %s\n",client.vehicleClass);
        	printf("Client's vehicle type: %s\n",client.vehicle);
        	printf("Client's vehicle liscence number: %s\n",client.liscenceNum);
        	printf("Client's accident count: %d\n",client.accidents);
        	if (client.accidents>0)
  			{
				printf("The client has not earned the discount of $200.\n");
			}
			else
			{
				if(client.accidents==0)
				{
					printf("The client has earned the discount of $200.\n");
				}
			}
			
        	if(client.yearlyFee=="no")
			{
				printf("Client has not payed the $2000 yearly fee.\n");
			}
			else
			{
				if(client.yearlyFee=="yes")
				{
				printf("Client has payed the yearly fee of $2000.\n");
				}
			}
       		printf("Client's total accident fee so far: $%d\n",client.totalAccidentFee);
        	printf("\n");
        	printf("************************************************************\n\n");
               	
            fseek(insurPointer,(client.id-1)*sizeof(struct clientInfo),SEEK_SET);
            fwrite(&client,sizeof(struct clientInfo),1,insurPointer);
            fclose(insurPointer);
		}
	}
}

void Result7()
{
	FILE*insurPointer;
	int identification;
	char licenceChange[6];
	char answer2[4];
	struct clientInfo client={0,"","","","",0,0,0,"","",""}; 
	if ((insurPointer=fopen("broken", "rb+"))==NULL)
	{
        printf("Cannot open file\n");
        exit(1);
    }
    else
    {
       	printf("Enter client ID to be update(1 to 100): ");
      	scanf("%d",&identification);
          	
       	fseek(insurPointer,(identification-1)*sizeof(struct clientInfo),SEEK_SET);
       	fread(&client,sizeof(struct clientInfo),1,insurPointer);
           	
       	if(client.id==0)
       	{
       		printf("************************************************************\n");
			printf("		THERE ARE NO RECORDS FOR THIS ID					\n");
    		printf("************************************************************\n\n");
    	}
        		
    	if(client.id!=0)
    	{
    		printf("Client ID: %d\n",client.id);
    		
    		printf("************************************************************\n");
			printf("		CLIENT INFORMATION TO BE UPDATED					\n");
    		printf("************************************************************\n\n");
        	printf("Client's full name: %s %s\n",client.firstname,client.lastname);
        	printf("Client's address: %s\n",client.address);
        	printf("Client's vehicle class: %s\n",client.vehicleClass);
        	printf("Client's vehicle type: %s\n",client.vehicle);
        	printf("Client's vehicle liscence number: %s\n",client.liscenceNum);
        	printf("Client's accident count: %d\n",client.accidents);
        	if (client.accidents>0)
  			{
				printf("The client has not earned the discount of $200.\n");
			}
			else
			{
				if(client.accidents==0)
				{
					printf("The client has earned the discount of $200.\n");
				}
			}
			
        	if(client.yearlyFee=="no")
			{
				printf("Client has not payed the $2000 yearly fee.\n");
			}
			else
			{
				if(client.yearlyFee=="yes")
				{
				printf("Client has payed the yearly fee of $2000.\n");
				}
			}
       		printf("Client's total accident fee so far: $%d\n",client.totalAccidentFee);
        	printf("\n");
        	printf("************************************************************\n\n");
                	
			printf("Has the client's licence number changed?(yes or no)\n");
            scanf("%s",&answer2);
            
            if ((stricmp(answer2,"yes")!=0)&&(stricmp(answer2,"no")!=0))
    		{
				while ((stricmp(answer2,"yes")!=0)&&(stricmp(answer2,"no")!=0))
				{
    				printf("This isn't an answer, please try again: ");
    				scanf("%s",&answer2); 
				}
			}
			else
			{
				if(stricmp(answer2,"yes")==0)
				{
					fgetc(stdin);
					printf("Enter the new licence number of the client: \n");
					scanf("%[^\n]%*c",&licenceChange); 
					
					strcpy(client.liscenceNum,licenceChange);
				}
			}
			printf("************************************************************\n\n");
               
			printf("************************************************************\n");
			printf("		UPDATED CLIENT INFORMATION					\n");
    		printf("************************************************************\n\n");
			printf("Client ID: %d\n",client.id);       
            printf("Client's full name: %s %s\n",client.firstname,client.lastname);
        	printf("Client's address: %s\n",client.address);
        	printf("Client's vehicle class: %s\n",client.vehicleClass);
        	printf("Client's vehicle type: %s\n",client.vehicle);
        	printf("Client's vehicle liscence number: %s\n",client.liscenceNum);
        	printf("Client's accident count: %d\n",client.accidents);
        	if (client.accidents>0)
  			{
				printf("The client has not earned the discount of $200.\n");
			}
			else
			{
				if(client.accidents==0)
				{
					printf("The client has earned the discount of $200.\n");
				}
			}
			
        	if(client.yearlyFee=="no")
			{
				printf("Client has not payed the $2000 yearly fee.\n");
			}
			else
			{
				if(client.yearlyFee=="yes")
				{
				printf("Client has payed the yearly fee of $2000.\n");
				}
			}
       		printf("Client's total accident fee so far: $%d\n",client.totalAccidentFee);
        	printf("\n");
        	printf("************************************************************\n\n");
               	
            fseek(insurPointer,(client.id-1)*sizeof(struct clientInfo),SEEK_SET);
            fwrite(&client,sizeof(struct clientInfo),1,insurPointer);
            fclose(insurPointer);
		}
	}
}

void Result8()
{
	FILE*insurPointer;
	int identification;
	struct clientInfo client={0,"","","","",0,0,0,"","",""}; 
			
	struct clientInfo blankClient={0,"","","","",0,0,0,"","",""}; 
	if ((insurPointer=fopen("broken", "rb+"))==NULL)
    {
        printf("Cannot open file\n");
		exit(1);
    }
            
    printf("************************************************************\n");
	printf("			DELETE RECORDS						\n");
    printf("************************************************************\n\n");
    		
    printf("Enter ID to be deleted: ");
    scanf("%d",&identification);
    		
    fseek(insurPointer,(identification-1)*sizeof(struct clientInfo),SEEK_SET);
    fread(&client,sizeof(struct clientInfo),1,insurPointer);
            
    if(client.id==0)
    {
    	printf("************************************************************\n");
		printf("			THERE IS NO SUCH RECORD						\n");
    	printf("************************************************************\n\n");
    }
    		
    if(client.id!=0)
    {
    	fseek(insurPointer,(client.id-1)*sizeof(struct clientInfo),SEEK_SET);
    	fwrite(&blankClient,sizeof(struct clientInfo),1,insurPointer);
    			
    	printf("************************************************************\n");
		printf("			RECORD DELETED						\n");
    	printf("************************************************************\n\n");
	}
	fclose(insurPointer);
}

main()
{   
	FILE*insurPointer;//pointer
	int result;
    result=MenuChoice();
    
    while(result!=9)
    {
    	if(result==1)
    	{
			Result1();
			result=MenuChoice();
		}
		
		if(result==2)
		{
			Result2();
	        result=MenuChoice();
		}
		
		if(result==3)
		{
			Result3();
			result=MenuChoice();
		}
		
		if(result==4)
		{
			Result4();
			result=MenuChoice();
		}
		
		if(result==5)
		{
			Result5();
			result=MenuChoice();
    	}
    	
    	if(result==6)
		{
			Result6();
			result=MenuChoice();
    	}
    	
    	if(result==7)
		{
			Result7();
			result=MenuChoice();
    	}
    	
    	if(result==8)
		{
			Result8();
			result=MenuChoice();
		}
	}
		
	if(result==9)
	{
		system("Pause");
	}
	
}
    
