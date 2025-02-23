class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = INT_MIN, mini;
        vector<int> maxSquare;
        for (int i = 0; i < rectangles.size(); i++) {
            mini = min(rectangles[i][0], rectangles[i][1]);

            if (maxLen < mini) {
                maxLen = mini;
            }

            maxSquare.push_back(mini);
        }

        int number = 0;
        for (int i = 0; i < maxSquare.size(); i++) {
            if (maxSquare[i] == maxLen) {
                number += 1;
            }
        }
        return number;
    }
};