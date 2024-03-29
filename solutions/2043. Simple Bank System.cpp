class Bank {
    vector<long long> mAcc;
public:
    Bank(vector<long long>& balance): mAcc(balance)  {
        
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1> mAcc.size() || account2 > mAcc.size() || mAcc[account1-1] < money)
            return false;
        mAcc[account1-1] -= money;
        mAcc[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account> mAcc.size()) return false;
        mAcc[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account> mAcc.size() || mAcc[account-1] < money ) return false;
        mAcc[account-1] -= money;
        return true;
    }
};
​
/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
