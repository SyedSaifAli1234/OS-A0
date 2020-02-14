#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	int d =0;
	while(d != 1){

		char choice[10], index[10];
		char temp;
		int check = 0;
		int number = 0; 
		int number2 = 0; 
		int count = 0;
		int for1 = 0;


		printf("Choose the action to perform: \n");
		printf("1. Add student \n");
		printf("2. Check records \n");
		printf("3. Remove student \n");
		printf("4. Exit \n");

		printf("Choose your option: ");
		fgets(choice, 10, stdin);

		number=atoi(choice);

		if(number == 1){
			FILE *mf = fopen ("Input.txt","a+");
			int n=0;
			char name[50];
			char roll[50];
			char email[50];

			if (mf == 0)
			{
				printf ("Error Opening File");
				return 1;
			}

			printf("Enter Name: ");
			fgets(name, 50, stdin);
			name[strlen(name) -1] = '\0';

			printf("Enter Roll N.o: ");
			fgets(roll, 50, stdin);
			roll[strlen(roll) -1] = '\0';


			printf("Enter Email: ");
			fgets(email, 50, stdin);
			email[strlen(email) -1] = '\0';


		    fprintf(mf, "Name    : %s \n" , name);
		    fprintf(mf, "Roll.no : %s \n" , roll);
		    fprintf(mf, "Email   : %s \n" , email);

		    fclose(mf);
			
		}
		else if(number == 2){
			FILE *fp = fopen ("Input.txt","r");
			

			printf("Enter the index of the student to check: ");
			fgets(index, 10, stdin);
			index[strlen(index) -1] = '\0';
			number2 = atoi(index);
			for1 = number2;

			temp = getc(fp);

				while(temp!=EOF){
					//printf("%c\n", temp);
					if(temp == '\n'){
						count++;
						if(count == 3){
							check++;
							count=0;
						}
					}
					if(check==number2){
						
							printf("%c", temp);
						
					}
					
					temp = getc(fp);
					//printf("Check: %d , Number2: %d \n", check, number2);
					
				}
			fclose(fp);
			printf("\n");
		}
		else if(number == 3){
			FILE *fp = fopen ("Input.txt","r");
			

			printf("Enter the index of the student to remove: ");
			fgets(index, 10, stdin);
			index[strlen(index) -1] = '\0';
			number2 = atoi(index);
			for1 = number2;

			temp = getc(fp);

				while(temp!=EOF){
					//printf("%c\n", temp);
					if(temp == '\n'){
						count++;
						if(count == 3){
							check++;
							count=0;
						}
					}
					if(check!=number2){
						if(for1==0){
							temp = getc(fp);
							for1++;
						}
						FILE *fp1 = fopen ("Input2.txt","a+");
						putc(temp,fp1);
						fclose(fp1);
					}
					
					temp = getc(fp);
					//printf("Check: %d , Number2: %d \n", check, number2);
					
				}
			fclose(fp);
			remove("Input.txt");
        	//rename the file copy.c to original name
        	rename("Input2.txt", "Input.txt");
		}
		else if(number == 4){
			d=1;
		}
		printf("-------------------------- \n");
	}
	
}