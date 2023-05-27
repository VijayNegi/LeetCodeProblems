Array.prototype.last1 = function() {
    if(this.length === 0) return -1
    return this[this.length-1]
};
// Implementation 3: Nullish Coalescing Operator
Array.prototype.last2 = function() {
  return this[this.length - 1] ?? -1;
}
 Array.prototype.last = function() {
  return this.at(-1) ?? -1;
}
/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */
