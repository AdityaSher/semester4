#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int gen_rand(int max)
{
  int x = random()%max;
  return x;
}
int ct(FILE *fp1)
{	int num=0;
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
   
}
int main()
{
 int c=0,n,temp,max;
 printf("enter maximum number ");
 scanf("%d",&max);
 FILE *fp,*fp1;
 fp=fopen("ipfile.txt","w");
 
 if(fp==NULL)
 {
   printf("file failed to open\n");
 }
 
 else{
   printf("file is now open\n");
   srand(time(0));
   printf("\nEnter number of numbers you want: ");
   scanf("%d",&n);
   //n = random()%1000000;
   srand(time(0));
   for(c=0;c<n;c++)
 {
   temp=gen_rand(max);
   fprintf(fp,"%d\n",temp);
 }
 fclose(fp);
 }
 fp1=fopen("ipfile.txt","r");
 ct(fp1);

 return 0;
 
}
