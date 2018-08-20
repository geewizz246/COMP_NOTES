#include<stdio.h>
#include<errno.h> //error handling
#include<stdlib.h> 
#include<stdbool.h> //boolean functions
#include<string.h>
#include<time.h> //necessary for randomized ID
#define strlength 100
#define strlength2 50
#define length 10 //length of queue
//STORES DRUG INFORMATION
struct drugInfo
{   
	int ID;
	char name[strlength];
	char company[strlength];
	char type[strlength2];
	int quantity;
	float price;
};
//STORES ORDER INFORMATION
struct orderInfo
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
//STORES QUEUE INFORMATION
struct queueInfo
{
	int position;/*this is customer's position in queue*/
	int ID;
	char firstname[strlength2];
	char lastname[strlength2];
	char drug[10][strlength];
	int quantity[10];
	float cost[10];
	float totalCost;
	int totalNumOrders;
};


//DETERMINES TYPE OF THE DRUG
char *determineType()
{
	int ans;
	static char drug1[strlength2]="Pain Relief";
	static char drug2[strlength2]="Antihistamine";
	static char drug3[strlength2]="Cough Medicine";
	static char drug4[strlength2]="Metabolic";
	static char drug5[strlength2]="Respiratory";
	static char drug6[strlength2]="Other";
	
	printf("  1. Pain Relief\n");
	printf("  2. Antihistamine\n");
	printf("  3. Cough Medicine\n");
	printf("  4. Metabolic\n");
	printf("  5. Respiratory\n");
	printf("  6. Other\n");
	printf("Enter corresponding number---->");
	scanf("%d",&ans);
	
	while((ans<1)||(ans>6))
	{
		printf("\n\n!!ERROR 0007!! Invalid value!\n");
		printf("Please re-enter number---->");
		scanf("%d",&ans);
	}/*end while*/
	
	if(ans==1)
		return drug1;
	if(ans==2)
		return drug2;
	if(ans==3)
		return drug3;
	if(ans==4)
		return drug4;
	if(ans==5)
		return drug5;
	if(ans==6)
		return drug6;
}//end determineType


//A SIMPLIFIED DISPLAY OF DRUGS IN STOCK
void miniDrugs()
{
	FILE*drugFile;//POINTER TO STOCK FILE
	struct drugInfo drug={0,"","","",0,0.0};/*declaring structure drugInfo*/
	
	drugFile = fopen("myfiledrugs", "rb+");/*open stock file*/
	
	printf("\n\n\t  ID \t\tSTOCK \t\t  PRICE\t\t   DRUG\n\n");
	while(!feof(drugFile))
	{   
		fread(&drug,sizeof(struct drugInfo),1,drugFile);
		if(drug.ID!=0)
		{
			printf("\t %04d\t\t %d\t\t $%06.2f         %s\n",drug.ID,drug.quantity,drug.price,drug.name);
		}/*end if*/    
	}/*end while*/
	printf("\n\n");
	
	fclose(drugFile);
}//end miniDrugs


//FORMATS DRUG INFO FOR VIEWING
void stockFormat(struct drugInfo drug)
{
	FILE*drugFile;
	drugFile = fopen("myfiledrugs", "rb+");/*open stock file*/
	
	printf("============================================================\n\n\n");
	printf("ID---->%04d",drug.ID);
	printf("\nNAME---->%s\n",drug.name);
	printf("COMPANY NAME---->%s\n",drug.company);
	printf("DRUG TYPE---->%s\n",drug.type);
	printf("AMOUNT IN STORE---->%d\n",drug.quantity);
	printf("SELLING PRICE---->$%.2f\n\n\n",drug.price);
	printf("============================================================\n\n\n");
	
	fclose(drugFile);
}//end stockFormat


//FORMATS CUSTOMER INFO FOR VIEWING
void orderFormat(struct orderInfo order)
{
	FILE*orderFile;
	int i;
	orderFile = fopen("myfileorders", "rb+");/*open order file*/
	
	printf("============================================================\n\n\n");
	printf("HERNANDO SANCHEZ PHARMACY\n");
	printf("Maxwell Coast Rd, Oistins, Christ Church\n");
	printf("Phone\t 467-8003\n\n");
	printf("Order	#%04d",order.ID);
	printf("\n%s %s\n\n",order.firstname,order.lastname);
	for(i=0;i<order.totalNumOrders;i++)
	{
		float drugCostATP=order.cost[i]/order.quantity[i];/*calculating drug cost at time of purchase*/
		
		printf("%d of %s @ $%.2f = $%.2f\n",order.quantity[i],order.drug[i],drugCostATP,order.cost[i]);
	}/*end for*/
	printf("\nTotal Cost = $%.2f\n\n",order.totalCost);
	printf("============================================================\n\n\n");
	
	fclose(orderFile);
}//end orderFormat


//FORMATS QUEUE INFO FOR VIEWING
void queueFormat(struct queueInfo queue)
{
	FILE*queueFile;
	int i;
	queueFile = fopen("myfilequeue", "rb+");/*open queue file*/
	
	printf("============================================================\n\n\n");
	printf("HERNANDO SANCHEZ PHARMACY\n");
	printf("Maxwell Coast Rd, Oistins, Christ Church\n");
	printf("Phone\t 467-8003\n\n");
	printf("Queue Position: %d\n",queue.position);
	printf("Order	#%04d",queue.ID);
	printf("\n%s %s\n\n",queue.firstname,queue.lastname);
	for(i=0;i<queue.totalNumOrders;i++)
	{
		float drugCostATP=queue.cost[i]/queue.quantity[i];/*calculating drug cost at time of purchase*/
		
		printf("%d of %s @ $%.2f = $%.2f\n",queue.quantity[i],queue.drug[i],drugCostATP,queue.cost[i]);
	}/*end for*/
	printf("\nTotal Cost = $%.2f\n\n",queue.totalCost);
	printf("============================================================\n\n\n");
	
	fclose(queueFile);
}//end queueFormat


//PASSWORD RECOGNITION FOR MAIN MENU
void password()
{
	char password[20];
	int i=2;
	
	printf("Welcome to the Hernando Sanchez Pharmacy! Please enter the password====>");
	scanf("%s",&password);
	while((strcmp(password,"drugs")!=0)&&(i!=0))
	{
		printf("\n\nINCORRECT PASSWORD!\n");
		printf("Please re-enter your password (tries left: %d)====>",i);
		scanf("%s",&password);
		i--;			
	}/*end while*/
	
	if(strcmp(password,"drugs")!=0)
	{
		printf("\n\n\n\n                  !!!ACCESS DENIED!!!                   \n");
		printf("              PROGRAM SHUTTING DOWN......            \n");
		exit(1);
	}/*end if*/
	else
	{
		printf("\n\n\n\n\t\t\t !!!SUCCESS!!!\n\n");	
	}/*end else*/
}//end password


//PASSWORD RECOGNITION FOR THE EMPLOYEE MENU
int passwordEmployee()
{
	char password[20];
	int access=0;
	
	printf("Please enter the administrative password to access the employee menu====>");
	scanf("%s",&password);
	
	if(strcmp(password,"empfunc")!=0)
	{
		printf("\n\n\n\t\t\t*INCORRECT PASSWORD*\n\n");
		printf("\t\t\t   *Access Denied*   \n\n");			
	}/*end if*/
	else
	{
		printf("\n\n\n\t\t\t!!!Access Granted!!!\n\n\n\n\n");
		access++;
	}/*end else*/
	return access;
}//end passwordEmployee


//GENERATES AND WRITES INDEX TO A FILE
void autocreateIndex(int autoGeneratedIndex)
{
	FILE*fileIndex;
	int index;
	
	if((fileIndex = fopen("autoIndex.txt", "w"))==NULL)
	{
		printf("Cannot open index file\n");
		exit(1);
	}/*end if*/
	
	index=autoGeneratedIndex;
	
	/*printing data to file*/
	fprintf(fileIndex,"%d",index);/*writes the generated index to the record*/
	fclose(fileIndex);/*close file*/
}//end autocreateIndex


