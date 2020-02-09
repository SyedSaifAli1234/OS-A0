#include <stdio.h>
#include <string.h>

int main(){

	
	FILE *fp1 = fopen ("q3_a.txt","a+");
	FILE *fp2 = fopen ("output","a+");

	char buff[100];
	char new [100];
	int flag = 0;
    
	rewind(fp1);
	

	while(fscanf(fp1, "%s", buff) !=EOF){
		for(int i=0; i< sizeof(buff); i++){
			if ( strcmp(&buff[i],"a") || strcmp(&buff[i],"e") || strcmp(&buff[i],"i") || strcmp(&buff[i],"o") || strcmp(&buff[i],"u") || 
				strcmp(&buff[i],"A") || strcmp(&buff[i],"E") || strcmp(&buff[i],"I") || strcmp(&buff[i],"O") || strcmp(&buff[i],"U")){
				flag = 1;
			}
		}
		if(flag == 0){
			for(int j = 0; j< sizeof(buff); j++ ){
				new[j]=buff[sizeof(buff)-j];
			}
			fputs(new, output);
			// printf("%s\n", new);
			memset(new,'\0',sizeof(new));
		}
		else if(flag == 1){
			fputs(buff, output);
			//printf("%s\n", buff);
			memset(buff,'\0',sizeof(buff));
		}
	}
		
	printf("%s\n", buff);
	printf("%s\n", new);
	fclose(fp1);
	fclose(fp2);

	return 0;
}

