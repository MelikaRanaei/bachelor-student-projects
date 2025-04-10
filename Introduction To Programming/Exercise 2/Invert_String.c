//  Created by Melika on 9/26/20.


#include <stdio.h>
#include <string.h>


int main() {

    char ch[100],t;

    int i=0,j=0;

    unsigned long z;

    gets(ch);

    z = strlen(ch);

    for(j=0;j<=z/2;j++){

         t=ch[j];

         ch[j]=ch[z-j];

         ch[z-j]=t;
     }

    for(i=1;i<=z;j++){

        if(ch[i]!=' '){

            printf("%c ", ch[i]);}

        i++;
    }
    
     printf("\n");

     return 0;
}
