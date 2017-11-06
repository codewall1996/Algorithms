#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bruteforce(char* text,char* pattern);
void horspool(char* text,char* pattern);
int main(){
	int maxl = 100;
	char* text = malloc(sizeof(char)*maxl);
	int currl = maxl;
	int c;int i=0;
	while((c=getchar())!='\n' && c!=EOF){
		text[i++] = (char)c;
		if(i==maxl){
			currl += i+maxl;
			text = realloc(text,currl);
		}
	}
	text[i] = '\0';
	char pattern[100];
	scanf("%[^\n]s",pattern);
	bruteforce(text,pattern);
	horspool(text,pattern);	
}
void bruteforce(char* text,char* pattern){
	int count = 0;int i;	
	int lt = strlen(text);int lp=strlen(pattern);
	for(i=0;i<=(lt-lp);i++){
		int j=0;
		while(text[i+j]==pattern[j] && j<strlen(pattern)){
			j++;
			count++;
		}
		count++;
		if(pattern[j]=='\0'){
			printf("%d %d\n",i,count-1);
			break;
		}
	//	if(j>0)	i+=j-1;		
	}
	if(i==lt-lp+1)	printf("-1 %d\n",count-1);
}
void horspool(char* text,char* pattern){
	int st[26];int i=0;
	int lp=strlen(pattern);
	int lt=strlen(text);
	for(i=0;i<26;i++){
		st[i] = lp;
	}
	for(i=0;i<lp-1;i++){
		st[pattern[i]-97] = lp-i-1;		
	}
	i=lp-1;int j=lp-1;int count=0;
	while(i<=(lt-lp)){
		int ti=i;int tj=j;int lst=0;
		while(text[ti]==pattern[tj] && lst<lp){
			ti--;tj--;lst++;//count++;
		}
		count++;
		if(lst==lp){
			printf("%d %d\n",i-lp+1,count);break;
		}
		i+=st[text[i]-97];
	}
	if(i>(lt-lp+1))	printf("-1 %d\n",count);
}
