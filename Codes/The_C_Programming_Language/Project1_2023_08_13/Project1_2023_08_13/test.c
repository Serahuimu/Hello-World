////��1. ��һ��C���Գ���
//#include <stdio.h>		//����ճ��stdio.h�ļ�������ļ�������printf()������ԭ��
////�����void��ʾmain�����������κβ���
//int main(void)			//�κ�C���򶼴�main()�����ĵ�һ�п�ʼִ�У�main()������C�������ڣ�������������ֻ��һ��
//{
//	printf("Hello, World!\n");	//printf()��������������Ļ�ϴ�ӡһЩ����
//
//	return 0;					//����ֵ������main()�ķ���������int�������ͣ�����ֵ��0
//}


////��2. ���϶Ⱥͻ��϶Ȼ�ת�ĳ���
////���϶� = (5 / 9) * (���϶� - 32)
//#include <stdio.h>
//#define LOW_FAHR 0
//#define MAX_FAHR 300
//#define STEP 20
//int main(void)
//{
//	int fahr, cel;
//	fahr = LOW_FAHR;	//�����ַ�ʽ��������ķ�ʽ�ɶ��ԺͿ��޸��Ի����Ӻܶ�
//	//fahr = 0;
//
//	while (fahr <= MAX_FAHR)
//	{
//		cel = ((fahr - 32) * 5 )/ 9;
//		printf("%4d%4d\n", fahr, cel);
//		fahr += STEP;
//	}
//
//	return 0;
//}

////��ϰ1-1�����Լ���ϵͳ������hello, world���򣬲�����ȥ�����ֿ�������ʲô����
//#include <stdio.h>
//
//int main(void)
//{
//	//printf("Hello, World!\n");
//	//printf("Hello, World!");
//	//printf("Hello, World!"
//	//	);
//	//printf("Hello, World);	//����
//
//	return 0;
//}

////��ϰ1-2���۲�printf()�����д���'\c'����ʱ�����ʲô���
//#include <stdio.h>
//
//int main(void)
//{
//	//����Ե�б�ߣ�ֱ�ӳ��������ĸ
//	printf("Hello, World!\c");
//	putchar('\n');
//	printf("Hello, World!\p");
//
//	return 0;
//}

////��3�������϶Ⱥͻ��϶Ȼ�ת�ĳ��򻻳�С������
//#include <stdio.h>
//#define MAX_FAHR 300
//#define LOW_FAHR 0
//#define STEP 20
//int main(void)
//{
//	double fahr, cel;
//
//	for (fahr = LOW_FAHR; fahr <= MAX_FAHR; fahr += STEP)
//	{
//		cel = (fahr - 32) * 5.0 / 9.0;
//		printf("%4.0lf%10.1lf\n", fahr, cel);
//	}
//
//	return 0;
//}

////��ϰ1-3���޸��¶�ת�������ڿ��ؼ��ϱ���
//#include <stdio.h>
//#define MAX_FAHR 300
//#define LOW_FAHR 0
//#define STEP 20
//
//int main(void)
//{
//	double fahr, cel;
//	
//	printf("fahr\tcel\n");
//	for (fahr = LOW_FAHR; fahr <= MAX_FAHR; fahr += STEP)
//	{
//		cel = (fahr - 32) * 5.0 / 9.0;
//		printf("%4.0lf%8.1lf\n", fahr, cel);
//	}
//
//	return 0;
//}

////��ϰ1-4����дһ�������϶�ת��Ϊ���϶ȵĳ���
//#include <stdio.h>
//#define MAX_CEL 300
//#define MIN_CEL 0
//#define STEP 1
//
//int main(void)
//{
//	double cel, fahr;
//
//	for (cel = MIN_CEL; cel <= MAX_CEL; cel += STEP)
//	{
//		//(fahr - 32) * 5 / 9 = cel
//		//cel * 9 / 5 + 32 = fahr
//		fahr = cel * 9 / 5 + 32;
//		printf("%4.0lf%10.1lf\n", cel, fahr);
//	}
//
//	return 0;
//}


////��ϰ1-5���޸��¶�ת������Ҫ���������ӡ��
//#include <stdio.h>
//#define MAX_FAHR 300
//#define LOW_FAHR 0
//#define STEP 20
//
//int main(void)
//{
//	double fahr, cel;
//
//	for (fahr = MAX_FAHR; fahr >= LOW_FAHR; fahr -= STEP)
//	{
//		cel = ((fahr - 32) * 5) / 9;
//		printf("%3.0lf%10.1lf\n", fahr, cel);
//	}
//
//	return 0;
//}


