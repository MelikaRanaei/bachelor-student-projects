
#include <stdio.h>

void d_to_b(int n);

void d_to_b(int n){

    int bin[100],i,j;

    for(i=0 ;n>0 ;i++){

        bin[i]=n%2 ;

        n=n/2;
    }
    for(j=i-1;j>=0;j--)

        printf("%d",bin[j]);
}
    
int main() {

    int n;

    scanf("%d",&n);

    d_to_b(n);
    
    return 0;
}
