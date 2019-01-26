#include "heads.h"
using namespace std;

class LRUCache {
    private:
        list<pair<int,int> > cache_;
        unordered_map<int, list<pair<int, int> >::iterator> m_;
        int cap;

    public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        //找到并放到第一个
        auto it = m_.find(key);
        if (it == m_.end()) {
            return -1;
        }
        cache_.splice(cache_.begin(), cache_, it->second);

        return it->second->second;
    }

    void put(int key, int value) {
        auto it = m_.find(key);
        //如果key已经存在,不管value是否相等，都把它更新成新的value
        if (it != m_.end()) {
            it->second->second = value;
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }
        //如果key不存在的话，需要将插入cache，此时需要判断一下cache是否满，如果满需要需要剔除最后一个
        if ((int)m_.size() == cap) {
            m_.erase(cache_.back().first);
            cache_.pop_back();
        }
        cache_.emplace_front(make_pair(key, value));
        m_[key] = cache_.begin();

    }
    /**
     * 写的太丑
     * 主要是判断key值存不存在时，还要判断value相不相等
    void put(int key, int value) {

        //如果满的话，看一看是否存在，如果不存在，需要将最后一个给剔除掉，然后将这个插入到链表首部
        //如果存在的话，把它放到链表首部
        auto it = m_.find(key);
        if ((int)cache_.size() == cap) {
            //not exist
            if (it == m_.end()) {
                m_.erase(cache_.back().first);
                cache_.pop_back();
                cache_.insert(cache_.begin(), make_pair(key, value));
                m_[key] = cache_.begin();
            } else {
                //exist
                if (value != it->second->second) {
                    it->second->second = value;
                    cache_.splice(cache_.begin(), cache_, it->second);
                } else {
                    cache_.splice(cache_.begin(), cache_, it->second);
                }
            }
        } else {
            // not full
            //如果存在，判断值是不是相等
            if (it != m_.end()) {
                //值不相等
                if (value != it->second->second) {
                    it->second->second = value;
                    cache_.splice(cache_.begin(), cache_, it->second);
                } else {
                    cache_.splice(cache_.begin(), cache_, it->second);
                }
            } else {
                //不存在
                cache_.insert(cache_.begin(), make_pair(key, value));
                m_[key] = cache_.begin();
            }
        }
    }
    */
};

int main() {
    return 0;
}
