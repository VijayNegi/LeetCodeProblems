/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNonDuplicate = function(nums) {
    var l = 0;
    var r = nums.length-1;
    while(l<r)
    {
        let m = l + Math.floor((r - l)/2);
        if(nums[m] == nums[m ^ 1])
            l = m +1;
        else
            r = m;
    }
    return nums[l];
};
