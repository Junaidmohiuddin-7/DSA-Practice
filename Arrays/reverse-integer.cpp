
class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        while (x != 0) {
            int n = x % 10;   // take last digit

            // check overflow before multiplying
            if (ans > INT_MAX/10 || (ans == INT_MAX/10 && n > 7)) return 0;
            if (ans < INT_MIN/10 || (ans == INT_MIN/10 && n < -8)) return 0;

            ans = ans * 10 + n;
            x /= 10;
        }

        return ans;
    }
};
