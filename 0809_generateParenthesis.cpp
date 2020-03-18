面试题 08.09. 括号

括号。设计一种算法，打印n对括号的所有合法的（例如，开闭一一对应）组合。
说明：解集不能包含重复的子集。
例如，给出 n = 3，生成结果为：
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

/**
 * @param {number} n
 * @return {string[]}
 */

var generateParenthesis = function(n) {
  let ans = [];
  
  function dfs(curr, l, r, restl, restr) {
    // 如果当前子集右括号数量大于左括号，终止此次递归
    if (r > l) return ;
    
    // 如果剩余左右括号都为0，那么记录此时的子集到结果集中，终止此次递归
    if (restl === 0 && restr === 0) {
      ans.push( curr );
      return ;
    }
    
    // 继续拿左右括号尝试
    if (restl > 0) {
      curr += '(';
      dfs(curr, l + 1, r, restl - 1, restr);
      curr = curr.slice(0, curr.length - 1); // 这一步为回退状态，回溯的核心
    }
    if (restr > 0) {
      curr += ')';
      dfs(curr, l, r + 1, restl, restr - 1);
      curr = curr.slice(0, curr.length - 1); // 这一步为回退状态，回溯的核心
    }
  };
  dfs('', 0, 0, n, n);
  
  return ans;
};




