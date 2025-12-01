class Solution {
public:
    int fib(int n) {
        return fastDoubling(n).first;
    }

private:
    // returns {F(n), F(n+1)}
    std::pair<long long, long long> fastDoubling(long long n) {
        if (n == 0) return {0, 1};

        auto p = fastDoubling(n >> 1);
        long long a = p.first;      // F(k)
        long long b = p.second;     // F(k+1)

        long long c = a * (2*b - a);    // F(2k)
        long long d = a*a + b*b;        // F(2k+1)

        if (n & 1)
            return {d, c + d};
        else
            return {c, d};
    }
};
