#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *fp;
	
	char filename[100];
	
	printf("Put a file name: ");
	scanf("%s", filename);
	
	fp = fopen(filename, "r");
	
	if (fp == NULL) {
	printf("File name error! Check the file name: %s\n", filename);
	return -1;		//���������� ������ �Ŷ� �ٸ� ������ ������ �ֱ� 
	}
	
	else {
	printf("%c\n", fgetc(fp));
	}
		
	fclose(filename);

	return 0;
}
