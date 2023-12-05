#include <iostream>
#include <set>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> output;
        set<int> set1;
        set<int>::iterator it;
        for(auto e:nums1){
            set1.insert(e);
        }
        for( auto e:nums2){
            it=set1.find(e);
            if(it!=set1.end()){
                output.push_back(e);
                set1.erase(it);
            }
        }
        return output;
    }
};


int main(){

    return 0;
}