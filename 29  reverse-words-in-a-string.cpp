class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;
        
        // Split the string into words
        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word += c;
            }
        }
        
        // Add the last word
        if (!word.empty()) {
            words.push_back(word);
        }
        
        // Reverse the order of the words
        reverse(words.begin(), words.end());
        
        // Concatenate the words with a single space
        string result;
        for (string w : words) {
            result += w + " ";
        }
        
        // Remove the trailing space
        result.pop_back();
        
        return result;
    }
};
