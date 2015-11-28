#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//线性搜索数组，回调函数

void *lsearch_self(void* key,void *base, int n,int size, int (*cmpfun)(void*,void*))
{
	int i;
	for(i=0;i<n;i++)
	{
		void* addr = (char*)base + size*i;
		if(cmpfun(key,addr)==0)
		{
			return addr;
		}
	}
	return NULL;
}

int IntCmpfun(void *key,void *addr)
{
	int* vp1= (int*)key;
	int* vp2 = (int*)addr;
	if(*vp1 == *vp2)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int StrCmpfun(void *key,void *addr)
{
	char* vp1 = *(char**)key;
	char* vp2 = *(char**)addr;
	return strcmp(vp1,vp2);
}

void main()
{
	//int a[] = {1,2,3,4};
	//int b = 3;
	//void * found = lsearch_self(&b,a,4,sizeof(int*),IntCmpfun);
	//int* result = (int*)found;
	//printf("%d",*result);
	//system("pause");
	char *a[]={"ab","cd","abc","cde"};
	char *b="abc";
	void *found = lsearch_self(&b,a,4,sizeof(char*),StrCmpfun);
	char **result = (char**)found;
	printf(*result);
	system("pause");
}