//*------将数组元素从首位起每位元素作为节点创建二叉树------*//
#include<iostream>
#include<ctime>

using namespace std;

struct node{               //二叉树节点结构体
    int key_value;         //节点值
    node *p_left;          //递归建立树父节点的左，右子树指针
    node *p_right;
};

node *insert(node *p_tree, int key)
{
    if (p_tree==NULL)  //若树为空，则新建树
    {
        node *p_new_tree=new node;  //为结构体动态分配内存
        p_new_tree->p_left=NULL; //左，右子节点初始化为空
        p_new_tree->p_right=NULL;
        p_new_tree->key_value=key;  //节点值为输入值key
        return p_new_tree;  //返回树
    }
    if(key<p_tree->key_value)  //若新输入值小于当前树的节点值
    {
        p_tree->p_left=insert(p_tree->p_left, key);  //在当前树左侧新建以输入值为节点的新子树
    }
    else                       //若新输入值大于当前树的节点值
    {
        p_tree->p_right=insert(p_tree->p_right, key);  //在当前树右侧新建以输入值为节点的新子树
    }
    return p_tree;  //返回树
}

int *node_number(int n) //创建用户定义大小的随机数数组
{
    int *a=new int[n];  //动态分配内存
    cout <<"a[]={";
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%20;
        cout <<a[i] <<" ";  //创建随机数元素并输出
    }
    cout <<"}" <<endl;
    return (a+n-1); //返回数组末位指针
}

/*------将随机数数组元素创建为二叉树------*/
node *build_tree2(int b[], int size)  //创建二叉树 build_tree2
{
    if (size==0)
    {
        cout <<b[size] <<endl;
        insert(NULL, b[size]);
    }
    else
    {
        cout <<*b  <<" ";  //倒序排列
        insert(build_tree2(b-1,size-1),*b);
    }
}

/*------将指定数组元素创建为二叉树------*/
node *build_tree1(int a[], int m)  //结构体函数 build_tree1，输入为数组末指针和数组末位索引号
{
    if (m==0)  //索引号为0时，即递归至数组首位时
    {
        cout <<a[m] <<endl;
        insert(NULL, a[m]);  //新建二叉树，将a[0]作为父节点
    }
    else  //索引号不为0时，向数组首位递归
    {
        cout <<*a <<" ";
        insert(build_tree1(a-1,m-1),*a); //采用递归方法，将前一位指针(a-1)及前一位索引(m-1)输入递归调用 build_tree1，同时将当前位置元素(*a)插入节点
    }
}

int main(void)
{
    //Project 1
    //将指定数组元素作为节点创建为二叉树
    int array[]={10,8,5};
    int l=3;
    cout <<array[3] <<endl;  //-----l=3在栈中的存储位置？array[3]=3-----//
    cout <<"array[]={" <<array[l-1] <<", "<<array[l-2] <<", "<<array[l-3] <<"}" <<endl; //显示数组array[]={10,8,5}
    cout <<"Build binary-tree1" <<endl; //建立二叉树 binary-tree1
    build_tree1(array+l-1, l-1);  //调用函数 binary-tree1，输入为数组末位指针及末位索引号

    //Project 2
    //创建随机数组，并将其元素创建为二叉树
    srand(time(NULL));  //产生随机数种子
    int n;
    cout <<"Input amount: ";
    cin >>n;  //用户定义数组大小，即数组元素数量
    cout <<"Build binary-tree2" <<endl;  //创建二叉树 binary-tree2
    build_tree2(node_number(n), n-1);  //调用 node_number 创建数组并显示，调用 build_tree2 将数组元素作为节点建立二叉树 build_tree2
    
    system("pause");
    return 0;
}