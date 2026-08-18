class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int, int>>> graph(n);

        // u -> {v, weight}
        for(int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];   // Correct weight

            graph[u].push_back({v, wt});
        }

        // {node, {cost, stops}}
        queue<pair<int, pair<int, int>>> q;

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // src with 0 cost and 0 stops
        q.push({src, {0, -1}});

        while(!q.empty()) {

            auto curr = q.front();
            q.pop();

            int u = curr.first;
            int cost = curr.second.first;
            int stops = curr.second.second;

            for(auto edge : graph[u]) {

                int v = edge.first;
                int wt = edge.second;

                if(dist[v] > cost + wt && stops + 1 <= k) {

                    dist[v] = cost + wt;

                    q.push({
                        v,
                        {dist[v], stops + 1}
                    });
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;

        return dist[dst];
    }
};