//  Created by Melika on 10/1/20.


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct book{

    int no;
    char name_book[20];
    char name_auther[20];
    int year;

};


void searchyear(struct book b[] ,int n_book, char value[]) ;

void searchbookname(struct book b[] ,int n_book, char value[]);

int main() {

    int num,i,n;

    struct book b[100];

    char value[100]="";

    char str[100]="";

//    printf("enter the number of books:");
    scanf("%d",&num);

    for(i=0;i<num;i++){

        scanf("%d",&b[i].no);

        char temp,temp1;

        scanf("%c",&temp);

        scanf("%[^\n]",b[i].name_book);

        scanf("%c",&temp1);

        scanf("%[^\n]",b[i].name_auther);

        scanf("%d",&b[i].year);

    }


    char temp;

    scanf("%c",&temp);

    fgets(value,100,stdin);

    if(sscanf(value,"%s",str)==1)

        searchbookname(b, num,value);

    else if(sscanf(value,"%d",&n)==1)

            searchyear(b, num,value);



    return 0;
}

void searchyear(struct book b[] ,int n_book, char value[]) {

    for(int i = 0 ; i < n_book ; i++) {

             if(b[i].year == atoi(value)) {

                 printf("%d,%s,%s,%d",b[i].no,b[i].name_book,b[i].name_auther,b[i].year);
             }

        }

    
}

void searchbookname(struct book b[] ,int n_book, char value[]) {

    for(int i = 0 ; i < n_book ; i++) {

             if(b[i].name_book == value) {
                
                 printf("%d,%s,%s,%d",b[i].no,b[i].name_book,b[i].name_auther,b[i].year);
                 
             }
        }
    
}
