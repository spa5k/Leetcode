/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    const res=[]
    const state =[]
    function dfs(start, used) {
        if (start===nums.length) {
            res.push([...state]);
            return;
        }
        
         for (let i = 0; i < nums.length; i++) {
             if (used[i]) continue;
             state.push(nums[i])
             used[i]=true;
             dfs(start+1, used);
             state.pop();
             used[i]=false;
         }
    }
    
    dfs(0, new Array(nums.length).fill(false)) 
    return res;
};