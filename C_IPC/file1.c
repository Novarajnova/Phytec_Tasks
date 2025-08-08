#include<stdio.h>

int main()
{
	struct emp
	{
		int id;
		char name[50];
		float sal;
	}e={2022,"nova",100000};

	FILE *fp;
	fp=fopen("file1.txt","w");
	fwrite(&e,sizeof(struct emp),1,fp);
	return 0;
}
