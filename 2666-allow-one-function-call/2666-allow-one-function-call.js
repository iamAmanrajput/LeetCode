var once = function (fn) {
    let count = 0;
    let ans;

    return function (...args) {
        if (count === 0) {
            ans = fn(...args);
            count++;
            return ans;
        }
        return undefined;
    }
};
