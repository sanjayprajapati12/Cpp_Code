#include<bits/stdc++.h>
using namespace std;

void getCounting(int n) {

  //Base Condition
  if(n<=0)
  return ;


  //subproblem or recursive call5
  getCounting(n-1);


  cout<<n<<endl;
  //Think, How to print the ascending counting ??  
}

int main() {
  
  int n;
  cout<<"Please Enter the Input"<<endl;
  cin>>n;

  cout<<"Counting: "<<endl ;
  getCounting(n);

}

