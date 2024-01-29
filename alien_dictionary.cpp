#include<iostream>
#include<vector>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/alien-dictionary/1

    string findOrder(string dict[], int n, int k) {
        
        // make the graph first.
        // 0 -> a , 1 -> b , 2 -> c like wise.
        vector<int>adj[k];
        
        int indegree[k] = {0};
        
        for(int i = 0; i<n-1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int j = 0;
            while(j < s1.size() ){
                if(s1[j] != s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
                j++;
            }
        }
        
        for(int i = 0; i<k; i++){
            for(auto it:adj[i]){
                indegree[it] ++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i<k; i++){
            cout<<"i -> "<<i<<" indeg -> "<<indegree[i]<<endl;
            if(indegree[i] == 0) q.push(i);
        }
        
        string ans = "";
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            ans += (node + 'a');
            
            for(auto it:adj[node]){
                indegree[it] --;
                if(indegree[it] == 0)  q.push(it);
            }
        }
        
        return ans;
    }

int main()
{
    return 0;
}