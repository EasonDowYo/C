#include<stdio.h>
#include<stdlib.h>

int countElement(int * arr , int arrSize){
    int * checkarr = calloc(arrSize,sizeof(int));
    int res=0;
    for(int i=0;i<arrSize;i++){
        if(checkarr[arr[i]+1]==0){
            printf("%d,",arr[i]+1);
            checkarr[arr[i]+1]=1;   
        }
              
    }

    for(int i=0;i<arrSize;i++){
        if(checkarr[arr[i]+1]==1){
            res++;
        }
    }
    free(checkarr);
    return res;
}




void main(){
    printf("HELLO countElement\n");
    int * a = calloc(5,sizeof(int));
    for(int i=0;i<5;i++){
        printf("%d",a[i]);
    }

    int arr[3] = {1,2,3};
    int arrSize=3;
    int res = countElement(arr,arrSize);
    printf("Result is : %d \n",res);

    int arr2[8] = {1,1,3,3,5,5,7,7};
    arrSize=8;

    res = countElement(arr2,arrSize);

    printf("Result2 is : %d \n",res);
    arrSize=6;
    int arr3[6] = {1,3,2,3,5,0};


    res = countElement(arr3,arrSize);

    printf("Result3 is : %d \n",res);

    int arr4[4] = {1,1,2,2};
    arrSize=4;

    res = countElement(arr4,arrSize);

    printf("Result4 is : %d \n",res);

    return;
}