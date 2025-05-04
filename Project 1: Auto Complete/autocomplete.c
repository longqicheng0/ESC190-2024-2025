#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "autocomplete.h"

//const void due to the comparator for qsort has to be the two
int lexCompare(const void *a, const void *b){
    return strcmp(((term *)a) -> term, ((term*)b) -> term);
}

//use to find only the citie's str length
int lSearch(const char *str){
    int cur = 0;
    while (str[cur] != '\0'){
        cur++;
    }
    return cur;
}

int char_int(char *str, int *rslt){
    int len = lSearch(str);

    for (int i = 0; i < len; i++){
        if (isdigit(str[i])){
            str[i] -= '0';
            *rslt = *rslt * 10 + str[i];
        }
    }
    return (*rslt);

}

void read_in_terms(term **terms, int *pnterms, char *filename){
    FILE *file = fopen(filename, "r"); 
    char line[200]; 
    fgets(line, 200, file); 

    *pnterms = atoi(line); 
    *terms = (term*) malloc((*pnterms) * sizeof(term)); 
    line[strlen(line) - 1] = '\0';
    
    for (int i = 0; i < *pnterms ; i++){
        fgets(line, 200, file); 
        int weight = 0;

        char *wchar = strtok(line, "\t");
        weight = char_int(wchar, &weight);
        (*terms)[i].weight = weight;

        char *tafter = strtok(NULL,"\n");
        strcpy((*terms)[i].term, tafter);

    }

    qsort(*terms, *pnterms, sizeof(term), lexCompare);
    
}

int lowest_match(struct term *terms, int nterms, char *substr){
    int lower = 0;
    int upper = nterms - 1;
    int len = lSearch(substr);

    while(lower <= upper){
        int mid = (lower + upper)/2;
        if (strncmp(terms[mid].term,substr, len) < 0){
            lower = mid + 1;
        }
        else if (strncmp(terms[mid].term,substr, len) >= 0){
            upper = mid - 1;
        }
    }
    return lower;

}

int highest_match(struct term *terms, int nterms, char *substr){
    int lower = 0;
    int upper = nterms - 1;
    int len = lSearch(substr);

    while (lower <= upper){
        int mid = (lower + upper)/2;
        if (strncmp(terms[mid].term, substr, len) > 0){
            upper = mid - 1;
        }
        else if (strncmp(terms[mid].term, substr, len) <= 0){
            lower = mid + 1;
        }
    }
    return upper;
}

int sort_weight(const void *a , const void *b){
    int diff = ((term *)a) -> weight - ((term *)b) -> weight;

    if (diff < 0){return 1;}
    else if (diff == 0){return 0;}
    else{return -1;}
}

void autocomplete(struct term **answer, int *n_answer, struct term *terms, int nterms, char *substr){
    int low = lowest_match(terms, nterms, substr);
    int high = highest_match(terms, nterms, substr);

    *n_answer = (high - low) + 1 ;
    *answer = (term*)malloc((*n_answer) * sizeof(term)); 

    int cnt = 0;
    for (int i = low; i < (high + 1); i++){
        strcpy((*answer)[cnt].term, (terms)[i].term );
        (*answer)[cnt].weight = (terms)[i].weight;
        cnt++;
    }

    qsort(*answer, *n_answer, sizeof(term), sort_weight);
}

