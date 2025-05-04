#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intlist.h"


int main(){
    //Q1: using memcpy doesnt deal with overlapping regions of the memeory, 
        //which would cause problems while moving things around
        //but memmove does. so mem move is better

    //Q2:
    IntList *list;
    int data[] = {1, 2, 3, 4};
    create_list_from_data(&list, data, 4);

    list_append(list, 5);
    printf("appended List elements: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list_get(list, i));
    }
    printf("\n");

    list_insert(list, 10, 2);
    printf("interted List elements: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list_get(list, i));
    }
    printf("\n");
    
    list_delete(list, 3);
    printf("deleted List elements: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list_get(list, i));
    }
    printf("\n");

    list_destroy(list);
    return 0;

}