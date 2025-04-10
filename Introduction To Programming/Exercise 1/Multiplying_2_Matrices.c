
#include <stdio.h>


int main() {

    int A[100][100];
    int B[100][100];
    int result[100][100];

    int i,j,a,k;

    scanf("%d",&a); //size of matrix 
    

    for(i=0;i<a;i++)

        for(j=0;j<a;j++)

            scanf("%d",&A[i][j]); // get the matrix A 


    for(i=0;i<a;i++)

        for(j=0;j<a;j++)

           scanf("%d",&B[i][j]); // get the matrix B


    for(i=0;i<a;i++)

        for(j=0; j<a; j++) {

            result[i][j]=0;

            for(k=0;k<a;k++)

                result[i][j]+= A[i][k]*B[k][j];}


    for(i=0;i<a;i++)

        { printf("\n");

          for(j=0;j<a;j++)

              printf("%d ",result[i][j]);
    }
    
    
    return 0;
}
