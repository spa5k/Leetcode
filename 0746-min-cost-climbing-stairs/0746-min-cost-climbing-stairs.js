/**
 * @param {number[]} cost
 * @return {number}
 */
const minCostClimbingStairs = (cost) => {
  for (let index = cost.length - 3; index >= 0; index--) {
    cost[index] += Math.min(cost[index + 1], cost[index + 2]);
  }
  return Math.min(cost[0], cost[1]);
};