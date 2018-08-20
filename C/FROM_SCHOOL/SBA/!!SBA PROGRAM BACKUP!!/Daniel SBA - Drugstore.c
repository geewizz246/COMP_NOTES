#include<stdio.h>
#include<errno.h>//error handling
#include<stdlib.h>
#include<string.h>
#define strlength 100
#define strlength2 50

struct drugInfo //STORES DRUG INFORMATION
{   
	int ID;
	
	char name[strlength];
	char company[strlength];
	char drug_type[strlength2];
	
	int quantity;
	float price;
	float sales;
};


struct customerInfo //STORES CUSTOMER INFORMATION
{
	int ID;
	
	char firstname[strlength2];
	char lastname[strlength2];
	char drug[10][strlength];
	
	int quantity[10];
	float cost[10];
	float totalCost;
	int totalNumOrders;
};
	
	

void idFormat(int id)//FORMATS ID INTO 4 DIGITS
{
	if(id<10)
	{
	    printf("000%d",id);
	}/*end if*/
	else
	if((id>=10)&&(id<100))
	{
		printf("00%d",id);
	}/*end else*/
	else
	if((id>=100)&&(id<1000))
	{
		printf("0%d",id);
	}/*end else*/
	else
	if(id>=1000)
	{
		printf("%d",id);
	}/*end else*/
}/*End Function*/


void password()//PASSWORD RECOGNITION
{
	char password[20];
	int i=2;
	
	printf("Welcome to the Hernando Sanchez Pharmacy! Please enter your password====>");
	scanf("%s",&password);
	while((strcmp(password,"bob")!=0)&&(i!=0))
	{
		printf("\nINCORRECT PASSWORD!\n");
		printf("Please re-enter your password (%d more chances)====>",i);
		scanf("%s",&password);
		i--;			
	}/*end while*/
	
	if(strcmp(password,"bob")!=0)
	{
		printf("\n\n\n\n");
		printf("                   !!!FAILURE!!!                   \n");
		printf("              PROGRAM SHUTTING DOWN......            \n");
		exit(1);
	}/*end if*/
	else
	{
		printf("\n\n\n\n\t\t\t !!!SUCCESS!!!\n\n");	
	}/*end else*/
}/*End Function*/


void miniDrugs()//A MINI DISPLAY OF DRUGS IN STOCK
{
	FILE*inDataFile1;//POINTER TO DRUGSTORE FILE
	
	struct drugInfo drug={0,"","","",0,0.0,0.0};/*declaring structure drugInfo*/
	
	inDataFile1=fopen ("myfiledrugs", "rb+");
	
	printf("\t ID \t\t PRICE \t\t STOCK \t\t DRUG\n\n");
	while(!feof(inDataFile1))
	{   
		fread(&drug,sizeof(struct drugInfo),1,inDataFile1);
		if(drug.ID!=0)
		{
			printf("\t");
			idFormat(drug.ID);//call to function idFormat
			printf("\t\t $%.2f\t\t %d\t\t %s\n",drug.price,drug.quantity,drug.name);
		}/*end if*/    
    }/*end while*/
    fclose(inDataFile1);
}/*End function*/


int mainMenu()//MENU GIVES USER A LIST OF OPTIONS
{
    int choice;
	  
	printf("\n\n");
    printf("\n\n");
    printf("====================================================================\n");
    printf("====================================================================\n\n\t");
	printf("=>=>=>=>=>=>=>HERNANDO SANCHEZ PHARMACY<=<=<=<=<=<=<=\n\n");
    printf("====================================================================\n");
    printf("====================================================================\n\n\n");

	printf("====================================================================\n\n\t");
	printf("OPTION              DESCRIPTION                   \n\n");
    printf("====================================================================\n\n\t ");
    
	printf("1 \t\t Create new files\n\n\t ");
	printf("2 \t\t Stock management\n\n\t ");
	printf("3 \t\t Drugstore management\n\n\t ");
	printf("4 \t\t Exit program\n\n\n");
   		
    printf("Task=====>");
    scanf("%d",&choice);
    
    while((choice<1)||(choice>4))//accounting for invalid entry
	{
		printf("\n\n");
		printf("!!ERROR 0007!! Invalid value.\n");
		printf("Enter task again=====>");
		scanf("%d",&choice);
	}/*end while*/
    
    printf("\n\n");
    printf("\n\n");
    
    return choice;
}/*End Function*/


int stockMenu()//MENU GIVES USER A LIST OF OPTIONS FOR MANAGING STOCK
{
	int choice;
	  
	printf("\n\n");
    printf("\n\n");
    printf("============================================================\n\n");
	printf("                      STOCK MANAGEMENT                      \n\n");
	printf("============================================================\n\n\n");
	
	printf("============================================================\n\n\t");
	printf("OPTION              DESCRIPTION                   \n\n");
    printf("============================================================\n\n\t ");
	
	printf("1 \t\t Add a new drug\n\n\t ");
	printf("2 \t\t Search for a drug\n\n\t ");
	printf("3 \t\t Update drug information\n\n\t ");
	printf("4 \t\t Display stock\n\n\t ");
	printf("5 \t\t Delete a drug\n\n\t ");
	printf("6 \t\t Add stock\n\n\t ");
	printf("7 \t\t Exit menu\n\n\n");
    printf("Task=====>");
    scanf("%d",&choice);
    
    while((choice<1)||(choice>7))//accounting for invalid entry
	{
		printf("\n\n");
		printf("!!ERROR 0007!! Invalid value.\n");
		printf("Enter task again=====>");
		scanf("%d",&choice);
	}/*end while*/
    
    printf("\n\n");
    printf("\n\n");
    
    return choice;
}/*End Function*/
    
	
int storeMenu()//MENU GIVES USER A LIST OF OPTIONS FOR OPERATING DRUGSTORE
{
	int choice;
	
	printf("\n\n");
    printf("\n\n");
	printf("============================================================\n\n");
	printf("                    DRUGSTORE MANAGEMENT                    \n\n");
	printf("============================================================\n\n\n\n");
 	
	printf("============================================================\n\n\t");
	printf("OPTION              DESCRIPTION                   \n\n");
    printf("============================================================\n\n\t ");
						    
	printf("1 \t\t Sell drugs\n\n\t ");
	printf("2 \t\t Display total sales\n\n\t ");
	printf("3 \t\t Search for a customer transaction\n\n\t ");
	printf("4 \t\t Display customer transactions\n\n\t ");
	printf("5 \t\t Delete a transaction\n\n\t ");	
	printf("6 \t\t Exit menu\n\n\n");
	
	printf("Task=====>");
	scanf("%d",&choice);
	
	while((choice<1)||(choice>6))
	{
		printf("!!ERROR 0007!! Invalid value.\n");
    	printf("Enter task again=====>");
    	scanf("%d",&choice);
	}/*end while*/
	
	printf("\n\n");
    printf("\n\n");
    
	return choice;
}/*End Function*/


