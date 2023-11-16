#include <iostream>
#include <vector>
#include <map>


using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> map1;
        vector<int> output;
        for(auto evec : nums1){
            map1.insert(pair<int, int>(evec, 1));
        }
        for(auto evec:nums2){
            if(map1[evec]){
                output.push_back(evec);
                map1[evec]=0;
            }
        }
        return output;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> output;
    // for (auto e : nums2)
    // {
    //     cout << "auto : " << e << endl;
    // }
    output = sol.intersection(nums1, nums2);
    for(auto e:output){
        cout<<e<<endl;
    }
    return 0;
}