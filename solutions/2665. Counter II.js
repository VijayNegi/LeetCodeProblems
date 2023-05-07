/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let curr = init
    let increment =  ()=>{ return ++curr }
    let decrement = ()=>{return --curr }
    let reset = ()=>{ return curr = init }
    return {
        increment, decrement, reset
    }
};
/* other way with Shortened Syntax
var createCounter = function(init) {
  let currentCount = init;
  return {
    increment: () => ++currentCount,
    decrement: () => --currentCount,
    reset: () => (currentCount = init),
  }
};
*/
​
/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
