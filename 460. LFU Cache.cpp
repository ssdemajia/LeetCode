#include "inc.h"
struct LFUNode {
  int key;
  int value;
  int count;
  list<int>::iterator iter;  // 指向双向链表结点，链表里面是key
};

class LFUCache {
public:
  LFUCache(int capacity) {
    cap = capacity;
  }

  int get(int key) {
    if (!keyToNode.count(key))
      return -1;
    LFUNode& node = keyToNode[key];
    adjust(node);
    return node.value;
  }

  void put(int key, int value) {
    if (cap == 0)
      return;
    
    if (keyToNode.count(key)) {
      keyToNode[key].value = value;
      adjust(keyToNode[key]);
      return;
    }
    LFUNode node;
    node.key=key;
    node.value=value;
    node.count=0;
    node.iter = countToList[0].begin();
    if (listLen == cap) { // 删除元素
      int delete_key = countToList[min_count].back();
      countToList[min_count].pop_back();
      keyToNode.erase(delete_key);      
    } else {
      listLen++;
    }
    min_count = 0;
    countToList[0].push_front(key);
    keyToNode[key] = node;
    keyToNode[key].iter = countToList[0].begin();
  }

  void adjust(LFUNode &node) {
    int prev_count = node.count;
    node.count++;
    countToList[prev_count].erase(node.iter);
    countToList[node.count].push_front(node.key);
    node.iter = countToList[node.count].begin();
    if (countToList[prev_count].empty() && prev_count == min_count) {
      min_count++;
    }
  }

private:
  unordered_map<int, LFUNode> keyToNode;
  unordered_map<int, list<int>> countToList;
  int listLen = 0; // 当前容量
  int cap;         // 最多能装多少
  int min_count = 0;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main() {
  LFUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  SS_ASSERT(cache.get(1) == 1);
  cache.put(3, 3);
  SS_ASSERT(cache.get(2) == -1);
  SS_ASSERT(cache.get(3) == 3);
  cache.put(4, 4);
  SS_ASSERT(cache.get(1) == -1);
  SS_ASSERT(cache.get(3) == 3);
  SS_ASSERT(cache.get(4) == 4);
}