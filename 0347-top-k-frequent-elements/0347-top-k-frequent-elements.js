var topKFrequent = function (nums, k) {
  const map = new Map();
  const res = [];
  for (const num of nums) {
    const existingFreq = map.get(num) + 1 || 1;
    map.set(num, existingFreq);
  }

  let sortedArray = [...map.entries()].sort((a, b) => b[1] - a[1]);
  for (let index = 0; index < k; index++) {
    res.push(sortedArray[index][0]);
  }
  return res;
};