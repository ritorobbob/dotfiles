#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
void fcmd(char *command, char array[]);
void cmd(char *command, char array[]);
/******************************************************************
 ******************************************************************
 ** #include<./cmd.h>     use as follows:				  		 **
 **--------------------------------------------------------------**
 ** void main(void){
		char arr[64]; <-- can be any size, must be 1 above expected output
		cmd("echo 'hello world \n lol'", arr);
		printf("%s", arr);
		printf("%c", arr[0]);
		return 0; }
**************************************************************
******************************************************************/
void fcmd(char *command, char array[])
{
	FILE *fp;
	char result[(sizeof(array) * 8)];
	fp = popen(command, "r");
//	printf("%i", sizeof(result));
	while(fread(result, 1, sizeof(result), fp) != 0)
	{ 
	//reads fp(stdin), into result array, each item is 1 byte long (char) 
	puts(result);
	}
	pclose(fp);

	strcpy(array, result);

}

void cmd(char *command, char array[])
{
	char result[(sizeof(array) * 8)];
	system(command);
	scanf("%c", result);



	strcpy(array, result);
}
