#include<stdio.h>
#include<stdlib.h>

int main(void){
    printf("HEELT1\n");
    int line_number=9;

    int column=line_number;
    printf(" %d\n",column/2);
    for(int i=0;i<line_number;i++){
        printf("%d",i);
        if(i < (column/2)+1){
            printf("up");
            for(int j=0;j<column;j++){
                if( j > column/2-1-i && j<column/2+1 +i){
                    printf("*");

                }else{
                    printf(" ");
                }
            }
            printf("\n");
        }else{
            printf("do");
            for(int j=0;j<column;j++){
                if( j > i-1-column/2 && j< column/2+column-i  ){
                    printf("*");

                }else{
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    printf("ENDEND\n");
    system("pause");
    return 0;
}