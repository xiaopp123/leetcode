#include <cstdio>
#include <iostream>
using namespace std;

struct Node{
    int val;
};
int main() {
    Node* n1 = new Node();
    n1->val = 10;
    Node* n2 = n1;
    n2->val = 20;
    cout << "n1->val: " << n1->val << endl;
    cout << "n2->val: " << n2->val << endl;
    return 0;
}
