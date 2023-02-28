var groupAnagrams = function (strs) {
  const map = {};
  for (const str of strs) {
    const sorted = str.split("").sort().join("");
    if (map[sorted]) {
      map[sorted].push(str);
    } else {
      map[sorted] = [str];
    }
  }
  return Object.values(map);
};