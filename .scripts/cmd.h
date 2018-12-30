#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
void cmd(char *command, char array[]);
/******************************************************************
 ******************************************************************
 ** #include<./cmd.h>     use as follows:				  		 **
 **--------------------------------------------------------------**
 ** void main(void){
		char arr[64]; <-- can be any size, must be 1 above expected output
		cmd("echo 'hello world'", arr);
		printf("%s", arr);
		printf("%c", arr[0]);
		return 0;
	}
**************************************************************
******************************************************************/
void cmd(char *command, char array[])
{
	FILE *fp;
	char result[(sizeof(array) + 8)];
	fp = popen(command, "r");
	while(fgets(result, sizeof(result), fp) != NULL){ //read fgets docs, try to get it so ite readd all lines of stdout not jsut the last
		printf("%s", result);
	}
	pclose(fp);

	strcpy(array, result);

}
