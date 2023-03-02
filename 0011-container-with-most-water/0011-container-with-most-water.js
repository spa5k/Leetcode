var maxArea = function (height) {
  let left = 0;
  let right = height.length - 1;
  let maxVol = Math.min(height[left], height[right]) * (right - left);
  while (left < right) {
    let curr = Math.min(height[left], height[right]) * (right - left);
    maxVol = Math.max(curr, maxVol);
    if (height[left] < height[right]) {
      left++;
    } else {
      right--;
    }
  }
  return maxVol;
};