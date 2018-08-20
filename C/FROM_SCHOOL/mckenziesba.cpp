#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define stringlength 70
#define LENGTH 100//NUMBER OF RECORDS IN THE FILE
#define tax 0.175


void Password()//asks user for password
{			
	char AdminPassword[50];
    int a;
 		
	printf("\n\n\n\t\t\t\t\t\t\t");
	printf("Welcome to Beans n' Stuff, where's it's more than just coffee.");
	printf("\n\n\t\t\t\t\t\t\t\t");
	printf("Enter administrator password to continue...\n");
	scanf("%s",&AdminPassword);


								
		while(strcmp(AdminPassword,"beansnstuff")!=0)
		{	
			printf("\nThe password you entered is incorrect. Please try again.\n\n");
			
			printf("Welcome to Beans n' Stuff, where's it's more than just coffee. Enter administrator password to continue\n");
			scanf("%s",&AdminPassword);
		} 
}






struct customerInfo//stores customer data

{
            
	int orderAuto;//this is person's position in queue
    int customerID;// every record MUST have some varaible that uniquely identifies it. // The record are stored in the binary files based on this "primary key"
    char firstName[stringlength];
	char lastName[stringlength];
	int ordercode;
	int quantity;
	int itemCount;
	int position;
	float nettotal;
    float total;
   
 };
//function genrerates and writes index to a file



struct menuStock{
	
	int foodID;
	char food[stringlength];
	int itemquan;
	float price;
	
};







