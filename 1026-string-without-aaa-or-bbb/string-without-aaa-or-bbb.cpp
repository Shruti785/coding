class Solution {
public:
    string strWithout3a3b(int a, int b) {
        int s = a+b;
        string ans;
        int checkA = 0;
        int checkB = 0;
        for(int i = 0;i<s;i++){
            if(b>0 && ((b>=a && checkB <2) || checkA ==2)){
                ans+='b';
                b--;
                checkB++;
                checkA =0;
            }
            else if(a>0 && ((a>=b && checkA<2) || checkB == 2)){
                ans+='a';
                a--;
                checkB = 0;
                checkA++;
            }
        }
        return ans;
    }
};