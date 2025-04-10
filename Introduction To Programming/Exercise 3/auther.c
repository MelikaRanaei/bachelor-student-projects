
//  Created by Melika on 10/2/20.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct auther{

    char name[20];
    int birth;
    int no;
    char gender[10];

};

struct book{

    int no;
    char name_book[20];
    int year;
    struct auther info[20];

};



void searchyear(struct book b[] ,int n_book,int n_auther, char value[]);

void searchbookname(struct book b[] ,int n_book,int n_auther,  char value[]);

// /////////////////////////////////////searchyear///////////////////////////////////////////////////

void searchyear(struct book b[] ,int n_book,int n_auther, char value[]) {

    for(int i = 0 ; i < n_book ; i++) {

        for(int j=0;j<n_auther;j++){

             if(b[i].year == atoi(value)) {

                 printf("%d,%s,%s,%d",b[i].no,b[i].name_book,b[i].info[j].name,b[i].year);
             }

        }

    }
}
// ///////////////////////////////////////searchbookname////////////////////////////////////////////

void searchbookname(struct book b[] ,int n_book,int n_auther, char value[]) {

    for(int i = 0 ; i < n_book ; i++) {

         for(int j=0;j<n_auther;j++){

             if(b[i].name_book == value) {

                 printf("%d,%s,%s,%d",b[i].no,b[i].name_book,b[i].info[j].name,b[i].year);
                 
             }
        }
    }
}

// ///////////////////////////////////////// main ////////////////////////////////////////////
    
int main() {

    int i,n;

    int n_book;

    int n_auther;

    char value[100]="";

    struct book b[100];

    struct auther a[10];

    char temp;

    char str[20]="";

//    printf("enter the number of auther:");
    scanf("%d",&n_auther);

//    printf("enter the number of books:");
    scanf("%d",&n_book);

    for(i=0;i<n_auther;i++){

        scanf("%c",&temp);

        scanf("%[^\n]",a[i].name);

        scanf("%d",&a[i].birth);

        scanf("%d",&a[i].no);

        scanf("%[^\n]",a[i].gender);
    }
    
    for(i=0;i<n_book;i++){

        scanf("%d",&b[i].no);

        scanf("%c",&temp);

        scanf("%[^\n]",b[i].name_book);

        for(int j=0;j<n_auther;j++){

             scanf("%c",&temp);

             scanf("%[^\n]",b[i].info[j].name);
    }
        scanf("%d",&b[i].year);
    }

    scanf("%c",&temp);

    fgets(value,100,stdin);

    if(sscanf(value,"%s",str)==1)

        searchbookname(b, n_book, n_auther,value);

    else if(sscanf(value,"%d",&n)==1)

            searchyear(b, n_book, n_auther,value);
        
    return 0;
}

