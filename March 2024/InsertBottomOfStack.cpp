
class Solution{
public:
    void insert(stack<int> &st,int k){
        if(st.size() == 0){
            st.push(k);
            return;
        }
        int top = st.top();
        st.pop();
        insert(st,k);
        st.push(top);
        return;
    }
    stack<int> insertAtBottom(stack<int> st,int x){
        insert(st,x);
        return st;
    }
};