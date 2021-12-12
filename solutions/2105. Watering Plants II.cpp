class Solution {
public:
    // 190 ms
    int minimumRefill1(vector<int>& plants, int capA, int capB) {
        int currA = capA;
        int currB = capB;
        int n = plants.size();
        int refill = 0;
        
        for(int i=0;i<=(n-1)/2;i++)
        {
            int j = n-i-1;
            if(i == j)
            {
                if(currA<currB)
                {
                   if(currB<plants[j])
                    {
                        ++refill;
                        currB = capB;
                    }
                    currB -= plants[j];
                }
                else 
                {
                    //Alice
                   if(currA<plants[i])
                    {
                        ++refill;
                        currA = capA;
                    }
                    currA -= plants[i];
                }
            }
            else
            {
                //Alice
                if(currA<plants[i])
                {
                    ++refill;
                    currA = capA;
                }
                currA -= plants[i];
                
                //bob
                if(currB<plants[j])
                {
                    ++refill;
                    currB = capB;
                }
                currB -= plants[j];
            }
        }
       
        return refill;
    }
    // just cleaner and concise : 152
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int i = 0, j = plants.size() - 1, canA = capacityA, canB = capacityB, res = 0;
        while (i < j) {
            res += (canA < plants[i]) + (canB < plants[j]);
            canA = canA < plants[i] ? capacityA : canA;
            canB = canB < plants[j] ? capacityB : canB;
            canA -= plants[i++];
            canB -= plants[j--];
        }
        return res + (i == j && max(canA, canB) < plants[i]);
    }
};
