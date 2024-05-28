#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <memory>
#include <vector>

using namespace std;

string left_padding_size(string nb_word)
{
    string res = "000";

    if (nb_word.size() == 1)
    {
        res[2] = nb_word[0];
    }
    else if (nb_word.size() == 2)
    {
        res[2] = nb_word[1];
        res[1] = nb_word[0];
    }
    else if (nb_word.size() == 3)
    {
        res[2] = nb_word[2];
        res[1] = nb_word[1];
        res[0] = nb_word[0];
    }

    return res;
}

// 3 NB_WORD | 3 SIZE_WORD_i | x WORD_i
string encode(vector<string> &strs)
{
    string res;
    string nb_words = to_string(strs.size());
    nb_words = left_padding_size(nb_words);
    res.append(nb_words);
    for (string s : strs)
    {
        string size_word = to_string(s.size());
        size_word = left_padding_size(size_word);
        res.append(size_word);
        res.append(s);
    }
    return res;
}

vector<string> decode(string s)
{
    vector<string> res;
    string init;
    string s_nb_words;

    int nb_words = 0;
    int i, j;

    for (i = 0; i < 3; i++)
    {
        s_nb_words.push_back(s[i]);
    }

    nb_words = stoi(s_nb_words);
    s.erase(0, 3);

    for (i = 0; i < nb_words; i++)
    {
        int size_word = 0;
        string tmp;
        for (j = 0; j < 3; j++)
        {
            tmp.push_back(s[j]);
        }

        size_word = stoi(tmp);
        s.erase(0, 3);

        res.push_back(init);
        for (j = 0; j < size_word; j++)
        {
            res[i].push_back(s[j]);
        }

        s.erase(0, size_word);
    }

    cout << "here nb_words:" << endl;
    cout << nb_words << endl;
    cout << "here:" << endl;
    return res;
}

int main()
{
    // TODO this use case: "we","say",":","yes","!@#$%^&*()"
    vector<string> input = {"we", "say", ":", "yes", "!@#$%^&*()"};
    vector<string> output;
    string res;
    res = encode(input);

    output = decode(res);

    cout << res << endl;
    for (string s : output)
    {
        cout << s << endl;
    }

    return 0;
}