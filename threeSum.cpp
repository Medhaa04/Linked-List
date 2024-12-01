#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    // vector<vector<int>> threeSum1(vector<int>& nums) {
    //     set<vector<int>>st;
    //     for(int i=0;i<n;++i){
    //         for(intj=i+1;j<n;++j){
    //             for(int k=j+1;k<n;++k){
    //                 if(arr[i]+arr[j]+arr[k]==0){
    //                     vector<int>temp={arr[i],arr[j],arr[k]};                      //brutal 3 loops
    //                     sort(temp.begin(),temp.end());
    //                     st.insert(temp);
    //                 }

    //             }
    //         }
    //     }
    //     vector<vector<int>>ans(st.begin(),st.end());
    //     return ans;
        
    // }
    // vector<vector<int>> threeSum2(vector<int>& nums){
    //     set<vector<int>>st;
    //     for(int i=0;i<n;++i){
    //         set<int>hashset;                                                               //optimised 2 loops and hashsets
    //         for(int j=i+1;j<n;++j){
    //             int third=-(arr[i]+arr[j]);
    //             if(arr[i]+arr[j]+third==0){
    //                 vector<int>temp={arr[i],arr[j],third};
    //                 sort(temp.begin(),temp.end());
    //                 st.insert(temp);
    //             }
    //             hashset.insert(arr[j]);
    //         }
    //     }
    //     vector<vector<int>>ans(st.begin(),st.end());
    //     return ans;
    // }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i){
            if(i>0 and nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0) j++;
                else if (sum>0) k--;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;

                }
                while(j<k and nums[j]==nums[j-1]) j++;
                while(j<k and nums[k]==nums[k+1]) k--;
            }
        }

    
     return ans;   
    }
};