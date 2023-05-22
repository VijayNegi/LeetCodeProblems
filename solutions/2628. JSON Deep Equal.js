/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
// Approach 1: Comparative Recursion: 69ms
var areDeeplyEqual = function(o1, o2) {
    if (o1 === o2) return true;
    if (o1 === null || o2 === null) return false;
    if (String(o1) !== String(o2)) return false;

    if (typeof o1 !== 'object') {
        return o1 === o2;
    }

    if (Array.isArray(o1)) {
        if (o1.length !== o2.length) return false;

        for (let i = 0; i < o1.length; i++) {
            if (!areDeeplyEqual(o1[i], o2[i])) return false;
        }

        return true;
    }

    if (Object.keys(o1).length !== Object.keys(o2).length) return false;

    for (const key in o1) {
        if (!areDeeplyEqual(o1[key], o2[key])) return false;
    }

    return true;
};
// Approach 2: Iterative Solution: 65ms
/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
function areDeeplyEqual2(o1, o2) {
  var objs = [[o1, o2]];

  while (objs.length) {
    [o1, o2] = objs.pop();

    if (o1 === o2) continue;
    if (typeof o1 !== 'object' || typeof o2 !== 'object') return false;
    if (Array.isArray(o1) !== Array.isArray(o2)) return false;

    const keys1 = Object.keys(o1);
    const keys2 = Object.keys(o2);

    if (keys1.length !== keys2.length) return false;
    for (const key of keys1) {
      if (!(key in o2)) return false;
      objs.push([o1[key], o2[key]]);
    }
  }

  return true;
}
// Approach 3: Using JSON.stringify and Sorting: 150ms
/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
function helper(key, value) {
    if (value && typeof value === "object" && !Array.isArray(value))
        return Object.fromEntries(Object.entries(value).sort());
    else
        return value;
}
 

var areDeeplyEqual3 = function(o1, o2) {
    const stringifiedO1 = JSON.stringify(o1, helper);
    const stringifiedO2 = JSON.stringify(o2, helper);

    return stringifiedO1 === stringifiedO2;
};
