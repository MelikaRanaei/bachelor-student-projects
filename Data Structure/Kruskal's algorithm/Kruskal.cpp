//
////  main.cpp
////  Kruskal
////
////  Created by Melika on 2/17/21.
//_____________________________________________________________
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int parents[1000];

struct Edge{

    int u;
    int v;
    int w;
};

typedef struct  Edge e;

vector <e> graph; //u v w
vector <e> MST_edges;
//_______________________compae __________________________________
bool compare (const e& l, const e& r){
    return l.w < r.w;
}
//________________________set_____________________________________
void set(int nodes){
    for(int i=1; i<=nodes; i++)
        parents[i] = i;
    return;
}
//_________________________findParent______________________________
int findParent( int r ){
    if( r == parents[r] ) return r;
    return parents[r] = findParent( parents[r] );
}
//__________________________Kruskal________________________________

int Kruskal (int nodes){

    set(nodes);

    sort(graph.begin(), graph.end(), compare);

    int e_Count=0, sum=0;

    int lenngth = graph.size();

    for(int i=0; i<lenngth; i++){

        int p_u = findParent( graph[i].u );
        int p_v = findParent( graph[i].v );

        if( p_u != p_v ){

            parents[ p_u ] = p_v;
            sum += graph[i].w;
            MST_edges.push_back( graph[i] );

            e_Count++;
            if( e_Count == nodes-1 )
                break;
        }

    }

    return sum;
}

//__________________________main________________________________
int main()
{
    e getEdge;
    int n, m;
    cin >> n;
    cin >> m;
    for(int i=1; i<=m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        getEdge.u = u; getEdge.v = v; getEdge.w = w;
        graph.push_back(getEdge);
    }
    int sum = Kruskal(n);
    cout<<sum;
    return 0;
}
