
#include<iostream>

#define n 4
using namespace std;

int a[n] = {-1,-1,-1,-1} ;// check the city is visit or not
int graph[4][4] =  { { 0, 1, 5, 10 }, { 1, 0, 2, 4 }, { 5, 2, 0, 3 }, {10, 4, 3, 0 } };

//_____________________________________________________________________________________
bool visit(int m) {//check that city k viseted or not
    for (int i = 0; i < n ; i++)
        if (a[i] == m) return 1 ;
            return 0;
}
//_____________________________________________________________________________________
void nextclostCity(int currentCity) { //Find the next city
    int temp = 10000;   // stores the value of the current minimum path
    for (int i = 0; i < n; i++)
    {
        if ( visit(i) == 0 && ::graph[i][a[currentCity]] <temp )
        {
            temp = ::graph[i][a[currentCity]] ;
            a[currentCity+1] = i ;//If the city has not been visited, and the distance was minimum stor in a[]
        }
   }
        
for (int i = 0; i < n; i++) //check that exit a city that not visited or no
{
    if ( a[i] == -1 )
        nextclostCity(a[currentCity+1]);
    }
}
//_______________________________________________________________________________________
void NN() {
    
    int cost = 0 ;
    a[0] = 0;//Start
    nextclostCity(a[0]) ;
    for (int i=0; i < n ; i++) {
        if (i == n -1) {
            cout<<"\n"<<a[i];
            cout<<"->"<<a[0] <<" cost is:\n"<<graph [ a[n-1] ] [a[0]];
            cost += graph [ a[n-1] ] [a[0]];
            cout<<"\nTotal cost is "<<cost<<endl;
            break ;
        }
            cout<<"\n"<<a[i]<<"->"<< a[i+1]<<" cost is:\n"<<graph[ a[i] ][ a[i+1] ]  ;
            cost += ::graph[ a[i] ][ a[i+1] ] ;
        }
     
    }

int main() {
    NN() ;
    return 0;
}
