func findMaxConsecutiveOnes(nums []int) int {
    ans := 0;
    k := 0;

    for i:= 0; i < len(nums); i++ {
        if(nums[i] == 1){
            k++
        }else {
            k = 0;
        }

        ans = max(k, ans);
    }

    return ans;
}