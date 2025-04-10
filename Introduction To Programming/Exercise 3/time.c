
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Course {

    char courseName[20];
    int courseID;
};

struct Student {

    char studentName[20];
    int studentID;
    int takenCoursesnumber;
    char takenCoursesname[20];
    struct Course course[20];
};

int coursesNumber;
int studentsNumber;
int courseID;


int main(){

//    printf("please enter number of courses:\n");
    scanf("%d" , &coursesNumber);
//    printf("please enter number of students:\n");
    scanf("%d" , &studentsNumber);

    struct Student student[studentsNumber];
    struct Course course[coursesNumber];

    for(int i = 0 ; i < coursesNumber ; i++) {

//        printf("please enter course name:\n");
        while ((getchar()) != '\n');
        scanf("%[^\n]s" , course[i].courseName);
//        printf("please enter course id:\n");
        scanf("%d" , &course[i].courseID);
    }

    for(int i = 0 ; i < studentsNumber ; i++) {

//        printf("please enter student name:\n");
        while ((getchar()) != '\n');
        scanf("%[^\n]s" , student[i].studentName);
//        printf("please enter student id:\n");
        scanf("%d" , &student[i].studentID);
//        printf("please enter number of taken courses:\n");
        scanf("%d" ,&student[i].takenCoursesnumber);
//        printf("please enter name of taken courses:\n");
        while ((getchar()) != '\n');
        scanf("%[^\n]s" , student[i].takenCoursesname);
    }

//     printf("please enter course ID for searching:\n");
     scanf("%d" , &courseID );

}
