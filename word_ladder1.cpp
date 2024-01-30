#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;


// problem link -> https://www.geeksforgeeks.org/problems/word-ladder/1

/* approach -> Brutforce = take the start word push into the queue with level as 1
                Get the word from the queue and try to change each character of the word from a to z.
                if you found the change word then push into the queue.

                do this things again and again and when you get the targetword return the level.

                else
                return 0;
*/

    int wordLadderLength(string startword, string targetWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startword);
        queue<pair<string, int>> q;
        
        q.push({startword, 1});
        
        while(!q.empty())
        {
            string s = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(s == targetWord) return level;
            
            for(int i = 0; i<s.size(); i++){
                char ch = s[i];
                
                for(char c = 'a'; c <= 'z'; c++){
                    
                    if(c != ch){
                        s[i] = c;
                        if(st.find(s) != st.end()) {
                            q.push({s, level+1});
                            st.erase(s);
                        }
                        s[i] = ch;
                    }
                }
            }
            
        }
        
        return 0;
    }

int main()
{
    
    return 0;
}