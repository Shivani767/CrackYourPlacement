class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for (auto& p : count) {
            pq.push({p.second, p.first});
        }
        
        string res = "";
        while (pq.size() > 1) {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            res += p1.second;
            res += p2.second;
            if (--p1.first > 0) pq.push(p1);
            if (--p2.first > 0) pq.push(p2);
        }
        
        if (!pq.empty()) {
            if (pq.top().first > 1) return "";
            res += pq.top().second;
        }
        
        return res;
    }
};
