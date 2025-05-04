#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>
#include "LAB3.h"

void printStudent(student1 student){
    printf("(%s, %s, %d)\n", student.name, student.student_number, student.year);
}

void set_default_name(student1 *p_s){
    strcpy(p_s->name, "Default Student");
    p_s->year = 0;

}

void set_default_name_wrong(student1 s){
    strcpy(s.name, "Default Student");
}

void create_block1(student1 **p_p_s, int n_students){
    *p_p_s = (student1 *)malloc(n_students * sizeof(student1));
}

void printBlock(student1 *s, int n_students){
    int i = 0;
    for (i = 0; i < n_students; i++){
        printf("Student %d:\n", i + 1);
        printf("  Name: %s\n", s[i].name);
        printf("  Student Number: %s\n", s[i].student_number);
        printf("  Year: %d\n", s[i].year);
    }
}

void set_name(student1 *s, const char *new_Name){
    strncpy(s->name, new_Name, 199);
    s->name[199] = '\0';
}

void destroy_block(student1 **p_p_s){
    if (*p_p_s != NULL){
        free(*p_p_s);
        *p_p_s = NULL;
    }
}

typedef struct student2{
char *name;
char *student_number;
int year;
} student2;

void create_block2(student2 **p_p_s, int n_students){
    *p_p_s = (student2 *)malloc(n_students * sizeof(student2));

    for(int i = 0; i < n_students; i++){
        (*p_p_s)[i].name = (char *)malloc(sizeof(char));
        (*p_p_s)[i].student_number = (char *)malloc(sizeof(char));
        (*p_p_s)[i].year = 0;
    }

    // a->b
    // (*a).b
}

void printBlock2(student2 *s, int n_students){
    int i = 0;
    for (i = 0; i < n_students; i++){
        printf("Student %d:\n", i + 1);
        printf("  Name: %s\n", s[i].name);
        printf("  Student Number: %s\n", s[i].student_number);
        printf("  Year: %d\n", s[i].year);
    }
}

void destroy_block2(student2 **p_p_s, int n){
    for(int i = 0; i < n; i++){
        free((*p_p_s)[i].name);
        free((*p_p_s)[i].student_number);
    }
    free(*p_p_s);
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

int findavr(){
    char filename[200] = "LAB3.txt";
    int N = 3;
    int sum = 0;
    int cnt = 0;


    char line[5];
    FILE *fp = fopen(filename, "r");
    while(fgets(line, sizeof(line), fp)){
         //read in at most sizeof(line) characters
        //(including ’\0’) into line.
        sum += line[0] - '0';
        cnt++;
    }

    fclose(fp);

    return (sum/cnt);
}

int main(){

    //Q1
    //the first one access the variable locally, therefore theres no change to the global variable
    //the second one goes into the address, therefore changes the value permanenetly

    //Q2
    student1 s = {"a", "1234567890", 2};
    printStudent(s);

    //Q3 a)
    set_default_name(&s);
    printStudent(s);    
    printf("return to default\n");
    student1 s1 = {"a", "1234567890", 2};
    set_default_name_wrong(s1);
    printStudent(s1);
    //the year also didnt worked because its modifyingthe copied value

    //Q4
    student1 *students = NULL;
    int n_students = 3;

    create_block1(&students, n_students);

    strcpy(students[0].name, "Alice");
    strcpy(students[0].student_number, "1001");
    students[0].year = 1;

    strcpy(students[1].name, "Bob");
    strcpy(students[1].student_number, "1002");
    students[1].year = 2;

    strcpy(students[2].name, "Charlie");
    strcpy(students[2].student_number, "1003");
    students[2].year = 3;

    printf("Student Block:\n");
    printBlock(students, n_students);


    //Q5
    set_name(&students[0], "Alice Wonderland");
    set_name(&students[1], "Bob the Builder");
    set_name(&students[2], "Charlie Brown with a really long name that exceeds 199 characters...........................................................................................................................................");

    printf("Student Block:\n");
    printBlock(students, n_students);

    //Q6
    printf("Student Block:\n");
    printBlock(students, n_students);

    destroy_block(&students);

    free(students);

    //Q7
    student2 *students2;
    int num_student = 3;

    create_block2(&students2, num_student);

    printf("Student Block:\n");
    printBlock2(students2, num_student);

    //Q8
    destroy_block2(&students2, num_student);

    //Q10
    //similar to Q1

    //Q13
    char filename[200] = "LAB3.txt";
    int N = 1;

    char line[200];
    FILE *fp = fopen(filename, "r");
    for(int i = 0; i < N; i++){
        fgets(line, sizeof(line), fp); //read in at most sizeof(line) characters
        //(including ’\0’) into line.
        printf("%s\n", line);
    }
    fclose(fp);

    //Q14
    printf("%d", findavr());
}