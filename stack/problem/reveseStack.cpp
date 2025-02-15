#include <iostream>
#include<stack>
using namespace std;

int main() {
     string  str = "shrawan";
    stack <char> c;
    
      for(int i=0 ;i<str.length();i++){
           char ch = str[i];
           c.push(ch);
            
      }
       string ans = "";
      while(!c.empty()){
        char ch = c.top();
         ans.push_back(ch);
         c.pop();
      }
      
      cout<<"ans->"<<ans;


    return 0;
}
