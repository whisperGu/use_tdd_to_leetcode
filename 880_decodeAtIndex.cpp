
880. 索引处的解码字符串
难度
中等

74

给定一个编码字符串 S。为了找出解码字符串并将其写入磁带，从编码字符串中每次读取一个字符，并采取以下步骤：
如果所读的字符是字母，则将该字母写在磁带上。
如果所读的字符是数字（例如 d），则整个当前磁带总共会被重复写 d-1 次。
现在，对于给定的编码字符串 S 和索引 K，查找并返回解码字符串中的第 K 个字母。

class Solution {
public:
	string decodeAtIndex(string S, int K) {
		unsigned long len = 0;
		int i = 0, strSize = S.size();
		while (i < strSize) {
            //遇到了字母，长度自增1
			while (i < strSize && S[i] >= 'a' && S[i] <= 'z') {
				++i;
				++len;
			}
            //遇到了数字d，扩大为原来的d倍
			while (i < strSize && S[i] >= '2' && S[i] <= '9') {
				len *= (S[i++] - '0');
			}
		}
		i = strSize - 1;
        //从后往前扫描S串
		while (true) {
            K %= len;//更新K
            if (K == 0 && S[i] >= 'a' && S[i] <= 'z'){
                //出口，此时所寻找的字符就是S[0, i]这一段的尾端非字母字符
                return string(1, S[i]);
            }
			else if (S[i] >= '2' && S[i] <= '9') {
                //遇到了数字d，缩小为原来的d分子一
				len /= (S[i] - '0');
			}
			else {
                //否则遇到了字母，len自减
				--len;
			}
			--i;
		}
	}
};

