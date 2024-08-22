class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> ump;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (ump.find(key) != ump.end()) {
            int value = ump[key]->second;
            cache.erase(ump[key]);
            cache.emplace_front(key, value);
            ump[key] = cache.begin();
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (ump.find(key) != ump.end()) {
            cache.erase(ump[key]);
        } else if (cache.size() == capacity) {
            ump.erase(cache.rbegin()->first);
            cache.pop_back();
        }
        cache.emplace_front(key, value);
        ump[key] = cache.begin();
    }
};
