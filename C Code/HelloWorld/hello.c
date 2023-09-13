#include <stdio.h>

void replaceElements(int* arr, int arrSize){
    int maxSoFar = arr[arrSize-1];
    arr[arrSize-1] = -1;
    for(int i=arrSize-2; i>=0; i--){
        int temp = arr[i];
        arr[i] = maxSoFar;
        if(temp > maxSoFar){
            maxSoFar = temp;
        }
    }
}
void moveZeroes(int* nums, int numsSize){
    for (int i = 0, j = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            j++;
        }
        else  {
            int tmp = nums[i];
            nums[i] = nums[i-j];
            nums[i-j] = tmp;
        }
    }
}

int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    
    int left = 0;
    int right = numsSize - 1;
    //int *res=(int *)malloc(sizeof(int)*numsSize);
    while (left < right) {
        // Find the next even number from the left side
        while (left < right && nums[left] % 2 == 0) {
            left++;
        }

        // Find the next odd number from the right side
        while (left < right && nums[right] % 2 != 0) {
            right--;
        }

        // Swap the even and odd numbers
        if (left < right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
        }
    }
    
    //res=nums;
    returnSize=numsSize;
    return nums;
}

void QuickSort(int* arr, int arraySize){
    int * nums = (int*)malloc(arraySize* sizeof(int));
}

int main(){
    int arr[] = {17,18,7,4,6,1};
    int arr2[] = {0,0,0,2,36,1};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    int arrSize2 = sizeof(arr2)/sizeof(arr2[0]);
    replaceElements(arr, arrSize);
    moveZeroes(arr2,arrSize2);
    for(int i=0; i<arrSize; i++){
        printf("%d ", arr[i]);
    }
    printf("NEXT\n");
    for(int i=0; i<arrSize; i++){
        printf("%d ", arr2[i]);
    }
    printf("NEXT\n");
    int arr3[] = {4, 2, 1, 3, 7, 6};
    int size = sizeof(arr3) / sizeof(arr3[0]);
    int returnSize=6;
    


    system("pause");
    return 0;
}