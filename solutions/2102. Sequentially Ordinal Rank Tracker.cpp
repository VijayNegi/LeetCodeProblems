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
​
            return loc[i].first > loc[j].first;
        };
        greater = [&](int i,int j)
        {
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
