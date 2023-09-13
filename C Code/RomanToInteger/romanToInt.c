#include<stdio.h>
#include<stdlib.h>

int romanToInt(char * s){
    int result=0;
    int slen=strlen(s);
    int add_idx=0;
    while(1){
        char grade = *(s+add_idx);
        switch(grade) {
        
            case 'M':
                result+=1000;
                add_idx++;
                break;
            case 'D':
                result+=500;
                add_idx++;

                break;
            case 'C':
                if(*(s+(add_idx+1))=='D'){
                    result+=400;
                    add_idx+=2;
                    break;
                }else if(*(s+(add_idx+1))=='M'){
                    result+=900;
                    add_idx+=2;
                    break;
                }else{
                    result+=100;
                    add_idx++;
                    break;
                }
            case 'L':
                result+=50;
                add_idx++;
                break;
            case 'X':
                if(*(s+(add_idx+1))=='L'){
                    result+=40;
                    add_idx+=2;
                    break;
                }else if(*(s+(add_idx+1))=='C'){
                    result+=90;
                    add_idx+=2;
                    break;
                }else{
                    result+=10;
                    add_idx++;
                    break;
                }
            case 'V':
                result+=5;
                add_idx++;
                break;
            case 'I':
                if(*(s+(add_idx+1))=='V'){
                    result+=4;
                    add_idx+=2;
                    break;
                }else if(*(s+(add_idx+1))=='X'){
                    result+=9;
                    add_idx+=2;
                    break;
                }else{
                    result+=1;
                    add_idx++;
                    break;
                }
        }


        if(add_idx>=slen)
            break;
    }
    return result;
}
int romanToInt_perfect(char* s){
    if (*s == 0){
        return 0;
    }
    int counter = 0;
    int result = 0;

    while (*s){
        counter++;
        s++;
    }
    for (int i = 0; i < counter; i++){
        s--;
    }
    for (int i = 0; i < counter; i++){
        if (s[i] == 'I'){
            if (s[i + 1] == 'V'){
                result += 4;
                i++;
            }
            else if (s[i + 1] == 'X'){
                result += 9;
                i++;
            }
            else{
                result += 1;
            }
        }
        else if (s[i] == 'X'){
            if (s[i + 1] == 'L'){
                result += 40;
                i++;
            }
            else if (s[i + 1] == 'C'){
                result += 90;
                i++;
            }
            else{
                result += 10;
            }
        }
        else if (s[i] == 'C'){
            if (s[i + 1] == 'D'){
                result += 400;
                i++;
            }
            else if (s[i + 1] == 'M'){
                result += 900;
                i++;
            }
            else{
                result += 100;
            }
        }
        else if (s[i] == 'V'){
            result += 5;
        }
        else if (s[i] == 'L'){
            result += 50;
        }
        else if (s[i] == 'D'){
            result += 500;
        }
        else if (s[i] == 'M'){
            result += 1000;
        }
        else {
            printf("Error");
            return 0;
        }
    }
    return result;
}
int main(){
    char * s = "ABCD";
    printf("%s\n",s);
    //int slen= strlen(s);
    char *w_ptr = s + 1; // 将指针移到 'W' 的位置

    char * ss= "IV";
    int result = romanToInt(ss);
    printf("%d\n",result);
printf("Character 'W': %c\n", *w_ptr); // 输出 'W'
    printf("%s\n",s+1);
    printf("--------");
    system("pause");
    return 0;
}