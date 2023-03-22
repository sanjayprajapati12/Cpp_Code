#include<bits/stdc++.h>
#define int long long
using namespace std;

int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// a>0 and b>0 (zero wale cases alag se handle karna)
bool find_any_solution(int a,int b,int c,int &x0 , int &y0 , int &g){
    g = extended_gcd(abs(a),abs(b),x0,y0);
    if(c%g){
        return false;
    }
    x0 *= (c/g);
    y0 *= (c/g);
    if(a<0){
        x0 *= -1LL;
    }
    if(b<0){
        y0 *= -1LL;
    }
    return true;
}

void shift(int &x , int &y , int a ,int b , int cnt ){
    x += cnt*b;
    y -= cnt*a;
}

int find_all_solution(int a,int b,int c ,int minx ,int maxx , int miny , int maxy){
    int x,y,g;
    if(!find_any_solution(a,b,c,x,y,g)){
        return 0;
    }
    a /= g;
    b /= g;
    int sign_a = a>0 ? +1LL : -1LL ;
    int sign_b = b>0 ? +1LL : -1LL ;
    
    shift(x,y,a,b,(minx-x)/b);
    if(x<minx){
        shift(x,y,a,b,sign_b);
    }
    if(x>maxx){
        return 0LL;
    }

    int lx1 = x;
    shift(x,y,a,b,(maxx-x)/b);
    if(x>maxx){
        shift(x,y,a,b,-1LL*sign_b);
    }
    int rx1 = x;

    shift(x,y,a,b,-(miny-y)/a);
    if(y<miny){
        shift(x,y,a,b,-1LL*sign_a);
    }
    if(y>maxy){
        return 0LL;
    }

    int lx2 = x;
    shift(x,y,a,b,-(maxy-y)/a);
    if(y>maxy){
        shift(x,y,a,b,sign_a);
    }
    int rx2 = x;

    if(lx2>rx2){
        swap(lx2,rx2);
    }
    int lx = max(lx1,lx2);
    int rx = min(rx1,rx2);

    if(lx>rx){
        return 0LL;
    }
    return (rx-lx)/abs(b) + 1;
}

int32_t main(){
    
    int a,b,c;
    // cin>>a>>b>>c;
    a = 9 ; 
    b = 15 ; 
    c = 6 ; 
    // equation -> ax + by = c;
    cout<<find_all_solution(a,b,c,0,19,-10,0)<<endl;
    // int x0 , y0 , g  ;

    // bool have = find_any_solution(a,b,c,x0,y0,g);
    // if(have==false){
    //     cout<<"No solution"<<endl;
    // }
    // else{
    //     cout<<"Equation have solution"<<endl;
    //     cout<<x0<<" "<<y0<<endl;
    //     cout<<"Gcd "<<g<<endl;
    // }
    return 0;
}