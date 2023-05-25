/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
// Approach 1: Using Brute Force
var chunk1 = function(arr, size) {
  const chunkedArray = [];
  let index = 0;
  
  while (index < arr.length) {
    let count = size;
    const temp = [];
    
    while (count-- > 0 && index < arr.length) {
      temp.push(arr[index]);
      index++;
    }
    
    chunkedArray.push(temp);
  }
  
  return chunkedArray;
};
​
// Approach 2: Using Slicing
var chunk2 = function(arr, size) {
  const chunkedArray = [];
  let index = 0;
  
  while (index < arr.length) {
    chunkedArray.push(arr.slice(index, index + size));
    index += size;
  }
  
  return chunkedArray;
};
​
// Approach 4: Using Reduce
var chunk = function(arr, size) {
  return arr.reduce((chunkedArray, element) => {
    const lastChunk = chunkedArray[chunkedArray.length - 1];
    if (!lastChunk || lastChunk.length === size) {
      chunkedArray.push([element]);
    } else {
      lastChunk.push(element);
    }
    return chunkedArray;
  }, []);
};
