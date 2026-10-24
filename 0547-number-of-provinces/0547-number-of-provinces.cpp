class Solution {
public:
void dfs(int curr, vector<vector<int>> & adj, vector <bool> &vis) {
    vis[curr] =true;

    for(int i=0; i< adj[curr].size(); i++) {
        if(adj[curr][i] == 1 && !vis[i]) {
            dfs(i, adj, vis);
        }
    }
}


    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int ans = 0;
        int n = isConnected.size(); 

        vector<bool> vis(n, false);

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i, isConnected, vis);
                ans++;
            }
        }
        return ans;
    }
};