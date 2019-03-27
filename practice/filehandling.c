#include<stdio.h>
#include<stdlib.h>

int main()

{
    int a,b,c;
    FILE* readit;

    readit=fopen("input.txt","r");

    if(readit==NULL)
    {
        printf("Either there has been an error in opening the file, OR the file doesn't exist");
    }

    else
    {
        fscanf(readit,"%d %d %d", &a, &b, &c);
        printf("%d\n%d\n%d\n",a,b,c);

        fclose(readit);
    }

    
        
    FILE* writeit;

    if(writeit==NULL)
    {
        printf("Could not open file.");
    }
    else
    {
        writeit=fopen("input.txt","a");
        fprintf(writeit,"\n%d\n%d\n%d",a,b,c);

        fclose(writeit);
    }
  

    readit=fopen("input.txt","r");

    while(c=fgetc(readit)!=EOF)
    {
        
    }
    
       

}

