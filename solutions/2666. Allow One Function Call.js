/**
 * @param {Function} fn
 * @return {Function}
 */
var once1 = function(fn) {
    let k=1;
    return function(...args){
        if(k<2){
            ++k
            return fn(...args)
        }
        return undefined
    }
};
var once2 = function(fn) {
  let hasBeenCalled = false;
  return function(...args){
    if (hasBeenCalled) {
      return undefined;
    } else {
      hasBeenCalled = true;
      return fn(...args);
    }
  }
};
// Implicitly Return Undefined
var once = function(fn) {
  let hasBeenCalled = false;
  return function(...args){
    if (!hasBeenCalled) {
      hasBeenCalled = true;
      return fn(...args);
    }
  }
};
​
/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
​
