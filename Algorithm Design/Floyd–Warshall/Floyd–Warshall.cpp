
#include <iostream>
using namespace std;
#define INF 99999
#define V 4




void floyd2(int w[][V])
{
    int D[V][V], i, j, k,p[V][V];
 
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++){
            p[i][j]=0;
            D[i][j] = w[i][j];
            
        }
    
 
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (D[i][j] > (D[i][k] + D[k][j]))
                    p[i][j]=k;
                    D[i][j] = D[i][k] + D[k][j];
            }
        }
    }
 
   for (int i = 0; i < V; i++) {
          for (int j = 0; j < V; j++) {
              if (D[i][j] == INF)
                  cout << "INF";
              else
                  cout << D[i][j];
          }
          cout << endl;
}
 
}



int main() {
  int w[V][V] = { { 0, 2, INF, 4 },
                      { INF, 0, 3, INF },
                      { 6, INF, 0, 1 },
                      { INF, INF, 2, 0 } };
    
       floyd2(w);
    
    return 0;
}
