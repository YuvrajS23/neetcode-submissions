class MinStack {
    vector<int> stk;
    vector<int> minVal;
public:
    MinStack() {
        stk = {};
        minVal = {};
    }
    
    void push(int val) {
        if (stk.empty()){
            stk.push_back(val);
            minVal.push_back(val);
        }
        else{
            stk.push_back(val);
            int minValTillNow = minVal.back();
            minVal.push_back(min(minValTillNow, val));
        }
    }
    
    void pop() {
        if(!stk.empty()){
            stk.pop_back();
            minVal.pop_back();
        }
    }
    
    int top() {
        if(!stk.empty()){
            return stk.back();
        }
    }
    
    int getMin() {
        if(!minVal.empty()){
            return minVal.back();
        }
    }
};
