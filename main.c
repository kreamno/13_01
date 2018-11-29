#include <stdio.h>
#include <stdlib.h>
int is_whitespace(char c)
{
	if(c == ' '||
	   c == '\t'||
	   c == '\n'||
	   c == '\r'||
	   c == '('||
	   c == ')')
	{
		return 1;
	}
	
		return 0;	//���ǹ��� ���ڴ� 
	
 } 

int fget_word(FILE *fp, char *word){
	
	char c;
	int cnt;
	 
	while ((c=fgetc(fp)) != EOF){
		if(is_whitespace(c) == 0){
			break;
		}	
	}
	
	if(c == EOF){	//���� ���� ���ڰ� �������� �� 
		return 0;
	}
	
	//���������� �ܾ �� ���ھ� ���� 
	cnt = 0;
	word[cnt++] = c;	//�Ʊ� ���� ù ���� �Է�  
	word[cnt] = '\0';	//Ȥ�� �ڿ��� �� ���� �� �������� 
	
	while((word[cnt]=fgetc(fp)) != EOF){ //1���� ���� 
		if(is_whitespace(word[cnt]) == 1)	//���� ���� ���� �Ÿ� ���  
		{
			word[cnt] = '\0';
			break;
		}
		cnt++;
	}
	return cnt;
}

int main(int argc, char *argv[]) {
	FILE *fp;
	
	char filename[100];
	char word[100];
	
	printf("Put a file name: ");
	scanf("%s", filename);
	
	fp = fopen(filename, "r");
	
	if (fp == NULL) {
	printf("File name error! Check the file name: %s\n", filename);
	return -1;		//���������� ������ �Ŷ� �ٸ� ������ ������ �ֱ� 
	}
	 
	//word reading
	while(fget_word(fp, word) != 0)
	{
		//word processing
		printf("%s\n",word); //test code
	}
		
	fclose(filename);

	return 0;
}
