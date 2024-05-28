#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <memory>
#include <vector>

using namespace std;

// Given an integer array nums and an integer k, return the k most frequent
// elements. You may return the answer in any order.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.

// Follow up: Your algorithm's time complexity must be better than O(n log n),
// where n is the array's size.
void printVector(vector<int> my_vec)
{
    for (int n : my_vec)
        cout << n << ' ';
    cout << '\n';
}

void printSet(set<int> my_set)
{
    for (auto n : my_set)
        cout << n << ' ';
    cout << '\n';
}

void print_vector_of_vector(vector<vector<int>> my_vec_vec)
{
    cout << '[';
    for (vector<int> my_vec : my_vec_vec)
    {
        cout << '[';
        for (int n : my_vec)
        {
            cout << n << " ,";
        }
        cout << ']';
    }
    cout << ']';
    cout << '\n';
}

void print_vector_of_set(vector<set<int>> my_v_s)
{
    cout << '[';
    for (set<int> my_s : my_v_s)
    {
        cout << '[';
        for (int n : my_s)
        {
            cout << n << " ,";
        }
        cout << ']';
    }
    cout << ']';
    cout << '\n';
}

void printMap(map<int, int> my_map)
{
    cout << "{";
    for (const auto [key, value] : my_map)
    {
        cout << key << " : " << value << ", ";
    }
    cout << "}" << endl;
}

void formatSetToVector(set<int> my_set, vector<int> &my_vec)
{
    for (auto const &val : my_set)
    {
        my_vec.push_back(val);
    }
}

// Could be renamed
bool value_greater_than_vector(vector<int> my_vec, int value)
{
    for (int n : my_vec)
    {
        if (n < value)
            return true;
    }
    return false;
}

int index_min(vector<int> my_vec)
{
    int current_min = 0;
    for (int n : my_vec)
    {
        if (n < current_min)
            current_min = n;
    }
    return current_min;
}

int search_min_key(map<int, int> my_map)
{
    int min_key;
    int min_value = 0;
    // Search min value
    for (const auto [key, value] : my_map)
    {
        if (value < min_value)
            min_value = value;
        min_key = key;
    }

    return min_key;
}

int search_vector(int num, vector<int> &my_vec)
{

    for (int i = 0; i < my_vec.size(); i++)
    {
        if (num == my_vec[i])
        {
            return i;
        }
    }
    return -1;
}

void add_in_place(int current_num, vector<vector<int>> &my_v_v)
{
    int i;
    int my_v_v_size = my_v_v.size();

    for (i = 0; i < my_v_v_size; i++)
    {
        if (search_vector(current_num, my_v_v[i]) == -1)
        {
            my_v_v[i].push_back(current_num);
            break;
        }
    }
}

void insert_vector(int current_num, vector<vector<int>> &my_v_v)
{
    bool visited = false;
    for (auto &v : my_v_v)
    {
        if (search_vector(current_num, v) == -1)
        {
            v.push_back(current_num);
            visited = true;
            break;
        }
    }
    if (!visited)
    {
        vector<int> new_element = {current_num};
        my_v_v.push_back(new_element);
    }
}

void insert_set(int current_num, vector<set<int>> &my_v_s)
{
    bool visited = false;
    for (auto &s : my_v_s)
    {
        // if (!s.contains(current_num))
        // {
        //     s.insert(current_num);
        //     visited = true;
        //     break;
        // }
    }
    if (!visited)
    {
        set<int> new_element = {current_num};
        my_v_s.push_back(new_element);
    }
}


vector<int> topKFreqv5(vector<int> &nums, int k)
{
    vector<int> res;
    vector<set<int>> occurence_v_s;
    map<int, int> counter;
    set<int> unique_numbers_s;
    int i;
    int nums_size = nums.size();
    int counter_size;

    // Occurence of nums
    for (i = 0; i < nums_size; i++)
    {
        counter[nums[i]] += 1;
    }

    // [Edge case]
    // if k = counter.size -> return all keys
    // Is this edge case really necessary ?
    counter_size = counter.size();
    if (k == counter_size)
    {
        for (const auto [key, value] : counter)
        {
            res.push_back(key);
        }
        return res;
    }

    // Init vector
    for (i = 0; i < counter_size; i++)
    {
        set<int> tmp;
        occurence_v_s.push_back(tmp);
    }

    for (const auto [key, value] : counter)
    {
        occurence_v_s[value - 1].insert(key);
    }

    print_vector_of_set(occurence_v_s);

    while (unique_numbers_s.size() != k)
    {
        set<int> current_v = occurence_v_s.back();

        for (int n : current_v)
        {
            unique_numbers_s.insert(n);
        }

        occurence_v_s.pop_back();
    }

    printSet(unique_numbers_s);

    formatSetToVector(unique_numbers_s, res);
    return res;
}

