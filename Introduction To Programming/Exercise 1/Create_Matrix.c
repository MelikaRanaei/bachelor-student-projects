
//  Created by Melika on 9/23/20.

#include <stdio.h>

int main() {

    int i,j,A[3][3];

    // get entries 

    for(i=0;i<3;i++)

        for(j=0;j<3;j++)

            scanf("%d",&A[i][j]);


    // print matrix
        
    for(i=0;i<3;i++){

        for(j=0;j<3;j++){

            printf("%d\t",A[i][j]);
        }

        printf("\n");
    }
    return 0;
}
