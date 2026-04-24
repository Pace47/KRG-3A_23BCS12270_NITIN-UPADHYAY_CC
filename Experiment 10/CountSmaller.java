class Solution {
    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        int[] index = new int[n];
        
        for (int i = 0; i < n; i++) {
            index[i] = i;
        }
        
        mergeSort(nums, index, result, 0, n - 1);
        
        List<Integer> res = new ArrayList<>();
        for (int count : result) {
            res.add(count);
        }
        return res;
    }
    
    private void mergeSort(int[] nums, int[] index, int[] result, int left, int right) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        mergeSort(nums, index, result, left, mid);
        mergeSort(nums, index, result, mid + 1, right);
        
        merge(nums, index, result, left, mid, right);
    }
    
    private void merge(int[] nums, int[] index, int[] result, int left, int mid, int right) {
        int[] temp = new int[right - left + 1];
        int i = left, j = mid + 1, k = 0;
        int rightCount = 0;
        
        while (i <= mid && j <= right) {
            if (nums[index[j]] < nums[index[i]]) {
                temp[k++] = index[j++];
                rightCount++;
            } else {
                result[index[i]] += rightCount;
                temp[k++] = index[i++];
            }
        }
        
        while (i <= mid) {
            result[index[i]] += rightCount;
            temp[k++] = index[i++];
        }
        
        while (j <= right) {
            temp[k++] = index[j++];
        }
        
        for (int p = 0; p < temp.length; p++) {
            index[left + p] = temp[p];
        }
    }
}
