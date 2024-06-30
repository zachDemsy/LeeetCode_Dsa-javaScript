class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> parentA(n + 1), parentB(n + 1), rankA(n + 1, 1), rankB(n + 1, 1);
        iota(parentA.begin(), parentA.end(), 0);
        iota(parentB.begin(), parentB.end(), 0);
        
        function<int(vector<int>&, int)> find = [&](vector<int>& parent, int x) {
            if (parent[x] != x) {
                parent[x] = find(parent, parent[x]);
            }
            return parent[x];
        };
        
        auto unionSets = [&](vector<int>& parent, vector<int>& rank, int x, int y) {
            int rootX = find(parent, x), rootY = find(parent, y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
                return true;
            }
            return false;
        };
        
        int usedEdges = 0;
        
        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                if (unionSets(parentA, rankA, edge[1], edge[2]) | unionSets(parentB, rankB, edge[1], edge[2])) {
                    usedEdges++;
                }
            }
        }
        
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (unionSets(parentA, rankA, edge[1], edge[2])) {
                    usedEdges++;
                }
            }
        }
        
        for (const auto& edge : edges) {
            if (edge[0] == 2) {
                if (unionSets(parentB, rankB, edge[1], edge[2])) {
                    usedEdges++;
                }
            }
        }
        
        int rootA = find(parentA, 1), rootB = find(parentB, 1);
        for (int i = 2; i <= n; ++i) {
            if (find(parentA, i) != rootA || find(parentB, i) != rootB) {
                return -1;
            }
        }
        
        return edges.size() - usedEdges;
    }
};
