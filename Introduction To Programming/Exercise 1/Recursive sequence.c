//  Created by Melika on 9/22/20.


#include <stdio.h>

int F(unsigned n);

int G(unsigned n);

int F(unsigned n){

    if(n==0) return 0;

    if(n==1) return 3;

    return F(n-1)+ 2 * G(n-2);
}


int G(unsigned n){

    if(n==0) return 2;

    if(n==1) return 5;

    return 3 * G(n-1)- F(n-2);
}


int main() {

    unsigned n;

    scanf("%d",&n);
    
    printf("%d,%d",F(n),G(n));
    
    
    return 0;
}
