#include<stdio.h>
#include<errno.h>//error handling
#include<stdlib.h>

#define strlength 25
#define strlength2 50
struct clientInfo
{   
	int ID;
	
	char first_name[strlength];
	char last_name[strlength];
 
    char DOB[strlength];
    char nationality[strlength2];
    float funds;
};

int MenuChoice()//menu gives user  a list of options 
{
    int choice;  
	
    printf("\n\n");
    printf("\n\n");
    printf("\n\n");

	printf("============================================================\n\n\t");
	printf("OPTION              DESCRIPTION                   \n\n");
    printf("============================================================\n\n\t ");
    
	printf("1 \t\t Create a new file\n\n\t ");
	printf("2 \t\t Add new account\n\n\t ");
	printf("3 \t\t Display account information\n\n\t ");
	printf("4 \t\t Account functions\n\n\t ");
	printf("5 \t\t Delete an account\n\n\t ");
	printf("6 \t\t Exit program\n\n");
   
	
	
    printf("====================================================================\n\n\t");
	printf("=>=>=>=>=>=>=>BANK OF PEDRO MARTINEZ=>=>=>=>=>=>=>\n\n");
    printf("====================================================================\n\n\t");
    printf("\n\n");
    printf("\n\n");
    printf("Task=====>");
    
    scanf("%d",&choice);
    
    return choice;
}/*End Function*/
    
