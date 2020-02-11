#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* arg[]){

	FILE *fp1 = fopen ("Input.txt","r");
	int n=0;

	if (fp1 == 0)
	{
		printf ("Error Opening File");
		return 1;
	}

    char c = fgetc(mf);

	while ( c != EOF )
	{
		if(c >= '0' && c <= '9'){
			n=n+1;
			c = fgetc(mf);
		}
		else{
			c = fgetc(mf);
		}

	}
	printf("The total number of digits are: %d \n", n );
	fclose(fp1);

}