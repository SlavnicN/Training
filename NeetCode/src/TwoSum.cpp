#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> twoSumHashv2(vector<int> &nums, int target) {
  vector<int> res = {0, 0};
  map<int, int> hashmap;
  int size = nums.size();
  int i;

  if (size == 2) {
    res[0] = 0;
    res[1] = 1;
    return res;
  }

  for (i = 0; i < size; i++) {
    if (hashmap.contains(nums[i])) {
      res[0] = hashmap[nums[i]];
      res[1] = i;
      return res;
    }
    hashmap.insert({target - nums[i], i});
  }

  // [3.2.3]
  for (i = 0; i < size; i++) {
    // hashmap.insert_or_assign(target - nums[i],i);
    if (!hashmap.contains(hashmap[target - nums[i]])) {
      hashmap[target - nums[i]] = i;
    }

    if (hashmap.contains(nums[i]) && i != hashmap[nums[i]]) {
      res[0] = hashmap[nums[i]]; // res[0] =
      res[1] = i;                // res[1] =
    }
  }

  for (auto const &[key, val] : hashmap) {
    std::cout << key        // string (key)
              << ':' << val // string's value
              << std::endl;
  }
  return res;
}

// vector<int> twoSumHash(vector<int>& nums, int target){
//      vector<int> res = {NULL, NULL};
//      map<int, int> hashmap;
//      int size = nums.size();
//      int i,j;

//     for (i = 0; i < size; i++){
//        hashmap.insert(pair<int,int>(target - nums[i],-1));

//     }

//     for (i = 0; i <size; i++){
//        if(hashmap.contains(nums[i])){
//           hashmap[nums[i]] = i;
//        }
//     }

//     for (i=0; i<size; i++) {
//        if (hashmap.contains(target - nums[i]) && (i != (target - nums[i])) &&
//        ) {
//            res[0] = i;
//            res[1] = hashmap[target - nums[i]];
//            break;
//        }
//     }

//     for (auto const& [key, val] : hashmap)
//     {
//        std::cout << key        // string (key)
//            << ':'
//            << val        // string's value
//            << std::endl;
//     }

//     std::cout << '\n';

//     return res;
// }

vector<int> twoSum(vector<int> &nums, int target) {
  vector<int> res = {0, 0};
  int size = nums.size();
  int i, j;

  // Boucle de boucle
  for (i = 0; i < size; i++) {
    for (j = i + 1; j < size; j++) {
      if (nums[i] + nums[j] == target) {
        res[0] = i;
        res[1] = j;
        break;
      }
    }
  }
  return res;
}

int main() {
  vector<int> test = {3, 2, 3};
  vector<int> res = twoSumHashv2(test, 6);

  for (int n : res)
    std::cout << n << ' ';
  std::cout << '\n';

  return 0;
}

//
// Created by Nikola Slavnic on 17/04/2024.
//
