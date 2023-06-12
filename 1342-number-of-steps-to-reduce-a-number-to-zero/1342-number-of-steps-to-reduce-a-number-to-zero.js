/**
 * @param {number} num
 * @return {number}
 */
var numberOfSteps = function (num) {
  let res = 0;
  while (num !== 0) {
    if (num % 2 !== 0) {
      num -= 1;
    } else {
      num /= 2;
    }
    res += 1;
  }
  return res;
};