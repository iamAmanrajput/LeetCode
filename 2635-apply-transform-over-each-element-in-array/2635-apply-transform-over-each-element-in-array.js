/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let ans = [];
    for(let i =0;i<arr.length;i++){
        ans.push(fn(arr[i],i));
    }
    return ans;
};