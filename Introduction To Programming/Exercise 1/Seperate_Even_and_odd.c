
#include <stdio.h>

int main() {

    int num;

    int A[1000];
    int B[1000];
    int C[1000];

    int i;

    scanf("%d",&num); //size of the array

    for(i=0;i<num;i++)

        scanf("%d",&A[i]);
        

    for(i=0;i<num;i++){

        if(A[i]%2==0){

            B[i]=A[i];

            printf("%d\t",B[i]); //even
        }}

    printf("\n");

    for(i=0;i<num;i++){

        if(A[i]%2!=0){

            C[i]=A[i];

             printf("%d\t",C[i]); //odd
        }
        
    }
    return 0;
}
