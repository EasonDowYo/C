#include <stdio.h>
#include <stdlib.h>



typedef struct hash_table {
    int key;
    int value;
    struct hash_table* next;
} HashTable;

HashTable* create_node(int key, int value) {
    HashTable* node = (HashTable*) malloc(sizeof(HashTable));
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}

void insert(HashTable** table, int key, int value) {
    int hash_val = abs(key) % 1000;
    HashTable* node = create_node(key, value);
    if (table[hash_val] == NULL) {
        table[hash_val] = node;
    } else {
        HashTable* temp = table[hash_val];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

int search(HashTable** table, int key) {
    int hash_val = abs(key) % 1000;
    HashTable* temp = table[hash_val];
    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int init_size = 1000;
    int size = init_size;
    HashTable** table = (HashTable**) malloc(sizeof(HashTable*) * size);
    for (int i = 0; i < size; i++) {
        table[i] = NULL;
    }
    int* result = (int*) malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int index = search(table, complement);
        if (index != -1) {
            result[0] = index;
            result[1] = i;
            free(table);
            return result;
        }
        insert(table, nums[i], i);
        if (i > size * 0.7) {
            size = size * 2;
            table = (HashTable**) realloc(table, sizeof(HashTable*) * size);
            for (int j = size / 2; j < size; j++) {
                table[j] = NULL;
            }
        }
    }
    free(table);
    return result;
}

int main(void) {
    printf("Hello! TwoSum1\n");

    int arr[] = {2,3,7,10};
    int * returnSize=0;
    int * result;
    int arr2[] = {0,0,0,2,36,1};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    int arrSize2 = sizeof(arr2)/sizeof(arr2[0]);
    result=twoSum(arr,arrSize,9,&returnSize);

    for(int i=0;i<returnSize;i++)
    {
        printf("%d\n",*(result+i));
    }
    return 0;
}