//READS INDEX FROM FILE
int readAutoIndex()
{
	FILE*readAutoIndex;
	int autoIdx,index;
	
	/*opening file for reading*/
	if((readAutoIndex = fopen("autoIndex.txt", "r"))==NULL)
	{
		printf("Cannot open index file\n");
		exit(errno);
	}/*end if*/
	else
	{
		/*read and display every line in the file*/
		while(!feof(readAutoIndex))/*while not end of file*/
		{
			fscanf(readAutoIndex,"%d",&autoIdx);
			index=autoIdx;
		}/*end while*/
		return index;
		fclose(readAutoIndex);
	}/*end else*/
}//end readAutoIndex


//MENU GIVES USER A LIST OF OPTIONS
int mainMenu()
{
	int choice;
    
	printf("\n\n\n\n");
	printf("=======================================================================\n");
	printf("=======================================================================\n\n");
	printf("=>=>=>=>=>=>=>         HERNANDO SANCHEZ PHARMACY         <=<=<=<=<=<=<=\n\n");
	printf("=======================================================================\n");
	printf("=======================================================================\n\n\n");
	printf("=======================================================================\n\n\t");
	printf("OPTION              DESCRIPTION                   \n\n");
	printf("=======================================================================\n\n\t ");
	printf(" 1 \t\t   Employee menu\n\n\t ");
	printf(" 2 \t\t   Order menu\n\n\t ");
	printf(" 3 \t\t   Exit program\n\n\n");
	printf("Task=====>");
	scanf("%d",&choice);
    
	while((choice<1)||(choice>3))/*accounting for invalid entry*/
	{
		printf("\n\n!!ERROR 0007!! Invalid value!\n");
		printf("Enter task again=====>");
		scanf("%d",&choice);
	}/*end while*/
    
	printf("\n\n\n\n");
	return choice;
}//end mainMenu


//MENU GIVES EMPLOYEE A LIST OF OPTIONS
int employeeMenu()
{
	int choice;
	
	printf("\n\n\n\n");
	printf("============================================================\n\n");
	printf("                       EMPLOYEE MENU                      \n\n");
	printf("============================================================\n\n\n");
	printf("============================================================\n\n\t");
	printf("OPTION              DESCRIPTION                   \n\n");
	printf("============================================================\n\n\t ");
	printf(" 1 \t\t   Create new files\n\n\t ");
	printf(" 2 \t\t   Stock management\n\n\t ");
	printf(" 3 \t\t   Pharmacy management\n\n\t ");
	printf(" 4 \t\t   Exit Menu\n\n\n");
	printf("Task=====>");
	scanf("%d",&choice);
    
	while((choice<1)||(choice>4))/*accounting for invalid entry*/
	{
		printf("\n\n!!ERROR 0007!! Invalid value!\n");
		printf("Enter task again=====>");
		scanf("%d",&choice);
	}/*end while*/
    
	printf("\n\n\n\n");
	return choice;
}//end employeeMenu


//MENU GIVES USER A LIST OF OPTIONS FOR MANAGING STOCK
int stockMenu()
{
	int choice;
	
	printf("\n\n\n\n");
	printf("============================================================\n\n");
	printf("                      STOCK MANAGEMENT                    \n\n");
	printf("============================================================\n\n\n");
	printf("============================================================\n\n\t");
	printf("OPTION              DESCRIPTION                   \n\n");
	printf("============================================================\n\n\t ");
	printf(" 1 \t\t   Add a new drug\n\n\t ");
	printf(" 2 \t\t   Search for a drug\n\n\t ");
	printf(" 3 \t\t   Display stock\n\n\t ");
	printf(" 4 \t\t   Update drug information\n\n\t ");
	printf(" 5 \t\t   Delete a drug\n\n\t ");
	printf(" 6 \t\t   Exit menu\n\n\n");
	printf("Task=====>");
	scanf("%d",&choice);
    
	while((choice<1)||(choice>6))/*accounting for invalid entry*/
	{
		printf("\n\n!!ERROR 0007!! Invalid value!\n");
		printf("Enter task again=====>");
		scanf("%d",&choice);
	}/*end while*/
    
	printf("\n\n\n\n");
	return choice;
}//end stockMenu  


//MENU GIVES USER A LIST OF OPTIONS FOR OPERATING PHARMACY
int pharmacyMenu()
{
	int choice;
	
	printf("\n\n\n\n");
	printf("============================================================\n\n");
	printf("                     PHARMACY MANAGEMENT                    \n\n");
	printf("============================================================\n\n\n\n");
	printf("============================================================\n\n\t");
	printf("OPTION              DESCRIPTION                   \n\n");
	printf("============================================================\n\n\t ");
	printf(" 1 \t\t   Display orders in queue\n\n\t ");
	printf(" 2 \t\t   Display all recorded orders\n\n\t ");
	printf(" 3 \t\t   Search for order\n\n\t ");
	printf(" 4 \t\t   Display total sales\n\n\t ");
	printf(" 5 \t\t   Delete an order\n\n\t ");
	printf(" 6 \t\t   Query number of orders in queue file\n\n\t ");
	printf(" 7 \t\t   Check if queue file is empty\n\n\t ");	
	printf(" 8 \t\t   Exit menu\n\n\n");
	printf("Task=====>");
	scanf("%d",&choice);
	
	while((choice<1)||(choice>8))
	{
		printf("\n\n!!ERROR 0007!! Invalid value!\n");
		printf("Enter task again=====>");
		scanf("%d",&choice);
	}/*end while*/
	
	printf("\n\n\n\n");
	return choice;
}//end pharmacyMenu


//MENU GIVES CUSTOMER A LIST OF OPTIONS IN RELATION TO ORDERS
int orderMenu()
{
	int choice;
	
	printf("\n\n\n\n");
	printf("=============================================================\n\n");
	printf("                         ORDER MENU                          \n\n");
	printf("=============================================================\n\n\n\n");
	printf("=============================================================\n\n\t");
	printf("OPTION              DESCRIPTION                   \n\n");
	printf("=============================================================\n\n\t ");
	printf(" 1 \t\t   Make an order\n\n\t ");
	printf(" 2 \t\t   Receive order\n\n\t ");
	printf(" 3 \t\t   Exit menu\n\n\n");
	printf("Task=====>");
	scanf("%d",&choice);
	
	while((choice<1)||(choice>3))
	{
		printf("\n\n!!ERROR 0007!! Invalid value!\n");
		printf("Enter task again=====>");
		scanf("%d",&choice);
	}/*end while*/
	
	printf("\n\n\n\n");
	return choice;
}//end orderMenu


//MENU GIVES A LIST OF OPTIONS FOR EDITING DRUGS
int editMenu()
{
	int choice;
	
	printf("\n\n\n\n");
	printf("============================================================\n\n\t");
	printf("OPTION              DESCRIPTION                   \n\n");
	printf("============================================================\n\n\t ");
	printf(" 1 \t\t   Change drug name\n\n\t ");
	printf(" 2 \t\t   Change company name\n\n\t ");
	printf(" 3 \t\t   Change drug type\n\n\t ");
	printf(" 4 \t\t   Add/remove stock\n\n\t ");
	printf(" 5 \t\t   Change selling price\n\n\t ");
	printf(" 6 \t\t   Cancel\n\n\n");	
	printf("Task=====>");
	scanf("%d",&choice);
	
	while((choice<1)||(choice>6))
	{
		printf("\n\n");
		printf("\n\n!!ERROR 0007!! Invalid value!\n");
		printf("Enter task again=====>");
		scanf("%d",&choice);
	}/*end while*/
	
	printf("\n\n\n\n");
	return choice;
}//end editMenu


//CREATES A NEW STOCK FILE
void createFileStock()
{
	FILE*drugFile;//POINTER TO STOCK FILE
	int f;
	struct drugInfo drug={0,"","","",0,0.0};/*declaring structure drugInfo*/

	if((drugFile = fopen("myfiledrugs","wb"))==NULL)
	{
		printf("Cannot open drug file \n");
		exit(1);
	}/*end if*/
	
	/*creating 1000 blank records*/
	for (f=0;f<1000;f++)
	{
		fwrite(&drug,sizeof(struct drugInfo),1,drugFile);
	}/*end for*/
	printf("\n\n");
	printf("************************************************************\n");
	printf("******              STOCK FILE CREATED                ******\n");
	printf("************************************************************\n\n");
	fclose(drugFile);
}//end createFileStock


