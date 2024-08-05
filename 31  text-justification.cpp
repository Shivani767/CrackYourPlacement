class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int index = 0;
        while (index < words.size()) {
            int count = words[index].size();
            int last = index + 1;
            while (last < words.size()) {
                if (words[last].size() + count + last - index > maxWidth) break;
                count += words[last].size();
                last++;
            }
            int gaps = last - index - 1;
            string line;
            if (last == words.size() || gaps == 0) {
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) line += " ";
                }
                while (line.size() < maxWidth) line += " ";
            } else {
                int spaces = (maxWidth - count) / gaps;
                int extra = (maxWidth - count) % gaps;
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) {
                        for (int j = 0; j < spaces; j++) line += " ";
                        if (extra-- > 0) line += " ";
                    }
                }
            }
            result.push_back(line);
            index = last;
        }
        return result;
    }
};
