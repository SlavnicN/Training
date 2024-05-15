#include <iostream>
#include <string>
using namespace std;

bool isAnagram(std::string s, std::string t)
{
    bool res = true;
    int i = 0, j = 0;
    int visited[s.size()];

    // test size s and t
    if (s.size() != t.size()){
        res = false;
    }

    for (i = 0; i < s.size(); i++){
        visited[i] = 0;
    }

    //loop on both word to check if each letter are present
    for (i = 0; i < s.size(); i++){
        for (j = 0; j < t.size(); j++){
            if (visited[j] == 0){
                if (s[i] == t[j]){
                    visited[j] = 1;
                    break;
                }
            }
        }
    }

    for (i = 0; i < s.size(); i++){
        if (visited[i] == 0){
            res = false;
        }
    }

    return res;
}


int main() {
    string s = "anagram";
    string t = "nagaram";

    bool res = isAnagram(s,t );

    std::cout << res;
    return 0;
}
