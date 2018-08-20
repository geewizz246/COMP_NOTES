#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<errno.h>
#include<windows.h>
#include<iostream>

void type_text(const std::string& text) //function for delayed character text
{
	for (std::size_t i = 0; i<text.size();i++)
	{
		std::cout << text[i] << std:: flush ;
		Beep(365.7,10);
		
		Sleep(25);
	}
}

main()
{
	type_text ("Hey how are ya, this is merely a test to see if the beep noise makes it through\n");
}

