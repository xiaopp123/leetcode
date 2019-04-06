#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode *child[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

class Trie {
    private:
        TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        int len = word.length();
        TrieNode* p = root;
        for (int i = 0; i < len; i++) {
            if (p->child[word[i] - 'a'] == NULL) {
                p->child[word[i] - 'a'] = new TrieNode();
            }
            p = p->child[word[i] - 'a'];
        }
        p->isWord = true;
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int len = word.length();
        TrieNode* p = root;
        for (int i = 0; i < len; i++) {
            if (p->child[word[i] - 'a'] != NULL) {
                p = p->child[word[i] - 'a'];
            } else {
                return false;
            }
        }
        return p->isWord;
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int len = prefix.length();
        TrieNode* p = root;
        for (int i = 0; i < len; i++) {
            if (p->child[prefix[i] - 'a'] != NULL) {
                p = p->child[prefix[i] - 'a'];
            } else {
                return false;
            }
        }
        return true;

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
int main() {
    Trie* obj = new Trie();
    string word;
    cin >> word;
    obj->insert(word);
    cin >> word;
    bool param_2 = obj->search(word);
    cout << param_2 << endl;
    cin >> word;
    bool param_3 = obj->startsWith(word);
    cout << param_3 << endl;
    return 0;
}
