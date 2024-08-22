class NestedIterator {
private:
    stack<NestedInteger> st;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it) {
            st.push(*it);
        }
    }

    int next() {
        int val = st.top().getInteger();
        st.pop();
        return val;
    }

    bool hasNext() {
        while (!st.empty()) {
            if (st.top().isInteger()) {
                return true;
            }
            vector<NestedInteger> list = st.top().getList();
            st.pop();
            for (auto it = list.rbegin(); it != list.rend(); ++it) {
                st.push(*it);
            }
        }
        return false;
    }
};
