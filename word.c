#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int a,char *argv[]){
	int cnum = 0;
	int wnum = 0;
	char ch;
	FILE *fp;
	bool flag = true;
	fp = fopen(argv[2],"r");
	if(fp==NULL){
		printf("�Ҳ����ļ�!"); 
		exit(1);
	}
	if(!strcmp("-c",argv[1])){
	while((ch=getc(fp))!=EOF){
		++cnum;
	}
	printf("�ַ���Ϊ��%d\n",cnum);
	fclose(fp); 
	}
	else if(!strcmp("-w",argv[1])){
			while((ch=getc(fp))!=EOF){
				if(ch==' '||ch==','||ch=='\n'){
					wnum++;
				}
		}
		if((ch=getc(fp))==EOF){
			wnum++;
		}
		printf("������Ϊ��%d\n",wnum);
		fclose(fp);
	}
	return 0;
}
