//  Created by Melika on 9/30/20.


#include <stdio.h>

struct distance{

    int kilo;
    int metr;
    int sant;
};


int main() {

    struct distance m1,m2,sum;

    scanf("%d %d %d",&m1.kilo,&m1.metr,&m1.sant);

    scanf("%d %d %d",&m2.kilo,&m2.metr,&m2.sant);

    sum.kilo= m1.kilo + m2.kilo;

    sum.metr= m1.metr + m2.metr;

    sum.sant= m1.sant + m2.sant;

    printf("%d\t%d\t%d", sum.kilo, sum.metr,sum.sant);
    
    
    
    return 0;
}
