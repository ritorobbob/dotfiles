#include</home/bob/.scripts/cmd2.h>

int main(void){

	char arr[64];
	fcmd("echo 'hello world well'", arr);
	printf("%s", arr);
	printf("\n%c", arr[12]);
	return 0;
}
