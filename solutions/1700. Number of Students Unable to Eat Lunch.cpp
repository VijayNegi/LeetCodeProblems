class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cZero,cOne;
        cZero = cOne = 0;
        for(auto& s:students)
            if(s==0) cZero++;
            else cOne++;
        for(auto& s: sandwiches){
            if(s ==0 && cZero)
                --cZero;
            else if(s == 1 && cOne)
                --cOne;
            else 
                break;
        }
        return max(cZero,cOne);
    }
};
