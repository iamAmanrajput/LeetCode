/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let count = n; // counter ka private state
    return () => count++; // arrow function me concise
};

/** 
 * Example usage:
 * const counter = createCounter(10);
 * console.log(counter()); // 10
 * console.log(counter()); // 11
 * console.log(counter()); // 12
 */
