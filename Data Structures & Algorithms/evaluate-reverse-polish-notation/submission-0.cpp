class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto op: tokens){
            if(op == "+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a+b);
            }
            else if(op == "-"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if(op == "*"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b*a);
            }
            else if(op == "/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b/a);
            }
            else{
                s.push(stoi(op));
            }
        }
        return s.top();
    }
};