//CREATES A NEW ORDER FILE
void createFileOrder()
{
	FILE*orderFile;//POINTER TO ORDER FILE
	int f;
	struct orderInfo order={0,"","","",0,0.0,0.0,0};/*declaring structure orderInfo*/
	
	if((orderFile = fopen("myfileorders","wb"))==NULL)
	{
		printf("Cannot open order file \n");
		exit(1);
	}/*end if*/
	
	/*creating 10000 blank records*/
	for (f=0;f<10000;f++)
	{
		fwrite(&order,sizeof(struct orderInfo),1,orderFile);
	}/*end for*/
	printf("\n\n");
	printf("*************************************************************\n");
	printf("******               ORDER FILE CREATED                ******\n");
	printf("*************************************************************\n\n");
	fclose(orderFile);
}//end createFileOrder


//CREATES A NEW QUEUE FILE
void createFileQueue()
{
	FILE*queueFile;//POINTER TO QUEUE FILE
	int f;
	struct queueInfo queue={0,0,"","","",0,0.0,0.0,0};/*declaring structure queueInfo*/
	
	if((queueFile = fopen("myfilequeue","wb"))==NULL)
	{
		printf("Cannot open queue file \n");
		exit(1);
	}/*end if*/
    
	autocreateIndex(-1);/*when file is FIRST created index is given a value of -1*/
	/*creating 10 blank records*/
	for (f=0;f<length;f++)
	{
		fwrite(&queue,sizeof(struct queueInfo),1,queueFile);
	}/*end for*/
	printf("\n\n");
	printf("************************************************************\n");
	printf("*******              QUEUE FILE CREATED              *******\n");
	printf("************************************************************\n\n");
	fclose(queueFile);	
}//end createFileQueue


//ADDS A NEW DRUG
void addDrug()
{
	FILE*drugFile;//POINTER TO STOCK FILE
	struct drugInfo drug={0,"","","",0,0.0};
	int val,taken=0;
	
	if((drugFile = fopen("myfiledrugs", "rb+"))==NULL)
	{
		printf("Cannot open drug file \n");
		exit(1);
	}/*end if*/

	printf("============================================================\n\n");
	printf("             		ADD A NEW DRUG                          \n\n");
	printf("============================================================\n\n\n\n");
	printf("Enter a unique ID for the drug (MUST BE<=1000)---->");
	scanf("%d",&val);
	
	while((val<1)||(val>1000))/*check for error*/
	{
		printf("\n!!ERROR 0036!! Invalid ID!\n");
		printf("Please re-enter ID (MUST BE<=1000)---->");
		scanf("%d",&val);
	}/*end while*/
				
	while(taken!=2)/*check if ID already taken*/
	{
		while(!feof(drugFile))
		{
			fread(&drug,sizeof(struct drugInfo),1,drugFile);
			while(drug.ID==val)
			{
				taken=0;
				printf("\n!!ERROR 0038!! Drug ID already taken!\n");
				printf("Please re-enter drug ID (MUST BE<=1000)---->");
				scanf("%d",&val);
			}/*end while*/
		}/*end while*/
		taken++;
		rewind(drugFile);/*reset file pointer to beginning*/
	}/*end while*/
	
	drug.ID=val;/*write val to drug.ID*/
	
	/*to read a string with spaces, an fgets function or a special scanf is required*/
	/*however, scanf is flawed in that it will leave a NEWLINE CHARACTER after reading an input*/
	/*The two aformentioned functions WILL NOT WORK when a scanf is used just prior as they take the newline character
	as their input, leaving no room for the user to input anything*/
	/*to prevent this from occuring, we need something to eat the newline character in its place*/
	fgetc(stdin);
	/*the function fgetc(stdin) eats a newline character and allows an fgets or special scanf to be used*/						
	printf("\nEnter the name of the drug---->");
	scanf("%[^\n]%*c",&drug.name); 
	/*this special scanf reads strings with spaces and discards the newline character created afterwards*/
	
	printf("\nEnter the name of the drug company---->");
	scanf("%[^\n]%*c",&drug.company);
	
	printf("\nTo be filed under which drug type:\n");
	strcpy(drug.type,determineType());/*call to function determineType*/

	printf("\nEnter the amount of the drug in stock---->");
	scanf("%d",&drug.quantity);

	printf("\nEnter the selling price of the drug---->");
	scanf("%f",&drug.price);
	
	fseek(drugFile,(drug.ID-1)*sizeof(struct drugInfo),SEEK_SET);
	fwrite(&drug,sizeof(struct drugInfo),1,drugFile);
	printf("\n\n");
	printf("**************************************\n");
	printf("****END OF ADD A NEW DRUG FUNCTION****\n");
	printf("**************************************\n\n\n");
	fclose(drugFile);
}//end addDrug


//SEARCHES FOR A DRUG
void searchDrug()
{
	FILE*drugFile;//POINTER TO STOCK FILE
	struct drugInfo drug={0,"","","",0,0.0};
	int answer,identification,found=0;
	char string[strlength];
	float low,high;
	
	if ((drugFile = fopen("myfiledrugs", "rb+"))==NULL)
	{
		printf("Cannot open drug file \n");
		exit(1);
	}/*end if*/
	
	printf("============================================================\n\n");
	printf("                      SEARCH FOR DRUG                       \n\n");
	printf("============================================================\n\n\n\n");
	printf("Choose how to search for drug:\n");
	printf("  1. ID\n");
	printf("  2. Name\n");
	printf("  3. Drug Type\n");
	printf("  4. Price Range\n");
	printf("Enter corresponding number---->");
	scanf("%d",&answer);
	
	while((answer<1)||(answer>4))/*check for error*/
	{
		printf("\n!!ERROR 0007!! Invalid value!\n");
		printf("Please re-enter number---->");
		scanf("%d",&answer);
	}/*end while*/
	
	if(answer==1)//SEARCH ID
	{
		printf("\nEnter ID of drug to search---->");
		scanf("%d",&identification);
		printf("\n\n\n");
		
		fseek(drugFile,(identification-1)*sizeof(struct drugInfo),SEEK_SET);
		fread(&drug,sizeof(struct drugInfo),1,drugFile);/*Read Mode*/
		
		if(drug.ID==identification)/*drug was found*/
		{
			stockFormat(drug);
			found=1;/*drug was found*/
		}/*end if*/	
	}//END SEARCH ID
	
	if(answer==2)//SEARCH NAME
	{
		fgetc(stdin);/*eat newline character*/
		printf("\nEnter name of drug to search---->");
		scanf("%[^\n]%*c",&string);
		printf("\n\n\n");
		
		while(!feof(drugFile))
		{   
			fread(&drug,sizeof(struct drugInfo),1,drugFile);/*Read Mode*/
			if(stricmp(drug.name,string)==0)
			{
				stockFormat(drug);
				found=1;/*drug was found*/
			}/*end if*/
		}/*end while*/
	}//END SEARCH NAME
	
	if(answer==3)//SEARCH TYPE
	{
		printf("\nSelect type of drug to search:\n");
		strcpy(string,determineType());/*call to function determineType*/
		printf("\n\n\n");
		
		while(!feof(drugFile))
		{   
			fread(&drug,sizeof(struct drugInfo),1,drugFile);/*Read Mode*/
			if(stricmp(drug.type,string)==0)
			{
				stockFormat(drug);
				found=1;/*drug was found*/
			}/*end if*/
		}/*end while*/
	}//END SEARCH TYPE
	
	if(answer==4)//SEARCH PRICE RANGE
	{
		printf("\nEnter price range to search (inclusive):\n");
		scanf("%f%f",&low,&high);
		
		if(high<low)/*ensure high always more than low*/
		{
			float temp;
			temp=low;
			low=high;
			high=temp;
		}/*end if*/
		
		printf("\nPRICE RANGE = $%.2f to $%.2f\n\n\n",low,high);
		while(!feof(drugFile))
		{   
			fread(&drug,sizeof(struct drugInfo),1,drugFile);/*Read Mode*/
			if((drug.price>=low)&&(drug.price<=high))
			{
				stockFormat(drug);
				found=1;/*drug was found*/
			}/*end if*/
		}/*end while*/	
	}//END SEARCH PRICE RANGE
	
	if(found==0)/*drug was not found*/
	{
		printf("\n\n");
		printf("============================================================\n\n");
		printf("             !!!!!!NO DRUG INFORMATION FOUND!!!!!!          \n\n");
		printf("============================================================\n\n\n");
	}/*end if*/
	
	printf("***************************************\n");
	printf("****END OF SEARCH FOR DRUG FUNCTION****\n");
	printf("***************************************\n\n\n");
	fclose(drugFile);
}//end searchDrug