vector<int> topKFreqv4(vector<int> &nums, int k)
{
    vector<int> res;
    vector<set<int>> v_s_occurence;
    set<int> tmp;
    set<int> unique_numbers_s;
    int i;
    int nums_size = nums.size();

    // [Edge case]
    // if k = counter.size -> return all keys
    // Is this edge case really necessary ?
    map<int, int> counter;
    int counter_size;
    for (i = 0; i < nums_size; i++)
    {
        counter[nums[i]] += 1;
    }

    counter_size = counter.size();
    if (k == counter_size)
    {
        for (const auto [key, value] : counter)
        {
            res.push_back(key);
        }
        return res;
    }

    // init vector<map>
    v_s_occurence.push_back(tmp);

    for (i = 0; i < nums_size; i++) // O(n2)
    {
        insert_set(nums[i], v_s_occurence); // O(n)
    }

    print_vector_of_set(v_s_occurence);

    while (unique_numbers_s.size() != k)
    {
        set<int> current_v = v_s_occurence.back();

        for (int n : current_v)
        {
            unique_numbers_s.insert(n);
        }

        v_s_occurence.pop_back();
    }

    printSet(unique_numbers_s);

    formatSetToVector(unique_numbers_s, res);

    return res;
}

vector<int> topKFreqv3(vector<int> &nums, int k)
{
    vector<int> res;
    vector<vector<int>> v_v_occurence;
    vector<int> tmp;
    set<int> unique_numbers_s;
    int i;
    int nums_size = nums.size();
    map<int, int> counter;

    // Is this edge case really necessary ?
    int counter_size;
    for (i = 0; i < nums_size; i++)
    {
        counter[nums[i]] += 1;
    }

    counter_size = counter.size();
    // [Edge case]
    // if k = counter.size -> return all keys
    if (k == counter_size)
    {
        for (const auto [key, value] : counter)
        {
            res.push_back(key);
        }
        return res;
    }

    // init occurence_v_v;
    v_v_occurence.push_back(tmp);

    for (i = 0; i < nums_size; i++) // O(n3)
    {
        insert_vector(nums[i], v_v_occurence); // O(n2)
    }

    print_vector_of_vector(v_v_occurence);

    // why does this work ? because unique solution to the couple nums <-> k ?
    while (unique_numbers_s.size() != k)
    {
        vector<int> current_v = v_v_occurence.back();

        for (int n : current_v)
        {
            unique_numbers_s.insert(n);
        }

        v_v_occurence.pop_back();
    }

    printSet(unique_numbers_s);

    formatSetToVector(unique_numbers_s, res);

    return res;
}

// third try !
// input [1, 1, 1, 2, 2, 3], k = 2
// i = 0, [1], | v_v_o = [[]]
//    check if in v_v_o[0]
//        yes:
//        no: insert [1] in v_v_o[0]=[1] continue | [[1]]
// i = 1, [1], | v_v_o = [[1]]
//    check if in v_v_[0]
//        yes: check if in v_v_o[1]
//            yes:
//            no: insert [1] in v_v_o[1]=[1] continue | [[1], [1]]
//        no:
// i = 2, [1], | [[1], [1]]
//    check if in v_v_o[0]
//        yes: check if in v_v_o[1]
//            yes: check if in v_v_o[2]
//                yes:
//                no: insert [1] in v_v_o[2]=[1] continue | [[1], [1], [1]]
//        no:
// i = 3, [2], | [[1], [1], [1]]
//    check if in v_v_o[0]
//        yes:
//        no: insert [2] in v_v_o[0] = [1,2] | [[1,2], [1], [1]]
// i = 4, [2] | [[1,2], [1], [1]]
//    check if in v_v_o[0]
//        yes: check if in v_v_o[1]
//            yes:
//            no: insert [2] in v_v_o[1] = [1,2]
//   vector<vector<int>> v_v_occurence;

vector<int> topKFreqv2(vector<int> &nums, int k)
{
    int i;
    int nums_size = nums.size();
    vector<int> res;
    vector<vector<int>> v_v_occurence;
    set<int> unique_numbers_s;
    map<int, int> counter;
    int counter_size;
    for (i = 0; i < nums_size; i++)
    {
        counter[nums[i]] += 1;
    }

    counter_size = counter.size();
    // [Edge case]
    // if k = counter.size -> return all keys
    if (k == counter_size)
    {
        for (const auto [key, value] : counter)
        {
            res.push_back(key);
        }
        return res;
    }

    for (i = 0; i < nums_size; i++)
    {
        vector<int> tmp;
        v_v_occurence.push_back(tmp);
    }

    for (i = 0; i < nums_size; i++) // O(n3)
    {
        add_in_place(nums[i], v_v_occurence); // O(n2)
    }

    // print_vector_of_vector(v_v_occurence);

    int highest_occurence = 0;
    for (int i = 0; i < v_v_occurence.size(); i++) // O(n)
    {
        if (v_v_occurence[i].size() == 0)
        {
            highest_occurence = i - 1;
            break;
        }
    }

    for (int i = 0; i < k; i++) // O(n2)
    {
        for (int n : v_v_occurence[highest_occurence - i])
        {
            unique_numbers_s.insert(n);
        }
    }

    formatSetToVector(unique_numbers_s, res);

    return res;
}

