#include<stdio.h>
#include<stdlib.h>

int numberOfNumbers()
{
	FILE *fp1;
	fp1=fopen("ipfile.txt","r");
	int num=0;
	char c;
  c=getc(fp1);
 while(c!=EOF)
	{	
	c=getc(fp1);			
	if(c=='\n')
		{
			num++;
		}
	}
 
 if (feof(fp1)) 
	printf("\n Number of numbers in file is %d \n",num);

fclose(fp1);
return num;
}

int readArray(int num)
	{
	arr=(int*)malloc(num * sizeof(int)); 
	// We need a dynamic array so that we can allot large amount of numbers
	if (arr==NULL)
	{
		printf("Error: Array has not been allocated! \n");
	}

	FILE *fp1=fopen("ipfile.txt","r");
	int i=0;
	while()
	{
		int z=0;
		printf("Entered while loop");
		fscanf(fp1,"%d",&z);
		ptr+i=z;
	}
	


return *arr
	}

int main()
{
	int num=numberOfNumbers();
	readArray(num);
	

 	return 0;
}
