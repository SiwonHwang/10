#include <stdio.h>
#include <stdlib.h>
#include "keyword.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int is_whitespace(char c)
{
	if (c == ' ' ||
	    c == '\t' ||
		c == '\n' ||
		c == '\r' ||
		c == '(' ||
		c == ')')
		return 1; //공백글자다. 
		
	return 0; //유의미한 글자다. 
 } 

int fget_word(FILE* fp, char* word){
	
	char c;
	int cnt;
	
	//유의미한 글자가 나올때까지 입력된 글자 버림 반복  
	while ((c=fgetc(fp)) != EOF){
		if (is_whitespace(c) == 0)
		{
			break; //무의미한 문자가 아니면 멈춤  
		}
	}
	
	if (c == EOF) //최초 읽은 문자가 마지막일때 (파일 끝일때) 
	{
		return 0;
	}
	
	//본격적으로 단어를 한글자씩 읽음  
	cnt=0;
	word[cnt++] = c; //아까 읽은 첫글자 입력  
	word[cnt] = '\0'; //혹시 뒤에서 못읽을 수 있으므로 (한글자짜리 단어) 
	
	while ((word[cnt]=fgetc(fp)) != EOF) //한 문자 받음  
	{
		if (is_whitespace(word[cnt]) == 1) //공백문자면 받은거 취소하고 나감  
		{
			word[cnt] = '\0';
			break;
		}
		cnt++;
	}
	
	return cnt;
}

int main(int argc, char *argv[]) {
	FILE* fp;
	char name[100];
	char word[100];
	
	printf("Input a file name : ");
	scanf("%s", name);
	
	fp = fopen(name, "r");
	
	if (fp == NULL)
	{
		printf("ERROR! check the file name : %s\n", name);
		return -1;
	}
	
	while (fget_word(fp, word) != 0)
	{
		printf("%s\n", word);
		//count_word(word); 
	}
	//print_word();
	
	fclose(fp);
		
	return 0;
}
