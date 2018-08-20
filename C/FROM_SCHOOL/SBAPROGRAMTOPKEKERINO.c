#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define LENGTH 100
#define size 20

struct customer
{       
	int AutoID;
	int identify;
	char firstname[size];
	char lastname[size];
    
};

struct bread
{
	int identify2;
	int quantity;
	int max;
	char breadName[size];
	float price;
	float revenue;
	
};
  
 int autocreateIndex(int autoGeneratedIndex)
{
  
    	FILE*fileIndex;
    	int index;
         if ((fileIndex = fopen("auto", "w"))==NULL)
        	{
        			printf("Cannot open file \n");
        			exit(1);
        	}
         else
         {   index=autoGeneratedIndex;
        
        	/*printing data tofile*/
          	 fprintf(fileIndex,"%d",index);//writes the generated index to the record.
             
        	 fclose(fileIndex);/*close file*/
        	 
          }
}//end function

int readAutoIndex()
{
   
    	FILE*readAutoIndex;
    	int autoIndex,ans;
    /* open file for reading */
       if ((readAutoIndex= fopen("auto", "r"))==NULL)
     	{
      		printf("Cannot open file \n");
      		exit(errno);
        }/*end if*/
 
     	else
        {
    
        	fscanf(readAutoIndex,"%d",&autoIndex);
            ans=autoIndex;
        		 
        	//read and display every line in the file
        	while(!feof(readAutoIndex))//while not the end of the file
        	{
                   fscanf(readAutoIndex,"%d",&autoIndex);
                   ans=autoIndex;
            }
         return ans;
         printf("ANS%d",ans);
         fclose(readAutoIndex);  /*close file*/

        }//end else
}//end function

void enqueueCustomerInfo(FILE*BakeryInfo , struct customer Bakery)
{
            	if ((BakeryInfo = fopen("CustomerFile", "rb+"))==NULL)//open binary file for reading and writing
               {
                                printf("Cannot open sadad file \n");
                                exit(1);
                }/*end if*/

              int Auto=readAutoIndex();  //get index from auto file
    
              if( Auto== (LENGTH-1))
                   printf("Queue full.");
              else
              {
                    
		        Auto= Auto+1;//determine position to write the entered record to in the file
		    
                       
                fseek(BakeryInfo,( Auto)*sizeof(struct customer),SEEK_SET);//find point in file to
                                                                                    //write the record
                fwrite(&Bakery,sizeof(struct customer),1,BakeryInfo);//write the record
		       
                }//end else
                fclose(BakeryInfo);//close the file   
                autocreateIndex(Auto);//write new value of index to the text file
  
}//end enqueueStudentInfo() 

  

int MenuChoice()//menu gives user a list of options 

{
    int choice;
    
   	printf("\n\n");
    printf("\n\n");
    printf("\n\n");
     
	
    
    printf("\n\n");
    printf("\n\n");
    printf("\n\n");

    printf("============================================================\n\n         ");
	printf("OPTION              DESCRIPTION                   \n\n");
    printf("============================================================\n\n         ");
    
	printf("1               Create a new file\n\n");
	printf("         2               Add Customer Information\n\n");
	printf("         3               Display Customer Information \n\n");
 	printf("        4               Delete Customer\n\n ");
 	printf("        5               Bill Customer\n\n ");
 	printf("	 6		 Move to BreadMenu \n\n");
	printf("         7               Exit program\n\n ");
   
	
	
    printf("============================================================\n\n         ");
	printf("=>=>=>=>=>=>=>The Breadening=>=>=>=>=>=>=>\n\n");
    printf("============================================================\n\n         ");


    printf("\n\n");
    printf("\n\n");
    printf("Task=====>");
    
    scanf("%d",&choice);
    
    return choice;
}//End Function

