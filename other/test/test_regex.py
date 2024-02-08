import re

# 定义正则表达式模式
pattern = r'[a-z](?![bc])'

# 要匹配的字符串
text = "bca quick brown fox jumps over the lazy dog"

# 使用re模块进行匹配
matches = re.findall(pattern, text)
print(matches[0])