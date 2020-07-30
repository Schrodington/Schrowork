// 输出123456789987654321
#include<iostream>
#include<ctime>
#include<cstdlib>
//#include<math.h>
using namespace std;
/*void printNum(int num)
{
    cout <<num;
    if (num<9)
    {
        printNum(num+1);
    }
    cout <<num;
}*/

/*int power(int a, int b)
{
    int powerresult;
    if(b==1)
        powerresult=a;
    else
        powerresult=a*power(a,b-1);
    return powerresult;
}*/


int outputarray(int array[])   //倒序输出函数
{
    if (*(array)=='/0')   //若此项是结束字符则显示准备开始递归输出
        cout <<"Inverted Order: " <<endl;
    else
    {
        cout <<outputarray(array+1) <<" ";  /*----若数组未结束则继续寻找末尾项----*/
    }
    return *(array-1);   //此时array指向数组的最后一项，因此从导数第二项开始注意返回并显示数组的每一项直到第一项 
}

int main(void)
{
    //printNum(1);
    //int x,y;
    //cout <<"Input value of x and y: " <<endl;
    //cin >> x >> y;
    //cout <<power(x, y) <<endl;
    int n=11;  //定义一个随机数数组，最后一项为结束字符'/0'
    srand(time(NULL));
    int *array=new int[n];
    array[n]='/0';
    for (int i=0;i<n;i++)
    {
        array[i]=rand()%50;    //给数组的前10项赋值随机数
        cout <<array[i] <<" ";
    }
    cout <<endl;
    outputarray(array);    //执行倒序输出函数
    cout <<endl;

    system("pause");
    return 0;
}