int BreadMenu()//menu gives user  a list of options 
{
    int choices;
    
   	printf("\n\n");
   	printf("\n\n");
    printf("\n\n");
     
	
    
   	printf("\n\n");
    printf("\n\n");
    printf("\n\n");

    printf("============================================================\n\n         ");
	printf("OPTION              DESCRIPTION                   \n\n");
    printf("============================================================\n\n         ");
    
	printf("1             Create New File     \n\n");
	printf("	 2             Add bread information     \n\n");
	printf("         3             Update quantity of bread        \n\n");
	printf("         4             Update unit price of bread        \n\n");
	printf("         5             Display bread information and revenue made \n\n");
 	printf("         6             Search for bread information\n\n ");
 	printf("        7             Delete a  bread record\n\n ");
	printf("        8             Return to previous menu\n\n ");
   	
    printf("============================================================\n\n         ");
	printf("=>=>=>=>=>=>=>The Breadening=>=>=>=>=>=>=>\n\n");
    printf("============================================================\n\n         ");

    printf("\n\n");
    printf("\n\n");
    printf("Task=====>");
    
    scanf("%d",&choices); 
    
    return choices;
}//End Function
	
void createFile()//Function to create a new file
{
	FILE*BakeryInfo;//Pointer to file CustomerFile
	int f,result;
	struct customer Bakery={0,0,"",""}; 
			         
    if ((BakeryInfo = fopen("CustomerFile", "wb"))==NULL)
    {
        printf("Cannot open file \n");     
        exit(1);
    }//end if
    else
    {
        for (f=0;f<=100;f++)
        {
            fwrite(&Bakery,sizeof(struct customer),1,BakeryInfo);
        }//end for      
 
        fclose(BakeryInfo);
    }//end else
            
    printf("============================================================\n\n         ");
	printf("             FILE CREATED                 \n\n");
	printf("============================================================\n\n         ");
	    	
	
}//End Function

void AddCustomer()//Function to add information to Customer file
{
	FILE*BakeryInfo;//Pointer to file CustomerFile
	
	struct customer Bakery={0,0,"",""}; 
 	
	if ((BakeryInfo = fopen("CustomerFile", "rb+"))==NULL)
    {
        printf("Cannot open this file \n");
        exit(1);
   
    }//end if
    
	else
	{
		int passAuto=readAutoIndex();
        Bakery.AutoID=readAutoIndex()+2;
        
    	printf("Enter Customer identification--->");
    	scanf("%d",&Bakery.identify);
            
   		 printf("Enter first name--->");
    	 scanf("%s",&Bakery.firstname);

    	 printf("Enter last name---->");
    	 scanf("%s",&Bakery.lastname);
    	 
    	 enqueueCustomerInfo(BakeryInfo ,Bakery);
            
    		fclose(BakeryInfo);           	 
	}//end else
	
}//End Function

void DisplayInfo()//Function to display information from Customer file
{
	FILE*BakeryInfo;//Pointer to file CustomerFile
	int result;
	struct customer Bakery={0,0,"",""};  
        
    if ((BakeryInfo = fopen("CustomerFile", "rb+"))==NULL)
    {
        printf("Cannot open file \n");                                
    }//end if
    else
    {
		printf("============================================================\n\n         ");
        printf("             \n\n\n\t\t\tVIEW RECORDS                 \n\n");
        printf("============================================================\n\n         ");
    
	    /*read and display every line in the file*/
	
		while(!feof(BakeryInfo))
        {   
            fread(&Bakery,sizeof(struct customer),1,BakeryInfo);
            if(Bakery.identify!=0)
            {
                printf("ID: %d\n",Bakery.identify);
                printf("Name: %s %s\n",Bakery.firstname,Bakery.lastname); 
                                                                  				   
	            printf("\n\n");
                printf("============================================================\n\n         ");
            }//end if    
      
        }//end while
    
    }//end else
    
    fclose(BakeryInfo);   
}//End Function

void DeleteCustomer()//Function to delete information in Customer file
{
	FILE*BakeryInfo;//Pointer to file CustomerFile
	int identification;
	
	struct customer Bakery={0,0,"",""};

	struct customer blankBakery={0,0,"",""};
                      
    if ((BakeryInfo = fopen("CustomerFile", "rb+"))==NULL)
    {
        printf("Cannot open file \n");
        exit(1);
    }//end if
            
    printf("============================================================\n\n         ");
	printf("          \n\n\n\t\t\t DELETE RECORDS                 \n\n");
    printf("============================================================\n\n         "); 
             
    printf("Enter Customer Id to delete(1 to 100)--->");
    scanf("%d",&identification);         
           
           
    fseek(BakeryInfo,(identification-1)*sizeof(struct customer),SEEK_SET);
    fread(&Bakery,sizeof(struct customer),1,BakeryInfo);
            
    /*Read Mode*/ 
             
    if(Bakery.identify==0)
    {
        printf("============================================================\n\n         ");
		printf("             !!!!!!RECORD DOES NOT EXIST!!!!!!                 \n\n");
    	printf("============================================================\n\n\n\n\n        ");
    }//end if
              
    if(Bakery.identify!=0)
    {
        fseek(BakeryInfo,(Bakery.identify-1)*sizeof(struct customer),SEEK_SET);
    	fwrite(&blankBakery,sizeof(struct customer),1,BakeryInfo);
                
        printf("============================================================\n\n         ");
		printf("          \n\n\n\t\t\t DELETE COMPLETE                \n\n");
    	printf("============================================================\n\n         "); 
    }//end if
        	
    fclose(BakeryInfo);
     
}//End Function

