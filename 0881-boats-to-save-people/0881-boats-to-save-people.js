/**
 * @param {number[]} people
 * @param {number} limit
 * @return {number}
 */
var numRescueBoats = function (people, limit) {
  people.sort((a, b) => a - b);
  let left = 0;
  let right = people.length - 1;
  let boats = 0;
  while (left <= right) {
    if (people[left] + people[right] <= limit) {
      left += 1;
    }
    boats += 1;
    right -= 1;
  }
  return boats;
};