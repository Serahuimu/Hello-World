#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	//��ȡ�ļ�ʱ�洢�ַ� 
	int ch;
	//�ļ�ָ�� 
	FILE * fp;
	//��¼�ļ��е��ַ����� 
	unsigned long count = 0;
	
	//��������в����� 
	if (2 !=argc)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	//����ļ����ļ����������˳����� 
	if (NULL == (fp = fopen(argv[1], "r")))
	{
		printf("Can not open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	//��ȡ�ļ��е��ַ���ֱ���ļ�ĩβ 
	while (EOF != (ch = getc(fp)))
	{
//		�ȼ���putchar(ch); 
		putc(ch, stdout);
		count++;
	}
	//�ر��ļ� 
	fclose(fp);
	printf("File %s has %lu characters.\n", argv[1], count);
	
	return 0;
}
