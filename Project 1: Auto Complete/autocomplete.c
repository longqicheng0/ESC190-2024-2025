#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "autocomplete.h"

//const void due to the comparator for qsort has to be the two
int lexCompare(const void *a, const void *b){
    return strcmp(((struct term *)a) -> term, ((struct term *)b) -> term);
}

void read_in_terms(struct term **terms, int *pnterms, char *filename){
    FILE *file = fopen(filename,"r");
    char line[200];
    fgets(line, 200, file); //first line

    *pnterms = atoi(line); // the number of terms infront of the file
    *terms = (struct term *)malloc((*pnterms) * sizeof(struct term)); //pre assign to blocks

    //jumping into file body with information
    for (int i = 0; i < *pnterms; i++){
        //cur line
        fgets(line, 200, file);

        //copying the entire line into terms first
        strcpy((*terms + i) -> term, line);

        //skipping the tab in the file go to weight
        int j = 0;
        while (isspace(((*terms + i) -> term[j])) != 0){
            j++;
        }
        int wStrt = j;

        //go to the space between weight and term
        while (isspace(((*terms + i) -> term[j])) == 0){
            j++;
        }
        int wEnd = j - 1;
        int tStrt = j + 1;
        int tEnd = strlen((*terms + i) -> term) - 2;

        //seperate
        char weight[200];
        strncpy(weight, (*terms + i) -> term + wStrt, wEnd);
        (*terms + i) -> weight = (double)atoi(weight);

        char term[200];
        strncpy(term, (*terms + i) -> term + tStrt, tEnd);
        //strcpy to replace the old one
        strcpy((*terms + i) -> term, term);
        if ((*terms + i) -> term[strlen((*terms + i) -> term) - 1] == '\n'){
            (*terms + i) -> term[strlen((*terms + i) -> term) - 1] = '\0';
        }
        qsort(*terms, *pnterms, sizeof(struct term), lexCompare);
        fclose(file);
    }

}

//use to find only the citie's str length
int lSearch(const char *str){
    int len = 0;
    while (isalpha(*str + len) != 0){
        len++;
    }
    return len;
}

int lowest_match(struct term *terms, int nterms, char *substr){
    int l = 0;
    int r = nterms;
    int len = lSearch(substr);

    while (l < r){
        int m = ((l + r)/2);

        int lexcur = strncmp(substr, (terms + m) -> term, len);
        int cur = strcmp(substr, (terms + m) -> term);
        //if 
        if (lexcur != 0 && cur > 0){
            l = m + 1;
        }
        else if (lexcur != 0 && cur < 0){
            r = m;
        }
        else if (lexcur == 0 && m > 0){
            r = m;
        }
        else{
            return m;
        }
    }
    if (l == r){
        return l;
    }
    return -9999999999999;
}

// int highest_match(struct term *terms, int nterms, char *substr){
//     int l = 0;
//     int r = nterms;
//     int len = lSearch(substr);

//     while (l < r){
//         int m = ((l + r)/2);

//         int lexcur = strncmp(substr, (*terms + m) -> term, len);
//         int cur = strcmp(substr, (*terms + m) -> term);


//         if (lexcur != 0 && cur > 0){
//             l = m + 1;
//         }
//         else if (lexcur != 0 && cur < 0){
//             r = m;
//         }
//         else if (lexcur == 0 &){
//             l = m + 1;
//         }
//         else{
//             return m;
//         }
//     }
//     if (l == r){
//         return l;
//     }
//     return -9999999999999;
// }

int highest_match(struct term *terms, int nterms, char *substr){
    int lower = 0;
    int upper = nterms;
    int len = strlen(substr);  // Assuming lenfinder() is just strlen()

    int result = -1;  // Instead of an extreme value, use -1 for "not found"

    while (lower < upper){
        int mid = (lower + upper) / 2;
        int lexcur = strncmp(substr, terms[mid].term, len);

        if (lexcur < 0){  
            upper = mid;  // Move left if the term is greater
        }
        else if (lexcur > 0){  
            lower = mid + 1;  // Move right if the term is smaller
        }
        else {  
            result = mid;  // Update highest match
            lower = mid + 1;  // Continue searching to the right
        }
    }
    return result;  // Return the last found match or -1 if not found
}

int weightcomp(const void *a, const void *b){
    return (((struct term *)b) -> weight -((struct term *)a) -> weight);
}

void autocomplete(struct term **answer, int *n_answer, struct term *terms, int nterms, char *substr){

    int low = lowest_match(terms, nterms, substr);
    int high = highest_match(terms, nterms, substr);

    if (low == high && low < 0){
        *n_answer = 0;
        return ;
    }

    *n_answer = (low + high) - 1;
    *answer =((struct term*)malloc(*n_answer * sizeof(struct term)));

    int cnt = 0;

    for (int i = 0; i < *n_answer; i++){
        strcpy((*answer + cnt) -> term, (terms + i) -> term);
        (*answer + cnt) -> weight = (terms + i) -> weight;
        cnt++;
    }

    qsort(*answer,*n_answer,sizeof(struct term),weightcomp);
}
