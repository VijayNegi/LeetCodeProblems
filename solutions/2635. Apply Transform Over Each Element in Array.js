/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map1 = function(arr, fn) {
    return arr.map(fn);
};
// InMemory transform
var map2 = function(arr, fn) {
    for(let i=0;i<arr.length;++i)
        arr[i] = fn(arr[i],i)
    return arr
};
// Initial empty array
var map3 = function(arr, fn) {
    const newArr = [];
    for (let i = 0; i < arr.length; ++i) {
        newArr[i] = fn(arr[i], i);
    }
    return newArr;
};
// works for sparse array
var map = function(arr, fn) {
    const newArr = new Array(arr.length);
    for (const i in arr) {
        newArr[i] = fn(arr[i], Number(i));
    }
    return newArr;
};
