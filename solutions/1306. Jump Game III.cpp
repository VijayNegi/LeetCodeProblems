class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        //set<int> idxs;
        queue<int> idxs;
        int n = arr.size();
        idxs.push(start);
        
        while(!idxs.empty())
        {
            int i = idxs.front();
            idxs.pop();
            if(arr[i] == 0)
                return true;
            if(arr[i] > 0 && (i - arr[i])>= 0  )
                idxs.push(i-arr[i]);
            if(arr[i] > 0  && (i + arr[i]) < n  )
                idxs.push(i+arr[i]);
            arr[i] = - abs(arr[i]);
                
        }
        return false;
    }
};
