//  Created by Melika on 10/8/20.


#include <stdio.h>
#include <math.h>

void  sigma(int *n,int *m,int *x,float *ans);

int main() {

    int n,m,x;

    float ans;

    //input lower bound
    scanf("%d",&n);

    //input upper bound
    scanf("%d",&m);

    scanf("%d",&x);

    sigma(&n,&m,&x,&ans);

    printf("%.5f",ans);
    
    return 0;
}

void sigma(int *n,int *m,int *x,float *ans){

    float s;

    for(int k=*n;k<=*m;k++){
        
        s=pow(*x,k);

        *ans+=s/(pow(k,2));
    }
}
