#include <stdio.h>
/*
	���ܣ���2102! = 2102 * 2101 * 2100 * ���� * 1=???
	��������0
	ԭ�������������ܱ�ʾ�������������64��2���(unsigned long)��
*/
int main(int argc, char **argv)
{
	unsigned long mul_num = 1;
	int i;
	for (i=2102; i>0; i--)
	{
		mul_num *= i;
	}
	printf("%lu\n", mul_num);
	
	return 0;
}
