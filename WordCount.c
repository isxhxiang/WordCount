#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]){
	int i;
	int flag = -1;
	//判断处理类型
	for(i = 0; i < argc-1; i++){
		//判断处理类型中的 "-c"
		if (strcmp(argv[i], "-c") == 0)
			flag = 1;
		//判断处理类型中的 "-w"
		else if (strcmp(argv[i], "-w") == 0)
			flag = 0;
	}
	
	FILE* fp;	
	fp = fopen(argv[argc-1], "r");
	if (fp == NULL){
		printf("请检查文件是否存在！");
		return 0;
	}
	if(flag==1)
		printf("字符数：%d", WordCount(fp,flag));
	else if(flag==0)
		printf("单词数：%d", WordCount(fp,flag));
	fclose(fp);
	return 0;
}
	//统计字符数 
	int WordCount(FILE* fp,int flag) {
		int word_Nums = 0;
		int char_Nums = 0;
		char ch;
			while(((ch=getc(fp))!=EOF)){
				char_Nums++;	//字符计数
			
				if(ch==' '||ch==','||ch=='\n')
					word_Nums++;	//单词计数	
			}
		return (flag==1)?char_Nums:++word_Nums;
	}

