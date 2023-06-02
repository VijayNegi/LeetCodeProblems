/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    let prev1 = 0;
    let prev2 = 1;
​
    while(true) {
        yield prev1;
        const temp = prev1;
        prev1 = prev2;
        prev2 += temp;
    }
};
​
// Destructuring assignment
var fibGenerator = function*() {
    let a = 0;
    let b = 1;
​
    while (true){
        yield a;
        [a,b] = [b, a+b]; 
    }
};
// recursive generator
var fibGenerator = function*(a = 0, b=1) {
    // yield the first number
    yield a;
​
    // recursively call fibGenerator and yield the entire generator function
    yield* fibGenerator(b, a+b);
};
​
​
​
/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */
