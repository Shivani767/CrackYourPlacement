class StockSpanner {
private:
    stack<pair<int, int>> stack;
    int day;

public:
    StockSpanner() {
        day = 0;
    }

    int next(int price) {
        int span = 1;
        while (!stack.empty() && stack.top().first <= price) {
            span += stack.top().second;
            stack.pop();
        }
        stack.push({price, span});
        day++;
        return span;
    }
};
