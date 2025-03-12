class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> unique;
        vector<string> str{".-",   "-...", "-.-.", "-..",  ".",    "..-.",
                           "--.",  "....", "..",   ".---", "-.-",  ".-..",
                           "--",   "-.",   "---",  ".--.", "--.-", ".-.",
                           "...",  "-",    "..-",  "...-", ".--",  "-..-",
                           "-.--", "--.."};

        string codeStr = "";
        for (int i = 0; i < words.size(); i++) {
            codeStr = "";
            string st = words[i];
            for (int j = 0; j < st.length(); j++) {
                int indices = st[j] - 'a';
                codeStr += str[indices];
            }
            unique.insert(codeStr);
        }
        return unique.size();
    }
};