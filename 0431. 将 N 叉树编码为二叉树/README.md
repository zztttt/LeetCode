设计一个算法，可以将 N 叉树编码为二叉树，并能将该二叉树解码为原 N 叉树。
一个 N 叉树是指每个节点都有不超过 N 个孩子节点的有根树。
类似地，一个二叉树是指每个节点都有不超过 2 个孩子节点的有根树。
你的编码 / 解码的算法的实现没有限制，你只需要保证一个 N 叉树可以编码为二叉树且该二叉树可以解码回原始 N 叉树即可。

例如，你可以将下面的 3-叉 树以该种方式编码：
![](https://img-blog.csdnimg.cn/20200811222610953.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzIxMjAxMjY3,size_16,color_FFFFFF,t_70)  


思路：
1. encode：对于每一个N叉树节点，左节点存孩子，右节点存兄弟
2. decode：对于每一个二叉树节点，从left 到left子树的rightmost，这一条就是原来的孩子们