/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose1 = function(functions) {
    
    return function(x) {
        let val=x
        for(let j=functions.length-1;j>=0;--j){
            val = functions[j](val)
        }
        return val
    }
};
var compose2 = function (functions) {
  return function (x) {
    let input = x;
​
    for (const func of functions.reverse()) {
      input = func(input);
    }
​
    return input;
  };
};
​
​
​
/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
