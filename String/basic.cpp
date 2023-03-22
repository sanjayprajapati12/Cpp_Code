#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// string has .push_back function like vector
int main(){
    
    // string str;
    // cin>>str;
    // cout<<str;

    // string str1="my name";
    // cout<<str1;

    // string str1(5,'n');
    // cout<<str1<<endl;

    // string str;
    // getline(cin,str);       // identify space and taking input according to it
    // cout<<str<<endl;

    // if we want to use above getline function in test-case  
    // int t;
    // cin>>t;
    // cin.ignore();
    // while(t--){
    //     string s;
    //     getline(cin,s);
    //     cout<<s<<endl;
    // }

    // string s1 = "fam";
    // string s2 = "ily";
    // s1.append(s2,0,);      //s1= s1 +s2 ; last one is excluded 
    // cout<<s1<<endl;


    // string str ="kjsg lghd akldsh";
    // str.clear();
    // cout<<str;

    // string s1 = "abc";
    // string s2 = "abc";

    // cout<<s2.compare(s1)<<endl; // if equal then retuen 0;

    string str = "nincompoop";
    // str.erase(3,3);  // index-3 se start hokar 3 char erase kar dega
    // cout<<str<<endl;;
    string s = "com";
    int i= str.find(s);
    cout<<i<<endl; // if not found then return -1
    // cout<<str.find("poop")<<endl;       // u can find char as well as string 
    // cout<<str.rfind('p')<<endl;         // reverse se find hoga
    
    // str.insert(2,"lol");
    // cout<<str.length();

    // string s1 = "nincompoop";
    // string s = s1.substr(6 ,4);
    // cout<<s<<endl;

    // string s2 = "2534";
    // int x = stoi(s2);
    // cout<<x+2<<endl;

    // int y = 234;
    // cout<< to_string(y) + "2"<<endl;

    // string s9 = "dslkdsbkjger";
    // sort(s9.begin() , s9.end());
    // cout<<s9;

return 0;
}