//  Created by Melika on 9/24/20.

#include <stdio.h>

void gcd(int x,int y);

int main() {

    int x,y;

    scanf("%d%d",&x,&y);

    gcd(x,y);
    
    
    return 0;
}

void gcd(int x,int y){

    int p,t,r;

     p=x*y;

     if(y>x){
         t=x;
         x=y;
         y=t;
     }

     do{
         r=x%y;
         x=y;
         y=r;

     }while(r!=0);
     
    printf("%d",x);
}
