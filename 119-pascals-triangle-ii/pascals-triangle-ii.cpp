class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> row(r + 1, 1);
        for (int i = 1; i < r; i++) {
            for (int j = i; j > 0; j--) {
                row[j] += row[j - 1];
            }
        }
        return row;
    }
};
