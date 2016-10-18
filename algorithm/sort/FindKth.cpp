#include <bits/stdc++.h>

using namespace std;

class quick_sort{
public:
    quick_sort(vector<int> vc){
        nums=vc;
    }
    int getSeparatorIndex(int low,int high){
        int k = nums[low];
        while(low<high){
            while(k<nums[high]&&low<high)
                high--;
            if(low<high)
                nums[low++]=nums[high];
            while(k>nums[low]&&low<high)
                low++;
            if(low<high)
                nums[high--]=nums[low];
        }
        nums[low]=k;
        return low;
    }
    int findKth(int k,int low,int high){
        int index = getSeparatorIndex(low,high);
        if(k==nums.size()-index)//num.size() 表示数组长度
            return nums[index];
        else{
            if(k>nums.size()-index)
                return findKth(k,low,index-1);
            else
                return findKth(k,index+1,high);
        }
    }
private:
    vector<int> nums;
};
