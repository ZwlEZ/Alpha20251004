#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//��
void Z_A_A(void)
{
	printf("�˳��������룺0\n�ӷ����룺1\n�������룺2\n�˷����룺3\n�������룺4\n");
	int a;
	scanf("%d", &a);
	if (a == 0)
	{
		exit(0);
	}
	else if (a == 1)
	{
		printf("�������������֣�\n");
		int b, c;
		scanf("%d%d", &b, &c);
		printf("����ǣ�%d\n", b + c);
	}
	else if (a == 2)
	{
		printf("�������������֣�\n");
		int b, c;
		scanf("%d%d", &b, &c);
		printf("����ǣ�%d\n", b - c);
	}
	else if (a == 3)
	{
		printf("�������������֣�\n");
		int b, c;
		scanf("%d%d", &b, &c);
		printf("����ǣ�%d\n", b * c);
	}
	else if (a == 4)
	{
		printf("�������������֣�\n");
		int b, c;
		scanf("%d%d", &b, &c);
		if (c == 0)
		{
			printf("��������Ϊ�㣡\n");
		}
		else
		{
			printf("����ǣ�%d\n", b / c);
		}
	}
	else
	{
		printf("����������������룡\n");
	}
	return;
}

int main()
{
	printf("��ӭʹ�á�\n");
	Z_A_A();
	return 0;
}