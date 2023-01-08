class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky(false),heavy(false);
        heavy = mass>=100;
        long vol = (long)length*width*height;
        if(length>=10000 || width >=10000 || height >=10000 || vol>=1000000000)
            bulky=true;
        if(heavy && bulky)
            return "Both";
        if(!(heavy || bulky))
            return "Neither";
        return bulky? "Bulky":"Heavy";
        
    }
};
