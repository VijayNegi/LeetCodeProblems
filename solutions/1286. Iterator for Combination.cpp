class CombinationIterator {
    string str;
    int comlen;
    int mask;
    string res;
    bool _hasNext;
public:
    CombinationIterator(string characters, int combinationLength) {
        str = characters;
        int len = characters.size();
        comlen = combinationLength;
        //mask = (1 << (comlen + 1)) - 1;
        //mask  = mask << (len - comlen);
        res = str.substr(0, comlen);
        _hasNext = true;
    }
    
    string next() {
        string temp = res;
        
        function<int(int)> comb = [&](int pos)
        {
            if(pos < 0)
                return -1;
            int l = str.find(res[pos]);
            int max = str.size() - comlen + pos;
            //cout<<"position of char "<< pos<<" at "<<l<<" and max till "<<max<<endl;
            if(l< max)
                return pos;
            return comb(pos - 1);
            
        };
        int mChar = comb(comlen -1);
        //cout<<" char to move "<<mChar<<endl;
        if(mChar == -1)
            _hasNext = false;
        else
        {
            int l = str.find(res[mChar]);
            res = res.substr(0, mChar) + str.substr(l +1, comlen - mChar);
        }
        //cout<<temp<<endl;
        return temp;
        
    }
    
    bool hasNext() {
        return _hasNext;
        //return (mask != 0) true: false;
    }
};
​
/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