int editMenu()//MENU GIVES LIST OF OPTIONS FOR EDITING DRUGS
{
	int choice;
	
	printf("\n\n");
	printf("============================================================\n\n\t");
	printf("OPTION              DESCRIPTION                   \n\n");
	printf("============================================================\n\n\t ");
	printf("1 \t\t Change drug name\n\n\t ");
	printf("2 \t\t Change company name\n\n\t ");
	printf("3 \t\t Change drug type\n\n\t ");
	printf("4 \t\t Change amount of drug\n\n\t ");
	printf("5 \t\t Change selling price\n\n\t ");
	printf("6 \t\t Clear drug sales\n\n\t ");
	printf("7 \t\t Cancel\n\n\n");
			
	printf("Task=====>");
	scanf("%d",&choice);
			
	while((choice<1)||(choice>7))
	{
		printf("\n\n");
	    printf("!!ERROR 0007!! Invalid value.");
	    printf("Enter task again=====>");
	    scanf("%d",&choice);
	}/*end while*/
	
	printf("\n\n");
	printf("\n\n");
	
	return choice;
}/*End Function*/


void createFileDrug()//CREATES A NEW DRUGSTORE FILE
{
	FILE*inDataFile1;//POINTER TO DRUGSTORE FILE
	int f;
	char ans[4];
	struct drugInfo drug={0,"","","",0,0.0,0.0};/*declaring structure drugInfo*/


	printf("Create new drug file? ('yes' or 'no')---->");
	scanf("%s",&ans);
	
	while((stricmp(ans,"yes")!=0)&&(stricmp(ans,"no")!=0))
	{
		printf("!!ERROR 0007!! Invalid answer.\n");
        printf("Enter answer again ('yes' or 'no')---->");
        scanf("%s",&ans);
	}/*end while*/
	
	if(stricmp(ans,"yes")==0)
	{
    	if((inDataFile1 = fopen("myfiledrugs","wb"))==NULL)
	    {
	        printf("Cannot open drug file \n");
	        exit(1);
	    }/*end if*/
		else
		{		
			for (f=0;f<=10000;f++)
        	{
        	    fwrite(&drug,sizeof(struct drugInfo),1,inDataFile1);
        	} /*end for*/
        	printf("\n\n");
        	printf("============================================================\n\n");
			printf("             		FILE CREATED                 \n\n");
		    printf("============================================================\n\n\n");
	        fclose(inDataFile1);
		}/*end else*/
    }/*end if*/
    
    else   
    if(stricmp(ans,"no")==0)
	{
    	printf("\n\n");
    	printf("Okay. No new file was made.");
    	printf("\n\n");
	}/*end else*/
	
}/*End Function*/


void createFileCustomer()//CREATES A NEW CUSTOMER FILE
{
	FILE*inDataFile2;//POINTER TO CUSTOMER FILE
	int f;
	char ans[4];
	struct customerInfo customer={0,"","","",0,0.0,0.0,0};/*declaring structure customerInfo*/
	
	printf("Create new customer file? (yes or no)---->");
	scanf("%s",&ans);
	
	while((stricmp(ans,"yes")!=0)&&(stricmp(ans,"no")!=0))
	{
		printf("!!ERROR 0007!! Invalid answer.\n");
        printf("Enter answer again (yes or no)---->");
        scanf("%s",&ans);
	}/*end while*/
	
	if(stricmp(ans,"yes")==0)
	{	
		if((inDataFile2 = fopen("myfilecustomers","wb"))==NULL)
		{
	        printf("Cannot open customer file \n");
	        exit(1);
	    }/*end if*/
		else
		{		
			for (f=0;f<=10000;f++)
        	{
        	    fwrite(&customer,sizeof(struct customerInfo),1,inDataFile2);
        	} /*end for*/
        	printf("\n\n");
        	printf("============================================================\n\n");
			printf("             		FILE CREATED                 \n\n");
		    printf("============================================================\n");
		    fclose(inDataFile2);
        }/*end else*/
    }/*end if*/
    
    else
	if(stricmp(ans,"no")==0)
    {
    	printf("\n\n");
    	printf("Okay. No new file was made.");
    	printf("\n\n");
	}/*end else*/
	
}/*End Function*/


