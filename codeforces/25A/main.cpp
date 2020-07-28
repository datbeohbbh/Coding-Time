#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>

using namespace std;

int main()
{
    char *p, *str,*h;
    p = new char[20];
    str = new char[20];
    h = new char[20];

    cout<<"nhap chuoi :" << endl;
    cin.getline(str,20);

    cout << "phan ban chon la :" << endl;
    cin.getline(h,20);

    p = strstr(str, h);

    cout << "chuoi ban chon la" << p << endl;
    cout << "vi tri tim thay : " << p - str;
    return 0;
}
