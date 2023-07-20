class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for(auto& a:asteroids){
            if(a < 0){
                while(!result.empty() && result.back()>0 && result.back() < abs(a)){
                    result.pop_back();
                }
                if(!(result.empty()) && result.back() + a == 0 )
                        result.pop_back();
                else if(result.empty() || result.back() < 0)
                    result.push_back(a);
            }
            else
                result.push_back(a);
        }
        return result;
    }
};
