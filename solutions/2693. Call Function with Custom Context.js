/**
 * @param {Object} context
 * @param {any[]} args
 * @return {any}
 */
// Approach 1: Using Object
Function.prototype.callPolyfill = function(context, ...args) {
  Object.defineProperty(context, 'fn', {
    value: this,
    enumerable: false,
  });
​
  return context.fn(...args);
}
​
// Approach 2: Using Symbol
Function.prototype.callPolyfill = function (context, ...args) {
  const uniqueSymbol = Symbol();
  context[uniqueSymbol] = this;
  const result = context[uniqueSymbol](...args);
  delete context[uniqueSymbol];
​
  return result;
};
​
// Approach 3: Using Bind
Function.prototype.callPolyfill = function(context, ...args) {
    return this.bind(context)(...args)
}
​
// Approach 4: Using apply
Function.prototype.callPolyfill = function(context, ...args) {
    return this.apply(context, args);
}
/**
 * function increment() { this.count++; return this.count; }
 * increment.callPolyfill({count: 1}); // 2
 */
