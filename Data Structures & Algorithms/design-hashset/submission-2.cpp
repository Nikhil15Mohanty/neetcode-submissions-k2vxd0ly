class MyHashSet {
public:
    vector<list<int>> vec;
    static const int SIZE = 15000;

    int getIndex(int key) {
        return key % SIZE;
    }

    MyHashSet() {
        vec.resize(SIZE);
    }
    
    void add(int key) {
        int index = getIndex(key);
        for (int element: vec[index]) {
            if (element == key) return;
        }
        vec[index].push_back(key);
    }
    
    void remove(int key) {
        int index = getIndex(key);
        vec[index].remove(key);
    }
    
    bool contains(int key) {
        int index = getIndex(key);
        for (int element: vec[index]) {
            if (element == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */