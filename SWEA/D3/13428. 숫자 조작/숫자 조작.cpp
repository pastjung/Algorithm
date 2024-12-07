#include <iostream>
using namespace std;
#include <cmath>
 
string str;
int num, minimum, Maximum;
 
void change() {
    num = 0;
    for (int i = 0; i < str.length(); i++) {
        num += (str[i] - '0') * pow(10, str.length() - 1 - i);
    }
}
 
void solve(int t)
{
    cin >> str;
    change();
    minimum = num;
    Maximum = num;
 
    for (int i = 0; i < str.length() - 1; i++) {
        for (int j = i; j < str.length(); j++) {
            if (i != 0 || str[j] != '0') {
                swap(str[i], str[j]);
                change();
                if (num > Maximum)
                    Maximum = num;
                if (num < minimum)
                    minimum = num;
                swap(str[i], str[j]);
            }
        }
    }
 
    cout << "#" << t << " " << minimum << " " << Maximum << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        solve(t);
    }
    return 0;
}