class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_count = 0, max_len = 0, window_start = 0;
        unordered_map<char, int> char_count;

        for (int window_end = 0; window_end < s.length(); window_end++) {
            char right_char = s[window_end];
            char_count[right_char]++;

            max_count = max(max_count, char_count[right_char]);

            if (window_end - window_start + 1 - max_count > k) {
                char left_char = s[window_start];
                char_count[left_char]--;
                window_start++;
            }

            max_len = max(max_len, window_end - window_start + 1);
        }

        return max_len;
    }
};
