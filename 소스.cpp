#include <iostream>
#include <string>
#include <vector>

using namespace std;

int CompareWord(char a,char b)
{
    int a_num = static_cast<int>(a);
    int b_num = static_cast<int>(b);
    if (a_num >= 97 && b_num <= 90)
    {
        a_num -= 32;
    }
    else if (a_num <= 90 && b_num >= 97)
    {
        b_num -= 32;
    }
    if (a_num == b_num)
    {
        return 1;
    }
    else if (a_num != b_num)
    {
        return 0;
    }
}

int solution(string word, vector<string> pages) 
{
    int answer = 0;
    return answer;
}

int main()
{
    string a = "a";
    int b = static_cast<int>(a[0]);
    b -= 32;
    a[0] = static_cast<char>(b);
    cout << a;
    int j;
    cin >> j;
}