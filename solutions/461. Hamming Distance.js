/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function(x, y) {
    let val = x ^ y;
    let counter = 0;
    while(val)
        {
            counter += val & 1;
            val = val>>1;
        }
    return counter;
};
