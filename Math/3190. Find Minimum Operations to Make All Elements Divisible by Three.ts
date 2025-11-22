function minimumOperations(nums: number[]): number {
  let operations = 0;
  const n = nums.length;

  for (let i = 0; i < n; i++) {
    if (nums[i] % 3 != 0) {
      operations++;
    }
  }

  return operations;
}
