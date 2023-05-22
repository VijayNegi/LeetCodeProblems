/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
​
// Approach 1: Recursive setTimeout Calls
var throttle = function(fn, t) {
  let timeoutInProgress = null;
  let argsToProcess = null;
  
  const timeoutFunction = () => {
    if (argsToProcess === null) {
      timeoutInProgress = null; // enter the waiting phase
    } else {
      fn(...argsToProcess);
      argsToProcess = null;
      timeoutInProgress = setTimeout(timeoutFunction, t);
    }
  };
​
  return function throttled(...args) {
    if (timeoutInProgress) {
      argsToProcess = args;
    } else {
      fn(...args); // enter the looping phase
      timeoutInProgress = setTimeout(timeoutFunction, t);
    }
  }
};
​
// Approach 2: setInterval + clearInterval
var throttle1 = function(fn, t) {
  let intervalInProgress = null;
  let argsToProcess = null;
  
  const intervalFunction = () => {
    if (argsToProcess === null) {
      clearInterval(intervalInProgress);
      intervalInProgress = null; // enter the waiting phase
    } else {
      fn(...argsToProcess);
      argsToProcess = null;
