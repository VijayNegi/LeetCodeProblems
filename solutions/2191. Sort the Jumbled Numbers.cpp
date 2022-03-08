class Solution {
public:
    int mapi(vector<int>& map,int a)
    {
        int result=0;
        long mul=1;
        if(a==0)
        {
            result = map[a];
        }
        else
        {
            while(a)
            {
                int d = a%10;
                result += map[d]*mul;
                a /=10;
                mul*=10;
            }
        }
        //cout<<a<<" "<<result<<endl;
        return result;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> sv;
        int n = nums.size();
        for(int i=0;i<n;++i)
            sv.push_back({mapi(mapping,nums[i]),i});
        auto cmp = [](pair<int,int> left,pair<int,int> right)
        {
            if(left.first == right.first)
                return left.second < right.second;
            return left.first < right.first;
            
        };
        sort(sv.begin(),sv.end(),cmp);
        vector<int> result;
        for(auto p:sv)
        {
            result.push_back(nums[p.second]);
        }
        return result;
    }
};
