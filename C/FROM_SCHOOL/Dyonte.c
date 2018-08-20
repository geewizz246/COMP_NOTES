#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

#define string_length 20
 int MenuChoice()//menu gives user  a list of options 
  { 
    int choice;
    
   	printf("\n\n");
     printf("\n\n");
     printf("\n\n");
     
	
    
     printf("\n\n");
     printf("\n\n");
     printf("\n\n");

printf("============================================================\n\n         ");
printf("OPTION              DESCRIPTION                  \n\n");
    printf("============================================================\n\n         ");
    
	printf("1               Create a new file for an employee\n\n");
	printf("         2               Add Employee information\n\n");
	
	printf("         3               Display Employee information \n\n");
 printf("         4               Update employee information\n\n ");
 printf("        5               Delete a record\n\n ");
 
	printf("        6               Exit program\n\n ");
   
	
	
     printf("============================================================\n\n         ");
	 printf("=>=>=>=>=>=>=>REGIONAL FIRE AND SECURITY=>=>=>=>=>=>=>\n\n");
     printf("============================================================\n\n         ");


     printf("\n\n");
     printf("\n\n");
     printf("Task=====>");
    
    scanf("%d",&choice);
    
    return choice;
    
}
main()
{
	struct EmployeeInfo{
    
	
	int ID;
	
	int hoursworked;
	int overtime_hours;
	 
   
	char firstname[ string_length ];
	char lastname[ string_length ];
 
   float grosspay;
    float wage;
    float overtime_pay;
     };

    
	FILE*EmployeeWage;//POINTER TO FILE
    int employeeName,result,f;
    float amount;
   
   
         /*create studentinfo with default information*/          
     
	
   
     
    	
  result=MenuChoice();/*call to function MenuChoice*/	

   while(result!=6)
   {	
     if(result==1)
     {
                  struct EmployeeInfo employee={0,0,0,"","", 0.0,0.0,0.0}; 
                  

                      
                 if ((EmployeeWage = fopen("employeefile1", "wb"))==NULL)
                {
                                  printf("Cannot open file \n");
                                  exit(1);
                }/*end if*/ 

                 else

                 {
                       for (f=0;f<=100;f++)
                       {
                               fwrite(&employee,sizeof(struct EmployeeInfo),1,EmployeeWage);
                        } /*end for*/      
 
 
                fclose(EmployeeWage);
               }/*end else*/
        printf("============================================================\n\n         ");
printf("             FILE CREATED                 \n\n");
    printf("============================================================\n\n         ");
result=MenuChoice();
}// ENDIF
if(result==2)//PROMPT USER FOR INFO TO FILL RECORD
  {
               struct EmployeeInfo employee={0,0,0,"","", 0.0,0.0,0.0}; 
 
               if ((EmployeeWage = fopen("employeefile1", "rb+"))==NULL)
               {
                                printf("Cannot open file \n");
                                exit(1);
   
                }
            
            printf("Enter ID---->");
            scanf("%d",&employee.ID);
            
          printf("Enter first name--->");
             scanf("%s",&employee.firstname);

            printf("Enter lastname---->");
            scanf("%s",&employee.lastname);
             
			 printf("Enter hours worked --->");
            scanf("%d",&employee.hoursworked);
            
                        
            printf("Enter overtime hours---->");
            scanf("%d",&employee.overtime_hours);  
            
            printf("Enter wage---->");
            scanf("%f",&employee.wage); 
			 
         
            fseek(EmployeeWage,(employee.hoursworked-1)*sizeof(struct EmployeeInfo),SEEK_SET);
            fwrite(&employee,sizeof(struct EmployeeInfo),1,EmployeeWage);
            fclose(EmployeeWage);
	        result=MenuChoice();
}
			 if(result==3)//VIEW RECORDS
     {	
                          struct EmployeeInfo employee={0,0,0,"","", 0.0,0.0,0.0};

                      
                          if ((EmployeeWage = fopen("employeefile1", "rb+"))==NULL)
                           {
                                            printf("Cannot open file \n");
                                             
                           }/*end if*/
                           else
                           {
	                                          printf("============================================================\n\n         ");
                                           printf("             \n\n\n\t\t\tVIEW RECORDS                 \n\n");
                                             printf("============================================================\n\n         ");
    
    

	                                         /*read and display every line in the file*/
	
                                             while(!feof(EmployeeWage))
                                             {   
                                                   fread(&employee,sizeof(struct EmployeeInfo),1,EmployeeWage);
                                                    if(employee.ID!=0)
                                                    {
                                                                       printf("HOURSWORKED---->%d\nFIRSTNAME---->%s\t%s\n\tLASTNAME----->%s\n\tWAGE---->%f",employee.hoursworked,employee.firstname,employee.lastname,employee.wage);
                                                                        printf("\n\tOVERTIME PAY---->%f\n\tGROSS PAY---->%f\n\tOVERTIME HOURS---->%d",employee.overtime_pay,employee.grosspay,employee.overtime_hours);
																		printf("\n\n\n");
   	     
   	      
	                                                                    printf("\n\n");
                                                                        printf("============================================================\n\n         ");
                                                    }//END IF    
      
      
                                             }/*end while*/
    
                                             }//end else
    
         fclose(EmployeeWage);
     

    result=MenuChoice();/*call to function MenuChoice*/	
} /*end if*/   
                 
        
}
}
