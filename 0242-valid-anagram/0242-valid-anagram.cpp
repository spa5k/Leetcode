/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
  const isEqual = s.length === t.length;
  if (!isEqual) return false;
    
  const map = new Map();
  for (let index = 0; index < s.length; index++) {
    const element = s[index];
    const count = (map.get(element) || 0) + 1;
    map.set(element, count);
  }

  for (let index = 0; index < s.length; index++) {
    const element = t[index];
    const count = map.get(element) - 1;
    map.set(element, count);
  }
  for (const [char, count] of map) {
    if (count !== 0) {
      return false;
    }
  }
  return true;
};