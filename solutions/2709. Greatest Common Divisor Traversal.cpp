// https://leetcode.com/problems/greatest-common-divisor-traversal/discuss/3573061/C%2B%2B-Java-Python-Slides-Explanation-or-BFS-DFS-Union-Find-or-Connected-Graph
class Graph {
private:
    int n;
    vector<int> parent, compSize;
​
    int getParent(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = getParent(parent[x]);
    }
​
    void unionSet(int x, int y) {
        int parx = getParent(x), pary = getParent(y);
        if (parx != pary) {
            if (compSize[parx] < compSize[pary]) {
                swap(parx, pary);
            }
            parent[pary] = parx;
            compSize[parx] += compSize[pary];
        }
    }
​
public:
    Graph(int n = 0) : n(n) {
        parent.resize(n);
        compSize.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    void addEdge(int x, int y) {
        unionSet(x, y);
    }
​
    bool isConnected() {
        return compSize[getParent(0)] == n;
    }
};
​
class Solution {
private:
    vector<int> getPrimeFactors(int x) {
        vector<int> primeFactors;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                primeFactors.push_back(i);
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        if (x != 1) {
            primeFactors.push_back(x);
        }
        return primeFactors;
    }
​
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
