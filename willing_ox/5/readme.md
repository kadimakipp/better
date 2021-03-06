## 二叉树

树(Tree) 是n(n>=0)个结点的有限集合，当n=0时，为空树；n>0时，为非空树。任意一棵非空树，满足:
1. 有且仅有一个称之为跟的结点；
2. 除根结点以外的其余结点可分为m(m>0)个互不相交的有限集T1,T2,...Tm,其中每一个集合本身又是一棵树，并称为子树。

名词:
1. 结点的度，结点拥有的子树个子数。
2. 树的度，树中结点的最大度数。
3. 终端结点，度为0的结点，又称为叶子。
4. 分支结点，度大于0的结点。除了叶子都是分支结点。
5. 内部结点，除了树根和叶子都是内部结点。
6. 结点的层次，从跟到该结点的层数(跟结点为第1层)。
7. 树的深度(或高度)，指所有结点中最大的层数。
8. 森林，由m(m>=0)棵不相交的树组成的集合。
9. 路径，树中两个结点之间的所经过的结点序列。
10. 路径长度，两结点之间路径上经过的边数。

树的存储结构
采用顺序存储和链式存储两种形式。

![bit_tree](https://github.com/kadimakipp/better/blob/master/img/bit_tree.png)

顺序存储方式

![bit_tree_save_1](https://github.com/kadimakipp/better/blob/master/img/bit_tree_save_1.png)

链式存储方式

![bit_tree_save_2](https://github.com/kadimakipp/better/blob/master/img/bit_tree_save_2.png)

