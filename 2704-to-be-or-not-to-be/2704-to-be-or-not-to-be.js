/**
 * @param {any} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        toBe: function(expected) {
            if (val !== expected) {
                throw new Error("Not Equal"); 
            }
            return true;
        },
        notToBe: function(expected) {
            if (val === expected) {
                throw new Error("Equal"); 
            }
            return true;
        }
    };
};

// Usage:
console.log(expect(5).toBe(5));       // true
console.log(expect(5).notToBe(10));   // true
// expect(5).notToBe(5);  // throws "Equal"
// expect(5).toBe(null);  // throws "Not Equal"
