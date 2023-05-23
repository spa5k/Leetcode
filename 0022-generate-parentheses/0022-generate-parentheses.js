function generateParenthesis(n) {
  function dfs(startIndex, path, openCount, closeCount, res) {
    if (startIndex == 2 * n) {
      // make a deep copy since otherwise we'd be append the same list over and over
      res.push(path.join(""));
      return;
    }
    if (openCount < n) {
      path.push("(");
      dfs(startIndex + 1, path, openCount + 1, closeCount, res);
      path.pop();
    }
    if (closeCount < openCount) {
      path.push(")");
      dfs(startIndex + 1, path, openCount, closeCount + 1, res);
      path.pop();
    }
  }

  const res = [];
  dfs(0, [], 0, 0, res);
  return res;
}