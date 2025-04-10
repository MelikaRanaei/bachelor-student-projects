//  Created by Melika on 10/8/20.


#include <stdio.h>


struct person{

    float weight;
    float height;

};

void person(struct person *p);

int main() {

    struct person *p;

    person(&p);

    return 0;
}

void person(struct person *p){

    float BMI;

    //please enter the height(m)
    scanf("%f\n",&(p->height));

    //please enter the weight(kg)
    scanf("%f",&(p->weight));


    BMI=(p->weight) / ((p->height)*(p->height));
    
    printf("%.2f",((signed long)(BMI*100)*0.01f));
    
}








