#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


void set_even_to_zero(int *block, int size){
    int i = 0;
    for( i = 0; i < size; i += 2){
        block[i] = 0;
    }
}

void display(int *a,int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void concat_V1(char *s1, const char *s2){
    int i = 0;
    int j = 0;
    while (s1[i] != '\0'){i++;}
    while (s2[j] != '\0'){
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
}

void concat_V2(char *s1, const char *s2){
    while(*s1 != '\0'){s1++;}
    while(*s2 != '\0'){
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}

int my_strcmp_rec(const char *s1, const char*s2){
    if ((sizeof(s1) / sizeof(s1[0])) != (sizeof(s2) / sizeof(s2[0]))){return -1;}

    int cnt = 0;
    while(*s1 == *s2){
        s1++;
        s2++;
        cnt++;
    }
    if (sizeof(s1) / sizeof(s1[0]) != cnt){return -1;}
    return 0;
}

int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void binary_search_deluxe(int *a, int target, int size, int *start, int *end){
    qsort(a, size, sizeof(a[0]), comp);

    int L = 0;
    int R = size - 1;

    if (L = R && a[L] == target){
        *start = L;
        *end = R;
        return ;
    }
    while (L <= R){
        int M = (L + R) / 2;
        if (a[M] < target){L = M + 1;}
        else{R = M - 1;}
    }

    *start = L;
    L = 0;
    R = size - 1;

    while (R >= L){
        int M = (L + R) / 2;
        if (a[M] > target){R= M - 1;}
        else{L = M + 1;}
    }

    *end = R;
}

int my_atoi(char *str){
    int i = 0;
    int ans = 0;
    while(str[i] !='\0'){
        if (!isdigit(str[i])){return -1;}
        ans = ans*10 + (str[i] - '0');
        i++;
    }
    return ans;
}

int main(){
    
    //Q1
    int block[] = {5,6,7,8};
    int size = 4;
    set_even_to_zero(&block,size);
    display(block, size);

    //Q2
    char s1[50] = "wassup, ";
    const char s2[] = "world";
    concat_V1(s1,s2);
    printf("%s\n", s1);

    char s3[50] = "world, ";
    const char s4[] = "wassup";
    concat_V2(s3,s4);
    printf("%s\n", s3);

    //Q3
    const char s5[] = "abcd";
    const char s6[] = "abcd";
    printf("%d\n",my_strcmp_rec(s5,s6));

    //Q4
    int start = 0;
    int end = 0;
    int a[] = {1};
    binary_search_deluxe(a, 1, 1,&start, &end);
    printf("%d ", start);
    printf("%d \n", end);

    //Q5
    char str[] = "223123";
    printf("%d\n",my_atoi(&str));

}