void stockManagement()//STORE MANAGEMENT
{
	FILE*inDataFile1;//POINTER TO FILE
	int funcAns,answer,funcAns2,answer2,identification,amount;
	char string[strlength],answer3[4],answer4[4];
	
	struct drugInfo drug={0,"","","",0,0.0,0.0};
	
	funcAns=stockMenu();/*call to function stockMenu*/
	
	while(funcAns!=7)
	{
		if(funcAns==1)//CREATES A NEW RECORD FOR AN DRUG
		{
			if ((inDataFile1 = fopen("myfiledrugs", "rb+"))==NULL)
		    {
		        printf("Cannot open drug file \n");
		        exit(1);
		    }/*end if*/
	
		    printf("============================================================\n\n");
			printf("             	    ADD A NEW DRUG                          \n\n");
			printf("============================================================\n\n\n");
			
			printf("Enter the ID of drug (4 DIGITS MAX)---->");
			scanf("%d",&drug.ID);
			
			while((drug.ID<1)||(drug.ID>9999))
			{
				printf("!!ERROR 0036!! Invalid ID.\n");
	    	    printf("Please re-enter ID---->");
	    	    scanf("%d",&drug.ID);
			}/*end while*/
			
			//to read a string with spaces, an fgets function or a special scanf is required
			//however, scanf is flawed in that it will leave a NEWLINE CHARACTER after reading an input
			//The two functions stated before when placed after a scanf WILL NOT WORK as it takes the newline character as its input, leaving no room for the user to input anything
			//to prevent this from occuring, we need something to eat the newline character in its place
			
			fgetc(stdin);
			//the function fgetc(stdin) eats a newline character and allows an fgets or special scanf to be used
			
			printf("\n");				            
	    	printf("Enter the name of drug---->");
	    	scanf("%[^\n]%*c",&drug.name); 
			//this special scanf reads a string with spaces and discards the newline character created afterwards
			
			printf("\n");		
	    	printf("Enter the name of company---->");
	    	scanf("%[^\n]%*c",&drug.company);   
	        
			printf("\n");    
	    	printf("To be filed under which drug type:\n");
	    	printf("   1. Pain Relief\n");
	    	printf("   2. Antihistamine\n");
	    	printf("   3. Cough Medicine\n");
	    	printf("   4. Metabolic\n");
	    	printf("   5. Respiratory\n");
	    	printf("   6. Other\n");
	    	printf("Enter corresponding number---->");
	    	scanf("%d",&answer);
	    	        
	    	while((answer<1)||(answer>6))
	    	{
	    	    printf("!!ERROR 0007!! Invalid value.\n");
	    	    printf("Please re-enter number---->");
	    	    scanf("%d",&answer);
			}/*end while*/
			
			if(answer==1)
			{
				strcpy(drug.drug_type,"Pain Relief");
			}
	    	if(answer==2)
			{
				strcpy(drug.drug_type,"Antihistamine");
			}
	        if(answer==3)
			{
				strcpy(drug.drug_type,"Cough Medicine");
			}
	    	if(answer==4)
			{
				strcpy(drug.drug_type,"Metabolic");
			}
		    if(answer==5)
			{
				strcpy(drug.drug_type,"Respiratory");
			}
	    	if(answer==6)
			{
				strcpy(drug.drug_type,"Other");
			}
	   	    
			printf("\n");                 
		    printf("Enter the amount of drug---->");
		    scanf("%d",&drug.quantity);
			
			printf("\n");    
	        printf("Enter the selling price of drug---->");
	        scanf("%f",&drug.price);
	        
		    printf("\n\n");
		    printf("**************************************\n");
	    	printf("****END OF ADD A NEW DRUG FUNCTION****\n");
	    	printf("**************************************\n");
			printf("\n\n");
		            		         
		    fseek(inDataFile1,(drug.ID-1)*sizeof(struct drugInfo),SEEK_SET);
		    fwrite(&drug,sizeof(struct drugInfo),1,inDataFile1);
		    fclose(inDataFile1);
		}//END OF ADD DRUG
	
		else
		if(funcAns==2)//SEARCH FOR DRUG
		{
			if ((inDataFile1 = fopen("myfiledrugs", "rb+"))==NULL)
		    {
		        printf("Cannot open drug file \n");
		        exit(1);
		    }/*end if*/
		    
		    int found=0;
		    
			printf("============================================================\n\n");
			printf("                      SEARCH FOR DRUG                       \n\n");
			printf("============================================================\n\n\n");
			fgetc(stdin);
			
			printf("\n\n");					
			printf("Enter drug name to search--->");
			scanf("%[^\n]%*c",&string);
			
			while(!feof(inDataFile1))
			{   
			    fread(&drug,sizeof(struct drugInfo),1,inDataFile1);
			    /*Read Mode*/ 
		
			    if(stricmp(drug.name,string)==0)
			    {
			        printf("\n\n");
			        printf("ID---->");
			    	idFormat(drug.ID);
					printf("\nNAME---->%s\n",drug.name);
					printf("COMPANY NAME---->%s\n",drug.company);
					printf("DRUG TYPE---->%s\n",drug.drug_type);
					printf("AMOUNT IN STORE---->%d\n",drug.quantity);
					printf("SELLING PRICE---->$%.2f\n",drug.price);
					printf("DRUG SALES---->$%.2f\n",drug.sales);
					
					found=1;
				}/*end if*/
		    }/*end while*/
		    
		    if(found==0)
		    {
		    	printf("\n\n");
		        printf("============================================================\n\n");
				printf("             !!!!!!RECORD HAS NO INFORMATION!!!!!!          \n\n");
		    	printf("============================================================\n\n");
		    }/*end if*/
		    
		    printf("\n\n");
		    printf("***************************************\n");
	    	printf("****END OF SEARCH FOR DRUG FUNCTION****\n");
	    	printf("***************************************\n");
	
			fclose(inDataFile1);
		}//END OF SEARCH FOR DRUG
		
		else
		if(funcAns==3)//ALLOWS USER TO UPDATE THE INFORMATION OF A DRUG
		{
			if ((inDataFile1 = fopen("myfiledrugs", "rb+"))==NULL)
		    {
		        printf("Cannot open drug file \n");
		        exit(1);
		    }/*end if*/
		    
		    printf("============================================================\n\n");
			printf("                   UPDATE DRUG INFORMATION                  \n\n");
			printf("============================================================\n\n");
			/*edits the information of a specific drug*/
			
			printf("\n\n");
			miniDrugs();/*call to fuction miniDrugs*/
			
			printf("\n\n");					
			printf("Enter drug ID to update--->");
			scanf("%d",&identification);
	        
		    fseek(inDataFile1,(identification-1)*sizeof(struct drugInfo),SEEK_SET);
		    fread(&drug,sizeof(struct drugInfo),1,inDataFile1);
		    /*Read Mode*/ 
		    if(drug.ID==0)
		    {
		        printf("============================================================\n\n");
				printf("             !!!!!!RECORD HAS NO INFORMATION!!!!!!          \n\n");
		    	printf("============================================================");
		    }/*end if*/
	            
			if(drug.ID!=0)
		    {
		        printf("\n\n");
		        printf("ID---->");
		    	idFormat(drug.ID);
				printf("\nNAME---->%s\n",drug.name);
				printf("COMPANY NAME---->%s\n",drug.company);
				printf("DRUG TYPE---->%s\n",drug.drug_type);
				printf("AMOUNT IN STORE---->%d\n",drug.quantity);
				printf("SELLING PRICE---->$%.2f\n",drug.price);
				printf("DRUG SALES---->$%.2f\n",drug.sales);
						
				funcAns2=editMenu();/*call to function editMenu*/
						
				while(funcAns2!=7)
				{
					if(funcAns2==1) //NAME
					{
						printf("Old name---->%s\n",drug.name);
						printf("Enter the new name of the drug---->");
						fgetc(stdin);
						scanf("%[^\n]%*c",&drug.name);
								
						printf("SUCCESS!! NEW NAME---->%s\n",drug.name);	
					} //END OF NAME
					
					else
					if(funcAns2==2) //COMPANY
					{
						printf("Old company---->%s\n",drug.company);
						printf("Enter the new name of the company---->");
						fgetc(stdin);
						scanf("%[^\n]%*c",&drug.company);
								
						printf("SUCCESS!! NEW COMPANY NAME---->%s\n",drug.company);	
					} //END OF COMPANY
					
					else
					if(funcAns2==3) //DRUG TYPE
					{
						printf("Old drug type---->%s\n",drug.drug_type);
						printf("New type:\n");
					    printf("   1. Pain Relief\n");
					    printf("   2. Antihistamine\n");
					    printf("   3. Cough Medicine\n");
					    printf("   4. Metabolic\n");
					    printf("   5. Respiratory\n");
					    printf("   6. Other\n");
					    printf("Enter corresponding number---->");
					    scanf("%d",&answer2);
	            
	            		while((answer2<1)||(answer2>6))
					    {
					        printf("!!ERROR 0007!! Invalid value.\n");
					        printf("Please re-enter number---->");
					    	scanf("%d",&answer2);
						}/*end while*/
						
						if(answer2==1)
						{
							strcpy(drug.drug_type,"Pain Relief");
						}/*end if*/
					    if(answer2==2)
						{
							strcpy(drug.drug_type,"Antihistamine");
						}/*end if*/
					    if(answer2==3)
						{
							strcpy(drug.drug_type,"Cough Medicine");
						}/*end if*/
					    if(answer2==4)
						{
							strcpy(drug.drug_type,"Metabolic");
						}/*end if*/
					    if(answer2==5)
						{
							strcpy(drug.drug_type,"Respiratory");
						}/*end if*/
					    if(answer2==6)
						{
							strcpy(drug.drug_type,"Other");
						}/*end if*/
								
						printf("SUCCESS!! NEW DRUG TYPE---->%s\n",drug.drug_type);	
					} //END OF DRUG TYPE
					
					else
					if(funcAns2==4) //AMOUNT
					{
						printf("Old drug amount---->%d\n",drug.quantity);
						printf("Enter the new amount of the drug---->");
						scanf("%d",&drug.quantity);
								
						printf("SUCCESS!! NEW DRUG AMOUNT---->%d\n",drug.quantity);	
					} //END OF AMOUNT
					
					else
					if(funcAns2==5) //PRICE
					{
						printf("Old selling price---->$%.2f\n",drug.price);
						printf("Enter the new selling price of the drug---->");
						scanf("%f",&drug.price);
								
						printf("SUCCESS!! NEW SELLING PRICE---->$%.2f\n",drug.price);	
					} //END OF PRICE
					
					else
					if(funcAns2==6) //CLEAR DRUG SALES
					{
						printf("Drug sales---->$%.2f\n",drug.sales);
						printf("Are you sure that you want to clear this drug's sales? (yes or no)---->");
						scanf("%s",&answer3);
							
						while((stricmp(answer3,"yes")!=0)&&(stricmp(answer3,"no")!=0))
						{
							printf("!!ERROR 0007!! Invalid answer.\n");
					        printf("Enter answer again (yes or no)---->");
					        scanf("%s",&answer3);
						}/*end while*/
						
						if(stricmp(answer3,"yes")==0)
						{
							drug.sales=0;
							printf("SUCCESS!! DRUG'S SALES HAVE BEEN RESET TO $%.2f\n",drug.sales);
						}/*end if*/
						
						else
						if(stricmp(answer3,"no")==0)
						{
							printf("Okay. The drug's sales remain the same.\n");
						}
					} //END OF CLEAR DRUG SALES
							
					printf("What else whould you like to update?\n");
					funcAns2=editMenu();/*call to function editMenu*/
				}/*end while*/
				
				if(funcAns2==7)
				{
					printf("\n\n");
					printf("Okay. The drug's information is as follows:\n");
					printf("ID---->");
		    	    idFormat(drug.ID);
					printf("\nNAME---->%s\n",drug.name);
					printf("COMPANY NAME---->%s\n",drug.company);
					printf("DRUG TYPE---->%s\n",drug.drug_type);
					printf("AMOUNT IN STORE---->%d\n",drug.quantity);
					printf("SELLING PRICE---->$%.2f\n",drug.price);
					printf("DRUG SALES---->$%.2f\n",drug.sales);
				}/*end if*/
						
				printf("\n\n");
			    printf("***********************************\n");
		    	printf("****END OF UPDATE DRUG FUNCTION****\n");
		    	printf("***********************************\n");
				
				fseek(inDataFile1,(drug.ID-1)*sizeof(struct drugInfo),SEEK_SET);
		        fwrite(&drug,sizeof(struct drugInfo),1,inDataFile1);
				fclose(inDataFile1);
			}/*end if*/
		}//END OF UPDATE DRUG INFORMATION
		
		else
		if(funcAns==4)//ALLOWS USER TO DISPLAY STOCK
		{
			if ((inDataFile1 = fopen("myfiledrugs", "rb+"))==NULL)
		    {
		        printf("Cannot open drug file \n");
		        exit(1);
		    }/*end if*/
		    
			printf("============================================================\n\n");
			printf("                       DISPLAY STOCK                        \n\n");
			printf("============================================================\n\n\n");
	    	
			while(!feof(inDataFile1))
			{   
				fread(&drug,sizeof(struct drugInfo),1,inDataFile1);
				if(drug.ID!=0)
				{
					printf("============================================================\n\n\n");
		    	    printf("ID---->");
					idFormat(drug.ID);/*call to function idFormat*/
					printf("\nNAME---->%s\n",drug.name);
					printf("COMPANY NAME---->%s\n",drug.company);
					printf("DRUG TYPE---->%s\n",drug.drug_type);
					printf("AMOUNT IN STORE---->%d\n",drug.quantity);
					printf("SELLING PRICE---->$%.2f\n",drug.price);
					printf("DRUG SALES---->$%.2f\n",drug.sales);
					printf("\n\n\n");
				}/*end if*/  
		    }/*end while*/
		    
		    printf("============================================================\n\n\n"); 
		    
		    printf("\n\n");
		    printf("*************************************\n");
	    	printf("****END OF DISPLAY STOCK FUNCTION****\n");
	    	printf("*************************************\n");
			
			fclose(inDataFile1);
		}//END DISPLAY STOCK
		
		else
		if(funcAns==5)//DELETES A DRUG RECORD
		{
			struct drugInfo blankDrug={0,"","","",0,0.0,0.0};
			
			if ((inDataFile1 = fopen("myfiledrugs", "rb+"))==NULL)
		    {
		        printf("Cannot open drug file \n");
		        exit(1);
		    }/*end if*/
		    
			printf("============================================================\n\n");
			printf("\t\t\t DELETE RECORDS \t\t\t\n\n");
		    printf("============================================================\n\n"); 
		    
		    printf("\n\n");
			miniDrugs();/*call to fuction miniDrugs*/
			
			printf("\n\n");
			printf("Enter drug ID to delete--->");
		    scanf("%d",&identification);         
		           
			fseek(inDataFile1,(identification-1)*sizeof(struct drugInfo),SEEK_SET);
			fread(&drug,sizeof(struct drugInfo),1,inDataFile1);
			/*Read Mode*/
					
			if(drug.ID==0)
			{
				printf("\n\n");
		        printf("============================================================\n\n");
				printf("             !!!!!!RECORD DOES NOT EXIST!!!!!!              \n\n");
				printf("============================================================");
		    }/*end if*/
		            
		    if(drug.ID!=0)
		    {
				fseek(inDataFile1,(drug.ID-1)*sizeof(struct drugInfo),SEEK_SET);
				fwrite(&blankDrug,sizeof(struct drugInfo),1,inDataFile1);
						
				printf("\n\n");
				printf("============================================================\n\n");
				printf("\t\t\t DELETE COMPLETE \t\t\t\n\n");
		    	printf("============================================================"); 
		    }
			printf("\n\n");
		    printf("**************************************\n");
	    	printf("****END OF DELETE A DRUG FUNCTION****\n");
	    	printf("**************************************\n");
			
			fclose(inDataFile1);
		}//END OF DELETE DRUG
		
		else
		if(funcAns==6)//ALLOWS USER TO ADD STOCK TO AN DRUG
		{
			if ((inDataFile1 = fopen("myfiledrugs", "rb+"))==NULL)
		    {
		        printf("Cannot open drug file \n");
		        exit(1);
		    }/*end if*/
		    
		    printf("\n\n");
			printf("============================================================\n\n");
			printf("                          ADD STOCK                         \n\n");
			printf("============================================================\n\n\n");
			
			miniDrugs();/*call to fuction miniDrugs*/

			printf("\n\n");
			printf("Enter drug ID---->");
			scanf("%d",&identification);
      		
			fseek(inDataFile1,(identification-1)*sizeof(struct drugInfo),SEEK_SET);
			fread(&drug,sizeof(struct drugInfo),1,inDataFile1);
			/*Read Mode*/ 
			if(drug.ID==0)
			{
				printf("\n\n");
			    printf("============================================================\n\n");
				printf("              !!!!!!DRUG DOES NOT EXIST!!!!!!               \n\n");
				printf("============================================================\n\n\n");
			}/*end if*/
      			    
			if(drug.ID!=0)
			{
			    printf("Drug requested---->%s\n",drug.name);
			    printf("Enter amount to add to stock---->");
				scanf("%d",&amount);
			        	
			    printf("\nAdding %d more stock to drug %s. Is this okay? (yes or no)---->",amount,drug.name);
				scanf("%s",&answer4);
					
				while((stricmp(answer4,"yes")!=0)&&(stricmp(answer4,"no")!=0))
				{
					printf("!!ERROR 0007!! Invalid answer.\n");
			        printf("Enter answer again (yes or no)---->");
			        scanf("%s",&answer4);
				}/*end while*/
			
				if(stricmp(answer4,"yes")==0)
				{
			        printf("\n\n");
			        drug.quantity=drug.quantity+amount;
			        printf("SUCCESS!! STOCK HAS BEEN ADDED!!\n");
			        printf("%s stock---->%d\n\n",drug.name,drug.quantity);
				}
				else
				if(stricmp(answer4,"no")==0)
				{
					printf("\n\n");
					printf("Okay. No stock was added.\n\n");
				}/*end if*/
						
			}/*end if*/
			
			fseek(inDataFile1,(drug.ID-1)*sizeof(struct drugInfo),SEEK_SET);
			fwrite(&drug,sizeof(struct drugInfo),1,inDataFile1);
			
			printf("\n\n");
		    printf("*********************************\n");
	    	printf("****END OF ADD STOCK FUNCTION****\n");
	    	printf("*********************************\n");
			printf("\n\n");
			
			fclose(inDataFile1);
		}//END OF ADD STOCK
		
		funcAns=stockMenu();/*call to function stockMenu*/
	}/*end while*/
		
	if(funcAns==7)
	{
		printf("\n\n");
	    printf("******************************************************************\n");
		printf("                      Returning to Main Menu                      \n");
		printf("******************************************************************\n");
	}/*end if*/
}/*End Function*/


