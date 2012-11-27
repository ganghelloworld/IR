#include <stdio.h>

char output[10]; 

void display_b(int a)
{
	int len = 0;
	while(a != 0)
	{
		output[len++] = (a % 2) ? '1' : '0';
		a /= 2;
	}
	int i, j;
	char temp;
	for(i = 0, j = len-1; i < j; i++, j--)
	{
		temp = output[i];
		output[i] = output[j];
		output[j] = temp;
	}
	output[len] = '\0';
}

int main()
{
	int i = 0;
	int fg[8] = {70, 69, 78, 71, 71, 65, 78, 71};
	for(i = 0; i < 8; i++)
	{
		display_b(fg[i]);
		printf("%s", output);
	}
	printf("\n");
}

