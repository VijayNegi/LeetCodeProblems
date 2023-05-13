/**
 * @param {Function} fn
 */
function memoize1(fn) {
    const cache = {}
    return function(...args) {
        const key = JSON.stringify(args)
        if(key in cache)
            return cache[key]
        const fnOutput = fn(...args)
        cache[key] = fnOutput
        return fnOutput
    }
}
// One Liner
var memoize = (fn, cache = {}) => (...args) => cache[args.join()] ?? (cache[args.join()] = fn(...args)) 
/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *   callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
