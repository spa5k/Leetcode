/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    const res=[]
    const state=[];
    const used = new Array(nums.length).fill(false)
    
    function dfs() {
        if (state.length === nums.length) {
            res.push([...state]);
            return;
        }
        
        for (let i=0;i<nums.length;i++) {
            if (used[i]) continue;
            
            state.push(nums[i])
            used[i]= true;
            dfs();
            
            state.pop();
            used[i]=false;
            
        }
        
    }
    dfs();
    return res;
};