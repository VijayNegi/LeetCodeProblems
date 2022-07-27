            result.push_back(maxheight);
        }
        return result;
    }
    // 62 ms
    // map solution without coordinate-compression
    // same as line-sweep
    // see diagram in problem and similar to 218. The Skyline Problem
    //https://leetcode.com/problems/falling-squares/discuss/108783/c%2B%2B-map-based-short-solution
    vector<int> fallingSquares2(vector<vector<int>>& positions) {
        map<int,int> mp = {{0,0}};
        int curr=0;
        vector<int> res;
        for(auto b:positions){
            int l = b[0],r = b[0]+b[1],h = b[1];
            auto it_i = mp.upper_bound(l);  // upper as we have a min sentry entry
            auto it_j = mp.lower_bound(r);  // match or upper 
            int tmp = it_j->first == r? it_j->second : prev(it_j)->second; // height after this box end
            int maxh=0;
            for(auto i=prev(it_i);i!=it_j;++i) {  // start from boxes that have already started.
                maxh = max(maxh,i->second);
            }
            mp.erase(it_i,it_j);      //erase range
            mp[l] = h+maxh;           // new left bound
            mp[r] = tmp;              // new right bound
            curr = max(curr, mp[l]);
            res.push_back(curr);
        }
        return res;
    }
    // 43 ms
    // line sweep with coordinate compression
    // https://leetcode.com/problems/falling-squares/discuss/1441736/C%2B%2B-coordinate-compression
    vector<int> fallingSquares(vector<vector<int>>& ps) {
        vector<int> x;
        for (auto &p : ps) x.push_back(p[0]),x.push_back(p[0] + p[1]);
        sort(x.begin(),x.end());
        vector<int> hs(x.size()), ans; // hs to store height
        unordered_map<int, int> idx;
        for (int i = 0; auto t : x) idx[t] = i++; // provide index for accessing hs
        for (int mh = 0; auto &p : ps) {
            int l = idx[p[0]], r = idx[p[0] + p[1]];
            int mx = *max_element(hs.begin() + l, hs.begin() + r);
            for (int i = l; i < r; i++) hs[i] = p[1] + mx;
            mh = max(mh, hs[l]);
            ans.emplace_back(mh);
        }
        return ans;
    }
};
