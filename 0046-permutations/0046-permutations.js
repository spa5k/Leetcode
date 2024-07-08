/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    const res=[]
    const state =[]
    const used = new Array(nums.length).fill(false);
    function dfs(start) {
        if (start===nums.length) {
            res.push([...state]);
            return;
        }
        
         for (let i = 0; i < nums.length; i++) {
             if (used[i]) continue;
             state.push(nums[i])
             used[i]=true;
             dfs(start+1);
             state.pop();
             used[i]=false;
         }
    }
    
    dfs(0, ) 
    return res;
};