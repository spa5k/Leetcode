var maxNumberOfBalloons = function (text) {
  const map = { b: 0, a: 0, l: 0, o: 0, n: 0 };

  for (const l of text) {
    map[l]++;
  }

  map.l = Math.floor(map.l / 2);
  map.o = Math.floor(map.o / 2);

  return Math.min(map.b, map.a, map.l, map.o, map.n);
};