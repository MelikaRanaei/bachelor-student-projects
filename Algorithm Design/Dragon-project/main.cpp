


#include <iostream>
#include <string>
#include <queue>
#include<algorithm>

using namespace std;

 


string Algoritm(int n, int m) {

    string did;
    int cost=0; //minimum cost for cutting the dragon's head
        int *head=new int[n];   //the Head diameter of dragons.
        int *vich=new int[m];   //the  Height of vichers.


        for(int i=0;i<n;i++)
            cin>>head[i];       //get  dragon's head diameter



        for(int i=0;i<m;i++)
            cin>>vich[i];       //get Height of vichers



        sort(head,head+n);  // sorting number of dragon's head diameter
        sort(vich,vich+m);  //sorting vichers Based on height.



         int curr=0;  //index of head to be cut

        //if the number of dragon's head greater than the number of vichers the dragon cannot killed
        if(n > m){
            did= "Just kill yourself!";
        }

        if(n<=m){
            for(int j=0;j<m;j++){
                if(head[curr]<=vich[j]){
                    cost+=vich[j];
                    curr=curr+1;  //next head diameter
                    if(curr==n)   // head array ended
                        break;
                    }
            }

        if(curr >= n)  //all the head are cutted
            did= (to_string(cost));
        if(curr<n) //no
            did="Just kill yourself!";
        }
    return did;
}

void print(queue<string> ans)  //for print cost or just kill yourself
{

    while (!ans.empty()) {
        cout << ans.front()<<'\n' ;
        ans.pop();
    }
}

int main() {
     int n,m;//n=the number of dragon's head && m=the number of vichers
     queue<string> answer;
    while(cin >> n >> m  ){
            
        if(n == 0 && m == 0)
            break;
        else {
            string answer1 = Algoritm(n,m);
            answer.push(answer1);
        
        }

    }
    print(answer);
    return 0;
}


