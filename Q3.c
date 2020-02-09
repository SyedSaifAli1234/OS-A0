#include <stdio.h>
#include <string.h>

int main(){

	
	FILE *fp1 = fopen ("q3_a.txt","r");
	FILE *fp2 = fopen ("new","a+");

	char buff[10];
	char new [10];
	int flag = 0;
	memset(buff,'\0',sizeof(buff));
    memset(new,'\0',sizeof(new));
	rewind(fp1);
	int i;

	while(fscanf(fp1, "%s", buff) !=EOF){
		for(i=0; buff[i]!='\0'; i++)
		{
			//printf("Strcmp: %d ", strcmp(&buff[i],"i"));
			//printf("The character is =%c \n",buff[i]);
			// if ( strcmp(&buff[i],"a") == 0 || strcmp(&buff[i],"e") == 0 || strcmp(&buff[i],"i") == 0 || strcmp(&buff[i],"o") == 0 || strcmp(&buff[i],"u") == 0 || 
			// 	 strcmp(&buff[i],"A") == 0 || strcmp(&buff[i],"E") == 0 || strcmp(&buff[i],"I") == 0 || strcmp(&buff[i],"O") == 0 || strcmp(&buff[i],"U") == 0){
		if ( buff[i] == 'a' || buff[i] == 'e' || buff[i] == 'i' || buff[i] == 'o' || buff[i] == 'u')
		{
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

