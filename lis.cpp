class Solution {
public:
    
    int get_idx(vector<int>&lis,int low,int high,int val){
        int ans=low;
        while(low<=high){
            int mid=(low+high)/2;
            if(lis[mid]>=val){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>par(n,-1),lis(n,1e7);
        int len=0;
        for(int i=0;i<nums.size();i++){
            int idx=get_idx(lis,0,len,nums[i]);
          //  cout<<i<<" "<<idx<<" "<<len<<" "<<nums[i]<<endl;
            lis[idx]=nums[i];
            par[i]=idx-1;
            if(idx+1>len){
                len++;
            }
        }
        return len;
    }
};
