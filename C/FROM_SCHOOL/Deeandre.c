#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 30
main()
{
	int num=0,num2=0,num3=0,num1=0,num4=0,num5=0,num6=0,num7=0;
	char seventh[size],second[size],third[size],sixth[size],first[size],fourth[size],fifth[size];
	
	char zero[size]="zero";
	char one[size]="one";
	char two[size]="two";
	char three[size]="three";
	char four[size]="four";
	char five[size]="five";
	char six[size]="six";
	char seven[size]="seven";
	char eight[size]="eight";
	char nine[size]="nine";
	char ten[size]="ten";
	char eleven[size]="eleven";
	char twelve[size]="twelve";
	char thirteen[size]="thirteen";
	char fourteen[size]="fourteen";
	char fifteen[size]="fifteen";
	char sixteen[size]="sixteen";
	char seventeen[size]="seventeen";
	char eighteen[size]="eighteen";
	char nineteen[size]="nineteen";
	char twenty[size]="twenty";
	char thirty[size]="thirty";
	char fourty[size]="fourty";
	char fifty[size]="fifty";
	char sixty[size]="sixty";
	char seventy[size]="seventy";
	char eighty[size]="eighty";
	char ninety[size]="ninety";
	char hundred[size]="hundred";
	char thousand[size]="thousand";
	char million[size]="million";

	printf("Enter a number\n");
	scanf("%d",&num);
	
	if(num==0)
	{
		printf("%s\n",zero);
	}
	if((num>=100)&&(num<1000))
	{
		num3=num/100;
		num2=(num-(num3*100))/10;
		num1=(num-(num3*100)-(num2*10));
	}
	if(num<100)
	{
		num2=num/10;
		num1=num-(num2*10);
	}
	if((num>=1000)&&(num<10000))
	{
		num4=num/1000;
		num3=(num-(num4*1000))/100;
		num2=(num-(num4*1000)-(num3*100))/10;
		num1=(num-(num4*1000)-(num3*100)-(num2*10));
	}
	if((num>=10000)&&(num<100000))
	{
		num5=num/10000;
		num4=(num-(num5*10000))/1000;
		num3=(num-(num5*10000)-(num4*1000))/100;
		num2=(num-(num5*10000)-(num4*1000)-(num3*100))/10;
		num1=(num-(num5*10000)-(num4*1000)-(num3*100)-(num2*10));	
	}
	if((num>=100000)&&(num<1000000))
	{
		num6=num/100000;
		num5=(num-(num6*100000))/10000;
		num4=(num-(num6*100000)-(num5*10000))/1000;
		num3=(num-(num6*100000)-(num5*10000)-(num4*1000))/100;
		num2=(num-(num6*100000)-(num5*10000)-(num4*1000)-(num3*100))/10;
		num1=(num-(num6*100000)-(num5*10000)-(num4*1000)-(num3*100)-(num2*10));
	}
	if((num>=1000000)&&(num<10000000))
	{
		num7=num/1000000;
		num6=(num-(num7*1000000))/100000;
		num5=(num-(num7*1000000)-(num6*100000))/10000;
		num4=(num-(num7*1000000)-(num6*100000)-(num5*10000))/1000;
		num3=(num-(num7*1000000)-(num6*100000)-(num5*10000)-(num4*1000))/100;
		num2=(num-(num7*1000000)-(num6*100000)-(num5*10000)-(num4*1000)-(num3*100))/10;
		num1=(num-(num7*1000000)-(num6*100000)-(num5*10000)-(num4*1000)-(num3*100)-(num2*10));
	}
	if(num1==1)
	{
		strcpy(first,one);
	}
	if(num1==2)
	{
		strcpy(first,two);
	}
	if(num1==3)
	{
		strcpy(first,three);
	}
	if(num1==4)
	{
		strcpy(first,four);
	}
	if(num1==5)
	{
		strcpy(first,five);
	}	
	if(num1==6)
	{
		strcpy(first,six);
	}
	if(num1==7)
	{
		strcpy(first,seven);
	}
	if(num1==8)
	{
		strcpy(first,eight);
	}
	if(num1==9)
	{
		strcpy(first,nine);
	}
	if(num5==1)
	{
		if(num4==0)
		{
			strcpy(fifth,ten);
		}
		if(num4>0)
		{
			if(num4==1)
			{
				strcpy(fifth,eleven);
			}
			if(num4==2)
			{
				strcpy(fifth,twelve);
			}
			if(num4==3)
			{
				strcpy(fifth,thirteen);
			}
			if(num4==4)
			{
				strcpy(fifth,fourteen);
			}
			if(num4==5)
			{
				strcpy(fifth,fifteen);
			}
			if(num4==6)
			{
				strcpy(fifth,sixteen);
			}
			if(num4==7)
			{
				strcpy(fifth,seventeen);
			}
			if(num4==8)
			{
				strcpy(fifth,eighteen);
			}
			if(num4==9)
			{
				strcpy(fifth,nineteen);
			}	
		}
	}
	if(num5==2)
	{
		strcpy(fifth,twenty);
	}
	if(num5==3)
	{
		strcpy(fifth,thirty);
	}
	if(num5==4)
	{
		strcpy(fifth,fourty);
	}
	if(num5==5)
	{
		strcpy(fifth,fifty);
	}	
	if(num5==6)
	{
		strcpy(fifth,sixty);
	}
	if(num5==7)
	{
		strcpy(fifth,seventy);
	}
	if(num5==8)
	{
		strcpy(fifth,eighty);
	}
	if(num5==9)
	{
		strcpy(fifth,ninety);
	}
		
	if(num2==1)
	{
		if(num1==0)
		{
			strcpy(second,ten);
		}
		if(num1>0)
		{
			if(num1==1)
			{
				strcpy(second,eleven);
			}
			if(num1==2)
			{
				strcpy(second,twelve);
			}
			if(num1==3)
			{
				strcpy(second,thirteen);
			}
			if(num1==4)
			{
				strcpy(second,fourteen);
			}
			if(num1==5)
			{
				strcpy(second,fifteen);
			}
			if(num1==6)
			{
				strcpy(second,sixteen);
			}
			if(num1==7)
			{
				strcpy(second,seventeen);
			}
			if(num1==8)
			{
				strcpy(second,eighteen);
			}
			if(num1==9)
			{
				strcpy(second,nineteen);
			}	
		}
	}
	if(num2==2)
	{
		strcpy(second,twenty);
	}
	if(num2==3)
	{
		strcpy(second,thirty);
	}
	if(num2==4)
	{
		strcpy(second,fourty);
	}
	if(num2==5)
	{
		strcpy(second,fifty);
	}	
	if(num2==6)
	{
		strcpy(second,sixty);
	}
	if(num2==7)
	{
		strcpy(second,seventy);
	}
	if(num2==8)
	{
		strcpy(second,eighty);
	}
	if(num2==9)
	{
		strcpy(second,ninety);
	}

	if(num3==1)
	{
		strcpy(third,one);
	}
	if(num3==2)
	{
		strcpy(third,two);
	}
	if(num3==3)
	{
		strcpy(third,three);
	}
	if(num3==4)
	{
		strcpy(third,four);
	}
	if(num3==5)
	{
		strcpy(third,five);
	}	
	if(num3==6)
	{
		strcpy(third,six);
	}
	if(num3==7)
	{
		strcpy(third,seven);
	}
	if(num3==8)
	{
		strcpy(third,eight);
	}
	if(num3==9)
	{
		strcpy(third,nine);
	}
	
	if(num4==1)
	{
		strcpy(fourth,one);
	}
	if(num4==2)
	{
		strcpy(fourth,two);
	}
	if(num4==3)
	{
		strcpy(fourth,three);
	}
	if(num4==4)
	{
		strcpy(fourth,four);
	}
	if(num4==5)
	{
		strcpy(fourth,five);
	}	
	if(num4==6)
	{
		strcpy(fourth,six);
	}
	if(num4==7)
	{
		strcpy(fourth,seven);
	}
	if(num4==8)
	{
		strcpy(fourth,eight);
	}
	if(num4==9)
	{
		strcpy(fourth,nine);
	}
	
	if(num6==1)
	{
		strcpy(sixth,one);
	}
	if(num6==2)
	{
		strcpy(sixth,two);
	}
	if(num6==3)
	{
		strcpy(sixth,three);
	}
	if(num6==4)
	{
		strcpy(sixth,four);
	}
	if(num6==5)
	{
		strcpy(sixth,five);
	}	
	if(num6==6)
	{
		strcpy(sixth,six);
	}
	if(num6==7)
	{
		strcpy(sixth,seven);
	}
	if(num6==8)
	{
		strcpy(sixth,eight);
	}
	if(num6==9)
	{
		strcpy(sixth,nine);
	}
	
	if(num7==1)
	{
		strcpy(seventh,one);
	}
	if(num7==2)
	{
		strcpy(seventh,two);
	}
	if(num7==3)
	{
		strcpy(seventh,three);
	}
	if(num7==4)
	{
		strcpy(seventh,four);
	}
	if(num7==5)
	{
		strcpy(seventh,five);
	}	
	if(num7==6)
	{
		strcpy(seventh,six);
	}
	if(num7==7)
	{
		strcpy(seventh,seven);
	}
	if(num7==8)
	{
		strcpy(seventh,eight);
	}
	if(num7==9)
	{
		strcpy(seventh,nine);
	}
	
	if(num7>0)
	{
		printf("%s %s ",seventh,million);
	}
	if(num6>0)
	{
		if((num4==0)&&(num5==0))
		{
			printf("%s %s %s ",sixth,hundred,thousand);
		}
		if((num4>0)||(num5>0))
		{
			printf("%s %s ",sixth,hundred);
		}
	}		
	if(num5>0)
	{
		if((num7>=0)&&(num6>0))
		{
			if(num4==0)
			{
				printf("and %s %s ",fifth,thousand);
			}
			else
			{
				printf("and %s ",fifth);
			}
		}
		else
		{
			if(num4==0)
			{
				printf("%s %s ",fifth,thousand);
			}
			if(num4>0)
			{
				printf("%s ",fifth);
			}
		}
	}
	if(num4>0)
	{
		if(num5==1)
		{
			printf("%s ",thousand);
		}
		else
		{
			printf("%s %s ",fourth,thousand);
		}
	}
	if(num3>0)
	{
		printf("%s %s ",third,hundred);
	}				
	if(num2>0)
	{
		if(num3>0)
		{
			printf("and %s ",second);
		}
		if(num3==0)
		{
			printf("%s ",second);
		}
	}
	if(num1>0)
	{
		if(num2==1)
		{
			printf("\n");
		}
		else
		{
			printf("%s",first);
		}
	}
}

