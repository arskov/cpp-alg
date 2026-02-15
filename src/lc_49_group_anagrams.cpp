#include <cassert>
#include <iostream>
#include <unordered_set>
#include <utility>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    if (strs.empty())
      return {};
    unordered_map<string, vector<string>> group;
    group.reserve(strs.size());
    for (const auto &word : strs) {
      string key = word;
      sort(key.begin(), key.end());
      group[key].push_back(word);
    }
    vector<vector<string>> result;
    result.reserve(group.size());
    for (auto &[k, words] : group) {
      result.push_back(std::move(words));
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<string> input{"eat", "tea", "tan", "ate", "nat", "bat"};
  auto res = s.groupAnagrams(input);
  for (const auto &g : res) {
    cout << "> ";
    for (const auto &w : g) {
      cout << w << ",";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