//��4���ļ�����
//#include <stdio.h>
//
//int main(void)
//{
//	int c;
//
//	c = getchar();
//	while (c != EOF) {
//		putchar(c);
//		c = getchar();
//	}
//
//	return 0;
//}

////��΢�޸�һ������ĳ���
//#include <stdio.h>
//
//int main(void)
//{
//	int c;
//	
//	while ((c = getchar()) != EOF) {
//		putchar(c);
//	}
//
//	return 0;
//}


////��ϰ1-6����֤���ʽgetchar() != EOF��ֵ��0����1
////��1
//#include <stdio.h>
//
//int main(void)
//{
//	int c;
//
//	if (0 == ((c = getchar()) != EOF))
//		printf("0\n");
//	else if (1 == ((c = getchar()) != EOF))
//		printf("1\n");
//	else
//		printf("else\n");
//
//	return 0;
//}


////��ϰ1-7����дһ����ӡEOFֵ�ĳ���
//#include <stdio.h>
//
//int main(void)
//{
//	printf("%d\n", EOF);
//
//	return 0;
//}

//��5��ͳ���ַ�
//#include <stdio.h>
//
//int main(void)
//{
//	long nc;
//	
//	nc = 0;
//	while (getchar() != EOF)
//		++nc;
//	printf("%ld\n", nc);
//
//	return 0;
//}

////��һ���汾
//#include <stdio.h>
//
//int main(void)
//{
//	double nc;
//
//	for (nc = 0; getchar() != EOF; ++nc)
//		;
//	printf("%.0lf\n", nc);
//
//	return 0;
//}

////�м����������м������з�������������
//#include <stdio.h>
//
//int main(void)
//{
//	int c, nl;
//
//	nl = 0;
//	while ((c = getchar()) != EOF) {
//		if (c == '\n') {		//�����״����װ�"=="��д��"="
//			++nl;
//		}
//	}
//	printf("%d\n", nl);
//
//	return 0;
//}


////��ϰ1-8����дһ��ͳ�ƿո��Ʊ���뻻�з������ĳ���
////��Ҫһ������c���getchar()������whileѭ���������
////��Ҫ���������ֱ�Ϊ�ո��Ʊ���ͻ��з�����
//#include <stdio.h>
//
//int main(void)
//{
//	int c, space, table, enter;
//
//	space = table = enter = 0;
//	while ((c = getchar()) != EOF) {
//		if (c == '\n') {
//			++enter;
//		}
//		else if (c == '\t') {
//			++table;
//		}
//		else if (c == ' ') {
//			++space;
//		}
//			
//	}
//
//	printf("�ո�%d, ���У�%d, �Ʊ����%d\n", space, enter, table);
//
//	return 0;
//}

//��ϰ1-9����дһ�����븴�Ƶ�����ĳ��򣬲������������Ķ���ո���һ���ո���档
//��Ҫ����c���whileѭ����getchar()�����������
//��ô�Ե�����Ŀո�

#include <stdio.h>

int main(void)
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {		//����Ӧ���������еĿո񣬲�����Ҫ��
			continue;
		}
		putchar(c);
	}

	return 0;
}


//��6������ͳ��
////���Լ�дһ��
////����ͳ�Ƴ���Ӧ�ø��ݿո񡢻��з���ˮƽ�Ʊ�����жϸ���
////��getchar()�������whileѭ�����������
//
//#include <stdio.h>
//
//int main(void)
//{
//	int count;
//	char c;
//
//	count = 0;
//	while ((c = getchar()) != EOF) {
//		if (c == '\n' || c == '\t' || c == ' ') {
//			++count;
//		}
//	}
//	printf("Total is %d\n", count);
//
//	return 0;
//}

////����д��
//#include <stdio.h>
//#define IN 1		//�ǵ���
//#define OUT 0		//���ǵ���
//
//int main(void)
//{
//	int c, nl, nw, nc, state;
//
//	state = OUT;
//	nl = nw = nc = 0;
//	while ((c = getchar()) != EOF) {
//		++nc;
//		if (c == '\n')
//			++nl;
//		if (c == ' ' || c == '\n' || c == '\t')
//			state = OUT;
//		else if (state == OUT) {
//			state = IN;
//			++nw;
//		}
//	}
//
//	printf("%d %d %d\n", nl, nw, nc);
//
//	return 0;
//}