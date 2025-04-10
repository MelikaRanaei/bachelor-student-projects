//  Created by Melika on 9/30/20.


#include <stdio.h>

struct lesson{

    char name_lesson[20];
    int code;

};

struct student{

    char name[20];

    int num;

    struct lesson list[10];

    char takelesson;

    int lessonnumber;

};


int main() {

    int n_l,n_s,i,no,j;

    struct student s1[100];

    struct lesson l[100];

//    printf("enter the number of lesson:");
    scanf("%d",&n_l);

//    printf("enter the number of student:");
    scanf("%d",&n_s);

    //informathin of lessons
    for(i=0;i<n_l;i++){

        char temp;

        scanf("%c",&temp);  //buffer

        scanf("%[^\n]",l[i].name_lesson);

        scanf("%d",&l[i].code);
    }

    //informathin of student
    for(i=0;i<n_s;i++){

        char temp;

        scanf("%c",&temp);  //buffer

        scanf("%[^\n]",s1[i].name);

        scanf("%d",&s1[i].num);

        scanf("%d",&s1[i].lessonnumber);

        for(j=0;j<s1[i].lessonnumber;j++){

            char temp;

            scanf("%c",&temp);

            scanf("%[^\n]",s1[i].list[j].name_lesson);
        }
    }
    scanf("%d",&no);

//    printf("%d",no);
    for(i=0;i<n_s;i++){

          for(j=i;j<s1[i].lessonnumber;j++){

              if(no==l[i].code){

                  printf("%s",s1[i].name);
                  
                  break;
              }
          }
    }
    return 0;
}