//DISPLAYS STOCK
void displayStock()
{
	FILE*drugFile;//POINTER TO STOCK FILE
	struct drugInfo drug={0,"","","",0,0.0};
	
	if ((drugFile = fopen("myfiledrugs", "rb+"))==NULL)
	{
		printf("Cannot open drug file \n");
		exit(1);
	}/*end if*/
	
	printf("============================================================\n\n");
	printf("                       DISPLAY STOCK                        \n\n");
	printf("============================================================\n\n\n\n");
	
	while(!feof(drugFile))
	{   
		fread(&drug,sizeof(struct drugInfo),1,drugFile);
		if(drug.ID!=0)
		{
			stockFormat(drug);
		}/*end if*/  
	}/*end while*/
	
	printf("\n\n\n\n");
	printf("*************************************\n");
	printf("****END OF DISPLAY STOCK FUNCTION****\n");
	printf("*************************************\n\n\n");
	fclose(drugFile);
}//end displayStock


//UPDATES DRUG INFORMATION
void updateDrug()
{
	FILE*drugFile;//POINTER TO STOCK FILE
	struct drugInfo drug={0,"","","",0,0.0};
	int identification,number;
	
	if ((drugFile = fopen("myfiledrugs", "rb+"))==NULL)
	{
		printf("Cannot open drug file \n");
		exit(1);
	}/*end if*/
	
	printf("============================================================\n\n");
	printf("                   UPDATE DRUG INFORMATION                  \n\n");
	printf("============================================================\n\n");
	
	miniDrugs();/*call to fuction miniDrugs*/				
	printf("Enter the ID of the drug to update---->");
	scanf("%d",&identification);
	printf("\n\n");
    
	fseek(drugFile,(identification-1)*sizeof(struct drugInfo),SEEK_SET);
	fread(&drug,sizeof(struct drugInfo),1,drugFile);/*Read Mode*/ 
	if(drug.ID!=identification)/*drug was not found*/
	{
		printf("============================================================\n\n");
		printf("             !!!!!!NO DRUG INFORMATION FOUND!!!!!!          \n\n");
		printf("============================================================\n\n\n");
	}/*end if*/
        
	if(drug.ID==identification)/*drug was found*/
	{
		stockFormat(drug);/*call to function stockFormat*/
		
		int funcAns2=editMenu();/*call to function editMenu*/
		
		while(funcAns2!=6)
		{
			if(funcAns2==1)//NAME
			{
				printf("Old name---->%s\n",drug.name);
				printf("Enter the new name of the drug---->");
				fgetc(stdin);
				scanf("%[^\n]%*c",&drug.name);
				
				printf("\n\nSUCCESS!! NEW NAME---->%s\n",drug.name);	
			}//END OF NAME

			if(funcAns2==2)//DRUG COMPANY
			{
				printf("Old drug company---->%s\n",drug.company);
				printf("Enter the new name of the drug company---->");
				fgetc(stdin);
				scanf("%[^\n]%*c",&drug.company);
				
				printf("\n\nSUCCESS!! NEW DRUG COMPANY NAME---->%s\n",drug.company);	
			}//END OF DRUG COMPANY

			if(funcAns2==3)//DRUG TYPE
			{
				printf("Old drug type---->%s\n",drug.type);
				printf("New type:\n");
				strcpy(drug.type,determineType());/*call to function determineType*/
					
				printf("\n\nSUCCESS!! NEW DRUG TYPE---->%s\n",drug.type);	
			}//END OF DRUG TYPE

			if(funcAns2==4)//ADD OR REMOVE STOCK
			{
				printf("Old drug amount---->%d\n",drug.quantity);
				printf("Enter the amount to add(+) / remove(-)---->");
				scanf("%d",&number);
				
				while((drug.quantity+number)<0)/*check for error*/
				{
					printf("\n\n!!ERROR 0021!! Amount being removed is more than amount in stock!\n");
					printf("Please re-enter amount add(+) / remove(-)---->");
					scanf("%d",&number);
				}/*end while*/
				
				drug.quantity=drug.quantity+number;
				
				printf("\n\nSUCCESS!! NEW DRUG AMOUNT---->%d\n",drug.quantity);	
			}//END OF ADD OR REMOVE STOCK

			if(funcAns2==5)//PRICE
			{
				printf("Old selling price---->$%.2f\n",drug.price);
				printf("Enter the new selling price of the drug---->");
				scanf("%f",&drug.price);
				
				printf("\n\nSUCCESS!! NEW SELLING PRICE---->$%.2f\n",drug.price);	
			}//END OF PRICE
			
			printf("What else would you like to update?\n");
			funcAns2=editMenu();/*call to function editMenu*/
		}/*end while*/
		
		if(funcAns2==6)
		{
			printf("\n\n");
			printf("Okay. The drug's information is as follows:\n");
			stockFormat(drug);
		}/*end if*/
		
		fseek(drugFile,(drug.ID-1)*sizeof(struct drugInfo),SEEK_SET);
		fwrite(&drug,sizeof(struct drugInfo),1,drugFile);
		
		printf("***********************************\n");
		printf("****END OF UPDATE DRUG FUNCTION****\n");
		printf("***********************************\n\n\n");
		fclose(drugFile);
	}/*end if*/
}//end updateDrug


//DELETES DRUG INFORMATION
void deleteDrug()
{
	FILE*drugFile;//POINTER TO STOCK FILE
	struct drugInfo drug={0,"","","",0,0.0};
	struct drugInfo blankDrug={0,"","","",0,0.0};
	int identification;
	
	if ((drugFile = fopen("myfiledrugs", "rb+"))==NULL)
	{
		printf("Cannot open drug file \n");
		exit(1);
	}/*end if*/
	
	printf("============================================================\n\n");
	printf("\t\t\t DELETE RECORDS \t\t\t\n\n");
	printf("============================================================\n\n");
	
	miniDrugs();/*call to fuction miniDrugs*/
	printf("[WARNING] WILL DELETE DRUG INFORMATION PERMANENTLY [WARNING]\n");
	printf("Enter the ID of the drug to delete.(-1 to cancel)---->");
	scanf("%d",&identification);
	
	if(identification!=-1)
	{
		fseek(drugFile,(identification-1)*sizeof(struct drugInfo),SEEK_SET);
		fread(&drug,sizeof(struct drugInfo),1,drugFile);
		printf("\n\n");
		
		if(drug.ID!=identification)/*drug was not found*/
		{
			printf("============================================================\n\n");
			printf("             !!!!!!NO DRUG INFORMATION FOUND!!!!!!          \n\n");
			printf("============================================================\n\n\n");
		}/*end if*/
		
		if(drug.ID==identification)/*drug was found*/
		{
			fseek(drugFile,(drug.ID-1)*sizeof(struct drugInfo),SEEK_SET);
			fwrite(&blankDrug,sizeof(struct drugInfo),1,drugFile);
			
			printf("============================================================\n\n");
			printf("\t\t\t DELETE COMPLETE \t\t\t\n\n");
			printf("============================================================\n\n\n"); 
		}/*end if*/
	}/*end if*/
	else
	{
		printf("\n\nDelete cancelled.\n\n\n");
	}/*end else*/
	
	printf("***************************************\n");
	printf("*****END OF DELETE A DRUG FUNCTION*****\n");
	printf("***************************************\n\n\n");
	fclose(drugFile);
}//end deleteDrug


