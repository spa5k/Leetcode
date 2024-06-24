var relativeSortArray = function(arr1, arr2) {
    const frequencyMap = new Map();
    const result = [];

    // Create a frequency map for arr1
    for (let num of arr1) {
        frequencyMap.set(num, (frequencyMap.get(num) || 0) + 1);
    }

    // Add elements from arr2 in the order they appear
    for (let num of arr2) {
        if (frequencyMap.has(num)) {
            const count = frequencyMap.get(num);
            for (let i = 0; i < count; i++) {
                result.push(num);
            }
            frequencyMap.delete(num);
        }
    }

    // Collect remaining elements from arr1 that are not in arr2
    const extra = [];
    for (let [num, count] of frequencyMap) {
        for (let i = 0; i < count; i++) {
            extra.push(num);
        }
    }

    // Sort the remaining elements and add to the result
    extra.sort((a, b) => a - b);
    result.push(...extra);

    return result;
};