class MyHashMap {
public:
    vector<list<pair<int, int>>> bucket;
    static const int size = 15000;

    int getIndex(int key) {
        return key % size;
    }

    MyHashMap() {
        bucket.resize(size);
    }
    
    void put(int key, int value) {
        int index = getIndex(key);
        for (auto& element : bucket[index]) {  // use reference
            if (element.first == key) {
                element.second = value;
                return;  // return to avoid duplicates
            }
        }
        bucket[index].push_back({key, value});
    }
    
    int get(int key) {
        int index = getIndex(key);
        for (auto& element : bucket[index]) {
            if (key == element.first) {
                return element.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index = getIndex(key);
        for (auto it = bucket[index].begin(); it != bucket[index].end(); ) {
            if (it->first == key) {
                it = bucket[index].erase(it);
            } else {
                ++it;
            }
        }
    }
};
