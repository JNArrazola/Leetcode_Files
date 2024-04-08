#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        set<pair<int,int>> nodes;

        nodes.insert({0, 0});
        for (size_t i = 0; i < path.size(); i++)
        {
            switch (path[i])
            {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
            break;
            case 'E':
                x++;
            break;
            case 'W':
                x--;
            break;
            default:
                break;
            }

            if(nodes.find({x, y})!=nodes.end())
                return true;
            else
                nodes.insert({x, y});
        }
        return false;
    }
};

int main()
{
    


    return 0;
}