class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> out (2);
        unordered_map<int,int> m;
        int n=nums.size();
        int complement=0;
        for(int i=0;i<n;i++)
        {
            complement = target-nums.at(i);
            if(m.find(complement)!=m.end()){
                out.at(0) = m[complement];
                out.at(1) = i;
                return out;
            }
            m[nums.at(i)]=i;
        }
        return out;
    }
};
