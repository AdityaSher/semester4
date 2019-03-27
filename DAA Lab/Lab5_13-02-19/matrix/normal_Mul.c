#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(int argc,char *argv[]){
    clock_t start,end;
    double total_time;
    start = clock();
    int size = atoi(argv[1]);
    int *arr1 = (int *)malloc(size * size * sizeof(int));
    int *arr2 = (int *)malloc(size * size * sizeof(int));
    int *arr = (int *)malloc(size * size * sizeof(int));
    


    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            *(arr1 + size*i + j) = rand();
            *(arr2 + size*i + j) = rand();
            *(arr + size*i + j) = 0;
        }
    }

    

    for(int i = 0;i < size ;i++){
        for(int j =0;j < size; j++){
            
            for(int k = 0; k < 3;k++){
                *(arr + i * size  + j) += *(arr1 + i*size + k) * *(arr2 + i*size + j);
            }
        }
    }
    free(arr1);
    free(arr2);
    free(arr);

    end = clock();

    total_time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%f",total_time);
    
    


}
