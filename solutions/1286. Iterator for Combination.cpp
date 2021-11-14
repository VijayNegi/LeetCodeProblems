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
        int len = str.size();
        
        int mChar = 1;
        while(mChar<= comlen && mChar <= len)
        {
            if(res[comlen - mChar] == str[ len - mChar])
                ++mChar;
            else
                break;
        }
​
        if(mChar>comlen)
            _hasNext = false;
        else
        {
            mChar = comlen - mChar;
            int l = str.find(res[mChar]);
            res = res.substr(0, mChar) + str.substr(l +1, comlen - mChar);
        }
        
        return temp;
        
    }
    
    bool hasNext() {
        return _hasNext;
        
    }
};
​
/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
