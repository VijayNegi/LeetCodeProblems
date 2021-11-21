/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var buildTree = function(inorder, postorder) {
    let hash = {};
    let len = inorder.length;
    for(let i=0;i<len;++i) hash[inorder[i]] = i;
    
    let helper = function(start,end){
        if(start > end) return null;
        let val = postorder.pop();
        let root = new TreeNode(val);
        root.right = helper(hash[val]+1, end);
        root.left = helper(start, hash[val] -1);
        return root;
    }
    
    return helper(0, len -1);
    
};
