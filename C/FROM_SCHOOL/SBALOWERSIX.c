#include<stdio.h>
#include<errno.h>//error handling
#include<stdlib.h>

#define string_length 20
 struct studentInfo{
    
         
	int id;
   
	char first_name[ string_length ];
	char last_name[ string_length ];
 
    char form[ string_length ];
    float mathsMark;
     };

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
printf("OPTION              DESCRIPTION                   \n\n");
    printf("============================================================\n\n         ");
    
	printf("1               Create a new file\n\n");
	printf("         2               Add Student Information\n\n");
	
	printf("         3               Display student information \n\n");
 printf("         4               Update math mark\n\n ");
 printf("        5               Delete a record\n\n ");
 
	printf("        6               Exit program\n\n ");
   
	
	
     printf("============================================================\n\n         ");
	printf("=>=>=>=>=>=>=>ACADEMY OF MATH=>=>=>=>=>=>=>\n\n");
    printf("============================================================\n\n         ");


     printf("\n\n");
     printf("\n\n");
     printf("Task=====>");
    
    scanf("%d",&choice);
    
    return choice;
}/*End Function*/
    
  main()
{   
	FILE*inDataFile1;//POINTER TO FILE
    int identification,result,f;
    float amount;
   
   
         /*create studentinfo with default information*/          
     
	
   
     
    	
  result=MenuChoice();/*call to function MenuChoice*/	

   while(result!=6)
   {	
     if(result==1)
     {
                  struct studentInfo student={0,"","","",0.0}; 

                      
                 if ((inDataFile1 = fopen("myfile5", "wb"))==NULL)
                {
                                  printf("Cannot open file \n");
                                  exit(1);
                }/*end if*/ 

                 else

                 {
                       for (f=0;f<=100;f++)
                       {
                               fwrite(&student,sizeof(struct studentInfo),1,inDataFile1);
                        } /*end for*/      
 
 
                fclose(inDataFile1);
               }/*end else*/
        printf("============================================================\n\n         ");
printf("             FILE CREATED                 \n\n");
    printf("============================================================\n\n         ");
result=MenuChoice();/*call to function MenuChoice*/


}/*end if*/

 
  if(result==2)//PROMPT USER FOR INFO TO FILL RECORD
  {
               struct studentInfo student={0,"","","",0.0}; 
 
               if ((inDataFile1 = fopen("myfile5", "rb+"))==NULL)
               {
                                printf("Cannot open file \n");
                                exit(1);
   
                }/*end if*/

         
         
            printf("Enter student Id--->");
            scanf("%d",&student.id);
            
            printf("Enter first name--->");
             scanf("%s",&student.first_name);

            printf("Enter lastname---->");
            scanf("%s",&student.last_name);

                        
            printf("Enter form---->");
            scanf("%s",&student.form);  
        
            printf("Enter math mark---->");
            scanf("%f",&student.mathsMark);  
         
            fseek(inDataFile1,(student.id-1)*sizeof(struct studentInfo),SEEK_SET);
            fwrite(&student,sizeof(struct studentInfo),1,inDataFile1);
            fclose(inDataFile1);
	        result=MenuChoice();/*call to function MenuChoice*/       	 
}//END IF		 
 	 

    
    
     if(result==3)//VIEW RECORDS
     {	
                          struct studentInfo student={0,"","","",0.0}; 

                      
                          if ((inDataFile1 = fopen("myfile5", "rb+"))==NULL)
                           {
                                            printf("Cannot open file \n");
                                             
                           }/*end if*/
                           else
                           {
	                                          printf("============================================================\n\n         ");
                                           printf("             \n\n\n\t\t\tVIEW RECORDS                 \n\n");
                                             printf("============================================================\n\n         ");
    
    

	                                         /*read and display every line in the file*/
	
                                             while(!feof(inDataFile1))
                                             {   
                                                   fread(&student,sizeof(struct studentInfo),1,inDataFile1);
                                                    if(student.id!=0)
                                                    {
                                                                       printf("ID---->%d\n\tNAME---->%s\t%s\n\tFORM----->%s\n\tMATH MARK---->%3.2f",student.id,student.first_name,student.last_name,student.form,student.mathsMark);
                                                                        printf("\n\n\n");
   	     
   	      
	                                                                    printf("\n\n");
                                                                        printf("============================================================\n\n         ");
                                                    }//END IF    
      
      
                                             }/*end while*/
    
                                             }//end else
    
         fclose(inDataFile1);
     

    result=MenuChoice();/*call to function MenuChoice*/	
} /*end if*/   




if(result==4)
  {     struct studentInfo student={0,"","","",0.0}; 

                       
        if ((inDataFile1 = fopen("myfile5", "rb+"))==NULL)
        {
                         printf("Cannot open file \n");
                         exit(1);
        }/*end if*/
       
       else{
             printf("Enter student Id to update(1 to 100)--->");
             scanf("%d",&identification);
        
             fseek(inDataFile1,(identification-1)*sizeof(struct studentInfo),SEEK_SET);
             fread(&student,sizeof(struct studentInfo),1,inDataFile1);
             /*Read Mode*/ 
             if(student.id==0)
              {
                          printf("============================================================\n\n         ");
printf("             !!!!!!RECORD HAS NO INFORMATION!!!!!!                 \n\n");
    printf("============================================================\n\n\n\n\n        ");
    
    
  
              }/*end if*/
              if(student.id!=0)
              {

	  
                         printf("ID---->%d\nNAME---->%s\t%s\nFORM----->%s\nMATH MARK---->%3.2f",student.id,student.first_name,student.last_name,student.form,student.mathsMark);
   	                     printf("\n\n");
           
   	                     printf("Enter increase(+) or decrease(-)--------->");
                         scanf("%f",&amount);
                         
    	
                         student.mathsMark=student.mathsMark+amount;/*update math mark*/ 
      
                         printf("NAME---->%s\t%s\nMATH MARK---->%3.2f",student.first_name,student.last_name,student.mathsMark);
   	                     printf("\n\n");
   	  
   	  
   	                     fseek(inDataFile1,(student.id-1)*sizeof(struct studentInfo),SEEK_SET);
                         fwrite(&student,sizeof(struct studentInfo),1,inDataFile1);
                         fclose(inDataFile1);
                        
             }   /*end if*/  
  
      } /*end else*/
      result=MenuChoice();/*call to function MenuChoice*/	
}/*end if*/                  
        
        if(result==5) 
        {              struct studentInfo student={0,"","","",0.0}; 


                      struct studentInfo blankStudent={0,"","","",0.0}; 
     
                      
                     if ((inDataFile1 = fopen("myfile5", "rb+"))==NULL)
                    {
                         printf("Cannot open file \n");
                         exit(1);
                    }/*end if*/
             printf("============================================================\n\n         ");
printf("          \n\n\n\t\t\t DELETE RECORDS                 \n\n");
    printf("============================================================\n\n         "); 
             
             
             printf("Enter student Id to delete(1 to 100)--->");
             scanf("%d",&identification);         
           
           
           fseek(inDataFile1,(identification-1)*sizeof(struct studentInfo),SEEK_SET);
             fread(&student,sizeof(struct studentInfo),1,inDataFile1);
             /*Read Mode*/ 
             if(student.id==0)
              {
                          printf("============================================================\n\n         ");
printf("             !!!!!!RECORD DOES NOT EXIST!!!!!!                 \n\n");
    printf("============================================================\n\n\n\n\n        ");
    
    
  
              }/*end if*/
              if(student.id!=0)
              {
           
           
                                fseek(inDataFile1,(student.id-1)*sizeof(struct studentInfo),SEEK_SET);
           
                                fwrite(&blankStudent,sizeof(struct studentInfo),1,inDataFile1);
            printf("============================================================\n\n         ");
printf("          \n\n\n\t\t\t DELETE COMPLETE                \n\n");
    printf("============================================================\n\n         "); 
             }            
             fclose(inDataFile1);
     
          result=MenuChoice();/*call to function MenuChoice*/	
}//END IF
                  
 
 if(result==6) //user wants to 
 {
       system("pause");
       
      
 }//END IF
          
         
                                                                          
 
       
        
 } //END WHILE      
 }                                                                      
 


 
	
		  	 

         
         


