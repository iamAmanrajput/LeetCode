/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let n = arr.length;
    let ans = new Array(n);

    for (let i = 0; i < n; i++) {
        ans[i] = fn(arr[i], i);
    }

    return ans;
};
