#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include<stdio.h>
#include<stdlib.h>

int numberOfNumbers();
int readArray(int num);
int partition(arr);

void main()
{
  
  int num=numberOfNumbers();
  int rnd_arr[num];
	readArray(num,rnd_arr);

	int i=0;
	
	int n = sizeof(arr)/sizeof(arr[0]); 
    quickSort(arr, 0, n-1); 
    printf("Sorted array: n"); 
    printArray(arr, n); 


 	return 0;   
}

/********************* End of Main *********************/

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

int readArray(int num, int arr[])
	{
	
  FILE *ptr=fopen("ipfile.txt","r");
	int i=0;
	int z=0;

  /* Refer: https://stackoverflow.com/questions/1835986/how-to-use-eof-to-run-through-a-text-file-in-c */

	while(!feof(ptr)) //workaround
	{
		fscanf(ptr,"%d\n",&z);
		arr[i]=z;
		i++;
		
	}
	
	
  return arr;
	}


