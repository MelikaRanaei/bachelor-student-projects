//  Created by Melika on 9/28/20.

#include <stdio.h>
#include <string.h>

int main() {

    char str[100],ch;

    int i,j;

    unsigned long n;

    gets(str);

    n = strlen(str);

    for(i=1;i<n;i++)

        for(j=0;j<n-i;j++)

            if(str[j]>str[j+1]){

               ch=str[j];

               str[j] = str[j+1];

               str[j+1]=ch;
             }

        printf("%s\n\n",str);
        
    return 0;
}
