struct customerInfo
{
	int ID;
	char firstname[strlength2];
	char lastname[strlength2];
	char telephone[25];
	char creditCard[13];
	char insuranceStat[4];
	char insuranceCompany[strlength];
	
	int totalPurchase;
	float totalSpent;
};

void createFileCustomer()
{
	FILE*customerFile;//POINTER TO CUSTOMER FILE
	int f;
	struct customerInfo customer={0,"","","","","","",0,0.0,0.0};/*declaring structure customerInfo*/
	
	if((customerFile = fopen("myfilecustomer","wb"))==NULL)
	{
		printf("Cannot open customer file \n");
		exit(1);
	}/*end if*/
	
	/*creating 10000 blank records*/
	for (f=0;f<1000;f++)
	{
		fwrite(&customer,sizeof(struct customerInfo),1,customerFile);
	}/*end for*/
	printf("\n\n");
	printf("*************************************************************\n");
	printf("******             CUSTOMER FILE CREATED               ******\n");
	printf("*************************************************************\n\n");
	fclose(customerFile);
}//end createFileCustomer


//ADDS A NEW CUSTOMER
void addCustomer()
{
	FILE*customerFile;//POINTER TO CUSTOMER FILE
	struct customerInfo customer={0,"","","","","","",0,0.0,0.0};
	
	static int taken=0;
	
	if((customerFile = fopen("myfilecustomer","wb"))==NULL)
	{
		printf("Cannot open customer file \n");
		exit(1);
	}/*end if*/
	
	printf("============================================================\n\n");
	printf("                     ADD A NEW CUSTOMER                     \n\n");
	printf("============================================================\n\n\n\n");
	
	int upper=10000,lower=1;/*setting upper and lower values for range*/
	srand(time(NULL));/*call this function so ID generated always changes*/
	int val=rand()%(upper-lower+1)+lower;/*generates random number between 1 and 10000 inclusive*/
	
	while(taken!=2)
	{
		while(!feof(customerFile))/*check if ID already taken*/
		{
			fread(&customer,sizeof(struct customerInfo),1,customerFile);
			while(customer.ID==val)
			{
				taken=0;
				val=rand()%(upper-lower+1)+lower;
			}/*end while*/
		}/*end while*/
		taken++;
		rewind(customerFile);/*reset file pointer to beginning*/
	}/*end while*/
	
	printf("Customer ID: %04d\n\n",val);
	customer.ID=val;/*write val to customer.ID*/
	
	printf("\n\nEnter your first name---->");
	scanf("%[^\n]%*c",&customer.firstname);
	printf("\nEnter your last name---->");
	scanf("%[^\n]%*c",&customer.lastname);
	
	printf("\nEnter your telephone number---->");
	scanf("%[^\n]%*c",&customer.telephone);
	printf("\nEnter your credit card no. (12 DIGITS)---->");
	scanf("%[^\n]%*c",&customer.creditCard);
	printf("\n\nDo you have insurance? (yes or no)---->");
	scanf("%s",&customer.insuranceStat);
	
	while((stricmp(customer.insuranceStat,"yes")!=0)&&(stricmp(customer.insuranceStat,"no")!=0))
	{
		printf("\n\n!!ERROR 0090!! Invalid answer!\n");
		printf("Enter your answer again (yes or no)---->");
		scanf("%s",&customer.insuranceStat);
	}/*end while*/
	
	if(stricmp(customer.insuranceStat,"yes")==0)
	{
		printf("\nPlease enter the name of the insurance company---->");
		scanf("%[^\n]%*c",&customer.insuranceCompany);
	}/*end if*/
	
	customer.totalPurchase=0;
	customer.totalSpent=0;
	
	fseek(customerFile,(customer.ID-1)*sizeof(struct customerInfo),SEEK_SET);
	fwrite(&customer,sizeof(struct customerInfo),1,customerFile);
	printf("\n\n");
	printf("**************************************\n");
	printf("****END OF ADD A NEW CUSTOMER FUNCTION****\n");
	printf("**************************************\n\n\n");
	fclose(customerFile);
}//end addCustomer
