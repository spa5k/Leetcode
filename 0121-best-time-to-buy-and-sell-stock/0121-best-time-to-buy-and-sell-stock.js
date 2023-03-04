var maxProfit = function (prices) {
  let left = 0;
  let right = 1;
  let max = 0;

  while (right < prices.length) {
    const canSlide = prices[right] <= prices[left];
    if (canSlide) left = right;

    const window = prices[right] - prices[left];

    max = Math.max(max, window);
    right++;
  }

  return max;
};