void storeManagement()//STORE MANAGEMENT
{
	FILE*inDataFile1;//POINTER TO DRUGSTORE FILE
	FILE*inDataFile2;//POINTER TO CUSTOMER FILE
	int funcAns,identification,num;
	char answer[4];
	float cost;
	float drugCostATP; /*shows drug cost at time of purchase*/
	
	struct drugInfo drug={0,"","","",0,0.0,0.0};
	struct customerInfo customer={0,"","","",0,0.0,0.0,0}; 
	
	
	funcAns=storeMenu();/*call to function storeMenu*/

	while(funcAns!=6)
	{
		if(funcAns==1)//SELL DRUGS
		{
			if((inDataFile1 = fopen("myfiledrugs", "rb+"))==NULL)
			{
			    printf("Cannot open drug file \n");
				exit(1);                   
			}/*end if*/
			
			if((inDataFile2 = fopen("myfilecustomers", "rb+"))==NULL)
			{
		        printf("Cannot open customer file \n");
		        exit(1);
		    }/*end if*/
		    customer.totalCost=0;
	    	customer.totalNumOrders=0;
	    	
			printf("\n\n");
			printf("*************************************************************\n");
			printf("*************************************************************\n");
			printf("***********             SELL DRUGS                ***********\n");
			printf("*************************************************************\n");
			printf("*************************************************************\n\n");
			
			printf("\n\n");
			printf("Enter customer's order number (4 DIGITS MAX)---->");
			scanf("%d",&customer.ID);
		
			while((customer.ID<1)||(customer.ID>9999))
			{
				printf("!!ERROR 0036!! Invalid order number.\n");
	    	    printf("Please re-enter order number---->");
	    	    scanf("%d",&customer.ID);
			}/*end while*/
			
			printf("\nEnter customer's first name---->");
			scanf("%s",customer.firstname);
			printf("\nEnter customer's last name---->");
			scanf("%s",customer.lastname);
		    
			printf("\n\n");			    
			miniDrugs();/*call to fuction miniDrugs*/
			
			printf("\n\n");
			printf("Enter drug ID (-1 to terminate)--->");
			scanf("%d",&identification);
      			
			while(identification!=-1)
			{
				fseek(inDataFile1,(identification-1)*sizeof(struct drugInfo),SEEK_SET);
				fread(&drug,sizeof(struct drugInfo),1,inDataFile1);
				/*Read Mode*/ 
				if(drug.ID==0)
				{
					printf("\n\n");
			        printf("============================================================\n\n");
					printf("              !!!!!!DRUG DOES NOT EXIST!!!!!!               \n\n");
					printf("============================================================");
				}/*end if*/	
					
				if(drug.ID!=0)
				{   
					if(customer.totalNumOrders>0)
					{
						printf("\n\n");
						printf("************************************************************\n\n");
						printf("        CONTINUING WITH YOUR PURCHASE        \n\n");
						printf("************************************************************\n\n");
					}
					printf("Drug requested---->%s\n\n",drug.name);	    			    
				    
					printf("Enter the desired amount of the drug---->");
				    scanf("%d",&num);
				    
				    cost=drug.price*num;
				    
				    printf("\nCost is $%.2f. Is this okay? (yes or no)---->",cost);
					scanf("%s",&answer);
					
					while((stricmp(answer,"yes")!=0)&&(stricmp(answer,"no")!=0))
					{
						printf("!!ERROR 0007!! Invalid answer.\n");
				        printf("Enter answer again (yes or no)---->");
				        scanf("%s",&answer);
					}/*end while*/
				
					if(stricmp(answer,"yes")==0)
					{
					    if(num>drug.quantity)
				        {
				        	printf("\n\n");
					    	printf("!!ERROR 0364!! NOT ENOUGH STOCK!\n\n");
						}/*end if*/
						else
						{
							drug.quantity=drug.quantity-num;
							drug.sales=drug.sales+cost;
							
							fseek(inDataFile1,(drug.ID-1)*sizeof(struct drugInfo),SEEK_SET);
							fwrite(&drug,sizeof(struct drugInfo),1,inDataFile1);
						    
						    fclose(inDataFile1);/*temporarly close file so it regesters changes next time minilist appears*/
							inDataFile1=fopen ("myfiledrugs", "rb+");/*reopen file*/
						    
						    strcpy(customer.drug[customer.totalNumOrders],drug.name);
						    customer.quantity[customer.totalNumOrders]=num;
							customer.cost[customer.totalNumOrders]=cost;
							customer.totalCost=customer.totalCost+cost;
						    
						    customer.totalNumOrders++;
							printf("\n\n");
				        	printf("SUCCESS!! PURCHASE HAS BEEN MADE!!\n");
						}/*end else*/
					}/*end if*/
					
					else
					if(stricmp(answer,"no")==0)
					{
						printf("\n\n");
						printf("Okay. No purchase was made.\n");
					}/*end else*/
				}/*end if*/
				
				printf("\n\n");
				miniDrugs();/*call to fuction miniDrugs*/
				
				printf("\n\n");
				printf("Enter drug ID (-1 to terminate)--->");
				scanf("%d",&identification);
					
			}/*end while*/
			
			if(customer.totalNumOrders>0)/*only writes transaction to file if purchase was made*/
			{
				fseek(inDataFile2,(customer.ID-1)*sizeof(struct customerInfo),SEEK_SET);
				fwrite(&customer,sizeof(struct customerInfo),1,inDataFile2);
			}/*end if*/
				
			printf("\n\n");
		    printf("**********************************\n");
	    	printf("****END OF SELL DRUGS FUNCTION****\n");
	    	printf("**********************************\n");
			printf("\n\n");
			
    		fclose(inDataFile1);
			fclose(inDataFile2);
		}//END OF SELL DRUGS
			
		else
		if(funcAns==2)//DISPLAY SALES
		{			
			if((inDataFile2 = fopen("myfilecustomers", "rb+"))==NULL)
			{
		        printf("Cannot open customer file \n");
		        exit(1);
		    }/*end if*/
		    
		    float totalSales=0;

			while(!feof(inDataFile2))
			{
				fread(&customer,sizeof(struct customerInfo),1,inDataFile2);
				if(customer.ID!=0)
				{
					totalSales=totalSales+customer.totalCost;
				}/*end if*/   
	    	}/*end while*/
					
			printf("\n\n");
			printf("*************************************************************\n");
			printf("*************************************************************\n");
			printf("                  TOTAL SALES========>$%.2f                  \n",totalSales);
			printf("*************************************************************\n");
			printf("*************************************************************\n\n");
			
			fclose(inDataFile2);
			
			printf("\n\n");
		    printf("*************************************\n");
	    	printf("****END OF DISPLAY SALES FUNCTION****\n");
	    	printf("*************************************\n");
			printf("\n\n");
		}//END OF DISPLAY SALES
		
		else
		if(funcAns==3)//SEARCH FOR CUSTOMER TRANSACTION
		{		  	      
			if((inDataFile2 = fopen("myfilecustomers", "rb+"))==NULL)
			{
				printf("Cannot open customer file \n");
				exit(1);
			}/*end if*/
			
			int i;
			
			printf("*************************************************************\n");
			printf("*************************************************************\n");
			printf("***********        SEARCH FOR TRANSACTION         ***********\n");
			printf("*************************************************************\n");
			printf("*************************************************************\n\n\n");
			
			printf("\n\n");					
			printf("Enter customer ID to search--->");
			scanf("%d",&identification);
			
			fseek(inDataFile2,(identification-1)*sizeof(struct customerInfo),SEEK_SET);
		    fread(&customer,sizeof(struct customerInfo),1,inDataFile2);
		    /*Read Mode*/
			if(customer.ID==0)
		    {
		    	printf("\n\n");
		        printf("============================================================\n\n");
				printf("             !!!!!!RECORD HAS NO INFORMATION!!!!!!          \n\n");
		    	printf("============================================================\n\n");
		    }/*end if*/
			
		    if(customer.ID!=0)
		    {
		        printf("\n\n");
		        printf("***Hernando Sanchez Pharmacy***\n");
		        printf("Maxwell Coast Rd, Oistins, Christ Church\n");
				printf("Cust ID   ");						
	    	    idFormat(customer.ID);/*call to function idFormat*/
				printf("\nCUSTOMER NAME---->%s %s\n\n",customer.firstname,customer.lastname);
				for(i=0;i<customer.totalNumOrders;i++)
				{
					drugCostATP=customer.cost[i]/customer.quantity[i];/*calculating drug cost at time of purchase*/
					
					printf("%d of %s @ $%.2f = %f\n",customer.quantity[i],customer.drug[i],drugCostATP,customer.cost[i]);
				}/*end for*/
				
				printf("\nTotal Cost = $%.2f\n",customer.totalCost);				
				printf("\n\n");
			}/*end if*/
	    
			fclose(inDataFile2);
			
			printf("\n\n");
		    printf("**********************************************\n");
	    	printf("****END OF SEARCH FOR TRANSACTION FUNCTION****\n");
	    	printf("**********************************************\n");
			printf("\n\n");
		}//END OF SEARCH FOR CUSTOMER TRANSACTION
		
		else
		if(funcAns==4)//DISPLAY CUSTOMER TRANSACTIONS
		{
			if((inDataFile2 = fopen("myfilecustomers", "rb+"))==NULL)
			{
		        printf("Cannot open customer file \n");
		        exit(1);
		    }/*end if*/

	    	int i;
	    	
	    	printf("*************************************************************\n");
			printf("*************************************************************\n");
			printf("***********     DISPLAY CUSTOMER TRANSACTIONS     ***********\n");
			printf("*************************************************************\n");
			printf("*************************************************************\n\n\n");
			while(!feof(inDataFile2))
			{   
				fread(&customer,sizeof(struct customerInfo),1,inDataFile2);
				if(customer.ID!=0)
				{
					printf("============================================================\n\n");
					
					printf("\n\n");
			        printf("***Hernando Sanchez Pharmacy***\n");
			        printf("Maxwell Coast Rd, Oistins, Christ Church\n");
					printf("Cust ID   ");
		    	    idFormat(customer.ID);/*call to function idFormat*/
					printf("\n%s %s\n\n",customer.firstname,customer.lastname);
					for(i=0;i<customer.totalNumOrders;i++)
					{
						drugCostATP=customer.cost[i]/customer.quantity[i];/*calculating drug cost at time of purchase*/
						
						printf("%d of %s @ $%.2f = $%.2f\n",customer.quantity[i],customer.drug[i],drugCostATP,customer.cost[i]);
					}
					printf("\nTotal Cost = $%.2f\n",customer.totalCost);
					
					printf("\n\n");
				}/*end if*/				
			}/*end while*/
				
	    	printf("============================================================\n\n");
		
			fclose(inDataFile2);
			
			printf("\n\n");
		    printf("********************************************\n");
	    	printf("****END OF DISPLAY TRANSACTIONS FUNCTION****\n");
	    	printf("********************************************\n");
			printf("\n\n");
		}//END OF DISPLAY CUSTOMER TRANSACTIONS
		
		else
		if(funcAns==5)//DELETE A TRANSACTION
		{
			if((inDataFile2 = fopen("myfilecustomers", "rb+"))==NULL)
			{
		        printf("Cannot open customer file \n");
		        exit(1);
		    }/*end if*/

	    	struct customerInfo blankCustomer={0,"","","",0,0.0,0.0,0};
		            
			printf("*************************************************************\n");
			printf("*************************************************************\n");
			printf("***********          DELETE A TRANSACTION         ***********\n");
			printf("*************************************************************\n");
			printf("*************************************************************\n\n\n");
		    
		    printf("\t ID               CUSTOMER                   \n\n");
			while(!feof(inDataFile2))
			{   
				fread(&customer,sizeof(struct customerInfo),1,inDataFile2);
				if(customer.ID!=0)
				{
					printf("\t");
					idFormat(customer.ID);//call to function idFormat
					printf("\t\t %s %s\n",customer.firstname,customer.lastname);
				}/*end if*/    
		    }/*end while*/
    
			printf("\n\n");
			printf("Enter customer ID to delete transaction--->");
		    scanf("%d",&identification);         
		           
			fseek(inDataFile2,(identification-1)*sizeof(struct customerInfo),SEEK_SET);
			fread(&customer,sizeof(struct customerInfo),1,inDataFile2);
			/*Read Mode*/
					
			if(customer.ID==0)
			{
				printf("\n\n");
		        printf("============================================================\n\n");
				printf("             !!!!!!RECORD DOES NOT EXIST!!!!!!              \n\n");
				printf("============================================================");
		    }/*end if*/
		            
		    if(customer.ID!=0)
		    {
				fseek(inDataFile2,(customer.ID-1)*sizeof(struct customerInfo),SEEK_SET);
				fwrite(&blankCustomer,sizeof(struct customerInfo),1,inDataFile2);
			
				printf("\n\n");
				printf("============================================================\n\n");
				printf("\t\t\t DELETE COMPLETE \t\t\t\n\n");
		    	printf("============================================================"); 
		    }            
           	
			fclose(inDataFile2);
           	
			printf("\n\n");
		    printf("******************************************\n");
	    	printf("****END OF DELETE TRANSACTION FUNCTION****\n");
	    	printf("******************************************\n");
			printf("\n\n");
		}//END OF DELETE A TRANSACTION
						
		funcAns=storeMenu();			
	}/*end while*/
				
	if(funcAns==6)
	{
		printf("\n\n");
	    printf("******************************************************************\n");
		printf("                      Returning to Main Menu                      \n");
		printf("******************************************************************\n");
		printf("\n\n");
	}/*end if*/
    
}/*End Function*/



main()
{   
	int result;
	
	password();/*call to function password*/
	
	result=mainMenu();/*call to function mainMenu*/

	while(result!=4)
	{	
    	if(result==1)//CREATE NEW FILE
    	{
            createFileDrug();/*call to function createFileDrug*/
            createFileCustomer();/*call to function createFileCustomer*/
			result=mainMenu();/*call to function mainMenu*/
		}/*end if*/

 
 
		if(result==2)//ENTER STOCK MANAGEMENT
		{
    		stockManagement();/*call to function stockManagement*/
	        result=mainMenu();/*call to function mainMenu*/       	 
		}/*end if*/	 		 
 	 
	    
		  
    	if(result==3)//ENTER STORE MANAGEMENT
    	{	
    	    storeManagement();/*call to function storeManagement*/
			result=mainMenu();/*call to function mainMenu*/	
		} /*end if*/   
		                                      
    
	}/*end while*/
	
	if(result==4)//END THE PROGRAM
	{
		printf("\t\t\t PROGRAM SHUTTING DOWN...... \n\n\n");
		system("pause");
	}/*end if*/
	     
}//END PROGRAM
