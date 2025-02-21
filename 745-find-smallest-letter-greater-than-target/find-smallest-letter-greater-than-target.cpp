class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int low=0;
        int high=letters.size()-1;

        char ans='z'+1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(target<letters[mid] && letters[mid]<=ans){
                ans=letters[mid];
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        if(ans=='z'+1){
            return letters[0];
        }
        else{
            return ans;
        }
    }
};