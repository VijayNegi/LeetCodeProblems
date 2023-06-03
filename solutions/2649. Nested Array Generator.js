/**
 * @param {Array} arr
 * @return {Generator}
 */
// self
var inorderTraversal = function*(arr) {
    let arr1 = arr.flat(99999999);
    for(ele of arr1)
        yield ele
    return
};
// flat method
var inorderTraversal = function*(arr) {
  yield* arr.flat(Infinity);
};
​
// Recursive Solution
var inorderTraversal = function* (arr) {
    if(!Array.isArray(arr)) {
        yield arr
        return
    }
​
    for(let i = 0; i < arr.length; i++) {
        yield* inorderTraversal(arr[i])
    }
};
/**
 * const gen = inorderTraversal([1, [2, 3]]);
 * gen.next().value; // 1
 * gen.next().value; // 2
 * gen.next().value; // 3
 */
