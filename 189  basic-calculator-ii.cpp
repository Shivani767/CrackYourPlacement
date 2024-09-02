class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        char prevOperator = '+';

        for (int i = 0; i <= s.length(); i++) {
            char ch = (i < s.length()) ? s[i] : '\0';

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            if ((!isdigit(ch) && ch != ' ') || i == s.length()) {
                if (prevOperator == '+') st.push(num);
                if (prevOperator == '-') st.push(-num);
                if (prevOperator == '*') {
                    int temp = st.top() * num;
                    st.pop();
                    st.push(temp);
                }
                if (prevOperator == '/') {
                    int temp = st.top() / num;
                    st.pop();
                    st.push(temp);
                }

                prevOperator = ch;
                num = 0;
            }
        }

        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};

// Usage Example
// int main() {
//     Solution sol;
//     string expression = "3+2*2";
//     int result = sol.calculate(expression);
//     cout << "Result: " << result << endl; // Output: 7
//     return 0;
// }
