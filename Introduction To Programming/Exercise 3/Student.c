//  Created by Melika on 9/29/20.
//Calculates the average age of students

#include <stdio.h>

struct student{

     int age;
     int num;
     char name[30];
     char gender[10];

};

int main() {

    int n,i;

    float sum=0,avg;

    scanf("%d",&n);

    struct student s1[100];

    for(i=0;i<n;i++){

        scanf("%d",&s1[i].age);

        scanf("%d",&s1[i].num);

        char temp;

        scanf("%c",&temp);  //buffer

        scanf("%[^\n]",s1[i].name);

        scanf("%s",s1[i].gender);

        sum+=s1[i].age;
    }
    avg=sum/n;

    char t=0;

    for(i=0;i<n;i++){

        for(int j=i+1;j<n;j++){

             if(s1[i].num==s1[j].num){

                 printf("Duplicate ID.");

                 t++;

                 break;
             }
        }
    }
    if(t==0)

        printf("%.2f\n",((signed long)(avg*100)*0.01f));

    return 0;
}