//STOCK MANAGEMENT
void stockManagement()
{
	int funcAns=stockMenu();/*call to function stockMenu*/
	
	while(funcAns!=6)
	{
		if(funcAns==1)//CREATES A NEW RECORD FOR AN DRUG
		{
			addDrug();/*call to function addDrug*/
		}//END OF ADD DRUG
		
		if(funcAns==2)//SEARCH FOR DRUG
		{
			searchDrug();/*call to function searchDrug*/
		}//END OF SEARCH FOR DRUG
		
		if(funcAns==3)//ALLOWS USER TO DISPLAY STOCK
		{
			displayStock();/*call to function displayStock*/
		}//END DISPLAY STOCK
		
		if(funcAns==4)//ALLOWS USER TO UPDATE THE INFORMATION OF A DRUG
		{
			updateDrug();/*call to function updateDrug*/
		}//END OF UPDATE DRUG INFORMATION
		
		if(funcAns==5)//DELETES A DRUG RECORD
		{
			deleteDrug();/*call to function deleteDrug*/
		}//END OF DELETE DRUG
		
		funcAns=stockMenu();/*call to function stockMenu*/
	}/*end while*/
		
	if(funcAns==6)
	{
		printf("\n\n");
		printf("******************************************************************\n");
		printf("                    Returning to Employee Menu                    \n");
		printf("******************************************************************\n\n\n");
	}/*end if*/
}//end stockManagement


//DISPLAYS ORDERS FROM QUEUE FILE
void viewQueuedOrders()
{
	FILE*queueFile;//POINTER TO QUEUE FILE
	struct queueInfo queue={0,0,"","","",0,0.0,0.0,0};
	
	/*set queue.position to 0 before while*/
	queue.position=0;/*allows function to run more than once without error*/
	int Auto=readAutoIndex();/*gets index*/
		
	if((queueFile = fopen("myfilequeue", "rb+"))==NULL)
	{
		printf("Cannot open queue file \n");
		exit(1);
	}/*end if*/
	
	printf("============================================================\n\n");
	printf("                        QUEUED ORDERS                       \n\n");
	printf("============================================================\n\n\n\n");
	
	while((!feof(queueFile))&&(queue.position<=Auto))
	{  
		fread(&queue,sizeof(struct queueInfo),1,queueFile); 
		if(queue.position!=0)/*if record exists*/
		{
			queueFormat(queue);/*call to function queueFormat*/
		}/*end if*/		
	}/*end while*/
	
	printf("\n\n\n\n");
	printf("*********************************************\n");
	printf("****END OF DISPLAY QUEUED ORDERS FUNCTION****\n");
	printf("*********************************************\n\n\n");
	fclose(queueFile);
}//end viewQueuedOrders


//DISPLAYS ORDERS FROM ORDER FILE
void viewOrders()
{
	FILE*orderFile;//POINTER TO ORDER FILE
	int i;
	struct orderInfo order={0,"","","",0,0.0,0.0,0};
	
	if((orderFile = fopen("myfileorders", "rb+"))==NULL)
	{
		printf("Cannot open order file \n");
		exit(1);
	}/*end if*/
	
	printf("===========================================================\n\n");
	printf("                ALL RECORDED CUSTOMER ORDERS               \n\n");
	printf("===========================================================\n\n\n\n");
	
	while(!feof(orderFile))
	{   
		fread(&order,sizeof(struct orderInfo),1,orderFile);
		if(order.ID!=0)
		{
			orderFormat(order);/*call to function orderFormat*/
		}/*end if*/
	}/*end while*/
	
	printf("\n\n\n\n");
	printf("******************************************\n");
	printf("****END OF DISPLAY ALL ORDERS FUNCTION****\n");
	printf("******************************************\n\n\n");

	fclose(orderFile);
}//end viewOrders


//SEARCHES ORDER FILE FOR A SPECIFIC ORDER
void findOrder()
{
	FILE*orderFile;//POINTER TO ORDER FILE
	FILE*queueFile;//POINTER TO QUEUE FILE
	int i,identification,found=0;
	int Auto=readAutoIndex();/*gets index*/
	struct orderInfo order={0,"","","",0,0.0,0.0,0};
	struct queueInfo queue={0,0,"","","",0,0.0,0.0,0};
	
	if((orderFile = fopen("myfileorders", "rb+"))==NULL)
	{
		printf("Cannot open order file \n");
		exit(1);
	}/*end if*/
	if((queueFile = fopen("myfilequeue", "rb+"))==NULL)
	{
		printf("Cannot open queue file \n");
		exit(1);
	}/*end if*/
	
	printf("============================================================\n\n");
	printf("                     SEARCH FOR AN ORDER                    \n\n");
	printf("============================================================\n\n\n\n");				
	printf("Enter customer ID to search---->");
	scanf("%d",&identification);
	
	while(!feof(orderFile))
	{
		fread(&order,sizeof(struct orderInfo),1,orderFile);
		if(order.ID==identification)
		{
			printf("\n\n");
			orderFormat(order);/*call to function orderFormat*/
			
			found++;
		}/*end if*/
	}/*end while*/
	
	if(found>0)
	{
		while(!feof(queueFile))
		{
			fread(&queue,sizeof(struct queueInfo),1,queueFile);/*Read Mode*/
			if(queue.ID==identification)
			{
				found++;
			}/*end if*/
		}/*end while*/
		if(found==2)
		{
			printf("======= ORDER IS STILL IN QUEUE =======\n\n");
		}/*end if*/
		if(found==1)
		{
			printf("======= ORDER HAS BEEN RECEIVED =======\n\n");
		}/*end else*/
	}/*end if*/
	
	if(found==0)
	{
		printf("\n\n");
		printf("============================================================\n\n");
		printf("             !!!!!!RECORD HAS NO INFORMATION!!!!!!          \n\n");
		printf("============================================================\n\n");
	}/*end if*/
	
	printf("\n\n");
	printf("*******************************************\n");
	printf("****END OF SEARCH FOR AN ORDER FUNCTION****\n");
	printf("*******************************************\n");
	printf("\n\n");	 
	fclose(orderFile);
}//end findOrder


//DISPLAYS TOTAL BUSINESS SALES
void displaySales()
{
	FILE*orderFile;//POINTER TO ORDER FILE
	struct orderInfo order={0,"","","",0,0.0,0.0,0};
	float totalSales=0;
	
	if((orderFile = fopen("myfileorders", "rb+"))==NULL)
	{
		printf("Cannot open order file \n");
		exit(1);
	}/*end if*/
	
	while(!feof(orderFile))
	{
		fread(&order,sizeof(struct orderInfo),1,orderFile);
		if(order.ID!=0)
		{
			totalSales=totalSales+order.totalCost;
		}/*end if*/   
	}/*end while*/
	
	printf("\n\n\n\n");
	printf("*******************************************************************\n");
	printf("*******************************************************************\n\n");
	printf("                     TOTAL SALES========>$%.2f                     \n\n",totalSales);
	printf("*******************************************************************\n");
	printf("*******************************************************************\n\n\n\n\n\n\n\n");
	
	printf("*************************************\n");
	printf("****END OF DISPLAY SALES FUNCTION****\n");
	printf("*************************************\n\n\n");
	fclose(orderFile);
}//end displaySales


