//  Created by Melika on 9/29/20.


#include <stdio.h>
#include <string.h>

#define size 100

int main() {

    char str[size],ch[size];

    int i=0,start,end;

    unsigned long n;

    gets(str);

    n=strlen(str);

    scanf("%d",&start);

    scanf("%d",&end);

    while (i < end)
      {
         ch[i] = str[start+i-1];

         i++;
      }

    ch[i]='\0';
    
    puts(ch);
    

        
    
    return 0;
}
