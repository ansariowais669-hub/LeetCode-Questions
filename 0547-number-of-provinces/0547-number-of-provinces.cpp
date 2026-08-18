class Solution {
public:

    int find(int x, vector<int>& par) {
        if(par[x] == x) return x;
        return par[x] = find(par[x], par);
    }

    void unionByRank(int a, int b, vector<int>& par, vector<int>& rank) {
        int parA = find(a, par);
        int parB = find(b, par);

        if(parA == parB) return;

        if(rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        }
        else if(rank[parA] > rank[parB]) {
            par[parB] = parA;
        }
        else {
            par[parA] = parB;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<int> par(n);
        vector<int> rank(n, 0);

        for(int i = 0; i < n; i++) {
            par[i] = i;
        }

        // Union connected cities
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(isConnected[i][j] == 1) {
                    unionByRank(i, j, par, rank);
                }
            }
        }

        // Count unique roots
        set<int> s;

        for(int i = 0; i < n; i++) {
            s.insert(find(i, par));
        }

        return s.size();
    }
};