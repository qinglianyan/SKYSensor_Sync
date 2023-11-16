#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        vector<int> output;
        // unordered_map<int, int>::iterator iteumap;
        int i=0;
        for(i=0;i<nums.size();i++){
            auto findflag=umap.find(target-nums[i]);
            if(findflag !=umap.end()){
                output.push_back(i);
                output.push_back(findflag->second);
                return output;
            }
            umap.insert(pair<int, int>(nums[i], i));
        }

        return output;
    }
};
int main(){
    vector<int> input={2, 7, 11, 15};
    int target=9;
    Solution sol;
    vector<int> output;

    output=sol.twoSum(input, target);
    for(auto e:output){
        cout<<"output:"<<e<<endl;
    }
    // cout<<output[0]<<","<<output[1]<<endl;
    getchar();
    return 0;
}