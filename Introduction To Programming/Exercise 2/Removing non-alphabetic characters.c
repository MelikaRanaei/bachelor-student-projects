//  Created by Melika on 9/30/20.

#include <stdio.h>
#include <string.h>

#define size 100

int main() {

    char str[size];

    int i=0,j=0;

    unsigned long n;

    n=strlen(str);

    gets(str);

   while (str[i]){

       if ((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || str[i]==' ')

            str[j++] = str[i];

       i++;
   }
    str[j]='\0';

    puts(str);
    
    return 0;
}
