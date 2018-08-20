#include <stdio.h>
#include <string.h>

int main() {
	int i;
	for (i = 1; i <= 100; i++)
	{
		char output[10] = "";
		if (i % 3 == 0) { strcat(output,"Fizz"); }
		if (i % 5 == 0) { strcat(output,"Buzz"); }
		if (output == "") { output = sprintf(output, "%s%d", output, i); }
		
		printf("%s\n", output);
	}
	
	return 0;
}
