#if 0
// contest , 500ms
class SORTracker {
    int qc;
    vector<int> maxh;
    vector<int> minh;
    vector<pair<string,int>> loc;
    function<bool(int,int)> less,greater;
public:
    SORTracker() {
        qc=1;
        less = [&](int i,int j)
        {
            if(loc[i].second<loc[j].second)
                return true;
            else if(loc[i].second>loc[j].second)
                return false;

            return loc[i].first > loc[j].first;
        };
        greater = [&](int i,int j)
        {
            if(loc[i].second>loc[j].second)
                return true;
            else if(loc[i].second<loc[j].second)
                return false;

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
        //     cout<<"max top : "<<loc[maxh.front()].first<<"\n";
        // if(minh.size()>=1)
        //     cout<<"min top: "<<loc[minh.front()].first<<"\n";
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
    SORTracker() : number_of_get(0) {}
    
    void add(string name, int score) {
        min_heap.push(make_pair(score, name));
        while (min_heap.size() > number_of_get) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    string get() {
        auto p = max_heap.top();
        min_heap.push(p);
        max_heap.pop();
        ++number_of_get;
        return p.second;
    }
    
private:
    struct Compare1 { // comparator for min_heap
        bool operator()(const pair<int, string>& a, const pair<int, string>& b)
        {
            if (a.first != b.first) {
                return a.first > b.first;
            } else {
                return a.second < b.second;
            }
        }
    };

    struct Compare2 { // comparator for max_heap
        bool operator()(const pair<int, string>& a, const pair<int, string>& b)
        {
            if (a.first != b.first) {
                return a.first < b.first;
            } else {
                return a.second > b.second;
            }
        }
    };
    
    priority_queue<pair<int, string>, vector<pair<int, string>>, Compare1> min_heap; // store number_of_get lowest-ranked locations
    priority_queue<pair<int, string>, vector<pair<int, string>>, Compare2> max_heap; // store the rest of the locations
    int number_of_get; // number of get() requests so far
};
#endif
//using set, 336 ms
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


/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
