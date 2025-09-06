/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function (arr, fn) {
    let n = arr.length;
    let ans = new Array(n);  // preallocate array (faster than push)
    let size = 0;

    for (let i = 0; i < n; i++) {
        if (fn(arr[i], i)) {
            ans[size++] = arr[i]; // insert directly
        }
    }

    ans.length = size; // trim unused slots
    return ans;
};
