class Solution {
public:
    //self
    int totalFruit1(vector<int>& fruits) {
        int result=0;
        unordered_map<int,int> basket;
        int start=0;
        for(int i=0;i<fruits.size();++i){
            basket[fruits[i]]++;
            while(basket.size()>2){
                basket[fruits[start]]--;
                if(basket[fruits[start]]==0)
                    basket.erase(fruits[start]);
                ++start;
            }
            result = max(result, i-start+1);
        }
        return result;
    }
    // others
    int totalFruit(vector<int> &tree) {
        unordered_map<int, int> count;
        int i, j;
        for (i = 0, j = 0; j < tree.size(); ++j) {
            count[tree[j]]++;
            if (count.size() > 2) {
                if (--count[tree[i]] == 0)count.erase(tree[i]);
                i++;
            }
        }
        return j - i;
    }
};
