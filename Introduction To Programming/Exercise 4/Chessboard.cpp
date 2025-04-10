//  Created by Melika on 10/9/20.

#include <iostream>

using namespace std;

int main() {

    //input the number of rows and column
    int n_row,n_column,i;

    cin>>n_row;

    cin>>n_column;

    int **array=new int*[n_row];

    for(i=0;i<n_row;i++){

        array[i]=new int [n_column];

    }

    //Coordinates
    int n,m;

    cin>>n;
    cin>>m;
    
    int *p=&array[n][m];

    if(n>n_row||m>n_column)

        cout<<"not exist";
    
    else cout<<p;
    
    delete [] array;
    
    return 0;
}