int MenuChoice()//Displays teh options available to teh system user
{
     int choice;//local variable which holds the option entered by the user
         
         
     printf("\n\n");
     printf("\n\n");
     printf("\n\n");
     
     printf("\n\n");
     printf("\n\n");
     printf("\n\n");

    printf("\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("\t\t\t\t\t\t\t\t          EMPLOYEE MENU - Beans n' Stuff                   \n\n");
    printf("\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    
	printf("\t\t\t\t\t\t\t      1               Create New Stock File\n");
	printf("\t\t\t\t\t\t\t      2              Enter New Stock Records\n");
	printf("\t\t\t\t\t\t\t      3               Display Stock Records\n");
    printf("\t\t\t\t\t\t\t      4               Search Stock Records\n ");
    printf("\t\t\t\t\t\t\t      5              Add Stock Quantity\n");
    
	printf("\n\n");
	
	printf("\t\t\t\t\t\t\t      6              Create New Order File\n");
    printf("\t\t\t\t\t\t 	    7   	         Enter New Order\n");
	printf("\t\t\t\t\t\t\t      8       		Display Order Database\n");
	printf("\t\t\t\t\t\t\t      9               Search Order Records\n ");
	printf("\t\t\t\t\t\t\t      10  			Delete Order\n");
	printf("\t\t\t\t\t\t\t      11               Check if file is empty\n");
	printf("\t\t\t\t\t\t\t      12			Order Count\n");
   	printf("\t\t\t\t\t\t\t      13               Exit program\n");
		
    printf("\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("\t\t\t\t\t\t\t=>=>=>=>=>=>=> Where it's more than just coffee. <=<=<=<=<=<=<=\n\n");
    printf("\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");


    printf("\n\n");
    printf("\n\n");
    printf("Please select an option...");
    
    scanf("%d",&choice);
    
    return choice;// the option choice by the user is returned to main-the function that called it
}/*End Function*/































void newStockFile()//creates a new stock file
{
	FILE*inDataFile2;//POINTER TO FILE
	int f;
	
	
	
	struct menuStock stock={0," ",0,0.0};  
                      
                 if ((inDataFile2 = fopen("BeansStock", "wb"))==NULL)
                {
                                  printf("Cannot open file \n");
                                  
                }/*end if*/ 

                 else

                 {
                       for (f=0;f<=10000;f++)
                       {
                               fwrite(&stock,sizeof(struct menuStock),1,inDataFile2);
                        } /*end for*/      
 
 
                fclose(inDataFile2);
               }/*end else*/
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n         ");
		printf("	          NEW STOCK FILE CREATED                 \n\n");
    	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n         ");
}











void newMenuStock()//adds new stock items to the inventory
{
	FILE*inDataFile2;//POINTER TO FILE
	
	struct menuStock stock={0," ",0,0.0};  

                      
                 if ((inDataFile2 = fopen("BeansStock", "rb+"))==NULL)
                {
                                  printf("Cannot open file\n");
                                  exit(1);
                }/*end if*/ 

                 else
                 {
                 
                 		printf("\n");
                 		printf("Enter stock identification number. Terminate input with 0:....\n\n");
                 		scanf("%d",&stock.foodID);
                 		  while(stock.foodID!=0)
						 {
						 		fflush(stdin);
						 	    printf("Enter a new stock item:\n");
					   		    scanf("%[^\n]%*c",&stock.food);
					   		    printf("\n");
					   		 
					        	printf("Enter product quantity:\n");
					    	    scanf("%d",&stock.itemquan);
					    	    printf("\n");
					    	    
					    	    printf("Enter unit price:\n");
					    	    scanf("%f",&stock.price);
					    	    printf("\n");
					    	    
					    	   
					    	    printf("\n");
					    	     
								fseek(inDataFile2,(stock.foodID-1)*sizeof(struct menuStock),SEEK_SET);
            	 				fwrite(&stock,sizeof(struct menuStock),1,inDataFile2);
            	 				
            	 			          	 				
					    	    
					    	    printf("Enter stock identification number. Terminate input with 0:\n");
                 		        scanf("%d",&stock.foodID);
                 		        
						 }	
					   
				 
				 }
				 	fclose(inDataFile2);
            	 			
}













void viewStock()//views the contents of the file
 {      
           FILE* inDataFile2;
		   struct menuStock stock={0," ",0,0.0};    
		   int y;

            if ((inDataFile2 = fopen("BeansStock", "rb+"))==NULL)
            {
                 printf("Cannot open file \n");
                 exit(1);
            }/*end if*/
	        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
            printf("             \n\n\n\t\t\tVIEW RECORDS                 \n\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    
    

	/*read and display every line in the file*/
	
            while(!feof(inDataFile2))//WHILE THE END OF FILE HAS NOT BEEN REACHED
            {   
               fread(&stock,sizeof(struct menuStock),1,inDataFile2);
               if(stock.foodID!=0)
               {
               		 printf("\n");
               		 
                     printf("\t\tStock ID: %d\n",stock.foodID);
					 printf("\t\tItem Description: %s\n",stock.food);
					 printf("\t\tUnit Price: %.2f\n",stock.price);
					 printf("\t\tAvailable Quantity: %d\n",stock.itemquan);
					 
               	     printf("\n\n\n");
              	     printf("\n\n");
                     printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    
                }/*end if*/
    
           }/*end while*/
           fclose(inDataFile2);//CLOSE FILE
  
}//end view Function   










int findID()//searches the stock file for records based on a given stock ID

 {
	FILE*inDataFile2;//POINTER TO FILE
	int search;
	int identification,y;
	struct menuStock stock={0," ",0,0.0}; 
	
	if((inDataFile2=fopen("BeansStock","rb+"))==NULL)
	{
		printf("Error.\n");
	}
	else
	{
		printf("\n");
		printf("Enter Stock Identification Number (SIN) to search the Beans n' Stuff Stock Database...\n");
		scanf("%d",&identification);
		printf("\n");
			
		fseek(inDataFile2,(identification-1)*sizeof(struct menuStock),SEEK_SET);
		fread(&stock,sizeof(struct menuStock),1,inDataFile2);
			
			if(identification!=stock.foodID)
    			{
       		 	printf("\t\t\t\t\t============================================================\n\n         ");
				printf("\t\t\t\t\t     !!!!!!THIS RECORD DOES NOT EXIST!!!!!!                 \n\n");
        		printf("\t\t\t\t\t============================================================\n\n\n\n\n        ");
    	  		}/*end if*/
		
			if(identification==stock.foodID)
			{	
    			printf("\n");
				printf("Results for SIN #%d:\n\n",stock.foodID);
				printf("Stock ID: %d\n",stock.foodID);
    			printf("Item Description: %s\n",stock.food);
    			printf("Unit Price: %.2f\n",stock.price);
        		printf("Available Quantity: %d\n",stock.itemquan);
        	}
    		
        	printf("\n");
    
    //endwhile	
	fclose(inDataFile2);
	
	} 
  
  
}










int updateStock()
{
		FILE* inDataFile2;//POINTER TO FILE
		int identification,result,addnum;
		char tempname[stringlength];//stores the temporary name of the item
		struct menuStock stock={0," ",0,0.0}; 
		
        if ((inDataFile2 = fopen("BeansStock", "rb+"))==NULL)
        {
                         printf("Cannot open file \n");
                         exit(1);
        }/*end if*/
       
       
       else
	   {     		 
       		        
             fseek(inDataFile2,(identification-1)*sizeof(struct menuStock),SEEK_SET);
             fread(&stock,sizeof(struct menuStock),1,inDataFile2);
             /*Read Mode*/ 
             
                       printf("\n");
			 printf("Enter Stock Identification Number (SIN) to search the Beans n' Stuff Stock Database...\n");
	         scanf("%d",&identification);
			 printf("\n");
			
			 fseek(inDataFile2,(identification-1)*sizeof(struct menuStock),SEEK_SET);
			 fread(&stock,sizeof(struct menuStock),1,inDataFile2);
			
			if(identification!=stock.foodID)
    			{
       		 	printf("\t\t\t\t\t============================================================\n\n         ");
				printf("\t\t\t\t\t     !!!!!!THIS RECORD DOES NOT EXIST!!!!!!                 \n\n");
        		printf("\t\t\t\t\t============================================================\n\n\n\n\n        ");
    	  		}/*end if*/
		
			if(identification==stock.foodID)
			{	
    			printf("\n");
				printf("Results for SIN #%d:\n\n",stock.foodID);
				printf("Stock ID: %d\n",stock.foodID);
    			printf("Item Description: %s\n",stock.food);
    			printf("Unit Price: %.2f\n",stock.price);
        		printf("Available Quantity: %d\n",stock.itemquan);
        	
    		             		
              		printf("\n");
              		
              		
              		
              		printf("Enter quantity to be added...\n");
              		scanf("%d",&addnum);
              		
              		stock.itemquan=stock.itemquan+addnum;
              	
              		fseek(inDataFile2,(identification-1)*sizeof(struct menuStock),SEEK_SET);
              		fwrite(&stock,sizeof(struct menuStock),1,inDataFile2);
            	 				
              	}	fclose(inDataFile2);
              	
                
		
			}//end else
			  
	}//end function







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










void enqueueOrderinfo(FILE*inDataFile1,struct customerInfo customer)
{

 
               if ((inDataFile1 = fopen("beansnstuff", "rb+"))==NULL)//open binary file for reading and writing
               {
                                printf("Cannot open file \n");
                                exit(1);
                }/*end if*/

              int Auto=readAutoIndex();  //get index from auto file
    
              if( Auto== (LENGTH-1))
                   printf("Queue full.");
              else
              {
                    
		        Auto= Auto+1;//determine position to write the entered record to in the file
		    
                       
                fseek(inDataFile1,( Auto)*sizeof(struct customerInfo),SEEK_SET);//find point in file to
                                                                                    //write the record
                fwrite(&customer,sizeof(struct customerInfo),1,inDataFile1);//write the record
		       
                }//end else
                fclose(inDataFile1);//close the file   
                autocreateIndex(Auto);//write new value of index to the text file
  
}//end enqueueOrderInfo() 









void newOrderFile()//creates a new order file
{
		FILE*inDataFile1;
		struct customerInfo customer={0,0,"","",0,0,0,0,0.0,0.0}; 
        int f;
                       autocreateIndex(-1);//when file is FIRST created index is gigen a value of -1
  
                       /* open file for customer input */
                       
                      if ((inDataFile1 = fopen("beansnstuff", "wb"))==NULL)
                      {
                            printf("Cannot open file \n");
                            exit(1);
                      }/*end if*/ 
                      
                      else

                     {
                              //creating 100 blank records
                              for (f=0;f<=500;f++)
                              {
                                     fwrite(&customer,sizeof(struct customerInfo),1,inDataFile1);
                              } /*end for*/      
 
 
                              fclose(inDataFile1);//closes the file pointer
                     }/*end else*/
                     
                       printf("\n\n");
                       
                       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");
                       printf("                  NEW CUSTOMER FILE CREATED                 \n\n");
                       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");
                       
            }//end newOrderFile function
            






void LunchMenu()
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("\t\t\tBAJAN BREAKFAST BITES - Beans n' Stuff\n\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	
    printf("\n");
	printf("Item Code\t\t\t\tItem Description\t\t\tPrice\n\n");
	
	printf("\t100\t\t\t\tCoffee(Black)\t\t\t2.13\n\n");
	printf("\t101\tJuice(Pineapple, Orange, Passion Fruit)\t\t2.13\n\n");
	
}



















int makeOrder()
{
	FILE*inDataFile1;
	FILE*inDataFile2;
	
	struct customerInfo customer={0,0,"","",0,0,0,0,0.0,0.0}; 
	struct menuStock stock={0,"",0,0.0}; 
	
	
	
	if ((inDataFile1=fopen("beansnstuff", "rb+"))==NULL)//open binary file for reading and writing
 				
                {
                                printf("Cannot open file \n");
                                exit(1);
                }/*end if*/
                
    
    if((inDataFile2=fopen("BeansStock","rb+"))==NULL)
    		{
    			printf("Cannot open file\n");
    			exit(1);
			}
                
                
               int passAuto=readAutoIndex();
               int result;
               

               customer.orderAuto=readAutoIndex()+2;
               
               customer.position=0;
               
             
               printf("\n");
               
			   printf("Enter a Unique Customer ID:...");
               scanf("%d",&customer.customerID);
               
               printf("\n");
                
               printf("Enter Customer Name:...");
               scanf("%s%s",&customer.firstName,&customer.lastName);
               
               LunchMenu();
               
               printf("Please enter your order code...\n\n");
               scanf("%d",&customer.ordercode);
               
               printf("\n\n");
               
               
            while(customer.ordercode!=0)
            {
            	printf("Enter item quantity: \n\n");
               	scanf("%d",&customer.quantity);
               	
               	stock.itemquan=stock.itemquan-customer.quantity;
               	customer.itemCount=customer.itemCount+customer.quantity;
               	
               	enqueueOrderinfo(inDataFile1,customer);//call  to function which queues up the customers in the file
               	
               	printf("\n\n");
               	
               	printf("Please select your order...(Terminate by 0)\n\n");
               	scanf("%d",&customer.ordercode);
               	
               	              	
               	fseek(inDataFile1,(customer.customerID-1)*sizeof(struct customerInfo),SEEK_SET);
        		fwrite(&customer,sizeof(struct customerInfo),1,inDataFile1);
        		fseek(inDataFile2,(stock.foodID-1)*sizeof(struct menuStock),SEEK_SET);
				fwrite(&stock,sizeof(struct menuStock),1,inDataFile2);
				
			}//endwhile
               
               fclose(inDataFile1);
               fclose(inDataFile2);
}
                       












 void viewOrders()
 {      
 			FILE*inDataFile1;//views the contents of the file
 			struct customerInfo customer={0,0,"","",0,0,0,0,0.0,0.0};
            struct menuStock stock={0,"",0,0.0};
			 

            int Auto=readAutoIndex ();//get index
            int i;
            
        
            if ((inDataFile1=fopen("beansnstuff", "rb+"))==NULL)
            {
                 printf("Cannot open file \n");
                 exit(1);
            }/*end if*/
            
            
	        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n         ");
            printf("             \n\n\t\t\tVIEW RECORDS                 \n\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n         ");
            
            printf("\n");
    
    

	/*read and display every line in the file*/
	
            while(!feof(inDataFile1)&& customer.orderAuto<=Auto)//WHILE THE END OF FILE HAS NOT BEEN REACHED
            {   
               fread(&customer,sizeof(struct customerInfo),1,inDataFile1);
               if(customer.customerID!=0)
               	{
					
               		 printf("\n");
               		 printf("\tQueue Number: %d\n",customer.orderAuto);
					 printf("\t\tOrder #%d\n",customer.customerID);
					 printf("\t\tCustomer Name: %s %s\n\n",customer.firstName,customer.lastName);
					 printf("\t\tItem Count: %d\n\n",customer.itemCount);
              	     printf("\t\tNet Total: %.2f\n\n",customer.nettotal);
              	     printf("\t\tTotal: %.2f\n\n",customer.total);
                     printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n         ");
    
                }/*end if*/
    
       		}//endwhile	
           
           
           fclose(inDataFile1);//CLOSE FILE
  
}//end view Function   

















int main()

{

	FILE*inDataFile2;
	
	struct menuStock stock={0,"",0,0.0};  
	
	int identification,result,f;
	
	Password();
 	result=MenuChoice();
	 
	 
	 	
	while(result!=12)
	
	{
		switch(result)
		
		{
			
			
			case 1://creates a new stock file
				{
	   				newStockFile();
	   				result=MenuChoice();
	   				break;
	   			}
	   			
	   			
	   			
	   		case 2://adds new stock items to the inventory
	   		
	   			{
	   				newMenuStock();
	   				result=MenuChoice();
	   				break;
			    }
			    
			    
			    
			case 3://allows the user to view the entered stock records
			
				{	
					viewStock();
					result=MenuChoice();
					break;
					
				}
				
			
			case 4://Search stock records
				
				{
					findID();
					result=MenuChoice();
					break;
				}
	   			
	   		
	   		case 5://Update stock records
	   			
	   			{
	   				updateStock();
	   				result=MenuChoice();
	   				break;
	   				
			    }
			    
	   		
			case 6://Creates a new order file
				{
					newOrderFile();
					result=MenuChoice();
					break;
				}	
				
			case 7://creates new order
			
				{
					makeOrder();
					result=MenuChoice();
					break;
				}
				
			case 8://view orders
				
				{
					viewOrders();
					result=MenuChoice();
					break;
				}
				
				
		}
		
	}
	
	
	
}