//DELETES INDIVIDUAL ORDERS FROM BOTH ORDER & QUEUE FILES
void deleteOrder()
{
	FILE*pointer1;
	FILE*pointer2;
	FILE*pointer3;//2ND POINTER TO QUEUE FILE
	int identification,i,val,deleted=0;
	struct orderInfo order={0,"","","",0,0.0,0.0,0};
	struct orderInfo blankOrder={0,"","","",0,0.0,0.0,0};
	struct queueInfo queue={0,0,"","","",0,0.0,0.0,0};
	struct queueInfo blankQueue={0,0,"","","",0,0.0,0.0,0};
	
	/*open pointer to order file*/
	if((pointer1 = fopen("myfileorders", "rb+"))==NULL)
	{
		printf("Cannot open order file \n");
		exit(1);
	}/*end if*/
	
	/*open pointer to queue file*/
	if((pointer2 = fopen("myfilequeue", "rb+"))==NULL)
	{
		printf("Cannot open queue file \n");
		exit(1);
	}/*end if*/
	/*open another pointer to queue file*/
	pointer3 = fopen("myfilequeue", "rb+");
	
	printf("============================================================\n\n");
	printf("                       DELETE AN ORDER                      \n\n");
	printf("============================================================\n\n\n\n");
	printf("[WARNING] WILL DELETE RECORD IN BOTH QUEUE & ORDER FILES [WARNING]\n");
	printf("Enter the ID of the customer to delete their order.(-1 to cancel)---->");
	scanf("%d",&identification);
	
	if(identification!=-1)
	{
		fseek(pointer1,(identification-1)*sizeof(struct orderInfo),SEEK_SET);
		fread(&order,sizeof(struct orderInfo),1,pointer1);
		printf("\n\n");
		
		if(order.ID!=identification)/*if record doesn't exist*/
		{
			printf("============================================================\n\n");
			printf("             !!!!!!RECORD DOES NOT EXIST!!!!!!              \n\n");
			printf("============================================================\n\n\n");
		}/*end if*/
		if(order.ID==identification)/*if record does exist*/
		{
			fseek(pointer1,(order.ID-1)*sizeof(struct orderInfo),SEEK_SET);
			fwrite(&blankOrder,sizeof(struct orderInfo),1,pointer1);/*write blank record*/
			
			printf("============================================================\n\n");
			printf("\t\t\t DELETE COMPLETE \t\t\t\n\n");
			printf("============================================================\n\n\n");
			printf("======= ORDER WITH ID %d HAS BEEN DELETED FROM ORDER FILE =======\n\n\n",identification);
		}/*end if*/
		fclose(pointer1);/*close pointer to order file*/  
		
		/*call to function which returns index value from auto file*/
		int deleteNum=readAutoIndex();
		if(deleteNum<0)/*check for error situation*/
		{
			printf("               ======= QUEUE FILE IS EMPTY =======\n\n\n");
		}
		else
		{	
			while((!feof(pointer2))&&(queue.position<=deleteNum))
			{
				fread(&queue,sizeof(struct queueInfo),1,pointer2);
				if(queue.ID==identification)/*if record is found in queue*/
				{
					val=queue.ID;/*takes ID of customer in queue*/
					
					/*delete from queue file*/
					fseek(pointer2,(queue.position-1)*sizeof(struct queueInfo),SEEK_SET);
					fwrite(&blankQueue,sizeof(struct queueInfo),1,pointer2);
					
					/*moving up records in file after delete*/
					for(i=(queue.position-1);i<deleteNum;i++)
					{
						fseek(pointer2,(i)*sizeof(struct queueInfo),SEEK_SET);/*find point i in file*/
						fseek(pointer3,(i+1)*sizeof(struct queueInfo),SEEK_SET);/*find point (i+1) in file*/
						fread(&queue,sizeof(struct queueInfo),1,pointer3);/*read record in (i+1) slot of file*/
						queue.position=i+1;
						fwrite(&queue,sizeof(struct queueInfo),1,pointer2);/*write record in slot (i+1) of file in slot i*/
					}/*end for*/
					
					deleted=1;
				}/*end if*/
			}/*end while*/	
			
			if(deleted==1)/*if record not found in queue*/
			{
				printf("   ======= ORDER WITH ID %d HAS BEEN DELETED FROM QUEUE =======\n\n\n",identification);
				autocreateIndex(deleteNum-1);/*index decremented by 1 after and its new value written to file*/
			}/*end if*/
			
			fclose(pointer2);/*close pointer to queue file*/
			fclose(pointer3);/*close second pointer to queue file*/
		}/*end else*/
	}/*end if*/
	else
	{
		printf("\n\nDelete cancelled.\n\n\n");
	}/*end else*/
	
	printf("***************************************\n");
	printf("****END OF DELETE AN ORDER FUNCTION****\n");
	printf("***************************************\n\n\n");
}//end deleteOrder


//DETERMINES NUMBER OF RECORDS IN THE FILES
int size()
{
	int numRecords;
	
	numRecords=(readAutoIndex())+1;
	
	return(numRecords);
}//end size


//CHECKS IF QUEUE IS EMPTY
bool isEmpty()
{
	if(readAutoIndex()==-1)
	{
		return true;	
	}/*end if*/
	else
	{
		return false;
	}/*end else*/
}//end isEmpty


//PHARMACY MANAGEMENT
void pharmacyManagement()
{
	int funcAns=pharmacyMenu();/*call to function pharmacyMenu*/

	while(funcAns!=8)
	{
		if(funcAns==1)//DISPLAY ORDERS IN QUEUE
		{
			viewQueuedOrders();/*call to function viewQueuedOrders*/
		}//END OF DISPLAY ORDERS IN QUEUE
		
		if(funcAns==2)//DISPLAY ORDERS IN ORDER FILE
		{
			viewOrders();/*call to function viewOrders*/
		}//END OF DISPLAY ORDERS IN ORDER FILE
		
		if(funcAns==3)//SEARCH FOR CUSTOMER ORDER
		{		  		  
			findOrder();/*call to function findOrder*/
		}//END OF SEARCH FOR CUSTOMER ORDER		
		
		if(funcAns==4)//DISPLAY TOTAL SALES
		{	
			displaySales();/*call to function displaySales*/
		}//END OF DISPLAY TOTAL SALES
		
		if(funcAns==5)//DELETE AN ORDER
		{
			deleteOrder();/*call to function deleteOrder*/
		}//END OF DELETE AN ORDER
		
		if(funcAns==6)//DETERMINE NUMBER OF ORDERS IN QUEUE FILE	
		{
			printf("============================================================\n\n");
			printf("               QUERY NUMBER OF ORDERS IN QUEUE              \n\n");
			printf("============================================================\n\n\n\n");
			int number=size();/*call to function size*/
			printf("============================================================\n");
			printf("            Number of orders in the queue====>%d\n",number);
			printf("============================================================\n\n\n\n");
			
			printf("***********************************************\n");
			printf("****END OF QUERY NUMBER OF RECORDS FUNCTION****\n");
			printf("***********************************************\n\n\n");
		}//END OF DETERMINE NUMBER OF ORDERS IN QUEUE FILE		
		
		if(funcAns==7)//CHECK IF QUEUE FILE EMPTY
		{
			printf("=============================================================\n\n");
			printf("                   DETEMINE IF QUEUE EMPTY                   \n\n");
			printf("=============================================================\n\n\n\n");
			
			if(isEmpty())/*call to function isEmpty*/
			{
				printf("==============================================================\n");
				printf("==================     QUEUE IS EMPTY     ====================\n");
				printf("==============================================================\n\n\n\n");
			}/*end if*/
			else
			{
				printf("==============================================================\n");
				printf("==================   QUEUE IS NOT EMPTY   ====================\n");
				printf("==============================================================\n\n\n\n");
			}/*end else*/
			
			printf("***********************************************\n");
			printf("****END OF DETERMINE IF FILE EMPTY FUNCTION****\n");
			printf("***********************************************\n\n\n");
		}//END OF CHECK IF QUEUE FILE EMPTY
		
		funcAns=pharmacyMenu();			
	}/*end while*/
	
	if(funcAns==8)
	{
		printf("\n\n");
		printf("******************************************************************\n");
		printf("                    Returning to Employee Menu                    \n");
		printf("******************************************************************\n\n\n");
	}/*end if*/   
}//end pharmacyManagement


//"QUEUES" UP ORDER IN QUEUE FILE
void enqueueOrder(FILE*pointer, struct queueInfo queue)
{
	int indexs=readAutoIndex();/*get index from auto file*/
	
	/*open binary file for reading and writing*/
	if((pointer = fopen("myfilequeue", "rb+"))==NULL)
	{
		printf("Cannot open queue file \n");
		exit(1);
	}/*end if*/
	
	if(indexs==(length-1))
	{
		printf("Queue is full.\n");
	}/*end if*/
	else
	{
		indexs++;/*determines position to write the entered record into file*/
		
		/*find point in file to write the record*/
		fseek(pointer,(indexs)*sizeof(struct queueInfo),SEEK_SET);
		fwrite(&queue,sizeof(struct queueInfo),1,pointer);/*write record*/
	}/*end else*/
	
	autocreateIndex(indexs);/*writes new value of index to text file*/
	
	fclose(pointer);/*close file*/
}//end enqueueorderInfo


