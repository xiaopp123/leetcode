#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);

    vector<int> t = s;

    s.push_back(5);

    cout << "s.size: " << (int)s.size() << endl;
    cout << "t.size: " << (int)t.size() << endl;



    return 0;
}
