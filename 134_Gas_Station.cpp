#include "heads.h"
using namespace std;

class Solution {
    public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = (int)gas.size();
        for (int i = 0; i < (int)gas.size(); i++) {
            bool flag = false;
            int gas_tot = gas[i];
            int index = i;
            while (true) {
                gas_tot = gas_tot - cost[index % n];
                if (gas_tot < 0) {
                    flag = true;
                    break;
                }
                gas_tot += gas[(index + 1) % n];
                index++;
                if (index % n == i) {
                    break;
                }
            }
            if (!flag) {
                return  i;
            }
        }
        return -1;
    }
};


int main() {
    return 0;
}
