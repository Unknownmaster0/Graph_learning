#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/word-ladder-ii/1

/* approach not comes over the mind as by seeing the code, go and check the explanation in copy.*/

/* very hard problem of the BFS traversal */
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        
        queue<vector<string>> q;
        q.push({beginWord});
        
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        
        vector<vector<string>> ans;
        
        int level = 0; // starting level of the queue.
        while(!q.empty())
        {
            vector<string> store = q.front();
            q.pop();
/*how to check which level are we in ? -> The number of elements in the store vector is the level number. */

            if(store.size() > level){
                level++;
                // incr. level and delete the usedOnLevel nodes from set
                for(auto it:usedOnLevel){
                    if(st.find(it) != st.end()){
                        st.erase(it);
                    }
                }
            }
            
            string s = store.back();
            
            if(s == endWord){
                // inserting the first sequence only.
                if(ans.size() == 0)
                    ans.push_back(store);
                    
                // inserting the other sequences.
                else if(ans[0].size() == store.size()){
                    // if the new sequence is also of the shortest length, then insert it also. 
                        ans.push_back(store);
                }
            }
            
            for(int i = 0; i<s.size(); i++){
                char ch = s[i];
                
                for(char c = 'a'; c <= 'z'; c++){
                    
                    if(c != ch){
                        s[i] = c;
                        if(st.find(s) != st.end()) {
                            // push into queue.
                            store.push_back(s);
                            q.push(store);
                            
                            // tell that we have used s on particular level.
                            usedOnLevel.push_back(s);
                            store.pop_back();
                        }
                    }
                }
                s[i] = ch;
            }
        }
        
        return ans;
    }

int main()
{
    
    return 0;
}