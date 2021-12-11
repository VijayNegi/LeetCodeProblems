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
#endif
//using set
class SORTracker {
public:
    set<pair<int, string>> s;
    set<pair<int, string>>::iterator it = end(s);    
    void add(string name, int score) {
        auto it1 = s.insert({-score, name}).first;
        if (it == end(s) || *it1 < *it)
            --it;
    }
    string get() {
        return (it++)->second;
    }
};
​
​
/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