void NextMenu()//Function to move to the bread menu
{
	FILE*BreadInfo;//Pointer to file BreadFile
	int identification,result2,e;
	float diff,amount;
	char search[size];
	
	result2=BreadMenu();//call to function BreadMenu
	
	while(result2!=8)
	{	
   		if(result2==1)
   		{
			struct bread info={0,0,0,"",0.0,0.0}; 
			         
    		if ((BreadInfo = fopen("BreadFile", "wb"))==NULL)
    		{
       			printf("Cannot open file \n");     
                exit(1);
    		}//end if
    		else
    		{
        		for (e=0;e<=100;e++)
        		{
            		fwrite(&info,sizeof(struct bread),1,BreadInfo);
        		}//end for   
 
        		fclose(BreadInfo);		
    		}//end else
			
			
			printf("============================================================\n\n         ");
			printf("             FILE CREATED                 \n\n");
			printf("============================================================\n\n         ");	
			result2=BreadMenu();//call to function BreadMenu
    	}
   		
     	if(result2==2)//PROMPT USER FOR INFO TO FILL RECORD
  		{
            struct bread info={0,0,0,"",0.0,0.0}; 
 
            if ((BreadInfo = fopen("BreadFile", "rb+"))==NULL)
            {
		        printf("Cannot open file \n");
		        exit(1);
		   	}//end if
		   	else
		   	{
		   		printf("============================================================\n\n         ");
		        printf("             \n\n\n\t\t\tADD RECORDS                 \n\n");
		        printf("============================================================\n\n         ");
		        
		        
				printf("Enter bread identification--->");
			    scanf("%d",&info.identify2);
			            
			    printf("Enter Quantity of the bread--->");
			    scanf("%d",&info.quantity);
			             		
			    info.max=info.quantity;
			
			    printf("Enter name of bread to be added---->");
			    scanf("%s",&info.breadName);
			            		
			    printf("Enter the unit price of the bread---->");
			    scanf("%f",&info.price);
			            
			    fseek(BreadInfo,(info.identify2-1)*sizeof(struct bread),SEEK_SET);
				fwrite(&info,sizeof(struct bread),1,BreadInfo);
				fclose(BreadInfo);
			}//end else
			            	
			result2=BreadMenu();//call to function BreadMenu      	 
		}//end if		 
					
		if(result2==3)
		{    
		  	struct bread info={0,0,0,"",0.0,0.0}; 
		           
		    if ((BreadInfo = fopen("BreadFile", "rb+"))==NULL)
			{
		        printf("Cannot open file \n");
		        exit(1);
		    }//end if
		    else
			{
		    	printf("Enter bread Id to update(1 to 100)--->");
		        scanf("%d",&identification);
		        
		        fseek(BreadInfo,(identification-1)*sizeof(struct bread),SEEK_SET);
		    	fread(&info,sizeof(struct bread),1,BreadInfo);
		        /*Read Mode*/ 
		             	
		        if(info.identify2==0)
		        {
		            printf("============================================================\n\n         ");
					printf("             !!!!!!RECORD HAS NO INFORMATION!!!!!!                 \n\n");
		    		printf("============================================================\n\n\n\n\n        ");
		        }//end if
		              	
		        if(info.identify2!=0)
		        {
			  		printf("ID: %d\n",info.identify2);
					printf("Name: %s\n",info.breadName);
		            printf("Quantity: %d\n",info.quantity);
		            printf("Price: %.2f\n",info.price);
		                        
		   	        printf("\n\n");
		           
		   	        printf("Enter increase(+) or decrease(-)--------->");
		            scanf("%f",&amount);
		                    		
		            info.quantity=info.quantity+amount; 
		                        	
		            if(info.max>info.quantity)
		            {
		                diff=info.max-info.quantity;
		                info.max=info.quantity;
						info.revenue=info.revenue+(diff*info.price);	
					}//end if
					else
					if(info.max<info.quantity);
					{
						info.max=info.quantity;
					}//end if
		            diff=0;
		      
		            printf("Name: %s\n",info.breadName);
		            printf("Quantity: %d\n",info.quantity);
		            printf("Revenue: $%.2f",info.revenue);
		                        
		   	        printf("\n\n");
		   	  
		   	        fseek(BreadInfo,(info.identify2-1)*sizeof(struct bread ),SEEK_SET);
		            fwrite(&info,sizeof(struct bread),1,BreadInfo);
		            fclose(BreadInfo);
		        }//end if
		    }//end else  
		      		
		   result2=BreadMenu();//call to function BreadMenu	
		}//end if 
						
		if(result2==4)
		{    
		  	struct bread info={0,0,0,"",0.0,0.0};  
		           
		    if ((BreadInfo = fopen("BreadFile", "rb+"))==NULL)
			{
		        printf("Cannot open file \n");
		        exit(1);
		    }//end if
		    else
			{
		        printf("Enter bread Id to update(1 to 100)--->");
		        scanf("%d",&identification);
		        
		        fseek(BreadInfo,(identification-1)*sizeof(struct bread),SEEK_SET);
		        fread(&info,sizeof(struct bread),1,BreadInfo);
		        /*Read Mode*/ 
		             	
		        if(info.identify2==0)
		     	{
		            printf("============================================================\n\n         ");
					printf("             !!!!!!RECORD HAS NO INFORMATION!!!!!!                 \n\n");
		    		printf("============================================================\n\n\n\n\n");
		        }//end if
		              	
		        if(info.identify2!=0)
		        {
			  		printf("ID: %d\n",info.identify2);
					printf("Name: %s\n",info.breadName);
		            printf("Quantity: %d\n",info.quantity);
		        	printf("Price: %.2f\n",info.price);
		                        
		   	        printf("\n\n");
		           
		   	        printf("Enter new unit price--------->");
		            scanf("%f",&amount);
		                    		
		            info.price=amount;
		                        
		            printf("Name: %s\n",info.breadName);
		            printf("Quantity: %d\n",info.quantity);
		            printf("Unit Price: $%.2f",info.price);
		                        
		   	        printf("\n\n");
		   	  	
		   	        fseek(BreadInfo,(info.identify2-1)*sizeof(struct bread),SEEK_SET);
		            fwrite(&info,sizeof(struct bread),1,BreadInfo);
		            fclose(BreadInfo);
		                        
		        }//end if  
		  
		    }//end else
		      		
		    result2=BreadMenu();//call to function BreadMenu
		}//end if                 
						
		if(result2==5)//VIEW RECORDS
		{	
		    struct bread info={0,0,0,"",0.0,0.0}; 
		             
		    if ((BreadInfo = fopen("BreadFile", "rb+"))==NULL)
		    {
		        printf("Cannot open file \n");                                
		    }//end if
		    else
		    {
			    printf("============================================================\n\n         ");
		        printf("             \n\n\n\t\t\tVIEW RECORDS                 \n\n");
		        printf("============================================================\n\n         ");
		    
			    /*read and display every line in the file*/
			
				while(!feof(BreadInfo))
		        {   
		            fread(&info,sizeof(struct bread),1,BreadInfo);
		            	
		            if(info.identify2!=0)
		            {
		                printf("ID: %d\n",info.identify2);
		                printf("Name: %s\n",info.breadName);
		                printf("Quantity: %d\n",info.quantity);
		                printf("Unit Price: $%3.2f\n",info.price);
		                printf("Revenue: $%3.2f\n",info.revenue);
		                        	                                               				   
			            printf("\n\n");
		                printf("============================================================\n\n         ");
		            }//end if    
		        }//end while
			}//end else
		    
		    fclose(BreadInfo);
		    result2=BreadMenu();//call to function BreadMenu	
		}//end if
						
		if(result2==6)
		{
			struct bread info={0,0,0,"",0.0,0.0}; 
							
			if ((BreadInfo = fopen("BreadFile", "rb+"))==NULL)
		    {
		        printf("Cannot open file \n");                                
		    }//end if
		    else
		    {
		        printf("Enter the name of the bread you are looking for\n");
		    	scanf("%s",&search);
		        printf("\n");
		            				
		        while(!feof(BreadInfo))
		        {   
		            fread(&info,sizeof(struct bread),1,BreadInfo);
					if(stricmp(info.breadName,search)==0)
					{
						printf("ID: %d\n",info.identify2);
		                printf("Quantity: %d\n",info.quantity);
		                printf("Unit Price: $%3.2f\n",info.price);
		                printf("Revenue: $%3.2f\n",info.revenue);
		                    			
		                printf("\n\n");
		                
					}//end if
					else
					if(stricmp(info.breadName,search)==0)
		            {
		                printf("============================================================\n\n         ");
						printf("             !!!!!!RECORD HAS NO INFORMATION!!!!!!                 \n\n");
		    			printf("============================================================\n\n\n\n\n");
		            }//end if					
				}//end while
			}//end else
			fclose(BreadInfo);				
			result2=BreadMenu();//call to function BreadMenu
		}//end if
						
		if(result2==7) 
		{              
			struct bread info={0,0,0,"",0.0,0.0};  
							
		    struct bread blankinfo={0,0,0,"",0.0,0.0}; 
		            	
		    if ((BreadInfo = fopen("BreadFile", "rb+"))==NULL)
		    {
		        printf("Cannot open file \n");
		        exit(1);
		    }//end if
	
		    printf("============================================================\n\n         ");
			printf("          \n\n\n\t\t\t DELETE RECORDS                 \n\n");
		    printf("============================================================\n\n         "); 
		             
		    printf("Enter bread Id to delete(1 to 100)--->");
		    scanf("%d",&identification);         
		           
		    fseek(BreadInfo,(identification-1)*sizeof(struct bread),SEEK_SET);
		    fread(&info,sizeof(struct bread),1,BreadInfo);
		            
		    /*Read Mode*/ 
		             
		    if(info.identify2==0)
		    {
		        printf("============================================================\n\n         ");
				printf("             !!!!!!RECORD DOES NOT EXIST!!!!!!                 \n\n");
		    	printf("============================================================\n\n\n\n\n        ");
		    }//end if
		              
		    if(info.identify2!=0)
		    {
		        fseek(BreadInfo,(info.identify2-1)*sizeof(struct bread),SEEK_SET);
		    	fwrite(&blankinfo,sizeof(struct bread),1,BreadInfo);
		                
		        printf("============================================================\n\n         ");
				printf("          \n\n\n\t\t\t DELETE COMPLETE                \n\n");
		    	printf("============================================================\n\n         "); 
		    }//end if
		        	
		    fclose(BreadInfo);
		    result2=BreadMenu();//call to function BreadMenu
		}//end if					
	}//end while								
}//End Function

main()
{   
	FILE*BreadInfo;//Pointer to file BreadFile
	FILE*BakeryInfo;//Pointer to file CustomerFile
    int identification ,result,result2,f, diff;
    float amount;
    char search[size];
    char password[size];
    
    printf("Enter the password\n");
    scanf("%s",&password);
	
	while(stricmp(password,"Breadman")!=0)
	{
		printf("Password Denied please try again\n");
		scanf("%s",&password);
	}//end while
	
	if(stricmp(password,"Breadman")==0)
    {
		printf("Password Confirmed\n");
	}//end if
	
                  	
  	result=MenuChoice();//call to function BreadMenu

	while(result!=6)
   	{
     	if(result==1)
     	{
        	createFile();//call to function createFile
        	result=MenuChoice();//call to function BreadMenu
		}//end if
		
  		if(result==2)
  		{
  			AddCustomer();//call to function AddCustomer
  			result=MenuChoice();//call to function BreadMenu
    	}//end if
 	 
     	if(result==3)
     	{	
            DisplayInfo();//call to function DisplayInfo
            result=MenuChoice();//call to function BreadMenu
		} //end if   

        if(result==4) 
        {   
			DeleteCustomer();//call to function DeleteCustomer
			result=MenuChoice();//call to function BreadMenu
		}//end if	

		if(result==5)
		{
			NextMenu();//call to function NextMenu
			result=MenuChoice();//call to function BreadMenu
		}//end if
	}//end while	
}//End Program

                                                                       
 


 
	
		  	 

         
         


