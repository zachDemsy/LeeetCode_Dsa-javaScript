class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n); 
        vector<vector<int>> ancestors(n); 
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        function<void(int, int)> dfs = [&](int start, int node) {
            for (int neighbor : adj[node]) {
                if (find(ancestors[neighbor].begin(), ancestors[neighbor].end(), start) == ancestors[neighbor].end()) {
                    ancestors[neighbor].push_back(start);
                    dfs(start, neighbor);
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            dfs(i, i);
        }
        for (int i = 0; i < n; ++i) {
            sort(ancestors[i].begin(), ancestors[i].end());
        }
        return ancestors;
    }
};