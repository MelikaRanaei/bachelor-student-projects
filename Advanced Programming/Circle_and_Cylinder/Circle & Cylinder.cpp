
#include <iostream>
#include <math.h>

using namespace std;

class Circle{

private:

    int Radius;

public:

    Circle(float=1);
    ~Circle();
    float Area();
    float pier();
    void setRadius(float);
    int getRadius(){return Radius;}
    void print();
};


Circle::Circle(float r){

    cout<<"Circle constructor is called!"<<endl;
    setRadius(r);
}

void Circle::setRadius(float r){

    if(r>0)
        Radius=r;
    else{
        cout<<"wrong ans"<<endl;
    }
}


float Circle::Area(){

    float area=pow(Radius,2)*M_PI;
    return area;
}


float Circle::pier(){

    return(2*Radius*M_PI);
    
}


Circle::~Circle(){

    cout<<"Circle destructor is called!"<<endl;
}

void Circle::print(){

    cout<<"Radius:"<<Radius<<endl;
}

//_______________________________________________________________

class Cylinder:public Circle{

    friend ostream& operator<<(ostream&, Cylinder&);
    friend istream& operator>>(istream&, Cylinder&);

private:

    float Height;

public:

    Cylinder(float=1.00,float=1.00);
    ~Cylinder();
    int getheight(){return Height;}
    void setheight(float);
    float Area();
    float volume();
    float pier(){return 0;}
//    void print();
};

Cylinder::Cylinder(float r,float h):Circle(r){

      cout<<"Cylinder constructor is called!"<<endl;
      setheight(h);
}

void Cylinder::setheight(float h){

    if(h>0)
        Height=h;
    else
        cout<<"wrong input"<<endl;
}

float Cylinder::Area(){

    float r=getRadius();
    float area=2*M_PI*r*Height+2*(Circle::Area());//2*pi*r(h+r)
    return (area);
}


Cylinder::~Cylinder(){

    cout<<"Cylinder destructor is called!"<<endl;
}


float Cylinder::volume(){

    return((Circle::Area())*Height);
    
}

ostream& operator<<(ostream& out, Cylinder& p) {

    out << "Radius:" << p.getRadius() << endl;
    out << "Height:" << p.Height << endl;
    return(out);
}

istream& operator >> (istream& in, Cylinder& p) {

    int r;
    in >> r;
    p.setRadius(r);
    in >> p.Height;
    return(in);
}


//________________________________________________________________

int main() {
    
    Circle ci;
    Cylinder cy;
    cin>>cy;
    cout<<cy;
    cout<<ci.Area()<<endl;
    cout<<cy.volume()<<endl;
    Circle *d=&ci;
    Cylinder *o=&cy;
    cout<<d->Area()<<endl;
    cout<<o->volume()<<endl;
    
    
    return 0;
}
