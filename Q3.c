#include <stdio.h>
#include <string.h>

int main(){

	FILE *fp1 = fopen ("q3_a.txt","a+");
	//FILE *fp2 = fopen ("output","a+");

	char buff[100];
	char new [100];
	int flag = 0;

	//memset(buff,'\0',sizeof(buff));
    //memset(new,'\0',sizeof(new));
	rewind(fp1);
	

	while(fscanf(fp1, "%s", buff) !=EOF){
		for(int i=0; i< sizeof(buff); i++){
			if ( buff[i] == "a" || buff[i] == "e" || buff[i] == "i" || buff[i] == "o" || buff[i] == "u" || 
				buff[i] == "A" || buff[i] == "E" || buff[i] == "I" || buff[i] == "O" || buff[i] == "U"){
				flag == 1;
			}
			if(flag == 1){
				for(int j = 0; j< sizeof(buff); i++ ){
					new[j]=buff[sizeof(buff)-1];
				}
				break;
			}
		}
	}
		
	
	fclose(fp1);
	//fclose(fp2);

	return 0;
}