main()
{   
	FILE*inDataFile1;//POINTER TO FILE
    int identification,result,f,num=0000,funcAns,answer2;
    char answer[4];
    float amount,deposit,withdraw;
    /*create studentinfo with default information*/          
     
	     
    result=MenuChoice();/*call to function MenuChoice*/	

	while(result!=6)
	{	
    	if(result==1)
    	{
            struct clientInfo client={0,"","","","",0.0}; 

            if((inDataFile1 = fopen("myfile5","wb"))==NULL)
            {
                printf("Cannot open file \n");
                exit(1);
            }/*end if*/ 
			else
			{
            	for (f=0;f<=100;f++)
                {
                    fwrite(&client,sizeof(struct clientInfo),1,inDataFile1);
                } /*end for*/      
 
             	fclose(inDataFile1);
            }/*end else*/
            
			printf("============================================================\n\n         ");
			printf("             		FILE CREATED                 \n\n");
    		printf("============================================================\n\n         ");
			result=MenuChoice();/*call to function MenuChoice*/
		}/*end if*/

 
		if(result==2)//PROMPT USER FOR INFO TO FILL RECORD
		{
    		struct clientInfo client={0,"","","","",0.0}; 
 
    	    if ((inDataFile1 = fopen("myfile5", "rb+"))==NULL)
            {
                printf("Cannot open file \n");
                exit(1);
            }/*end if*/
   		
   			num=num+1;
   			client.ID=num;
   			            
            printf("Enter first name--->");
            scanf("%s",&client.first_name);

            printf("Enter last name---->");
            scanf("%s",&client.last_name);
                        
            printf("Enter date of birth (DD/MM/YYYY)---->");
            scanf("%s",&client.DOB);  
            
            printf("Enter nationality---->");
            scanf("%s",&client.nationality);
            
            printf("You need a starting point of at least $100 for your account.\n");
			printf("How much are you starting with?---->");
            scanf("%f",&client.funds);
            
            while(client.funds<100)
            {
				printf("!!Error 16!!\n");
				printf("Amount entered is less than $100.\n");
				printf("Please re-enter the amount---->");
				scanf("%f",&client.funds);	
			}
         
            fseek(inDataFile1,(client.ID-1)*sizeof(struct clientInfo),SEEK_SET);
            fwrite(&client,sizeof(struct clientInfo),1,inDataFile1);
            fclose(inDataFile1);
	        result=MenuChoice();/*call to function MenuChoice*/       	 
		}//END IF		 
 	 

    
    	if(result==3)//VIEW RECORDS
    	{	
    	    struct clientInfo client={0,"","","","",0.0};
	
	        if((inDataFile1 = fopen("myfile5", "rb+"))==NULL)
	        {
	            printf("Cannot open file \n");                   
	        }/*end if*/
	        else
	        {
				printf("============================================================\n\n");
				printf("\t\t\t VIEW RECORDS \t\t\t\n\n");
				printf("============================================================\n\n");
	    		/*read and display every line in the file*/
    		
				while(!feof(inDataFile1))
				{   
					fread(&client,sizeof(struct clientInfo),1,inDataFile1);
					if(client.ID!=0)
					{
	                	printf("ID---->%d\n",client.ID);
						printf("NAME---->%s %s\n",client.first_name,client.last_name);
						printf("DOB---->%s\n",client.DOB);
						printf("NATIONALITY---->%s\n",client.nationality);
						printf("FUNDS---->$%.2f",client.funds);
						   	        	      
    	    	        printf("\n\n");
    		            printf("============================================================");
					}//END IF    
	    	    }/*end while*/
    	    }//end else
		
			fclose(inDataFile1);
     		result=MenuChoice();/*call to function MenuChoice*/	
		} /*end if*/   




		if(result==4)
		{     
			struct clientInfo client={0,"","","","",0.0};
  	      
	        if ((inDataFile1 = fopen("myfile5", "rb+"))==NULL)
	        {
				printf("Cannot open file \n");
				exit(1);
	        }/*end if*/
			else
			{
				printf("Enter account ID to update(1 to 100)--->");
				scanf("%d",&identification);
        
	            fseek(inDataFile1,(identification-1)*sizeof(struct clientInfo),SEEK_SET);
	            fread(&client,sizeof(struct clientInfo),1,inDataFile1);
	            /*Read Mode*/ 
	            if(client.ID==0)
	            {
	            	printf("============================================================\n\n         ");
					printf("             !!!!!!RECORD HAS NO INFORMATION!!!!!!                 \n\n");
	    			printf("============================================================\n\n\n\n\n        ");
	            }/*end if*/
            
				if(client.ID!=0)
	            {
	            	printf("\n");
					printf("ID---->%d\n",client.ID);
					printf("NAME---->%s %s\n",client.first_name,client.last_name);
					printf("DOB---->%s\n",client.DOB);
					printf("NATIONALITY---->%s\n",client.nationality);
					printf("FUNDS---->$%.2f",client.funds);
					printf("\n\n");
				
					printf("What would you like to do?\n");
					printf("1. Deposit\n");
					printf("2. Withdrawl\n");
					printf("3. Change account info\n\n");
					printf("Answer---->");
					scanf("%d",&funcAns);
				
					if(funcAns==1) //DEPOSIT
					{
						printf("\n");
						printf("Enter amount to deposit---->");
						scanf("%f",&deposit);
					
						client.funds=client.funds+deposit;
						printf("\n\n");
						printf("SUCCESS!\n");
					} //END OF DEPOSIT
					else
					if(funcAns==2) //WITHDRAWL
					{
						printf("\n");
						printf("Enter amount to withdraw---->");
						scanf("%f",&withdraw);
						
						while(withdraw>client.funds)
						{
							printf("\n");
							printf("!!Error 12!!\n");
							printf("Amount entered is more than amount in account.\n");
							printf("Please try again---->");
							scanf("%f",&withdraw);
						}
						
						if(withdraw==client.funds)
						{
							printf("\n");
							printf("Amount entered is the same as amount in account.\n");
							printf("Is this okay?--->");
							scanf("%s",&answer);
							
							if(stricmp(answer,"yes")==0)
							{
								printf("\n\n");
								printf("SUCCESS!\n");
							}
							else
							if(stricmp(answer,"no")==0)
							{
								printf("\n\n");
								printf("No changes have been made to your funds.\n");
							}
						}
						
						if(withdraw<client.funds)
						{
							client.funds=client.funds-withdraw;
							printf("\n\n");
							printf("SUCCESS!\n");
						}
					} //END OF WITHDRAWL
					else
					if(funcAns==3)
					{
						printf("\n\n");
						printf("What part of account information is to be changed?\n");
						printf("1. Name\n");
						printf("2. Date of Birth (DOB)\n");
						printf("3. Nationality\n");
						printf("4. Nothing\n\n");
						printf("Answer---->");
						scanf("%d",&answer2);
						
						while((answer2!=1)&&(answer2!=2)&&(answer2!=3)&&(answer2!=4))
						{
							printf("\n");
							printf("!!Error54!!\n");
							printf("Answer does not correspond with given options.\n");
							printf("Please try again---->");
							scanf("%d",&answer2);       	    			
						}
							
						while(answer2!=4)
						{
							if(answer2==1)
							{
								printf("Enter first name--->");
            					scanf("%s",&client.first_name);
	
    	        				printf("Enter last name---->");
    	        				scanf("%s",&client.last_name);
    	        				
    	        				printf("\n");
    	        				printf("NAME---->%s %s\n\n",client.first_name,client.last_name);
    	        			}
    	        			
    	        			if(answer2==2)
							{                        
    	        				printf("Enter date of birth (DD/MM/YYYY)---->");
								scanf("%s",&client.DOB);
								
								printf("\n");
								printf("DOB---->%s\n\n",client.DOB);
							}
							
							if(answer2==3)
							{            				
								printf("Enter nationality---->");
        	    				scanf("%s",&client.nationality);
        	    				
        	    				printf("\n");
        	    				printf("NATIONALITY---->%s\n\n",client.nationality);
        	    			}
        	    			
        	    			printf("\n\n");
        	    			printf("Would you like to change anything else?\n");
        	    			printf("1. Name\n");
							printf("2. Date of Birth (DOB)\n");
							printf("3. Nationality\n");
							printf("4. Nothing\n\n");
							printf("Answer---->");
							scanf("%d",&answer2);
							
							while((answer2!=1)&&(answer2!=2)&&(answer2!=3)&&(answer2!=4))
							{
								printf("\n");
								printf("!!Error54!!\n");
								printf("Answer does not correspond with given options.\n");
								printf("Please try again---->");
								scanf("%d",&answer2);       	    			
							}
        	    		}
        	    		if(answer2==4)
        	    		{
        	    			printf("Okay. Any changes made have been saved.\n\n");
						}
					}
				
					printf("NAME---->%s %s\nFUNDS---->$%.2f",client.first_name,client.last_name,client.funds);
					printf("\n\n");
					fseek(inDataFile1,(client.ID-1)*sizeof(struct clientInfo),SEEK_SET);
	            	fwrite(&client,sizeof(struct clientInfo),1,inDataFile1);
					fclose(inDataFile1);
						
				}/*end if*/  
			}/*end else*/
		
			result=MenuChoice();/*call to function MenuChoice*/	
		
		}/*end if*/                  
        
        if(result==5) 
        {
			struct clientInfo client={0,"","","","",0.0}; 

			struct clientInfo blankClient={0,"","","","",0.0};
			
			if((inDataFile1 = fopen("myfile5", "rb+"))==NULL)
			{
                printf("Cannot open file \n");
                exit(1);
            }/*end if*/
            
			printf("============================================================\n\n");
			printf("\t\t\t DELETE RECORDS \t\t\t\n\n");
    		printf("============================================================\n\n"); 
             
            printf("Enter student Id to delete(1 to 100)--->");
            scanf("%d",&identification);         
           
			fseek(inDataFile1,(identification-1)*sizeof(struct clientInfo),SEEK_SET);
			fread(&client,sizeof(struct clientInfo),1,inDataFile1);
			/*Read Mode*/
			
			if(client.ID==0)
			{
                printf("============================================================\n\n");
				printf("             !!!!!!RECORD DOES NOT EXIST!!!!!!              \n\n");
				printf("============================================================\n\n\n\n\n");
            }/*end if*/
            
            if(client.ID!=0)
            {
				fseek(inDataFile1,(client.ID-1)*sizeof(struct clientInfo),SEEK_SET);
				fwrite(&blankClient,sizeof(struct clientInfo),1,inDataFile1);

				printf("============================================================\n\n");
				printf("\t\t\t DELETE COMPLETE \t\t\t\n\n");
    			printf("============================================================\n\n"); 
            }            
            
			fclose(inDataFile1);
			result=MenuChoice();/*call to function MenuChoice*/	
		}//END IF
                  
 
		if(result==6) //user wants to 
		{
			system("pause");
		}//END IF                                                   
    
	}//END WHILE      
}//END PROGRAM
