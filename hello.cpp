#include<iostream>
#include<string>
using namespace std;
int main(void)
{
    
    //
    cout <<"1) hello c++"<< endl;  //Comment out << << end line(回车同\n)
    
    //
    cout <<"2) Output Number"<<"please input a number: \n";
    int input;
    cin >> input;
    cout <<"Inputed " <<input <<endl;

    //
    cout <<"3) Output String\n" <<"input string: " <<endl;
    string a;
    cin >>a;
    cout <<"inputed string is: " <<a <<endl;
    
    //
    cout <<"4) calculate sum of two numbers\n"
         <<"input two numbers" <<endl;
    float b,c;
    cin >>b >>c;
    cout <<b+c <<endl;
    cout <<b/c <<endl; 
    
    //
    cout <<"5) getline" <<endl;
    string first_name, second_name;
    getline(cin, first_name, '\n');
    getline(cin, second_name, '\n');
    cout << first_name <<" " <<second_name <<endl;
    
    //
    cout <<"6) Verify Password part1\n" 
         <<"Enter your password: " <<endl;
    string password;
    getline(cin, password, '\n');
    if (password != "Schrodington")
    {
        cout << "You inputted invalid password and try again" << "\n";
    }
    else cout << "Access allowed" <<endl;
    
    //
    cout <<"7) Verify Password part2\n" 
         <<"Enter your password: " <<endl;
    string password1;  
    int i=0;
    while (1)
    {
        getline(cin, password1, '\n');
        if (password1 != "Schrodington")
        {
            i++;
            if (i>4)
            {
                cout <<"System has been locked" <<endl;
                break;
            }
            cout << "You inputted invalid password, please try again:" << "\n";
        }
        else {cout << "Access allowed" <<endl; break;}
    }
    
    //
    cout <<"8) Summation of Input Number\n" <<"Please input number: \n" <<endl;
    int sum=0,num;
    cin >> num;
    while(num!=0)
    {
        sum+=num;
        cin >> num;
    }
    cout <<"Sum = " <<sum <<endl;
    

    system("pause");
    return 0;
}