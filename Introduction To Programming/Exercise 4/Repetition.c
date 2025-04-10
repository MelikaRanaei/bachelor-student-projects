//  Created by Melika on 10/8/20.


#include <stdio.h>
#include <string.h>

int main() {

    char str[100];

    char ch;

    gets(str);

    scanf("%c",&ch);

    char *count;

    count=str;

    int s=0;

    unsigned long lenght=strlen(str);

    for(int i=0;i<lenght;i++){

        if(*(count+i)==ch)

            s++;
        
    }
    
    printf("%d",s);
    
    
    
    
    
   
    return 0;
}
