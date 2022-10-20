class Solution {
    vector<int> nums{1000,900,500,400,100,90,50,40,10,9,5,4,1,0};
    vector<string> roman{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    //map<int,char> num2char{{1000,'M'},{500,'D'},{100,'C'},,{50,'L'},{10,'X'},{5,'V'},{1,'I'}};
public:
    string intToRoman1(int num) {
        string result;
        int k=0;
        while(num){
            if(nums[k]>num){
                ++k;
                continue;
            }
            result += roman[k];
            num -= nums[k];
        }
        return result;
    }
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};
