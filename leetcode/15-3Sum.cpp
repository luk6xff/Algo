class Solution {

#define V  std::vector
using vi = V<int>;

public:
    
    V<vi> threeSum(vi& nums)
    {
        V<vi> res;
        
        // Sort numbers (increasing order)
        std::sort(nums.begin(), nums.end());
        //print_vec(nums); 
  
        for (int i = 0; i < nums.size(); i++) 
        { 
            // Skip the same values
            if (i>0 && nums[i-1] == nums[i])
            {
                continue;
            }
            // Set the indexes
            int sum = 0;
            int left_idx = i + 1; 
            int right_idx = nums.size()-1; 
            const int value = nums[i]; 
            while (left_idx < right_idx) 
            {
                sum = value + nums[left_idx] + nums[right_idx];
                // If sum == 0, add it to the result checking if already exist
                if (sum == 0) 
                {   
                    //std::cout<<"value: "<<value<<" l_idx: "<<left_idx<<" r_idx: "<<right_idx<<'\n';
                    //std::cout<<'['<<value<<','<<nums[left_idx]<<','<<nums[right_idx]<<"]\n";
                    res.push_back({value, nums[left_idx], nums[right_idx]});
                    
                    // Skip the same values
                    while(left_idx < nums.size()-1 && nums[left_idx] == nums[left_idx+1])
                    {
                        left_idx++;
                    }
                    left_idx++;
                    
                    // Skip the same values
                    while(right_idx > 0 && nums[right_idx] == nums[right_idx-1])
                    {
                        right_idx--;
                    }
                    right_idx--;
                }
                // If sum < 0, increase the left_idx
                else if (sum < 0)
                {
                    // Skip the same values
                    while(left_idx < nums.size()-1 && nums[left_idx] == nums[left_idx+1])
                    {
                        left_idx++;
                    }
                    left_idx++;
                }
                // If sum > 0, decrease the right index
                else
                {
                    // Skip the same values
                    while(right_idx > 0 && nums[right_idx] == nums[right_idx-1])
                    {
                        right_idx--;
                    }
                    right_idx--;
                }
            }
        }
        return res;
    }
    

private:
    void print_vec(const vector<int>& v)
    {
        std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n';
    }
};
