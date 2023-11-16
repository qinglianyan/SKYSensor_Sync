#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (int i = 0; i < s.size(); i += (2 * k))
        {
            if (i + k <= s.size())
            {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else
            {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

int main()
{
    string input = "hello";
    string output;
    Solution sol;
    output=sol.reverseStr(input, 2);
    std::cout << input << std::endl;
    cout<<output<<endl;
    return 0;
}