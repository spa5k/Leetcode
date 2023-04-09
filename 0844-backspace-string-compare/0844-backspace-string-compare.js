var backspaceCompare = function (s, t) {
  const s1 = [];
  const s2 = [];

  for (const i of s) {
    if (i === "#") {
      if (s1.length > 0) {
        s1.pop();
      }
    } else {
      s1.push(i);
    }
  }

  for (const i of t) {
    if (i === "#") {
      if (s2.length > 0) {
        s2.pop();
      }
    } else {
      s2.push(i);
    }
  }
  if (s1.length !== s2.length) {
    return false;
  }
  while (s1.length > 0) {
    const t1 = s1[s1.length - 1];
    const t2 = s2[s1.length - 1];
    s1.pop();
    s2.pop();
    if (t1 !== t2) {
      return false;
    }
  }
  return true;
};