/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter1 = function(arr, fn) {
    const res = [] 
    for (const i in arr) {
        if(fn(arr[i], Number(i)))
            res.push(arr[i])
    }
    return res
};
var filter2 = function(arr, fn) {
    return arr.filter(fn);
};
var filter = function(arr, fn) {
    const newArr = [];
    for (let i = 0; i < arr.length; ++i) {
        if (fn(arr[i], i)) {
            newArr.push(arr[i]);
        }
    }
    return newArr;
};
