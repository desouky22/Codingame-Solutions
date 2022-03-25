#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        long long f;
        cin >> f; cin.ignore();
        while (f%5==0 || f%3==0 || f%2==0 ){
            if (f%5==0) f/=5; 
            else if (f%3==0) f/=3; 
            else f/=2; 
        }
        if (f==1) cout<<"VICTORY"<<endl;
        else cout<<"DEFEAT"<<endl;
    }

}
