/*
设变量name_index为name的下标，typed_index为typed的下标，两者都从零开始。以name为基准遍历。分两种情况。当name当前下标的字符与下一个下标的字符不相等时，判断typed当前下标的字符是否相等，并将typed的下标右移到下一个不同字符的前一个下标；当name当前下标的字符与下一个相同时，比较后typed的下标不进行右移。遍历到name结束。
口齿不清，敬请谅解！
*/
bool isLongPressedName(char * name, char * typed){
    int name_index=0,typed_index=0;
    while(name[name_index]!=0){
        if(name[name_index+1]!=name[name_index]){
            if(typed[typed_index]!=name[name_index]) return 0;
            while(typed[typed_index+1]==name[name_index]) typed_index++;
        }
        else if(typed[typed_index]!=name[name_index]) return 0;
        typed_index++;
        name_index++;
    }
    return 1;
}

你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。

你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。

 

示例 1：

输入：name = "alex", typed = "aaleex"
输出：true
解释：'alex' 中的 'a' 和 'e' 被长按。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/long-pressed-name
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。