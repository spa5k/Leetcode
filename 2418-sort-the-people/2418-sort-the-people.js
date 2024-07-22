/**
 * @param {string[]} names
 * @param {number[]} heights
 * @return {string[]}
 */
var sortPeople = function(names, heights) {
    const data = [];
    
    for (let i = 0;i<heights.length;i++) {
        const height = heights[i]
        data.push([height, i]);
    }
    
    data.sort((a,b)=> b[0] - a[0]);
    
    const result =[];
    
    for (let d of data) {
        result.push(names[d[1]])
    }
    
    return result;
};