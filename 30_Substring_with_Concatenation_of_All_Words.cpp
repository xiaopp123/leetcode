#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

/**
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 * 1、思路
 * 首先建立一个词典的映射表
 * 然后对字符串截取（因为词的长度一致）
 * 对于截取后的字符串 一个单词一个单词进行拆分，存入另一个单词的映射表
 * 最后比较这两个单词的映射表是否相同
 *
class Solution {
    public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordsNum = (int) words.size();
        if (s.length() == 0 || wordsNum == 0) {
            return res;
        }
        map<string, int> wordCount;
        int wordLen = words[0].length();
        // 词典映射表
        for (int i = 0; i < wordsNum; i++) {
            if (wordCount.count(words[i])) {
                wordCount[words[i]]++;
            } else {
                wordCount[words[i]] = 1;
            }
        }

        map<string, int> iterCount;
        int strLen = s.length();
        for (int i = 0; i < strLen - wordsNum * wordLen + 1; i++) {
            string tempStr = s.substr(i, wordsNum * wordLen);
            bool flag = true;
            iterCount.clear();
            for (int j = 0; j < (int) tempStr.length(); j += wordLen) {
                string tempWord = tempStr.substr(j, wordLen);
                if (wordCount.count(tempWord) > 0) {
                    if (iterCount.count(tempWord) > 0) {
                        iterCount[tempWord]++;
                    } else {
                        iterCount[tempWord] = 1;
                    }
                } else {
                    flag = false;
                    break;
                }
            }

            if (!flag) {
                continue;
            }
            if (compare(iterCount, wordCount)) {
                res.push_back(i);
            }
        }

        return res;
    }

    private:
    bool compare(map<string, int> iterCount, map<string, int> wordCount) {
        map<string, int> :: iterator it;
        for (it = wordCount.begin(); it != wordCount.end(); it++) {
            if (iterCount[it->first] != it->second) {
                return false;
            }
        }

        return true;
    }
};
*/
class Solution {
    public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordsNum = (int) words.size();
        int sLen = s.length();
        vector<int> res;
        if (wordsNum == 0 || sLen == 0) {
            return res;
        }
        int wordLen = words[0].size();

        map<string, int> wordCount;
        for (int i = 0; i < wordsNum; i++) {
            if (wordCount.count(words[i]) > 0) {
                wordCount[words[i]]++;
            } else {
                wordCount[words[i]] = 1;
            }
        }

        int head, tail;
        head = tail = 0;
        map<string, int> itemWord;
        int allCnt = 0;
        while (tail < sLen - wordLen + 1) {
            string word = s.substr(tail, wordLen);
            if (wordCount.count(word) > 0) {
                if (itemWord.count(word) == 0) {
                    itemWord[word] = 1;
                } else {
                    itemWord[word]++;
                }
                allCnt++;
                tail += wordLen;

                if (itemWord[word] > wordCount[word]) {
                    //修改head
                    string removeWord = s.substr(head, wordLen);
                    while (removeWord.compare(word) != 0) {
                        allCnt--;
                        itemWord[removeWord]--;
                        head += wordLen;
                        removeWord = s.substr(head, wordLen);
                    }
                    allCnt--;
                    itemWord[removeWord]--;
                    head += wordLen;
                }

                if (allCnt == wordsNum) {
                    res.push_back(head);
                    itemWord[s.substr(head, wordLen)]--;
                    allCnt--;
                    head += wordLen;
                }
            } else {
                tail++;
                head = tail;
                itemWord.clear();
                allCnt = 0;
            }
        }

        return res;
    }
};



int main() {

    Solution *solution = new Solution();
    string s;
    int n;
    vector<string> words;
    while (cin >> s >> n) {
        string word;
        for (int i = 0; i < n; i++) {
            cin >> word;
            words.push_back(word);
        }
        vector<int> res = solution->findSubstring(s, words);

        for (int i = 0; i < (int)res.size(); i++) {
            cout << res[i] << " ";
        }

    }

    return 0;
}

