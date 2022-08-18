class Solution {
public:
    // self : 171 ms
    int minSetSize1(vector<int>& arr) {
        sort(begin(arr),end(arr));
        priority_queue<int> q;
        int pre = 0,count=0;;
        for(auto& n:arr) {
            if(pre == n)
                ++count;
            else {
                q.push(count);
                count=1;
                pre = n;
            }
        }
        q.push(count);
        int h = arr.size()/2;
        int result = 0;
        count=0;
        while(count<h) {
            count += q.top();
            q.pop();
            ++result;
        }
        return result;
    }
    // hashmap 354 ms
    int minSetSize2(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int x : arr) ++cnt[x];
        
        vector<int> frequencies;
        for (auto [_, freq] : cnt) frequencies.push_back(freq);
        sort(frequencies.begin(), frequencies.end());
        
        int ans = 0, removed = 0, half = arr.size() / 2, i = frequencies.size() - 1;
        while (removed < half) {
            ans += 1;
            removed += frequencies[i--];
        }
        return ans;
    }
    // hashmap count sort : 220 ms
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> cnt;
        for (int x : arr) ++cnt[x];
​
        vector<int> counting(n + 1);
        for (auto [_, freq] : cnt) ++counting[freq];
​
        int ans = 0, removed = 0, half = n / 2, freq = n;
        while (removed < half) {
            ans += 1;
            while (counting[freq] == 0) --freq;
            removed += freq;
            --counting[freq];
        }
        return ans;
    }
};
