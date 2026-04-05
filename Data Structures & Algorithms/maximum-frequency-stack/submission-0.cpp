class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int maxFrequency = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        int f = ++freq[val];
        if (f > maxFrequency) maxFrequency = f;
        group[f].push(val);
    }
    
    int pop() {
        int value = group[maxFrequency].top();
        group[maxFrequency].pop();

        if (group[maxFrequency].empty()) {
            maxFrequency--;
        }

        freq[value]--;
        return value;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */