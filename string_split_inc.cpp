// Problem#: 14046
// Submission#: 3676048
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n; int o;
    string *p;
    p = new string[100];
    string sentence, sentence1;
    string temp;
    int k;
    cin >> n;
    int size[100];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        size[i] = sizeof(p[i]);
    }
    getline(cin, sentence);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <i; j++)
        {
            if (size[j] < size[j + 1])
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
                k = size[j];
                size[j] = size[j + 1];
                size[j + 1] = k;
            }
        }
    }
    sentence1.assign(sentence);
    k = 0;
    for (int i = 0; i < n; i++)
    {
        if (sentence1.find(p[i])>0 && sentence1.find(p[i]) < 100)
        {
            sentence1.erase(sizeof(p[i]), sentence1.find(p[i]));
            o = sentence.find(p[i]);
            sentence.insert(o, " ");
            k++;
        }
    }
    sentence1.assign(sentence);
    int a, b = 0;
    bool is = false;
    for (int i = 0; i <k; i++)
    {
        a = sentence1.find(" ", b);
        for (int j = 0; j < n; j++)
        {
            if (p[i].compare(b + 1, a - b, sentence1) == 0)
            {
                is = true;
                break;
            }
        }
        if (!is)
        {
            for (int j = b + 1; j < a; j++)
                sentence.insert(j, " ");
        }
        b = a;
    }
    cout << sentence << endl;
    return 0;

}            