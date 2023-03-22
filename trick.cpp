#include <bits/stdc++.h>
#define ll long long
using namespace std;

// a+b = (a|b) + (a&b) = (a^b) + 2*(a&b)

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int find_set_bit(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

char set_to_lowercase(char c)
{
    return c^32;
}

char set_to_upercase(char c)
{
    return c^32;
}

bool check_power_of_two(int n)
{
    return !(n & (n - 1));
}

void swap(int &a , int &b){
    a = a^b;
    b = b^a;
    a = a^b;
}

int main()
{
    // int arr[] = {2, 3, 5, 8, 6, 8, 5};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // cout<<n<<endl;

    // cout << find_set_bit(6) << endl;

    // char A = 'A';
    // char a = 'a';
    // cout << set_to_lowercase(A)<<endl;
    // cout << set_to_upercase(a)<<endl;

    // // power of two
    // if(check_power_of_two(30))
    //     cout<<"yes"<<endl;
    // else cout<<"no"<<endl;
    
    // // No. of digits
    // int n = 3654;
    // int c= log10(n)+1;
    // cout<<c<<endl;
    
    // swap the numbers
    // int q= 4;
    // int p=10;
    // swap(p,q);
    // cout<<p<<" "<<q<<endl;
   
    // v[1,3,4,7] then maik pair {1,3},{3,4},{4,7},{7,1}
    // for(int i = 0; i < v.size(); i++)
	// {
	// 	int u = v[i];
	// 	int v = v[(i + 1) % v.size()];				
	// }
    
    float z = 1.245;       
    cout <<  setprecision(10) << z <<endl;

    // how to find digit after decimal --> https://codeforces.com/contest/900/problem/B
    // how to compare ai/bi where i is from [1,n] with the help of --> https://codeforces.com/problemset/problem/1133/D
    
    // rightmost setbit position
    // 12 = 1100 return 3;
    int n = 12;
    int k = log2(n & -n) + 1;
    cout<<k<<endl;
    return 0;
}


// iterate over mask with k set bit

// for(int mask = (1 << k) - 1; mask < (1 << n); ) {
// 	if (mask == 0) break;
// 	int x = mask & -mask;
//     int y = mask + x;
//     cout<<mask<<endl;
// 	mask = (( (mask & ~y) / x ) >> 1) | y;
// }