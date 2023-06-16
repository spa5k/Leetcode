/**
 * @param {number[][]} boxTypes
 * @param {number} truckSize
 * @return {number}
 */
var maximumUnits = function (boxTypes, truckSize) {
  let ans = 0;
  let boxesLeft = truckSize;
  boxTypes.sort((a, b) => b[1] - a[1]);

  for (let i = 0; i < boxTypes.length; i++) {
    let [box, units] = boxTypes[i];
    box = Math.min(boxesLeft, box);
    ans += box * units;
    boxesLeft -= box;

    if (boxesLeft === 0) {
      break;
    }
  }

  return ans;
};