#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;


/*Approach -> dijkstra algo is applied as we are talking about minimum number from src to destination.

            But the code can be more optimised when we use the distance array -> thus to avoid the number which we get previously with the minimum distance.
*/
    
    // time complexity -> O(1e5 * N) [N is the size of arr] 
    int minimumMultiplications(vector<int>& arr, int start, int end) {
     
        int mod = 1e5;
        // no need to make the adj list.
        if(start == end)    return 0;
        vector<int> distance(100000, INT_MAX);
        distance[start] = 0;
        
        queue<pair<int,int>> q;
        q.push({0,start}); // steps, start node.
        
        while(!q.empty())
        {
            auto itr = q.front();
            q.pop();
            
            int steps = itr.first;
            int node = itr.second;

            for(auto it:arr){
                
                int mul = (node * it) % mod; // getting new start
                
                if(steps + 1 < distance[mul]){
                    distance[mul] = steps + 1;
                    if(mul == end)  return steps + 1;
                    q.push({steps + 1, mul});
                } 
                
            }
        }
        
        return -1;
    }

int main()
{

    return 0;
}