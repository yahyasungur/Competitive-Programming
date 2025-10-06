class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		int Ksize = nums.size()-1;
		int i=0,j=1,k=nums.size()-1;
		int sum;
		
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		
		while(i<j && i<k && i<Ksize-1){
			if(i>0 && nums[i] == nums[i-1]){
				i++;
				continue;
			}
			
			j = i+1;
			k=Ksize;
			while(j<k){
				sum = nums[i]+nums[j]+nums[k];
				if(sum == 0){
					result.push_back({nums[i],nums[j],nums[k]});
					j++;
					while(nums[j] == nums[j-1] && j < k){
						j++;
					}
				}
				else if(sum > 0){
					k--;
				}
				else{
					j++;
				}
			}
			i++;
		}
		
		return result;
    }
};
