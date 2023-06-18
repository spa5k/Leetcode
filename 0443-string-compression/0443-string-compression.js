/**
 * @param {character[]} chars
 * @return {number}
 */
var compress = function (chars) {
  let left = 0;
  let right = 1;
  let currSum = 1;
  let write = 0; // Pointer to write compressed characters

  while (right <= chars.length) {
    if (chars[left] == chars[right]) {
      currSum += 1;
    } else {
      chars[write] = chars[left];
      write++;

      if (currSum >= 2) {
        const countStr = currSum.toString();
        for (let i = 0; i < countStr.length; i++) {
          chars[write] = countStr[i];
          write++;
        }
      }

      currSum = 1;
    }

    left++;
    right++;
  }

  return write;
};