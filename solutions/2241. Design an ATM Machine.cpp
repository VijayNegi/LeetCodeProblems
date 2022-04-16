class ATM {
    int vec[5];
    map<int,long long> count;
public:
    ATM() {
        vec[4]=500; vec[3]= 200; vec[2]=100; vec[1] = 50; vec[0] = 20;
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<5;++i)
            count[vec[i]] += banknotesCount[i];
    }
    
    vector<int> withdraw(int amount) {
        vector<int> invalid{-1};
        vector<int> result(5,0);
        
        for(int i=4;i>=0;--i)
        {
            if(count[vec[i]] && amount)
            {
                long long notes = amount/ vec[i];
                notes = min(notes,count[vec[i]]);
                amount -= vec[i]*notes;
                result[i] = notes;
                count[vec[i]] -= notes;
            }
        }
        if(amount!= 0)
        {
            deposit(result);
            return invalid;
        }
        return result;
    }
};
​
/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
