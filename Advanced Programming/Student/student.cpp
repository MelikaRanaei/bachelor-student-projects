
#include <iostream>
#include <cstring>

using namespace std;

class student{

private:

    int id;
    float average;
    char family[20];

public:

    student(int = 0,char* = "No Name",float = 0);
    ~student();
    void setstudent(int,char*,float);
    int getid();
    char* getfamily();
    void printStudent();
    float getaverage();
};


student::student(int id,char* f,float avg){

    setstudent(id,f,avg);

}

student::~student(){
//    cout << "distructor is called" <<endl;

}

void student::setstudent(int i,char* f,float a){

    if(i>=0 && a>=0 && a<=20){

         id=i;
         average=a;
         strcpy(family,f);

    }

}

float student::getaverage(){

    return(average);
}


int student::getid(){

        return(id);
}


char* student::getfamily(){

        return(family);
}


void student::printStudent(){

    cout<<id;
    cout<<family;
    cout<<average;
}


int main() {

    int number,id;
    float avg;
    char *family=new char[20];

    cin>>number;

    student *s1;

    s1=new student[number];

    for (int i=0; i<number; i++) {

        cin>>id;
        cin>>family;
        cin>>avg;
        s1[i].setstudent(id,family,avg);

    }

    for (int i=0; i<number; i++){

        if(s1[i].getaverage() > 17){
            cout<<s1[i].getid()<<endl;
            cout<< s1[i].getfamily()<<endl;
            
        }
    }
          delete[] s1;
    return 0;
}
