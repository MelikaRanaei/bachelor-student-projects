#include <stdio.h>

struct master{

    char name[20];
    int national;

};


struct teacher{

    char name[20];
    int no;
    int salary;

};


struct student{

    char name[20];
    int base;
    float avg;
    int no_teacher;

};


int main() {

    int i,n_stu,n_teacher,no;

    struct master m1;

    struct teacher t1[5];

    struct student s1[20];

    //input number of student
    scanf("%d",&n_stu);

    //input number of teacher
    scanf("%d",&n_teacher);

    //input information  of headmaster
    char temp;

    scanf("%c",&temp);//beffer

    scanf("%[^\n]",m1.name);

    scanf("%d",&m1.national);

    //input information of teacher
    for(i=0;i<n_teacher;i++){

        char temp;

        scanf("%c",&temp);  //buffer

        scanf("%[^\n]",t1[i].name);

        scanf("%d",&t1[i].no);

        scanf("%d",&t1[i].salary);

    }

    //input information of student
    for(i=0;i<n_stu;i++){

        char temp;

        scanf("%c",&temp);  //buffer

        scanf("%[^\n]",s1[i].name);

        scanf("%d",&s1[i].base);

        scanf("%f",&s1[i].avg);

        scanf("%d",&s1[i].no_teacher);

    }

    scanf("%d",&no);//input the number of teacher

    char t=0;

    for(i=0;i<n_stu;i++){

        if(no==s1[i].no_teacher){

            printf("%s\n",s1[i].name);

            t++;
        }
    }

    if(t==0)
        
         printf("No student.");
        
    return 0;
}
