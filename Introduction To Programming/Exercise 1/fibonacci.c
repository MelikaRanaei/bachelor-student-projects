
#include <stdio.h>


void fib(int n);

int main(){

    int n;

    scanf("%d",&n);

    fib(n);

    return 0;
}



void fib(int n){

    int F[100];

    F[1]=1;

    F[2]=1;


    for(int k=3;k<=n;k++)

        F[k]=F[k-1]+F[k-2];

    for(int k=1;k<=n;k++){

        printf("%d",F[k]);

        if(k < n){
            printf(",");
        }
    }
    
}
