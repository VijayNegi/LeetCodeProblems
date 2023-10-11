class Solution {
public:
    // self : 266 ms
    vector<int> fullBloomFlowers1(vector<vector<int>>& flowers, vector<int>& people) {
        int n = people.size();
        vector<pair<int,int>> arrival;
        for(int i=0;i<n;++i){
            arrival.push_back({people[i],i});
        }
        sort(arrival.begin(),arrival.end());
        sort(flowers.begin(),flowers.end());
        priority_queue<int,vector<int>,greater<>> endQueue;
        int i=0,f=0,bloom=0;
        int fsize = flowers.size();
        vector<int> result(n,0);
        while(i<n){
            int k = arrival[i].first;
            int pos = arrival[i].second;
            // add all the flowers that had bloomed
            while(f<fsize && flowers[f][0]<=k){
                if(flowers[f][1]>=k){
                   endQueue.push(flowers[f][1]);
                    ++bloom;
                }
                ++f;
            }
           // remvoe all the flowers whos time has passed
            while(endQueue.size() &&  endQueue.top()<k ){
                endQueue.pop();
                --bloom;
            }
            result[pos] = bloom;
            ++i;
        }
        return result;
    }
    // line sweep
    // 266 ms
    vector<int> fullBloomFlowers2(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> difference;
        difference[0] = 0;
        
        for (vector<int>& flower : flowers) {
            difference[flower[0]]++;
            difference[flower[1] + 1]--;
        }
        
        vector<int> positions;
        vector<int> prefix;
        int curr = 0;
        for (auto& pair : difference) {
            positions.push_back(pair.first);
            curr += pair.second;
            prefix.push_back(curr);
        }
        
        vector<int> ans;
        for (int person : people) {
            int i = upper_bound(positions.begin(), positions.end(), person) - positions.begin() - 1;
            ans.push_back(prefix[i]);
        }
        
        return ans;
    }
    // simple binary search
    // 227 ms
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> starts;
        vector<int> ends;
        
        for (vector<int>& flower : flowers) {
            starts.push_back(flower[0]);
            ends.push_back(flower[1] + 1);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        vector<int> ans;
        
        for (int person : people) {
            int i = upper_bound(starts.begin(), starts.end(), person) - starts.begin();
            int j = upper_bound(ends.begin(), ends.end(), person) - ends.begin();
            ans.push_back(i - j);
        }
        
        return ans;
    }
};
