/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
var findAnagrams = function (s, p) {
  const pHash = new Array(26).fill(0);
  const sHash = new Array(26).fill(0);

  const res = [];

  if (p.length > s.length) {
    return res;
  }

  let left = 0;
  let right = 0;
  while (right < p.length) {
    pHash[p.charCodeAt(right) - 97]++;
    sHash[s.charCodeAt(right) - 97]++;
    right++;
  }
  right--;

  while (right < s.length) {
    if (pHash.join("") === sHash.join("")) {
      res.push(left);
    }
    right++;
    if (right !== s.length) {
      sHash[s.charCodeAt(right) - 97]++;
      sHash[s.charCodeAt(left) - 97]--;
    }
    left++;
  }
  return res;
};