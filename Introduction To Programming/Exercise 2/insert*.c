//  Created by Melika on 9/28/20.


#include <stdio.h>

#define size 100

int main() {

    char str[size];

    int i=0;

    gets(str);

    while(str[i]!='\0'){

        if(str[i]==' ' || str[i]=='\t'){

            str[i]='*';
           
        }

         printf("%c",str[i]);

        i++;
    }
    
    return 0;
}
