#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* arg[]){

	FILE *fp1;

	if(*arg[1] == 'a'){
		fp1 = fopen ("q1_a.txt","r");
	}
	else if(*arg[1] == 'b'){
		fp1 = fopen ("q1_b.txt","r");
	}
	else if(*arg[1] == 'c'){
		fp1 = fopen ("q1_c.txt","r");
	}
	else{
		printf("Invalid arguement \n");
		exit(0);
	}

	//FILE *fp1 = fopen ("Input.txt","r");
	int n=0;

	if (fp1 == 0)
	{
		printf ("Error Opening File");
		return 1;
	}

    char c = fgetc(fp1);

	while ( c != EOF )
	{
		if(c >= '0' && c <= '9'){
			n=n+1;
			c = fgetc(fp1);
		}
		else{
			c = fgetc(fp1);
		}

	}
	printf("The total number of digits are: %d \n", n );
	fclose(fp1);

}