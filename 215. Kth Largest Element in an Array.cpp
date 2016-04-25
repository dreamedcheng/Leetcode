
class Solution {
public:
    void quick_sort(vector<int>& nums, int left, int right, int k) {
        int privot = nums[left];
        int b = left, e = right;
        
        while (left < right) {
            while (left < right && nums[right] >= privot) right--;
            nums[left] = nums[right];
            while (left < right && nums[left] <= privot) left++;
            nums[right] = nums[left];
        }
        nums[left] = privot;
        
        //cout << left << " " << privot << endl;
        
        if (left == nums.size() - k) return;
        else if (left > nums.size() - k) quick_sort(nums, b, left-1, k);
        else quick_sort(nums, left+1, e, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        
        quick_sort(nums, 0, nums.size() - 1, k);
        
        return nums[nums.size()-k];
    }
};
