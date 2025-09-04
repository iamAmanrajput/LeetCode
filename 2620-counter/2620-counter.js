/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let currVal = n; // counter ka apna state
    return function() {
        return currVal++; // pehle return, phir increment
    };
};

/** 
 * Example usage:
 * const counter = createCounter(10)
 * console.log(counter()) // 10
 * console.log(counter()) // 11
 * console.log(counter()) // 12
 */
