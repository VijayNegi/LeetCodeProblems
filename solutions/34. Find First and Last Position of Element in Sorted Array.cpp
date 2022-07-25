                l=mid+1;
            else r = mid;
        }
        //++l;
        //cout<<"c";
        if(l==n || nums[l]!=target)
            return {-1,-1};
        int start = l;
        l=0,r=n;
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid]<= target)
                l=mid+1;
            else r = mid;
        }
        --l;
        return {start,l};
    }
    // one pass : 3 ms
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        int len = nums.size();
        if(len==0)
            return result;
        int begin = 0;
        int end = len-1;
        
        while(nums[begin]< nums[end])
        {
            int mid = begin + ((end-begin)/2);
            
            if(nums[mid]> target)
                end = mid-1;
            else if(nums[mid]< target)
                begin = mid+1;
            else
            {
                if(nums[begin]<target)
                    ++begin;
                if(nums[end]>target)
                    --end;
            }
            
        }
        if(nums[begin]==target)
            result[0]=begin,result[1]=end;
        return result;
    }
};
