#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]){
	int i;
	int flag = -1;
	//�жϴ�������
	for(i = 0; i < argc-1; i++){
		//�жϴ��������е� "-c"
		if (strcmp(argv[i], "-c") == 0)
			flag = 1;
		//�жϴ��������е� "-w"
		else if (strcmp(argv[i], "-w") == 0)
			flag = 0;
	}
	
	FILE* fp;	
	fp = fopen(argv[argc-1], "r");
	if (fp == NULL){
		printf("�����ļ��Ƿ���ڣ�");
		return 0;
	}
	if(flag==1)
		printf("�ַ�����%d", WordCount(fp,flag));
	else if(flag==0)
		printf("��������%d", WordCount(fp,flag));
	fclose(fp);
	return 0;
}
	//ͳ���ַ��� 
	int WordCount(FILE* fp,int flag) {
		int word_Nums = 0;
		int char_Nums = 0;
		char ch;
			while(((ch=getc(fp))!=EOF)){
				char_Nums++;	//�ַ�����
			
				if(ch==' '||ch==','||ch=='\n')
					word_Nums++;	//���ʼ���	
			}
		return (flag==1)?char_Nums:++word_Nums;
	}

