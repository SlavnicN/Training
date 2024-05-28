#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <stdio.h>
#include <vector>

using namespace std;

bool isAnagram(string s, string t) {
  int s_size = s.size();
  int t_size = t.size();
  int i = 0, j = 0;

  cout << "s= " << s << " t= " << t << endl;
  // test size s and t

  if (s_size != t_size) {
    return false;
  } else if (s_size == 0) {
    return true;
  }

  int visited[s_size];

  for (i = 0; i < s_size; i++) {
    visited[i] = 0;
  }

  // loop on both word to check if each letter are present
  for (i = 0; i < s_size; i++) {
    for (j = 0; j < s_size; j++) {
      if (visited[j] == 0) {
        if (s[i] == t[j]) {
          visited[j] = 1;
          break;
        }
      }
    }
  }

  for (i = 0; i < s_size; i++) {
    if (visited[i] == 0) {
      return false;
    }
  }

  return true;
}

void printMap(map<string, vector<string>> mymap) {
  for (auto const &[key, val] : mymap) {
    cout << '[' << key << ']' << ' ' << "=" << ' ';
    for (string n : val)
      cout << n << ' ';
    cout << endl;
  }
}

vector<string> formatSetToVector(vector<string> myset) {
  vector<string> myVector;
  for (auto const &val : myset) {
    myVector.push_back(val);
  }
  return myVector;
}

void printVector(vector<vector<string>> myVector) {
  for (auto const &var : myVector) {
    cout << '{';
    for (string n : var)
      cout << n << " ";
    cout << "}";
  }
  cout << endl;
}

void formatMapToVector(map<string, vector<string>> mymap,
                       vector<vector<string>> &myres) {
  for (auto const &[key, val] : mymap) {
    myres.push_back(formatSetToVector(val));
  }
}

vector<vector<string>> formatMapToVector(map<string, vector<string>> mymap) {
  vector<vector<string>> myVector;
  vector<string> tmp;
  for (auto const &[key, val] : mymap) {
    myVector.push_back(formatSetToVector(val));
  }
  return myVector;
}

bool vector_contains(vector<string> my_vec, string str) {
  int i = 0;
  int vec_size = my_vec.size();

  for (i = 0; i < vec_size; i++) {
    if (my_vec[i] == str) {
      return true;
    }
  }
  return false;
}

string is_anagram_keys(string word,
                       map<string, vector<string>> word_vector_anagram) {
  for (auto const &[key, val] : word_vector_anagram) { // O(n)
    if (isAnagram(key, word))                          // O(n2)
      return key;
  }
  return "0";
}

// "eat","tea","tan","ate", "nat", "bat"
// i = 0 | strs[i] = eat | sorted_words = {}
//      sort eat | aet
//      check aet in sorted_words:
//      yes:
//      no: insert aet in sorted_words | sorted_words = {aet: []}
// i = 1 | strs[1] = tea | sorted_words = {aet: []}
//      sort tea | aet
//      check aet in sorted_words:
//          yes: continue
//          no:
// i = 2 | strs[2] = tan | sorted_words = {aet: []}
//      sort tan | ant
//      check ant in stored_words:
//          yes:
//          no: insert ant in sorted_words | {aet: [], ant: []}
// i=3 | strs[3] = ate | {aet: [], ant: []}
//      sort ate | aet
//      check aet in sorted_words:
//          yes: continue
//          no:
// i = 4 | strs[4]=nat | {aet: [], ant: []}
//      sort nat | ant
//      check ant in sorted_words:
//          yes: continue
//          no:
// i = 5 | strs[5]=bat | {aet: [], ant: []}
//      sort bat | abt
//      check abt in sorted_words:
//          yes:
//          no: insert abt in sorted_words | {aet: [], ant: [], abt: []}

map<string, vector<string>> sort_words_vector(vector<string> vec) {
  map<string, vector<string>> map_sorted_words;
  vector<string> empty_vec;
  int size_vec = vec.size();
  int i;
  string sorted_word;
  for (i = 0; i < size_vec; i++) {
    sorted_word = vec[i];
    sort(sorted_word.begin(), sorted_word.end());
    map_sorted_words.insert({sorted_word, empty_vec});
  }
  return map_sorted_words;
}

