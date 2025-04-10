//  Created by Melika on 9/19/20.


#include <stdio.h>

int main() {

    int i, j, x1, x2, x3, det, m[3][3],a,c,b;

    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            scanf("%d", &m[i][j]);

    a= (m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]));

    b= (m[0][1] * (m[1][0]* m[2][2] - m[1][2] * m[2][0]));

    c=(m[0][2] * (m[1][0] * m[2][1] - m[2][0] * m[1][1]));

    det=a-b+c;

    printf("%d", det);
    
    return 0;
}