vector<int> topKFreqv1(vector<int> &nums, int k)
{
    vector<int> res;
    map<int, int> counter;
    int i;
    int nums_size = nums.size();
    int counter_size;

    // [Edge case]
    // nums.len=1 return nums[0]

    // Thoughts
    // - nums = list -> ordered, maybe sorting it out first will help me
    // - frequence -> map Counter (forcement positif)
    // - nombre negatif
    // - constrain n log n -> no sort
    // - res.size = k
    // - notion de min/max
    // - point positif counter:
    //    - constant get
    // - point negatif counter:
    //    - search O(n)
    // - I use a counter for the unicity and existance + fast get but I use it
    // also to search which is not optimal
    // search index in array not good here
    // Resoudre les exo en te disant que tu parcour qu'une seul fois linput

    // By hand:
    // [1,1,1,2,2,3], k=2
    // i = 0, nums[0]=1 | res = []
    //    insert 1 in counter | count = {1:1}
    // i = 1, nums[1]=1 | res = []
    //    insert 1 in counter | count = {1:2}
    // i = 2, nums[2]=1 | res = []
    //    insert 1 in counter | count = {1:3}
    // i = 3, nums[3]=2 | res = []
    //    insert 2 in counter | count = {1:3, 2:1}
    // i = 4, nums[4]=2 | res = []
    //    insert 2 in counter | count = {1:3, 2:2}
    // i = 5, nums[5]=3 | res = []
    //    insert 3 in counter | count = {1:3, 2:2, 3:1}
    for (i = 0; i < nums_size; i++)
    {
        counter[nums[i]] += 1;
    }

    counter_size = counter.size();

    // [Edge case]
    // if k = counter.size -> return all keys
    if (k == counter_size)
    {
        for (const auto [key, value] : counter)
        {
            res.push_back(key);
        }
        return res;
    }

    // recupere les k plus grand valeur de count.
    // count = {1:3, 2:2, 3:1}, k = 2
    // !!! Did take k into account
    // i = 0,  {key=1 : value=3} | res = []
    //    check res empty
    //        yes: insert key=1
    //        no:
    //    check value = 3 > all count[res[*]].value
    //        yes: search minValue = min(count.value)
    //            -> get minKey from minValue
    //            -> search res[x]= minKey
    //            -> replace res[x] by current count.key         | res = [1]
    //        no:
    // i = 1,  {key = 2 : value = 2} | res = [1]
    //    check count["2"].value = 2 > all count[res[i]].value
    //        yes: replace min(res[i].value) by count["1"].value | res = [1,2]
    //        no:
    // i = 2,  {3:1} | res = [1,2]
    //    check count["3"].value = 1 > all count[res[i]].value
    //        yes:
    //        no: continue
    for (const auto [key, value] : counter)
    {

        cout << "{" << key << ":" << value << "}" << endl;
        if (res.size() == 0)
        {
            res.push_back(key);
        }
        if (value_greater_than_vector(res, value))
        {
            // search minValue get minKey
            int min_key = search_min_key(counter);
            cout << "the min key: " << min_key << endl;
            // search res[x]=minKey
            // int index_min = search_index_min(res);
            // replace res[x] = current count.key
            // res[index_min] = key;
        }
        cout << "res = ";
        printVector(res);
    }

    // second try !
    //         [0,1,2,3,4,5]
    // input = [1,1,1,2,2,3], k=2
    // i = 0, [1] | {}
    //    check [1] in {}
    //        yes:
    //        no: insert  {1: [1]}
    // i = 1, [1] | {1: [1]}
    //    check [1] in {1: [1]}
    //        yes: get key from [1] -> insert {key++; [1]} | {1:[1], 2:[1]}
    //        no:
    // i = 2, [1] | {1:[1], 2:[1]}
    //    check [1] in {1:[1], 2:[1]}
    //        yes: get key from [1] -> insert {key++; [1]} | {1:[1], 2:[1], 3:[1]}
    //        no:
    // i = 3, [2] | {1:[1], 2:[1], 3:[1]}
    //    insert {1:[1,2], 2:[1], 3:[1]}
    // i = 4, [2] | {1:[1,2], 2:[1], 3:[1]}
    //    insert {1:[1,2], 2:[1,2], 3:[1]}
    // i = 5, [3] | {1:[1,2], 2:[1,2], 3:[1]}
    //    insert | {1:[1,2,3], 2:[1,2], 3:[1]}

    return res;
}

int main()
{
    vector<int> input = {1, 1, 1, 2, 2, 3};

    vector<int> res = topKFreqv5(input, 2);
    // printVector(res);
    return 0;
}
