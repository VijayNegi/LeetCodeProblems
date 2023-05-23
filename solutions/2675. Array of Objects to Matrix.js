/**
 * @param {Array} arr
 * @return {Matrix}
 */
var jsonToMatrix = function (arr) {
  const isObject = x => (x !== null && typeof x === 'object')
​
  const getKeys = (object) => {↔}
​
  const keysSet = arr.reduce((acc, curr) => {↔}, new Set());
​
  const keys = Array.from(keysSet).sort();
​
  const getValue = (obj, path) => {↔}
​
  const matrix = [keys]
  arr.forEach(obj => {
    matrix.push(keys.map(key => getValue(obj, key)))
  })
​
  return matrix
};
