// 提取子字符串
// substr() 函数用于从 string 字符串中提取子字符串，它的原型为：

//     string substr(size_t pos = 0, size_t len = npos) const;
// pos 为要提取的子字符串的起始下标，len 为要提取的子字符串的长度。

//字符串查找
//  1) find() 函数
// find() 函数用于在 string 字符串中查找子字符串出现的位置，它其中的两种原型为：

// size_t find (const string& str, size_t pos = 0) const;
//  size_t find(const char* s, size_t pos = 0) const;
//  第一个参数为待查找的子字符串，它可以是 string 字符串，也可以是C风格的字符串。第二个参数
//  为开始查找的位置（下标）；如果不指明，则从第0个字符开始查找。
// find() 函数最终返回的是子字符串第一次出现在字符串中的起始下标。

//  2) rfind() 函数
// rfind() 和 find() 很类似，同样是在字符串中查找子字符串，不同的是 find() 函数从第二个参数开始往后查找，
// 而 rfind() 函数则最多查找到第二个参数处，如果到了第二个参数所指定的下标还没有找到子字符串，则返回一个
// 无穷大值4294967295。