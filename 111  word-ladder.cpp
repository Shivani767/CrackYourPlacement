class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) {
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        int step = 1;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();
                if (curr == endWord) {
                    return step;
                }
                for (int j = 0; j < curr.size(); j++) {
                    char c = curr[j];
                    for (char k = 'a'; k <= 'z'; k++) {
                        if (k == c) {
                            continue;
                        }
                        curr[j] = k;
                        if (wordSet.count(curr) && !visited.count(curr)) {
                            q.push(curr);
                            visited.insert(curr);
                        }
                    }
                    curr[j] = c;
                }
            }
            step++;
        }
        
        return 0;
    }
};
