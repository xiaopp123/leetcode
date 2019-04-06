#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int carry = 0;
        int sum = 0;
        for (int i = len - 1; i >= 0; i--) {
            sum = digits[i] + carry + (i == len - 1 ? 1 : 0);
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};

int main() {
    return 0;
}
