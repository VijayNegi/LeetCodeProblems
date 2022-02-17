class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int currSum = 0;
        vector<vector<int>> result;
        vector<int> currCom;
            
        function<void(int)> cal = [&](int i)
        {
            if(i>=candidates.size())
                return;
            while(currSum < target)
            {
                cal(i+1);
                currSum += candidates[i];
                currCom.push_back(candidates[i]);
                if(currSum == target)
                {
                    result.push_back(currCom);
                    break;
                }     
            }
            while(currCom.size()>0 && currCom.back() == candidates[i])
            {
                currSum -= candidates[i];
                currCom.pop_back();
            }
            
        };
        
        cal(0);
        return result;
    }
};
