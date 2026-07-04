class Solution {
public:
    bool detectCapitalUse(string word) {
        int capital=0;
        for(int i=0;i<word.length();i++){
            if (isupper(word[i])) {
                capital++;
            }
        }
        return capital == word.length() || capital == 0 || capital == 1 && isupper(word[0]);
    }
};