//计算给定范围内质因数之和为质数的数，并列出，说明共有多少个
//一个数可分为几个不同的质因数的乘积，如：10=2×5；90=2×3×3×5
//主要思想：（1）将获得的数先迭代除以最小质因数2，所得的商再迭代除以从2到商的范围内的次小质因数，
//         依此类推，直到从2到所得商的范围内不再有质数；（2）将每个质因数与其相应的迭代次数相乘并求和得质因数之和；
//         （3）验证质因数之和是否是质数，是质数则输出原数及其质因数之和，并累积个数。
#include<iostream>

using namespace std;

bool Prime(int f) //布尔函数，判断质因数之和是否为质数
{
    int i;
    for (i=2;i<f;i++) //寻找2到sum范围内sum的因数
    {
        if(f%i==0) //若sum被因数i整除则sum不是质数
            break; //跳出循环
    }
    if (i<f) return false; //存在小于sum的因数，则返回“假”
    else return true; //否则返回“真”
}

int* Prime_factor_sum(int N) //质因数求和，并判定；
{
    int k;
    int *a;
    a=new int [2];
    int sum=0;
    if (N%2==0) //当原数能被最小质数2整除时
    {
        int n=N; //原数赋值给n
        for(k=2;k<n;k++) //寻找2到原数范围内n的因数
        {
            if (n%k==0) //如果有因数k能将n整除
                while(n%k==0) //迭代求商，余数不为0时退出循环，k++重新寻找新余数
                {
                    n=n/k; //求商并将商赋予n
                    sum+=k; //每迭代求商一次，将因数k加入sum
                }
        }
        sum+=n;
    }
    else sum=0; //k不能被最小质数整除时，和为0；

    if (Prime(sum)) //判定“sum是质数”是否为真
        a[0]=N,a[1]=sum; //若为真返回第一项为原数，第二项为质因数之和的数组a[i]
    else 
        a[0]=a[1]=0; //否则返回0数组
    return a;
}

void output_sum_Prime(int num) //输出质因数之和为质数的原数及和数；
{
    int j=2,l=0;
    int *b;
    cout <<"Number and sum of primefactor" <<endl;
    while(1)
    {
        b=Prime_factor_sum(j);  //调用质因数求和函数
        if(b[0]!=0&&b[1]!=0) //数组为0时，即原数质因数之和不是质数，则不输出
        {
            cout <<b[0] <<" " <<b[1] <<endl;
            l++; //累加输出个数
        }
        j++; //累加判定次数
        if (j==num) break; //次数等于范围值时，跳出循环
    }
    cout <<"There are (" <<l <<") numbers in total" <<endl;
}

int main(void)
{
    int Number;
    cout <<"Please input range" <<endl;
    cin >>Number;
    output_sum_Prime(Number);

    system("pause");
    return 0;
}