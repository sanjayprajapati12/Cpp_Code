#include <bits/stdc++.h>
using namespace std;

int exp(int a , int b)
{
    if (b == 0)
        return 1;
    int chotta_answer = exp(a,b / 2);

    //odd
    if (b & 1)
    {
        return (2 * chotta_answer * chotta_answer);
    }
    else
    {
        //even
        return (chotta_answer * chotta_answer);
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << a << " to the power of " << b << " is -> " << exp(a, b) << endl;
}
