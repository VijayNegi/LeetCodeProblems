/**
 * @param {number} millis
 */
// Approach 1: Asynchronous Programming with Promises and setTimeout
async function sleep(millis) {
  return new Promise(resolve => {
    setTimeout(resolve, millis);
  });
}
​
// Approach 2: Asynchronous Programming with Promises and setTimeout without Return
async function sleep1(milliseconds) {
    await new Promise(res => setTimeout(res, milliseconds)); 
}
/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
