#include <iostream>
#include <string>
#include <vector>

using namespace std;

int CompareWord(const char a,const char b)
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
    int* score = new int[pages.size()];
    int* OutLink = new int[pages.size()];
    int* name = new int[pages.size()];
    string href = "href";

    for (int i = 0; i < pages.size(); i++)
    {
        score[i] = 0;
        OutLink[i] = 0;
    }

    for (int i = 0; i < pages.size(); i++)
    {
        for (int j = 0; j < pages[i].length(); j++)
        {
            if (CompareWord(word[0], pages[i][j]) && j + word.length() < pages[i].size())
            {
                for (int k = 0; k < word.length(); k++)
                {
                    if (!CompareWord(word[k],pages[i][j+k]))
                    {
                        break;
                    }
                    else if (k == word.length() - 1)
                    {
                        if (static_cast<int>(pages[i][j + k + 1]) > 64 && static_cast<int>(pages[i][j + k + 1]) < 91)
                        {
                            break;
                        }
                        else if (static_cast<int>(pages[i][j + k + 1]) > 96 && static_cast<int>(pages[i][j + k + 1]) < 123)
                        {
                            break;
                        }
                        score[i]++;
                    }
                }
            }
            if (href[0] == pages[i][j] && j + href.length() < pages[i].size())
            {
                for (int k = 0; k < href.length(); k++)
                {
                    if (href[k] != pages[i][j+k])
                    {
                        break;
                    }
                    else if (k == href.length() - 1)
                    {
                        OutLink[i]++;
                    }
                }
            }
        }
    }

    cout << "score : ";
    for (int i = 0; i < pages.size(); i++)
    {
        cout << score[i] << " ";
    }
    cout << endl;

    cout << "OutLink : ";
    for (int i = 0; i < pages.size(); i++)
    {
        cout << OutLink[i] << " ";
    }
    cout << endl;

    int answer = 0;

    delete score, name, OutLink;

    return answer;
}

int main()
{
    vector<string> pages = { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>" };
    solution("blind", pages);

    int j;
    cin >> j;
}