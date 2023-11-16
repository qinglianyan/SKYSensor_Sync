#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
// 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
// 例如，121 是回文，而 123 不是。
bool isPalindrome(int x){
	long swap=0;
	long temp=x;

	if(x<0){
		return false;
	}
	if(x%10==0&&x!=0){
		return false;
	}
	
	while(temp/10!=0){
		swap=swap*10+temp%10;
		temp/=10;
	}
	swap=swap*10+temp;
	if(swap==x){
		return true;
	}
	return false;
	
}

int main(){
	bool output;
	output=isPalindrome(121);
	printf("%d", output==true);
	return 0;
}
