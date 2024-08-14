class WordDictionary {
private:
    struct TrieNode {
        bool isEndOfWord;
        unordered_map<char, TrieNode*> children;
        
        TrieNode() : isEndOfWord(false) {}
    };
    
    TrieNode* root;
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        return searchHelper(root, word, 0);
    }
    
private:
    bool searchHelper(TrieNode* node, string word, int index) {
        if (index == word.size()) {
            return node->isEndOfWord;
        }
        
        if (word[index] == '.') {
            for (auto& child : node->children) {
                if (searchHelper(child.second, word, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            if (!node->children.count(word[index])) {
                return false;
            }
            return searchHelper(node->children[word[index]], word, index + 1);
        }
    }
};
