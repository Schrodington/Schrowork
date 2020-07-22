#include <iostream>
#include <string>
using namespace std;
void verify(string password1)
{
    int i=0;  //初始化输入次数i
    while (1) //进入循环
    {
        getline(cin, password1, '\n'); //获得密码
        if (password1!="Schrodington") //若密码不正确
        {
            i++; //次数+1
            if (i>4) //超过5次停止循环，锁定系统
            {
                cout <<"System has been locked" <<endl;
                break;
            }
            cout <<"Invalid Password!(" <<5-i <<")times left" <<endl; //输出错误以及剩下的次数
        }        
        else //若密码正确
        {
            cout <<"Accessfull" <<endl; //显示正确
            break; //跳出循环
        }
    }   
}

int main(void)
{
    string password; //定义密码字符串
    cout <<"Enter password" <<endl;
    verify (password);

    system("pause");
    return 0;
}