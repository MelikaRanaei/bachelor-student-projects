
#include <iostream>
using namespace std;

const int maxSize = 500000 ;

void classify(int total[], int arr[], int k){
    int tempF=0, tempS=0;
    total[0]=1, arr[0]=1;
  /// k as common multiple
  for (int i=1; i<=maxSize; i++){
        if (i-1>=0)
            tempF=arr[i-1];
        if (i-k>=0)
           tempS=arr[i-k];

        arr[i] =(tempF + tempS) % 1000000007;
    }
    for (int i=1; i<maxSize+1; i++)
        total[i] = (total[i - 1] + arr[i]) % 1000000007;
}

int main() {
     int n, k, s, t, arr[maxSize], total[maxSize] , print[maxSize] ;
     cin>>n>>k;

    classify(total,arr,k); /// function to classify the books


    int j=0 ; /// using while loop in order to store the outputs
    while(j<n){
    for(int i=0; i < n; i++){
     cin>>s>>t;
    ///at least one book have to be on shelf
    ///number of arrangements:
        if(s==0){
            print[j]= total[i];
            j++;
    }
       if(total[t]-total[s-1]<0){
            print[j]= total[t]-total[s-1]+1000000007;
             j++;
    }
      else
       {    print[j] = total[t]-total[s-1];
            j++;
      }
    }
 }

  for(int j=0; j<n; j++)
    cout<<print[j]<<endl;

}






























