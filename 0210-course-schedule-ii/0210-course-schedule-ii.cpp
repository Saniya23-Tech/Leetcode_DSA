class Solution {
    public:

    bool dfs(int curr, vector<vector<int>> &graph, vector<bool> &vis, vector<bool>& recPath, stack<int> &st) {
        vis[curr] = true;
        recPath[curr] = true;

        for(int v : graph[curr]) {
            if(!vis[v]) {
                if(dfs(v, graph, vis, recPath, st)) { //selfcalling + result checking 
                    return true;
                }
            }
            else if(recPath[v]) {
                return true; //cycle
            }
        }
        recPath[curr] = false;
          st.push(curr);
          return false;
    }
    vector<int> findOrder(int numcourses , vector<vector<int>> &preq) {
        vector<vector<int>> graph(numcourses); // hence numcourses are 4 so graph is 4 creates a 4 vectors for each list 
        for(auto p: preq) {
            int course =p[0];
            int preq = p[1];

            graph[preq].push_back(course); //complete the 0 course first then complete the course 1 later 
        }

        vector<bool> vis(numcourses , false);
        vector<bool> recPath(numcourses, false);

        stack<int> st;

        for(int i=0; i < numcourses; i++) {
            if(!vis[i]) {
                if(dfs(i, graph, vis, recPath, st)) {
                    return {};
                }
            }
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};