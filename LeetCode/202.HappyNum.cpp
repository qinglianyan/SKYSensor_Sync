#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int getsum(int n){
        int i, j;
        int temp, out=0;
        while(n){
            temp=n%10;
            out+=temp*temp;
            n=n/10;
        }
        return out;
    }
    bool isHappy(int n) {
        set<int> set1;
        int next;
        set<int>::iterator it;
        next=n;
        while(true){
            next=getsum(next);
            if(next==1){
                return true;
            }
            it=set1.find(next);
            if(it==set1.end()){
                set1.insert(next);
            }
            else{
                return false;
            }
        }
    }
};
int main(){
    int input=19;
    Solution sol;
    bool out=sol.isHappy(input);
    if(out==true){
        cout<<"TRUE!"<<endl;
    }
    else
        cout<<"FALSE!"<<endl;
    // getchar();
    return 0;
}