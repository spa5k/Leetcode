var longestConsecutive = function (nums) {
  const set = new Set();
  for (const num of nums) {
    set.add(num);
  }
  let longest = 0;
  for (const num of set) {
    if (!set.has(num - 1)) {
      // New sequence
      let length = 1;
      while (set.has(num + length)) {
        length++;
      }
      longest = Math.max(longest, length);
    }
  }
  return longest;
};