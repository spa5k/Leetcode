var isPalindrome = function (s) {
  s = s.toLowerCase();
  s = s.replace(/[^A-Za-z0-9]/g, "");

  let start = 0;
  let end = s.length - 1;

  while (start < end) {
    if (s[start] !== s[end]) return false;
    start++;
    end--;
  }
  return true;
};