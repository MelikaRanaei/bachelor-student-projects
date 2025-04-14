 
 /* Huffman tree - priority queue */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;


priority_queue<int,vector<int>,greater<int> > Queue;


int main(){
        int n, b1, b2, b3, cost = 0;
      // number of balls
        cin>>n;

     // if it's even number, push 0 (as the weight) into the priority queue,
     // cause our priority is to divide the balls in three boxes
     // for minimum cost
     if(n%2==0)
        Queue.push(0);

     for(int i=0;i<n;i++){
        int color;
       // color(number) of boxes
        cin>>color;
        Queue.push(color);
    }

     // n is an odd number
    //take out the 3 smallest balls each time and merge them until they are into a group
    // non of the boxes should be empty
    while(Queue.size()!=1){

    int sum;

        b1= Queue.top();
            Queue.pop();
        b2= Queue.top();
            Queue.pop();
        b3= Queue.top();
            Queue.pop();
            
        sum= b1 + b2 + b3;
        Queue.push(sum);
        cost+=sum;
    }

    cout<<cost;

}
















