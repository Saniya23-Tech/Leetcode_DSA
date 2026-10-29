class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n= mat[0].size();

        queue<pair<int, int>> q;

        vector<vector<int>> dist(m, vector<int>(n, -1));

        //push all zeroes into the queue
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {

                if(mat[i][j] == 0) {
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }

        int dir_r[4] = {-1, 1, 0, 0};
        int dir_c[4] = {0, 0,-1, 1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();


            for(int k=0; k<4; k++) {
                int r = row+ dir_r[k];
                int c = col+ dir_c[k];

                if(r >=0 && r <m && c >=0 && c <n && dist[r][c] == -1)  {
                    dist[r][c] = dist[row][col] + 1;


                    q.push({r, c});
                }
            }
        }
        return dist;

        
    }
};