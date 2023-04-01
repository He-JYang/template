#Problems Understanding

####AtCoder Beginner Contest 294
#####F
混合NxM杯糖水，求第K大

二分

check函数用上mid

对每一次check，计算达到mid这个浓度，混合前每杯糖水应该增加多少克糖，可以为负数
按增加糖的克数排序N,M 对于N中每一杯（假设这杯缺dx克糖达到mid浓度），在M中lower_bound(-dx)，多余糖在dx以上的和N中的这一杯混合，都能达到mid及以上浓度
