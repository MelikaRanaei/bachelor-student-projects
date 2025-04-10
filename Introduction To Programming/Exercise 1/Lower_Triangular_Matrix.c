//  Created by Melika on 9/23/20.


#include <stdio.h>

int main() {

    int A[100][100],r,i,j;

    scanf("%d",&r); //get size of matrix

    for(i=0;i<r;i++)
        for(j=0;j<r;j++)
            scanf("%d",&A[i][j]);


    for(i=0;i<r;i++)
        for(j=0;j<r;j++)
            if(j>i)
                A[i][j]=0;

    for(i=0;i<r;i++){
           for(j=0;j<r;j++){
               printf("%d\t",A[i][j]);}
        printf("\n");
    }
    
            
    
    
    return 0;
}
