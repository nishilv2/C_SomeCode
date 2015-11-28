#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//模板实现交换
void swap_self(void *vp1,void *vp2,int length)
{
	void *p = malloc(length);
	memcpy(p,vp1,length);
	memcpy(vp1,vp2,length);
	memcpy(vp2,p,length);
}

void main()
{
	int a=1;
	int b=2;
	printf("a=");
	printf("%d\n",a);
	printf("b=");
	printf("%d\n",b);
	printf("********\n");
	swap_self(&a,&b,4);
	printf("a=");
	printf("%d\n",a);
	printf("b=");
	printf("%d\n",b);
	system("pause");
}


