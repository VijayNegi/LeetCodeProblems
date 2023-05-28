/**
 * @param {Function} fn
 * @return {Array}
 */
// self
Array.prototype.groupBy1 = function(fn) {
    let arr = {}
    for(const ele of this){
        const k = fn(ele)
        if(!arr[k])
            arr[k] = []
        arr[k].push(ele)
    }
    return arr
};
Array.prototype.groupBy = function(fn) {
    let arr = {}
    for(const ele of this){
        const k = fn(ele)
        arr[k] ||= []; // Note
        arr[k].push(ele)
    }
    return arr
};
​
Array.prototype.groupBy2 = function(fn) {
  const returnObject = {};
  for (const item of this) {
    const key = fn(item);
    if (key in returnObject) {
      returnObject[key].push(item);
    } else {
      returnObject[key] = [item];
    }
  }
  return returnObject;
};
​
/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */
