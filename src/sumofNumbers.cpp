#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    int N;
    string number;
    int sum=0;

    cin >> N;
    cin >> number;

   for(int i=0; i < number.length(); i++)
   {
        sum += number[i] -'0'; 
   }

    cout<<sum;
    
    return 0;
}