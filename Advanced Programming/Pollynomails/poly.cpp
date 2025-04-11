#include <iostream>

using namespace std;

const int mySize=10;

class Poly{

private:

    int degree;
    int data[mySize];

public:
    
    Poly(int=10);
    void set(int,int[]);
    void print();
     int isMember(int);
    bool operator==(Poly&);
    bool operator!=(Poly&);
    Poly operator+(Poly&);
    Poly operator*(Poly&);
    int operator[](int) const;
    int& operator[](int);



};
//_______________________________________________________________
Poly::Poly(int n){
    if (n >= 0)
        degree = n+1;
    for(int i=0;i<=mySize;i++)
        data[i]=0;

}
//_______________________________________________________________
void Poly::set(int d,int list[]){
    degree=d;
    for (int i = 0; i<degree; i++){
        data[i]=list[i];
    }
    for(int i=d;i>=mySize;i++)
        data[i]=0;
}
//_______________________________________________________________
void Poly::print() {
    cout << data[degree] << "x^" << degree;
    for (int i = degree - 1; i >= 0; i--) {
        if (data[i] > 0) {
            if (i != 1 && i != 0) {
                cout << "+" << data[i] << "x^" << i;}
            else if (i == 1) {
                cout << "+" << data[i] << "x";}
            else if (i == 0) {
                cout << "+" << data[i];}
        }
        else if (data[i] < 0) {
            if (i != 1 && i != 0) {
                cout << data[i] << "x^" << i;}
            else if (i == 1) {
                cout << data[i] << "x";}
            else if (i == 0) {
                cout << data[i];}
        }
    }
}
//_______________________________________________________________
bool Poly::operator==(Poly& p2){
    int i;
        if (degree != p2.degree)
            return(false);
        for (i = 0; i < p2.degree; i++)
            if (isMember(p2.data[i]) == -1)//if(second.isMember(data[i])
                return(false);
        return(true);


}
//_______________________________________________________________
int Poly::isMember(int a) {
    int i;
    if (degree == 0)
        return(-1);
    for (i = 0; i < degree; i++)
        if (a == data[i])
            return(i);
    return(-1);
}
//_______________________________________________________________
bool Poly::operator!=(Poly& p2){
     int i;
    if (degree != p2.degree)
        return(true);
    for (i = 0; i < p2.degree; i++)
        if (isMember(p2.data[i]) == -1)
            return(true);
    return(false);
//    return(((*this)==p2)); we can use this


    }
//____________________________________________________________
Poly Poly::operator+(Poly& p2){
   int size= (degree >= p2.degree )?degree:p2.degree;
    Poly p3(size-1);
    if(degree >= p2.degree ){
        for ( int i=0;i<p2.degree; i++ )
            p3.data[i]=data[i]+p2.data[i];
        for ( int i=p2.degree;i<degree; i++ )
            p3.data[i]=data[i];
   }
    else{
    for ( int i=0;i<degree; i++ )
        p3.data[i]=data[i]+p2.data[i];
    for ( int i=degree;i<p2.degree; i++ )
        p3.data[i]=p2.data[i];
    }
    return p3;}
//_______________________________________________________________
Poly Poly::operator*(Poly& p2){
    int totaldegree=degree+p2.degree-2;
    Poly p3(totaldegree);
    for ( int i=0;i<degree; i++ ){
         for ( int j=0;j<p2.degree; i++ )
             p3.data[i+j]+=data[i] * p2.data[j];
    }
    return p3;

}
//_______________________________________________________________
int Poly::operator[](int myindex) const {
    if (myindex >= 0 && myindex <= degree) {
        return (data[myindex]);
    }
    else {
        cout << "invalid parmeter  ";
        return (data[0]);

    }
}
int& Poly::operator[](int myindex) {
    if (myindex >= 0 && myindex <= degree) {
        return (data[myindex]);
    }
    else {
        cout << "invalid parmeter ";
        return (data[0]);

    }
}
//_______________________________________________________________
int main() {

    int max_degree_1,max_degree_2,i;
    cin>>max_degree_1;
    int *data1=new int[max_degree_1+1];
    for(i=max_degree_1;i>=0;i--){
        cin>>data1[i];
    }
    Poly p1(max_degree_1);
    p1.set(max_degree_1,data1);

    cin>>max_degree_2;
    int *data2=new int[max_degree_2+1];
       for(i=max_degree_2;i>=0;i--){
           cin>>data1[i];
       }
    Poly p2(max_degree_2);
    p2.set(max_degree_2,data2);

    int index;
    cin>>index;
    int d,z;
    cin>>d;
    cin>>z;

    p1.print();
    cout<<endl;
    p2.print();
     cout<<endl;
    cout<<p1[index]<<endl;
    Poly add=p1+p2;
    add.print();
     cout<<endl;
    Poly multi=p1*p2;
    multi.print();


    if(p1==p2)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    if(p1!=p2)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;

    return 0;
}
