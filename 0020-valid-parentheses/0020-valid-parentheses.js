/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  const stack = [];
  for (const i of s) {
    if (i == "(" || i == "[" || i == "{") {
      stack.push(i);
    } else if (
      (i === ")" && stack.length > 0 && stack[stack.length - 1] === "(") ||
      (i === "}" && stack.length > 0 && stack[stack.length - 1] === "{") ||
      (i === "]" && stack.length > 0 && stack[stack.length - 1] === "[")
    ) {
      stack.pop();
    } else {
      return false;
    }
  }

  if (stack.length === 0) {
    return true;
  }
  return false;
};