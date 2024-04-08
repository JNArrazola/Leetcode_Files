#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> letras;

        for (const char &c : s)
        {
            letras[c]++;
        }

        for (const char &c : t)
        {
            letras[c]--;
        }

        for (auto itr = letras.begin(); itr != letras.end(); itr++)
        {
            if((*itr).second!=0) return false;
        }

        return true;
    }
};

int main()
{
    Solution solucion;

    std::cout << solucion.isAnagram("anagram", "nagaram") << endl;
    return 0;
}
