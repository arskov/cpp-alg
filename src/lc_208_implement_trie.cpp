#include <cassert>
#include <memory>
#include <string>
#include <unordered_map>

using namespace std;

class Node {
   public:
    bool isLeaf;
    unordered_map<char, shared_ptr<Node>> map;
};

class Trie {
   private:
    shared_ptr<Node> root;

   public:
    Trie() { root = make_shared<Node>(); }

    void insert(string word) {
        auto curr = root;
        for (char& c : word) {
            if (curr->map.find(c) == curr->map.end()) {
                auto tmp = make_shared<Node>();
                curr->map.insert({c, tmp});
                curr = tmp;
            } else {
                curr = curr->map.at(c);
            }
        }
        curr->isLeaf = true;
    }

    bool search(string word) {
        auto curr = root;
        for (auto& c : word) {
            if (curr->map.find(c) != curr->map.end()) {
                curr = curr->map.at(c);
            } else {
                return false;
            }
        }
        return curr->isLeaf;
    }

    bool startsWith(string prefix) {
        auto curr = root;
        for (auto& c : prefix) {
            if (curr->map.find(c) != curr->map.end()) {
                curr = curr->map.at(c);
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    assert(trie.search("apple"));
    assert(!trie.search("app"));
    assert(trie.startsWith("app"));
    trie.insert("app");
    assert(trie.search("app"));
}
