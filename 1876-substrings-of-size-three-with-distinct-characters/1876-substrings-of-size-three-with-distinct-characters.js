var countGoodSubstrings = function (s) {
  let res = 0;
  for (let i = 0; i < s.length - 2; i++) {
    const window = [s[i], s[i + 1], s[i + 2]];
    const chars = new Set(window);

    if (chars.size === 3) {
      res++;
    }
  }
  return res;
};