// "eat","tea","tan","ate", "nat", "bat"
// i=0 | strs[i] = eat | wva = {}
//    check eat isAnagram wva.keys
//        yes:
//        no: creation [eat] + insert wva = {eat : [eat]}
//
//
// i=1 | strs[i] = tea | wva = {eat : [eat]}
//    check tea isAnagram wva.keys | {eat}
//        yes: insert tea in wva[eat] | wva = {eat : [eat, tea]}
//        no: creation {tan} + insert wva = {tan : {tan}} | wva = {eat :eat},
//        tan: {tan}}
//
//
// i=2 | strs[2] = tan | wva = {eat : [eat, tea]}
//    check tan isAnagram wva.keys | {eat}
//        yes:
//        no: creation [tan] + insert wva = {tan : [tan]} | wva = {eat :
//        [eat,tea], tan: [tan]}
//
// i=3 | strs[3] = ate | wva = {eat : [eat, tea], tan: [tan]}
//    check ate isAnagram wva.keys | {eat, tan}
//        yes: insert ate in wva[eat] | wva = {eat : [eat, tea, ate]}
//        no: creation [tan] + insert wva = {tan : [tan]}
//            | wva = {eat : [eat,tea], tan: [tan]}
//
//
// i=4 | strs[4] = nat | wva = {eat : [eat, tea, ate], tan: [tan]}
//    check nat isAnagram wva.keys | {eat, tan}
//        yes: insert nat in wva[tan] | wva = {eat : [eat, tea],
//        tan:[tan,nat]} no: creation [tan] + insert wva = {tan : [tan]} | wva
//        = {eat : [eat, tea], tan: [tan]}
//
//
// i=5 | strs[5] = bat | wva = {eat : [eat, tea], tan: [tan,nat]}
//    check bat isAnagram wva.keys | {eat, tan}
//        yes: insert nat in wva[tan] | wva = {eat : [eat, tea], tan:
//        [tan,nat]} no: creation [bat] + insert wva = {bat : [bat]} | wva =
//        {eat : [eat, tea], tan: [tan,nat], bat: [bat]}

// is_anagram_keys(word=eat, wva= {})
//  i = 0, word=eat, wva.key(0) = {}
//     check isAnagram(eat, {})
//         yes:
//         no: return "0"

// is_anagram_keys(word=tea, wva= {eat : [eat]})
//  i = 0, word=tea, wva.key(0) = eat
//     check isAnagram(tea, eat)
//         yes: return eat
//         no:

// is_anagram_keys(word=tan, wva= {eat : [eat,tea]})
//  i = 0, word=tan, wva.key(0) = eat
//     check isAnagram(tan, eat)
//         yes:
//         no: return 0

// is_anagram_keys(word=ate, wva= {eat : [eat,tea], tan: [tan]})
//  i = 0, word=ate, wva.key(0) = eat
//     check isAnagram(ate, eat)
//         yes: return eat
//         no:

// is_anagram_keys(word=nat, wva= {eat : [eat,tea,ate], tan: [tan]})
//  i = 0, word=nat, wva.key(0) = eat
//     check isAnagram(ate, eat)
//         yes:
//         no:
//  i=1, word=nat, wva.key(1) = tan
//     check isAnagram(nat, tan)
//         yes: return tan
//         no:

vector<vector<string>> groupAnagramsv2(vector<string> &strs) { // O(n2logn)
  map<string, vector<string>> map_sorted_words;
  vector<vector<string>> res;

  int strs_size = strs.size();
  int i;

  if (strs_size < 2) {
    res.push_back(strs);
    return res;
  }
  // map_sorted_words = sort_words_vector(strs);

  for (i = 0; i < strs_size; i++) { // O(n)
    string sorted_word = strs[i];
    sort(sorted_word.begin(), sorted_word.end()); // O(nlogn)

    map_sorted_words[sorted_word].push_back(strs[i]);

    printMap(map_sorted_words);
    cout << "+++++++++" << endl;
  }

  formatMapToVector(map_sorted_words, res);
  printMap(map_sorted_words);

  // printVector(res);
  return res;
}

vector<vector<string>> groupAnagrams(vector<string> &strs) { // O(n4)
  map<string, vector<string>> word_vector_anagram;
  vector<vector<string>> res;

  int strs_size = strs.size(); // O(n)
  int i;

  if (strs_size < 2) {
    res.push_back(strs); // O(1)
    return res;
  }

  for (i = 0; i < strs_size; i++) {                                     // O(n)
    string key_anagram = is_anagram_keys(strs[i], word_vector_anagram); // O(n3)
    if (key_anagram != "0") {
      word_vector_anagram[key_anagram].push_back(strs[i]);
    } else {
      word_vector_anagram[strs[i]].push_back(strs[i]);
    }

    printMap(word_vector_anagram);
    cout << "+++++++++" << endl;
  }

  formatMapToVector(word_vector_anagram, res); // O(n)
  printMap(word_vector_anagram);
  // printVector(res);
  return res;
}

int main() {
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  // map<string, vector<string>> test_sort;
  // test_sort = sort_words_vector(strs);
  // printMap(test_sort);
  vector<vector<string>> res = groupAnagramsv2(strs);
  printVector(res);

  return 0;
}
