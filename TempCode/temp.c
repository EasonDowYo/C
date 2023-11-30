/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int cmpChar(const void * a , const void * b){
     return *(const char*)a-*(const char*)b;
 }

typedef struct{
    char *original;
    char *sorted;
}Pair;

int comPair(const void *a, const void *b){
    const Pair* pa=(const Pair*)a;
    const Pair* pb=(const Pair*)b;
    return strcmp(pa->sorted,pb->sorted);
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    Pair * pairs = malloc(sizeof(Pair)*strsSize);

    for(int i=0;i<strsSize;i++){
        char *sorted_str = malloc( sizeof(char)* ( strlen(strs[i])+1 ) );
        strcpy(sorted_str,strs[i]);
        qsort(sorted_str,strs[i],sizeof(char),cmpChar);

        pairs[i].original = strs[i];
        pairs[i].sorted = sorted_str;

    }

    qsort(pairs,strsSize,sizeof(Pair),comPair);

    char *** returnResult = NULL;
    *returnSize=0;
    *returnColumnSizes=NULL;

    for(int i=0;i<strsSize;i++){
        if(i==0||strcmp(pairs[i].sorted,pairs[i-1].sorted)!=0){
            int lastGroupIndex = *returnSize;
            returnResult = realloc(returnResult,sizeof(char**)*(*returnSize+1));

            returnResult[lastGroupIndex] = malloc(sizeof(char *)*1);

            returnResult[lastGroupIndex][0]=pairs[i].original;

            (*returnSize)++;
            *returnColumnSizes= realloc(*returnColumnSizes,sizeof(int)*(*returnSize));
            (*returnColumnSizes)[lastGroupIndex]=1;

        }else{
            int lastGroupIndex = *returnSize -1;
            int lastGroupSize= (*returnColumnSizes)[lastGroupIndex];
            returnResult[lastGroupIndex]=realloc(returnResult[lastGroupIndex],sizeof(char*)*(lastGroupIndex+1));
            returnResult[lastGroupIndex][lastGroupSize]= pairs[i].original;
            (*returnColumnSizes)[lastGroupIndex]=lastGroupSize+1;


        }
    }

    return returnResult;

}






typedef struct {
         char *original;    
         char *sorted;      
 } Pair;

int compar(const void *a, const void *b)
{
        return *(const char *)a - *(const char *)b;
}

/* 对Input数组整体字符串进行排序的比较函数 */
int cmpPair(const void *a, const char *b)
{
        const Pair *pa = (const Pair *)a;
        const Pair *pb = (const Pair *)b;

        return strcmp(pa->sorted, pb->sorted);
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
        int i = 0;
        Pair *pairs = malloc(sizeof(Pair)*strsSize);
        for(i=0; i<strsSize; i++) {
                char *sorted_str = malloc(sizeof(char)*(strlen(strs[i])+1));
                strcpy(sorted_str, strs[i]);
                qsort(sorted_str, strlen(sorted_str), sizeof(char), compar);
                pairs[i].original = strs[i];
                pairs[i].sorted = sorted_str;
        }
        qsort(pairs, strsSize, sizeof(Pair), cmpPair);

        /* debug用，用于查看排序过后的input数组情况 */
        for(i=0; i<strsSize; i++) {
                printf("%s: %s\n", pairs[i].original, pairs[i].sorted);
        }

        /* 将结果整理成Output要求的形式 */
        char ***returnResult = NULL;
        *returnSize = 0;
        *returnColumnSizes = NULL;

        int r_size = 1;
        int rc_size = 1;
        int r_index = 0;
        int rc_index = 0;

        int rr_size = 1;
        int rr_index = 0;

        returnResult = malloc(sizeof(char **)*r_size);
        returnResult[r_index] = malloc(sizeof(char *)*1);
        returnResult[r_index][0] = pairs[0].original;
        *returnSize = 1;
        *returnColumnSizes = malloc(sizeof(int)*rc_size);
        (*returnColumnSizes)[rc_index] = 1;

        for(i=1; i<strsSize; i++) {
                /* 不相同 */
                if(strcmp(pairs[i].sorted, pairs[i-1].sorted)) {
                        rr_size  = 1;
                        rr_index = 0;
                        returnResult = realloc(returnResult, sizeof(char**)*(++r_size));
                        returnResult[++r_index] = malloc(sizeof(char *)*rr_size);
                        returnResult[r_index][rr_index] = pairs[i].original;
                        *returnSize += 1;
                        *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int)*(++rc_size));
                        (*returnColumnSizes)[++rc_index] = 1;
                } else {
                        returnResult[r_index] = realloc(returnResult[r_index], sizeof(char *)*(++rr_size));
                        returnResult[r_index][++rr_index] = pairs[i].original;
                        (*returnColumnSizes)[rc_index] += 1;
                }        
        }

        return returnResult;
}