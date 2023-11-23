class Solution {
public:
    bool check(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != diff) {
                return false;
            }
        }
        
        return true;
    }
    // sorting
    vector<bool> checkArithmeticSubarrays1(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for (int i = 0; i < l.size(); i++) {
            vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
            ans.push_back(check(arr));
        }
        
        return ans;
    }
    // hash
    bool check_hash(vector<int>& arr) {
        int minElement = INT_MAX;
        int maxElement = INT_MIN;
        unordered_set<int> arrSet;
        
        for (int num : arr) {
            minElement = min(minElement, num);
            maxElement = max(maxElement, num);
            arrSet.insert(num);
        }
        
        if ((maxElement - minElement) % (arr.size() - 1) != 0) {
            return false;
        }
        
        int diff = (maxElement - minElement) / (arr.size() - 1);
        int curr = minElement + diff;
        
        while (curr < maxElement) {
            if (arrSet.find(curr) == arrSet.end()) {
                return false;
            }
            
            curr += diff;
        }
        
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for (int i = 0; i < l.size(); i++) {
            vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
            ans.push_back(check_hash(arr));
        }
        
        return ans;
    }
};
