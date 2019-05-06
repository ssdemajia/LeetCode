#include "inc.h"

class StreamChecker {
public:
  struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    TreeNode *letters[26];
    bool is_word = false;
  };
  StreamChecker(vector<string> &words) {
    trie = new TreeNode();
    for (auto &word : words) {
      reverse(word.begin(), word.end());
      build(trie, word);
    }
  }

  bool query(char letter) {
    history.push_back(letter);
    return search(trie, history.size() - 1);
  }

  void build(TreeNode *root, string &word) {
    for (int i = 0; i < word.size(); i++) {
      if (!root->letters[word[i] - 'a']) {
        root->letters[word[i] - 'a'] = new TreeNode();
      }
      if (i == word.size() - 1) {
        root->letters[word[i] - 'a']->is_word = true;
      }
      root = root->letters[word[i] - 'a'];
    }
  }

  bool search(TreeNode *trie, int index) {
    for (int i = history.size() - 1; i >= 0; i--) {
      char c = history[i];
      TreeNode *next = trie->letters[c - 'a'];
      if (!next) {
        return false;
      } else if (next->is_word) {
        return true;
      }
      trie = next;
    }
    return false;
  }

private:
  vector<char> history;
  TreeNode *trie;
};
/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

int main(int argc, char const *argv[]) {
  vector<string> words = {"ba", "aaab", "abab", "baa", "ab"};
  StreamChecker *obj = new StreamChecker(words);
  SS_ASSERT(obj->query('a'));
  SS_ASSERT(obj->query('b'));
  return 0;
}