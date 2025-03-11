class Solution {
public:
bool isVowel(char ch){
    ch =tolower(ch);
    return ch=='a' || ch=='e'|| ch=='i'||ch=='o'||ch=='u';
}
    string reverseVowels(string s) {
        int left=0,right=s.length();
            while(left<right){
                if(isVowel(s[left]) && isVowel(s[right])){
                    swap(s[left],s[right]);
                    left++;
                    right--;
                }
                else if(isVowel(s[left])==0){
                left++;
            }
            else{
                right--;
            }
         }
        return s;
    }
};