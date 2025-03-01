class Solution {
public:
    string convert(string str) {
        string ans = "";
        int counter = 1;
        for(int i=1; i<str.size(); i++) {
            if (str[i] == str[i-1]) {
                counter++;
            } else {
                ans += to_string(counter);
                ans.push_back(str[i-1]);
                counter = 1;
            }
        }
        ans += to_string(counter);
        ans.push_back(str[str.size()-1]);
        return ans;
    }
    string countAndSay(int n) {
        if(n == 1) return "1";
        return convert(countAndSay(n-1));
    }
};