//"DEQUEUES" RECORDS FROM QUEUE FILE
int dequeueOrder(FILE*pointer1)
{
	FILE*pointer2;//2ND POINTER TO QUEUE FILE
	struct queueInfo queue={0,0,"","","",0,0.0,0.0,0};
	struct queueInfo blankQueue={0,0,"","","",0,0.0,0.0,0};
	
	int i,val;
	
	/*open pointer to the file*/
	if((pointer1 = fopen("myfilequeue", "rb+"))==NULL)
	{
		printf("Cannot open queue file \n");
		exit(1);
	}/*end if*/
	/*open another pointer to the file*/
	pointer2 = fopen("myfilequeue", "rb+");
	
	/*call to function which returns index value from auto file*/
	int deleteNum=readAutoIndex();
	
	if(deleteNum<0)/*check for error situation*/
	{
		printf("FILE IS EMPTY. NO RECORDS PRESENT.\n");
	}
	else
	{
		/*seek record to delete, i.e. the first record*/
		fseek(pointer1,(0)*sizeof(struct queueInfo),SEEK_SET);
		/*read record to delete*/
		fread(&queue,sizeof(struct queueInfo),1,pointer1);
		
		if(queue.position==0)/*if record doesn't exist*/
		{
			printf("\n\n");
			printf("============================================================\n\n");
			printf("             !!!!!!RECORD DOES NOT EXIST!!!!!!              \n\n");
			printf("============================================================\n\n");
		}/*end if*/
		
		if(queue.position!=0)/*if record exists*/
		{
			val=queue.ID;/*takes ID of customer in queue*/
			
			/*write blank record in its place*/
			fseek(pointer1,(0)*sizeof(struct queueInfo),SEEK_SET);
			fwrite(&blankQueue,sizeof(struct queueInfo),1,pointer1);
			
			/*moving up records in file after delete*/
			for(i=0;i<deleteNum;i++)
			{
				fseek(pointer1,(i)*sizeof(struct queueInfo),SEEK_SET);/*find point i in file*/
				fseek(pointer2,(i+1)*sizeof(struct queueInfo),SEEK_SET);/*find point (i+1) in file*/
				fread(&queue,sizeof(struct queueInfo),1,pointer2);/*read record in (i+1) slot of file*/
				queue.position=i+1;
				fwrite(&queue,sizeof(struct queueInfo),1,pointer1);/*write record in slot (i+1) of file in slot i*/
			}/*end for*/
			
			autocreateIndex(deleteNum-1);/*index decremented by 1 after and its new value written to file*/
		}/*end if*/
		fclose(pointer1);/*close pointer to file*/
		fclose(pointer2);/*close second pointer to file*/
	}/*end else*/
	
	return val;
}//end dequeueOrder


//ORDER FUNCTIONS
void orderFunc()
{
	FILE*drugFile;//POINTER TO STOCK FILE
	FILE*orderFile;//POINTER TO ORDER FILE
	FILE*queueFile;//POINTER TO QUEUE FILE
	int val,identification,num;
	static int taken=0,number=0;
	char answer[4],confirmOrder[4];
	float cost;
	float drugCostATP; /*shows drug cost at time of purchase*/
	
	struct drugInfo drug={0,"","","",0,0.0};
	struct orderInfo order={0,"","","",0,0.0,0.0,0};
	struct queueInfo queue={0,0,"","","",0,0.0,0.0,0};
	
	int funcAns=orderMenu();/*call to function orderMenu*/

	while(funcAns!=3)
	{
		if(funcAns==1)//MAKE AN ORDER
		{
			if((drugFile = fopen("myfiledrugs", "rb+"))==NULL)
			{
				printf("Cannot open drug file \n");
				exit(1);                   
			}/*end if*/
			if((orderFile = fopen("myfileorders", "rb+"))==NULL)
			{
				printf("Cannot open order file \n");
				exit(1);
			}/*end if*/
			if((queueFile = fopen("myfilequeue", "rb+"))==NULL)
			{
				printf("Cannot open queue file \n");
				exit(1);
			}/*end if*/
			
			/*initialise values*/
			order.totalCost=0;
			order.totalNumOrders=0;
			queue.totalCost=0;
			queue.totalNumOrders=0;
			queue.position=readAutoIndex()+2;/*auto generate customer pos. in queue*/
			
			printf("\n\n");
			printf("*************************************************************\n");
			printf("*************************************************************\n");
			printf("***********            MAKE AN ORDER              ***********\n");
			printf("*************************************************************\n");
			printf("*************************************************************\n\n\n\n");
			
			int upper=10000,lower=1;/*setting upper and lower values for range*/
			srand(time(NULL));/*call this function so ID generated always changes*/
			int val=rand()%(upper-lower+1)+lower;/*generates random number between 1 and 10000 inclusive*/
			
			while(taken!=2)
			{
				while(!feof(orderFile))/*check if ID already taken*/
				{
					fread(&order,sizeof(struct orderInfo),1,orderFile);
					while(order.ID==val)
					{
						taken=0;
						val=rand()%(upper-lower+1)+lower;
					}/*end while*/
				}/*end while*/
				taken++;
				rewind(orderFile);/*reset file pointer to beginning*/
			}/*end while*/
			
			printf("Customer ID: %04d\n\n",val);
			order.ID=val;/*write val to order.ID*/
			
			fgetc(stdin);
			printf("\nEnter your first name---->");
			scanf("%[^\n]%*c",order.firstname);
			printf("\nEnter your last name---->");
			scanf("%[^\n]%*c",order.lastname);
			
			/*copy to struct queueInfo*/
			queue.ID=order.ID;/*copy to queue*/
			strcpy(queue.firstname,order.firstname);
			strcpy(queue.lastname,order.lastname);
			
			miniDrugs();/*call to fuction miniDrugs*/
			printf("Enter the ID of the drug to purchase (-1 to terminate)---->");
			scanf("%d",&identification);
			
			while((identification!=-1)&&(order.totalNumOrders!=10))
			{/*repeat until termination requested or ten orders are made*/
				fseek(drugFile,(identification-1)*sizeof(struct drugInfo),SEEK_SET);
				fread(&drug,sizeof(struct drugInfo),1,drugFile);
				/*Read Mode*/ 
				if(drug.ID!=identification)
				{
					printf("\n\n\n\n");
					printf("============================================================\n\n");
					printf("              !!!!!!DRUG DOES NOT EXIST!!!!!!               \n\n");
					printf("============================================================\n\n\n\n");
				}/*end if*/
				
				if(drug.ID==identification)
				{   
					number=0;
					if(order.totalNumOrders>0)
					{
						printf("\n\n");
						printf("************************************************************\n");
						printf("                  CONTINUING WITH PURCHASE                  \n");
						printf("************************************************************\n\n");
					}
					printf("Drug requested---->%s\n\n",drug.name);						
					printf("Enter the desired amount of the drug---->");
					scanf("%d",&number);
					
					while((number<=0)||(number>drug.quantity))/*check for error*/
					{
						while(number<=0)/*if too little requested*/
						{
							printf("\n\n!!ERROR 0344!! Requested amount is < or = 0!\n\n");
							printf("Enter the desired amount again---->");
							scanf("%d",&number);
						}/*end while*/
						while(number>drug.quantity)/*if too much requested*/
						{
							printf("\n\n!!ERROR 0364!! Not enough stock!\n\n");
							printf("Enter the desired amount again---->");
							scanf("%d",&number);
						}/*end while*/
					}/*end while*/
					
					cost=drug.price*number;
					printf("\nCost is $%.2f. Is this okay? (yes or no)---->",cost);
					scanf(" %s",&answer);
					
					while((stricmp(answer,"yes")!=0)&&(stricmp(answer,"no")!=0))
					{
						printf("\n\n!!ERROR 0090!! Invalid answer!\n");
						printf("Enter your answer again (yes or no)---->");
						scanf(" %s",&answer);
					}/*end while*/
				
					if(stricmp(answer,"yes")==0)
					{
						/*add to orderInfo structure*/
						strcpy(order.drug[order.totalNumOrders],drug.name);
						order.quantity[order.totalNumOrders]=number;
						order.cost[order.totalNumOrders]=cost;
						order.totalCost=order.totalCost+cost;
						order.totalNumOrders++;
						
						/*add to queueInfo structure*/
						strcpy(queue.drug[queue.totalNumOrders],drug.name);
						queue.quantity[queue.totalNumOrders]=number;
						queue.cost[queue.totalNumOrders]=cost;
						queue.totalCost=queue.totalCost+cost;
						queue.totalNumOrders++;
						
						drug.quantity=drug.quantity-number;
						
						fseek(drugFile,(drug.ID-1)*sizeof(struct drugInfo),SEEK_SET);
						fwrite(&drug,sizeof(struct drugInfo),1,drugFile);
						fclose(drugFile);/*temporarly close file so changes are recorded in minilist*/
						drugFile=fopen ("myfiledrugs", "rb+");/*reopen file*/
						
						printf("\n\nSUCCESS!! PURCHASE WAS MADE!!\n\n");
					}/*end if*/
					
					if(stricmp(answer,"no")==0)
					{
						printf("\n\nOkay. No purchase was made.\n\n");
					}/*end if*/
				}/*end if*/
				
				miniDrugs();/*call to fuction miniDrugs*/
				printf("Enter the ID of the drug to purchase (-1 to terminate)---->");
				scanf("%d",&identification);		
			}/*end while*/
			
			if(order.totalNumOrders>0)/*only writes order to file if purchase was made*/
			{
				printf("\n\n\n======= YOUR ORDER IS COMPLETE! YOU ARE IN POSITION %d IN THE QUEUE! =======\n\n\n",queue.position);
				printf("                 ======= THANK YOU FOR STOPPING BY! =======\n\n\n\n\n");
				
				enqueueOrder(queueFile,queue);/*call to function enqueueOrder*/
				fseek(orderFile,(order.ID-1)*sizeof(struct orderInfo),SEEK_SET);/*seeks position to write in order file*/
				fwrite(&order,sizeof(struct orderInfo),1,orderFile);/*write customer order to order file*/
			}/*end if*/
			else
			{
				printf("\n\n\n======= THE ORDER WAS CANCELLED =======\n\n\n\n\n");
			}/*end if*/
			
			printf("***********************************\n");
			printf("***END OF MAKE AN ORDER FUNCTION***\n");
			printf("***********************************\n\n\n");
			fclose(drugFile);
			fclose(orderFile);
			fclose(queueFile);
		}//END OF MAKE AN ORDER
		
		if(funcAns==2)//RECEIVE ORDER
		{
			if((queueFile = fopen("myfilequeue", "rb+"))==NULL)
			{
				printf("Cannot open queue file \n");
				exit(1);
			}/*end if*/
			
			printf("\n\n");
			printf("*************************************************************\n");
			printf("*************************************************************\n");
			printf("***********            RECEIVE ORDER              ***********\n");
			printf("*************************************************************\n");
			printf("*************************************************************\n\n\n\n");
			
			if(isEmpty())
			{
				printf("            ======= NO ONE IS IN QUEUE =======\n\n\n\n\n");
			}
			else
			{
				printf("=============================================================\n\n");
				printf("              +*+*+ WELCOME BACK CUSTOMER +*+*+              \n\n");
				printf("=============================================================\n\n");
				fseek(queueFile,(0)*sizeof(struct queueInfo),SEEK_SET);
				fread(&queue,sizeof(struct queueInfo),1,queueFile);
				
				printf("+++++++++++++++++++++  ORDER ID: %04d  ++++++++++++++++++++++\n\n",queue.ID);
				printf("Is this your order ID? If not, please seek help from staff.\n");
				printf("Answer yes or no---->");
				scanf("%s",&confirmOrder);
				
				while((stricmp(confirmOrder,"yes")!=0)&&(stricmp(confirmOrder,"no")!=0))
				{
					printf("\n\n!!ERROR 0090!! Invalid answer!\n");
					printf("Enter your answer again (yes or no)---->");
					scanf("%s",&confirmOrder);
				}/*end while*/
				
				if(stricmp(confirmOrder,"yes")==0)//YES
				{
					printf("\n\n\nPrinting your bill........\n\n\n");
					queueFormat(queue);/*call to function queueFormat*/
					int serveID=dequeueOrder(queueFile);/*call to function dequeueOrder*/
					
					printf("\n\n++++++++++++++++++  ORDER %04d DEQUEUED  ++++++++++++++++++++\n\n",serveID);
					printf("\n\n");
					printf("=============================================================\n\n");
					printf("          *+*+* YOUR ORDER HAS BEEN FULFILLED *+*+*          \n");
					printf("           *+*+* THANK YOU FOR YOUR PURCHASE *+*+*           \n\n");
					printf("=============================================================\n\n\n\n\n");
				}/*end if*/
				if(stricmp(confirmOrder,"no")==0)//NO
				{
					printf("\n\n\n        ======= NO ORDER HAS BEEN FULFILLED =======\n\n\n\n\n");
				}/*end if*/
			}/*end else*/
			
			printf("***********************************\n");
			printf("***END OF RECEIVE ORDER FUNCTION***\n");
			printf("***********************************\n\n\n");
			fclose(queueFile);
		}//END OF RECEIVE ORDER
		
		funcAns=orderMenu();/*call to function orderMenu*/
	}/*end while*/
	
	if(funcAns==3)
	{
		printf("\n\n");
		printf("******************************************************************\n");
		printf("                      Returning to Main Menu                      \n");
		printf("******************************************************************\n\n\n");
	}/*end if*/
}//end orderFunc


