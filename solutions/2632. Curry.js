/**
 * @param {Function} fn
 * @return {Function}
 */
// Currying with Recursive Function Calls
var curry1 = function(fn) {
    return function curried(...args) {
        if(args.length >= fn.length)
            return fn(...args)
        return (...nextArgs) => curried(...args,...nextArgs)
    };
};
// Currying with the Built-in Bind Method
var curry = function (fn) {
  return function curried(...args) {
    if (args.length >= fn.length) {
      return fn.apply(this, args);
    }
​
    return curried.bind(this, ...args);
  };
};
​
/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */
​
