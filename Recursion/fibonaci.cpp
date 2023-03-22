#include <iostream>
using namespace std;

int getFib(int n) {

  //Base Condition
  if(n==0 || n==1)
  return n;

  //how to Optimise this, overlapping subproblems ??
  return getFib(n-1) + getFib(n-2);
 
}


int main() {
  
  int n;
  cout<<"Please Enter the Input"<<endl;
  cin>>n;
//Fib series -> 0,1,1,2,3,5,8,13,......
//0th fibonacci number is 0
//1st fibonacci number is 1
//2nd fibonacci number is 1
//3rd fibonacci number is 2 and so on 
  cout<<"Value of "<<n<<"th Fibonacci is " << getFib(n)<<endl;

}

