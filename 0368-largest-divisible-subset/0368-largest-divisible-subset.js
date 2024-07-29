var largestDivisibleSubset = function (nums) {
    nums.sort((a, b) => a - b);

    const dp = new Array(nums.length).fill(1);

    let maxSize = 1;
    let maxIndex = 0;

    for (let i = 0; i < nums.length; i++) {
        for (let j = 0; j < i; j++) {
            const ni = nums[i];
            const nj = nums[j];

            if (ni % nj === 0) {
                dp[i] = Math.max(dp[i], dp[j] + 1);

                if (dp[i] > maxSize) {
                    maxSize = dp[i];
                    maxIndex = i;
                }
            }
        }
    }

    let result = [];
    let num = nums[maxIndex];
    for (let i = maxIndex; i >= 0; i--) {
        if (num % nums[i] === 0 && dp[i] === maxSize) {
            result.push(nums[i]);
            num = nums[i];
            maxSize--;
        }
    }

    return result;
};