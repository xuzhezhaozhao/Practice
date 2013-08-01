破解数独游戏
===========

看到CSDN上有位大神用C#写了一个破解数独的程序（[点击打开链接](http://blog.csdn.net/sq_zhuyi/article/details/7717324)），不过我对C#也不懂，比较喜欢C++，就用标准C++也写了一个，希望各位喜欢。三纯程序，纯控制台程序，纯各人爱好，纯算法程序，无win API。基本思路与之前那个类似，采用brute force加剪枝，找到第一个符合条件的情况就立即退出不再查找。一般一个合格的数独只有唯一解，如果你的数独多解的话，那也就不叫数独了。

[点击查看CSDN博客](http://blog.csdn.net/xzz_hust/article/details/9673777)。