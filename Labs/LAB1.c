
#include <stdio.h>
#include <string.h>

void changeA(int *num){
    *num = 10;
}

void changeARR(char arr[]){
    char changed_array[100] = "modified contents";
    int i;
    for (i = 0; i < strlen(changed_array); i++){
        arr[i] = changed_array[i];
    }
    arr[i] = '\0';
}

void dispArr(char arr[]){
    int i;

    for (i = 0; arr[i] != '\0'; i++){
      printf("%c", arr[i]);  
    }
}

void insSort(int arr[]){
    int i = 0;
    int j;

    while(i < 5){
        j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            //swap
            int temp = arr[j-1];
            printf("temp is: %d\n",temp);
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
        i++;
    }
}

void display(int arr[]){
    int i;

    for (i = 0; i < 5; i++){
      printf("%d, ", arr[i]);  
    }
}

int countLen(char A[]){
    int i;
    int cnt = 0;

    for(i = 0; A[i] != '\0'; i++){
        cnt++;
    }
    
    return cnt;
}

void seq_replace(int* arr1, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz){
    int i;
    int j;
    int k;

    for(i = 0; i < arr1_sz; i++){
        int cur = *(arr1+i);
        int cnt = 0;

        if (cur == arr2[0]){
            //checker
            for(j = i; j < (i + arr2_sz); j++){
                if(*(arr1+j) == *(arr2+j-i)){
                    cnt++;
                }
            }
            //same count
            if(cnt == arr2_sz){
                //change 
                for(k = i; k < (i + arr2_sz); k++){
                    arr1[k] = 0;
                }
                i = k - 1;
            }
        }
    }
}

void display2(int arr[]){
    int i;

    for (i = 0; i < 10; i++){
      printf("%d, ", arr[i]);  
    }
}

int main(){
    //Q2
    int a;
    a = 5;
    printf("before: %d\n", a);
    changeA(&a);
    printf("after: %d\n", a);

    //Q3
    char arr[100] = "original contents";
    printf("before:");
    dispArr(arr);
    printf("\n");
    changeARR(arr);
    printf("after:");
    dispArr(arr);
    printf("\n");

    //Q4
    int arr2[5] = {4,5,2,6,1};
    insSort(arr2);
    display(arr2);
    printf("\n");

    //Q5
    char arr5[100] = "whats the string length";
    printf("%d \n",countLen(arr5));
    //O(n)

    //Q6
    int a1[] = {5, 9, 7, 8, 6, 7,5, 6, 6,7};
    int b1[] = {6, 7};
    seq_replace(a1,10,b1,2);
    display2(a1);

    return 0;
}