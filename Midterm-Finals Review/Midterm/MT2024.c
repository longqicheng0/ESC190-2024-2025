#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum_odd(int *arr, int sz){
    int sum = 0;

    for (int i = 0; i < sz; i++){
        if (arr[i] % 2 != 0){
            sum += arr[i];
        }
    }

    return sum;

}

int cmp(const void *a, const void* b){
    return (*(int *)a - *(int *)b);
}

void g(int *arr, int n){
    int *temp = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        temp[i] = arr[i];
    }
    qsort(temp,n,sizeof(int),cmp);

    printf("the sorted list is: [");
    for (int j = 0; j < n; j++){
        if (j != n - 1){
            printf("%d,",temp[j]);
        }else{
            printf("%d", temp[j]);
        }
    }
    printf("]\n");
    free(temp);
}

int last_occurrence(char *str1, char *str2){
    if (strlen(str1) < strlen(str2)){return -1;}
    int l_idx = -1;
    int end1 = strlen(str1);
    int end2 = strlen(str2);
    for (int i = 0; i < end1; i++){
        if (strncmp(str1 + i,str2,end2) == 0){
            l_idx = i;
        }
        // if ((str1[i] == str2[0]) && (end1 - i - 1 >= end2)){
        //     int cnt  = 0;
        //     int j = 0;
        //     while (str1[i + j] == str2[j]){
        //         cnt++;
        //         j++;
        //     }
        //     if (cnt == end2){
        //         l_idx = i;
        //     }
        // }
    }
    return l_idx;
}

int first_occurance(char *str1, char* str2, int i, int j){
    //base case?
    //
    if (str2[j] == '\0' || str1[i] == '\0'){
        return -1;
    }
    if(str2[j] == str1[i]){
        if (str2[j+1] == '\0'){
            return i-j;
        }
        return first_occurance(str1,str2,i+1,j+1);
    }
    return first_occurance(str1,str2,i+1,0);
}

typedef struct student{
    int sNumber[11];
    int sMark[10];
}student;

// void read_in(char *filename, ){
//     FILE *f = fopen(filename,"r");
//     int i = 0;
//     while (!feof(f)){
//         fgets()
//     }
// }

typedef struct node{
    int data;
    struct node *next;
} node;
typedef struct LL{
    node *head;
} LL;

int LL_length(LL *l){
    int sz = 0;

    node * cur = l->head;
    while (cur != NULL){
        sz ++;
        cur = cur->next;
    }
    return sz;
}

void convert(LL *l, int *arr){
    *arr = (int*) malloc(LL_length(l)*sizeof(int));
    int idx = 0;
    node *cur = l -> head;
    while (cur != NULL){
        arr[idx] = cur-> data;
        idx ++;
        cur = cur->next;
    }
}

int median(LL *l){
    int sz = LL_length(l);
    int *arr;
    convert(l,arr);
    qsort(arr,sz,sizeof(int),cmp);
    free(arr);
    return (arr[sz/2]);
}

int main(){

    int arr[] = {4, 3, 2, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", sum_odd(arr, n));
    g(arr, n); 
    char str1[] = "EngEngSciEngSciTrackOne";
    char str2[] = "EngSci";
    int res = last_occurrence(str1, str2);
    printf("%d",res);
    return 0;

}