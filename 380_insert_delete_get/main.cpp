#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
public:   
    unordered_map<int, int> num_index;
    vector<int> nums = {};

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(num_index.find(val)==num_index.end()){
            num_index.insert({val, nums.size()});
            nums.push_back(val);
            return true;
        } else {
            return false;
        }
    }
    
    bool remove(int val) {
        if(num_index.find(val)!=num_index.end()){
            nums.erase(nums.begin()+num_index[val]);
            num_index.erase(val);
            return true;
        } else {
            return false;
        }
    }
    
    int getRandom() {
        return rand()%nums.size()-1;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    


    return 0;
}