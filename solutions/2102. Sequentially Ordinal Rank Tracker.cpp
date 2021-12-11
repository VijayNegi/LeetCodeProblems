            if(loc[i].second>loc[j].second)
                return true;
            else if(loc[i].second<loc[j].second)
                return false;
​
            return loc[i].first < loc[j].first;
        };
    }
    
    void add(string name, int score) {
        int pos = loc.size();
        loc.push_back({name,score});
        if(minh.size()==0)
        {
            minh.push_back(pos);
            return;
        }
        if(greater(pos,minh.front()))
        {
            minh.push_back(pos);
            std::push_heap(minh.begin(), minh.end(),greater);
            if(minh.size()>qc)
            {
                int k = minh.front();
                std::pop_heap(minh.begin(), minh.end(),greater);
                minh.pop_back();
                maxh.push_back(k);
                std::push_heap(maxh.begin(), maxh.end(),less);
            }
        }
        else
        {
            maxh.push_back(pos);
            std::push_heap(maxh.begin(), maxh.end(),less);
            if(minh.size()<qc)
            {
                int k = maxh.front();
                std::pop_heap(maxh.begin(), maxh.end(),less);
                maxh.pop_back();
                minh.push_back(k);
                std::push_heap(minh.begin(), minh.end(),greater);
            }
        }
        
        
        // if(maxh.size()>=1)
        //     cout<<"max top : "<<loc[maxh.front()].first<<"\n";
        // if(minh.size()>=1)
        //     cout<<"min top: "<<loc[minh.front()].first<<"\n";
        // cout<<"------"<<endl;
    }
    
    string get() {
        ++qc;
        int k = minh.front();
        if(maxh.size()>=1)
        {
            int p = maxh.front();
            std::pop_heap(maxh.begin(), maxh.end(),less);
            maxh.pop_back();
            minh.push_back(p);
            std::push_heap(minh.begin(), minh.end(),greater);
        }
        //cout<<"out: "<<loc[k].first<<endl;
        return loc[k].first;
        
    }
};
// using priority queues
class SORTracker {
public:
