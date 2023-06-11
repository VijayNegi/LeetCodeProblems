//const int kDef = 99999;
class SnapshotArray {
    vector<map<int,int>> mData;
    int mLength;
    int mSnapId{0};
public:
    SnapshotArray(int length): mData(length){
        mLength = length;
        for(int i=0;i<mLength;++i)
        {
            mData[i][mSnapId] = 0;
        }
    }
    
    void set(int index, int val) {
        mData[index][mSnapId] = val;
    }
    
    int snap() {
        // for(int i=0;i<mLength;++i)
        // {
        //     if(mData[i].size()>1)
        //     {
        //         auto it = mData[i].end();
        //         advance(it,-2);
        //         if(it->second != mData[i][kDef])
        //             mData[i][mSnapId] = mData[i][kDef];
        //     }
        //     else
        //     {
        //         mData[i][mSnapId] = mData[i][kDef];
        //     }
        // }
        return mSnapId++;
    }
    
    int get(int index, int snap_id) {
        // some checks
        // if(snap_id>=mSnapId)
        //     return mData[index][kDef];
        map<int,int>& mp = mData[index];
        auto it = mp.upper_bound(snap_id);
        auto itPrev = prev(it);
        return itPrev->second;
    }
};
​
/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
