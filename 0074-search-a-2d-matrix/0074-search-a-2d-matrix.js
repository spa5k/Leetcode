/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function (matrix, target) {
  for (const mat of matrix) {
    const res = binarySearch(mat, target);
    if (res) {
      return true;
    }
  }
  return false;
};

const binarySearch = (matrix, target) => {
  let left = 0;
  let right = matrix.length - 1;

  if (target < matrix[left] || target > matrix[right]) {
    return false;
  }

  while (left <= right) {
    let mid = Math.floor((left + right) / 2);
    let midn = matrix[mid];

    if (midn === target) {
      return true;
    } else if (midn < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return false;
};