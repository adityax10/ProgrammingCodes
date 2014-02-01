#include<stdio.h>

int main()
{
	FILE *fp;
	fp = fopen(".//testcases.txt","w");
	
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			fprintf(fp,"%c",'^');
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}
