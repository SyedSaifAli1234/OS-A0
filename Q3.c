#include <stdio.h>
#include <string.h>

int main(int argc, char* arg[]){

	printf("Arguement is %s \n", arg[1]);

	if(*arg[1] == 'a'){
		FILE *fp1 = fopen ("q3_a.txt","r");
	}
	if(*arg[1] == 'b'){
		FILE *fp1 = fopen ("q3_b.txt","r");
	}
	FILE *fp2 = fopen ("new","a+");
	

	char buff[10];
	char new [10];
	int flag = 0;
	memset(buff,'\0',sizeof(buff));
    memset(new,'\0',sizeof(new));
	rewind(fp1);
	int i;

	while(fscanf(fp1, "%s", buff) !=EOF){
		for(i=0; buff[i]!='\0'; i++){

		if ( buff[i] == 'a' || buff[i] == 'e' || buff[i] == 'i' || buff[i] == 'o' || buff[i] == 'u' ||
			 buff[i] == 'A' || buff[i] == 'E' || buff[i] == 'I' || buff[i] == 'O' || buff[i] == 'U'){

			flag = 1;
			printf("The flag = %d for %c \n", flag, buff[i]);
			
			}
		}

		if(flag == 0){
			int i = strlen(buff) - 1;
			for(int j = 0; j < strlen(buff); j++ ){
				new[j] = buff[i];
				i--;
			}
			i = 0;
			fputs(new, fp2);			
		}
		else if(flag == 1){
			fputs(buff, fp2);			
			
		}
		memset(new,'\0',sizeof(new));
		memset(buff,'\0',sizeof(buff));
		flag = 0;
	}
	fclose(fp1);
	fclose(fp2);

	return 0;
}

