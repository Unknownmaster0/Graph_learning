/*
 there are two methods to store the graph
 1. using the adjacency matrix -> space complex = O(n * n)  [n = number of nodes/vertices].
 2. using the adjacency list/array -> space complex. = O(2 * number of edges) [in case of undirected graph].
                                                    = O(number of edges)    [in case of directed graph].
*/ 

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // n -> number of nodes/vertices  &  m -> number of edges
    int n,m;
    cin>>n>>m;
    /*
    // Method 1 -> using the adjacency matrix to store the graph
    int adj[n+1][n+1];
    for(int i = 0; i<m; i++)
    {
        // n1 -> node1 & n2 -> node2 [from node1 to node2 there is the edge.]
        int n1, n2;
        cin>>n1>>n2;
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
        // to store the weighted graph just insted of storing 1 store their weight at that idx.
        // adj[n1][n2] = weight; // whatever weight is given
    }
    */
    // Method 2 -> using the adjacency list to store the graph.
    vector<int>adj[n+1];
    /*to store the wieghted graph slight changes, you need to store pairs of vector in the array.
        vector<pair<int,int>> adj[n+1]; // where the first element of pair -> node value.
                                        // second element of pair -> weight value.
    */
    for(int i = 0; i<m; i++)
    {
        // n1 -> node1 & n2 -> node2 [from node1 to node2 there is the edge.]
        int n1, n2;
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        // when we are having the directed graph then we need to store only one of the two line.
        // thus the space complexity becomes O(m) [m = number of edges]
        adj[n2].push_back(n1);
        // to store the weighted graph
        // adj[n2].push_back({n1,weight});
    }

    


    return 0;
}