/**
 * @param {number[]} arr
 * @param {number} k
 * @param {number} threshold
 * @return {number}
 */
var numOfSubarrays = function (arr, k, threshold) {
  threshold *= k;
  let res = 0;
  let sum = 0;
  for (let i = 0; i < k; i++) {
    sum += arr[i];
  }
  if (sum >= threshold) {
    res++;
  }
  for (let i = k; i < arr.length; i++) {
    sum += arr[i] - arr[i - k];
    if (sum >= threshold) {
      res++;
    }
  }
  return res;
};