/**
 * @param {number[]} mapping
 * @param {number[]} nums
 * @return {number[]}
 */
var sortJumbled = function(mapping, nums) {
    const translateInteger = (num) => {
        let digits = num.toString().split('');
        for (let i = 0; i < digits.length; i++) {
            digits[i] = mapping[digits[i]];
        }
        return parseInt(digits.join(''));
    };

    const numberMapping = {};
    for (let num of nums) {
        if (!(num in numberMapping)) {
            numberMapping[num] = translateInteger(num);
        }
    }

    nums.sort((a, b) => numberMapping[a] - numberMapping[b]);

    return nums;
};