//
//  main.c
//  معکوس کردن (متوسط)
//
//  Created by Melika on 9/24/20.
//  Copyright © 2020 Melika. All rights reserved.
//

#include <stdio.h>

int main() {

    int n;
    int A[100];
    int i,t;

    scanf("%d",&n); //size of array

    for(i=0;i<n;i++)
        scanf("%d",&A[i]); // get elements of array 

    // invert elements

    for(i=0;i<=n/2;i++){

        t=A[i];

        A[i]=A[n-i];

        A[n-i]=t;
    }

     for(i=1;i<=n;i++)
        
         printf("%d\t",A[i]);
    

    
   
    return 0;
}
