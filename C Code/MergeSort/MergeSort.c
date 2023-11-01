#include<stdio.h>

void Merge( int * nums, int left ,int right , int mid){
    const int n = right- left +1; // Merge Range -> array size
    int *x = malloc(n * sizeof(int));

    int i =left, j =mid+1;
    
    for(int k=0;k<n;k++){
        if(i == mid+1){
            x[k] = nums[j++];
        }
        else if( j == right+1){
            x[k] = nums[i++];
        }
        else if( nums[i]<=nums[j]){
            x[k] = nums[i++];
        }
        else{
            x[k] = nums[j++];
        }

    }

    for(int k=0;k<n;k++){
        nums[left + k]=x[k];
    }

}


void Merge_Sort( int * nums, int left , int right){
    if( left >= right) return ;

    int mid= left + (right -left )/2;
    Merge_Sort(nums,left,mid);
    Merge_Sort(nums,mid+1,right);

    Merge(nums,left,right,mid);

}
void PrintArr(int *nums,int numsSize){
    for(int i=0;i<numsSize;i++){
        printf("%d ,",nums[i]);
    }
    printf("\n");
}

int main(void){
    printf("HEELT1\n");

    int arr[] = {3,13,7,10,4,35};
    int arrSize=6;
    PrintArr(arr,6);
    Merge_Sort(arr,0,arrSize-1);
PrintArr(arr,6);


    printf("ENDEND\n");
    //ystem("pause");
    return 0;
}