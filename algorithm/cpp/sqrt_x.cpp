#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    double binarySearch(int x, double start, double end) {
        double mid = (double)(start + ((end - start) / 2.0));
        if (abs(start - end) < 0.1) return end;
        if (double(mid * mid) > (double)x) return binarySearch(x, start, mid);
        if (double(mid * mid) == (double)x) return mid;
        if (double(mid * mid) < (double)x) return binarySearch(x, mid, end);
        return end;
    }

    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        return (int) binarySearch(x, 1, x);
    }
};

int main() {
    int x = 2;
    Solution s = Solution();
    cout << s.mySqrt(x) << endl;
    return 0;
}