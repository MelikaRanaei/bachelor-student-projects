
#include <stdio.h>

struct student{

    char name[50];
    float grade;
    int num;

};

int main() {

    int n_stu,i;

    float sum=0,avg;

//
    scanf("%d",&n_stu);

    struct student s1[30];

    for(i=0;i<n_stu;i++){

        char temp;

        scanf("%c",&temp);  //buffer

        scanf("%[^\n]",s1[i].name);

        scanf("%f",&s1[i].grade);

        scanf("%d",&s1[i].num);

        sum+=s1[i].grade;

    }

    avg=sum/n_stu;

    printf("%.2f",((signed long)(avg*100)*0.01f));

    for(i=0;i<n_stu;i++){

        if(s1[i].grade>avg)

            printf("\n%s",s1[i].name);

    }

    return 0;
}