//MAIN PROGRAM
int main()
{   
	int result,resultEmp,pass,ans;
	
	password();/*call to function password*/
	result=mainMenu();/*call to function mainMenu*/

	while(result!=3)
	{	
		if(result==1)//EMPLOYEE MENU
		{
			pass=passwordEmployee();
			if(pass==1)/*if password is correct*/
			{
				resultEmp=employeeMenu();
				while(resultEmp!=4)
				{
					if(resultEmp==1)//CREATE NEW FILES
					{
						printf("[WARNING] WILL CREATE EMPTY FILES!!! [WARNING]\n");
						printf("Which new file do you want to create?\n\n");
						printf(" 1. Stock file only\n");
						printf(" 2. Queue file only\n");
						printf(" 3. Order & Queue File\n");
						printf(" 4. All three\n");
						printf(" 5. Cancel\n\n");
						printf("Task=====>");
						scanf("%d",&ans);
						
						while((ans<1)||(ans>5))/*check for error*/
						{
							printf("\n\n!!ERROR 0007!! Invalid value!\n");
							printf("Enter task again=====>");
							scanf("%d",&ans);
						}/*end while*/
						
						if(ans==1)
						{
							createFileStock();/*call to function createFileStock*/
						}/*end if*/
						if(ans==2)
						{
							createFileQueue();/*call to function createFileQueue*/
						}
						if(ans==3)
						{
							createFileOrder();/*call to function createFileOrder*/
							createFileQueue();/*call to function createFileQueue*/
						}/*end if*/
						if(ans==4)
						{
							createFileStock();
							createFileOrder();
							createFileQueue();
						}/*end if*/
						if(ans==5)
						{
							printf("\n\n");
							printf("Okay. No new file was made.\n\n");
						}/*end if*/
					}//END OF CREATE NEW FILES
					
					if(resultEmp==2)//STOCK MANAGEMENT
					{
						stockManagement();/*call to function stockManagement*/
					}//END OF STOCK MANAGEMENT
					
					if(resultEmp==3)//PHARMACY MANAGEMENT
					{
						pharmacyManagement();/*call to function pharmacyManagement*/
					}//END OF PHARMACY MANAGEMENT
					
					resultEmp=employeeMenu();
				}/*end while*/
				
				if(resultEmp==4)
				{
					printf("\n\n");
					printf("******************************************************************\n");
					printf("                      Returning to Main Menu                      \n");
					printf("******************************************************************\n\n\n");
				}/*end if*/
			}/*end if*/
		}/*end if*/
		
		if(result==2)//ENTER CUSTOMER MENU
		{	
			orderFunc();/*call to function orderFunc*/	
		} /*end if*/
		
		result=mainMenu();/*call to function mainMenu*/
	}/*end while*/
	
	if(result==3)//END THE PROGRAM
	{
		printf("\t\t\t PROGRAM SHUTTING DOWN...... \n\n\n");
		system("pause");
	}/*end if*/   
}//END PROGRAM
