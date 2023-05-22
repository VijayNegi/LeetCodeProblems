/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
// Approach 1: setTimeout + clearTimeout
var debounce1 = function(fn, t) {
  let timeout;
  return function(...args) {
    clearTimeout(timeout);
    timeout = setTimeout(() => {
      fn(...args)
    }, t);
  };
};
​
// Approach 2: setInterval + clearInterval
// Inefficient too
var debounce = function(fn, t) {
  let interval;
  return function(...args) {
    const lastCall = Date.now()
    clearInterval(interval);
    interval = setInterval(() => {
      if (Date.now() - lastCall >= t) {
        fn(...args);
        clearInterval(interval);
      }
    }, 1);
  }
};
/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */
