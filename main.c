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
	
		return 0;	//유의미한 글자다 
	
 } 

int fget_word(FILE *fp, char *word){
	
	char c;
	int cnt;
	 
	while ((c=fgetc(fp)) != EOF){
		if(is_whitespace(c) == 0){
			break;
		}	
	}
	
	if(c == EOF){	//최초 읽은 문자가 마지막일 때 
		return 0;
	}
	
	//본격적으로 단어를 한 글자씩 읽음 
	cnt = 0;
	word[cnt++] = c;	//아까 읽은 첫 글자 입력  
	word[cnt] = '\0';	//혹시 뒤에서 못 읽을 수 있음으로 
	
	while((word[cnt]=fgetc(fp)) != EOF){ //1문자 받음 
		if(is_whitespace(word[cnt]) == 1)	//공백 문자 받은 거면 취소  
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
	return -1;		//정상적으로 끝나는 거랑 다른 값으로 지정해 주기 
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
