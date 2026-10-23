class Solution {
public:

   vector<int> par, rank;
   int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]); //path compresssion 
   }

    //return true if it is union(no cycle) 
    bool unionByRank(int a , int b) {
        int parA = find(a);
        int parB = find(b);

        if(parA == parB) return false; //cycle 

        if(rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        } else if( rank[parA] > rank[parB]) {
            par[parB] = parA;
        } else {
            par[parA] = parB;
        }
        return true;
    } 
   

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        //DSU i it 
        par.resize(n);
        rank.assign( n , 0);
        for(int i=0; i<n; i++ ) {
            par[i] = i;
        }
        vector<array<int , 3>> edges; // {weight, u, v}
        //To create the edge between each pair(manhattan distance)

        for(int i=0; i< n ; i++) {
            for(int j=i+1; j <n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                edges.push_back({dist, i, j});
            }
        }

        //sorting edges by weight 
        sort(edges.begin() ,edges.end());


        //kruskal's

        int totalCost =0, edgesUsed =0;
        for(auto& [wt, u, v] : edges) {
            if(unionByRank(u,v)) {
                totalCost +=wt;
                edgesUsed++;
                if(edgesUsed == n-1) break;
            }
        }

        return totalCost;
        
    }
};