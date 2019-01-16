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

int* readArray(int num)
	{
	int *arr;
	arr=(int*)malloc(num * sizeof(int)); 
	// We need a dynamic array so that we can allot large amount of numbers
	if (arr==NULL)
	{
		printf("Error: Array has not been allocated! \n");
	}

	FILE *ptr=fopen("ipfile.txt","r");
	int i=0;
	int z=0;

/* Refer: https://stackoverflow.com/questions/1835986/how-to-use-eof-to-run-through-a-text-file-in-c */

	while(!feof(ptr)) //workaround
	{
		fscanf(ptr,"%d\n",&z);
		//printf("\n%d\n",z); Was used to verify whether reading was happening properly
		int *temp=arr+i;
		i++;
		*temp=z;
		// printf("%d",*temp); Was used to verify whether assignment of z to arr+i was happening properly
	}
	
	
return arr;
	}

int main()
{
	int num=numberOfNumbers();
	int *rnd_arr=readArray(num);
	int i=0;
	int* temp=rnd_arr;
	while(temp!=NULL)
	{
		temp=rnd_arr+i;
		printf("%d\n",*temp);		
		i++;
	}

 	return 0;
}
