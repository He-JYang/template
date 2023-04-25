#Problems Understanding

####AtCoder Beginner Contest 294
#####F
混合NxM杯糖水，求第K大

二分

check函数用上mid

对每一次check，计算达到mid这个浓度，混合前每杯糖水应该增加多少克糖，可以为负数
按增加糖的克数排序N,M 对于N中每一杯（假设这杯缺dx克糖达到mid浓度），在M中lower_bound(-dx)，多余糖在dx以上的和N中的这一杯混合，都能达到mid及以上浓度

####AtCoder Beginner Contest 295
#####E - Kth Number
给定一些数和一些随机数（取值范围均在1~M之间）求第K大的数学期望

数学

对于任何一个在1~M之间的概率变量X
$(\text{expected value of } X)= \sum\limits_{i = 1}^m (i × (\text{probability that }X = i ))= \sum\limits_{i=1}^m (\text{probability that }X ≥ i)$
自然语言描述该公式为：X的数学期望=X取每个值的概率乘以值求和=X比每个值的大的概率求和