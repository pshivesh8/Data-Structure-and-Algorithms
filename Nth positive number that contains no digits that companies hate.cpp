Problem:

Rastogi Ji observed an interesting pattern: Windows 10 came out right after Windows 8, Iphone X came right after Iphone 8. Seems like companies hate the digit 9! Like digit 9 is almost a 10 ,but not quite. He told this to professor Virus!

Enraged, prof Virus handed Rastogi Ji a list of digits which companies hate & will not use it in their product number. So in set of all natural numbers, remove all numbers that contains a digit that companies hate. Rastogi is asked to compute Nth number in this set or that he will be expelled from the College!

Rastogi is in immense pressure and is looking out for his Rancho in need, are you the one? Be wary, numbers can be bigger than ego of Virus!

Input
The first line will contain an integer d, the number of digits companies hate.
The second line will contain d distinct integers in increasing order, representing the digits companies hate. (These d digits will all be positive, 0 is never a digit that companies hate)
The third line will contain an integer N, as described in problem.

Constraints
1   ≤   d   ≤   8
1   ≤   N   ≤   10^18

Output
Output a single integer: the Nth positive number that contains no digits that companies hate.
Note that this number can have more than 18 digits

Example
Input
1
9
9
Output
10


Input
2
1 8
10
Output
23

Solution:

/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡖⠁⠀⠀⠀⠀⠀⠀⠈⢲⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣼⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣧⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣸⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⡇⠀⢀⣀⣤⣤⣤⣤⣀⡀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣔⢿⡿⠟⠛⠛⠻⢿⡿⣢⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣀⣤⣶⣾⣿⣿⣿⣷⣤⣀⡀⢀⣀⣤⣾⣿⣿⣿⣷⣶⣤⡀⠀⠀⠀⠀
⠀⠀⢠⣾⣿⡿⠿⠿⠿⣿⣿⣿⣿⡿⠏⠻⢿⣿⣿⣿⣿⠿⠿⠿⢿⣿⣷⡀⠀⠀
⠀⢠⡿⠋⠁⠀⠀⢸⣿⡇⠉⠻⣿⠇⠀⠀⠸⣿⡿⠋⢰⣿⡇⠀⠀⠈⠙⢿⡄⠀
⠀⡿⠁⠀⠀⠀⠀⠘⣿⣷⡀⠀⠰⣿⣶⣶⣿⡎⠀⢀⣾⣿⠇⠀⠀⠀⠀⠈⢿⠀
⠀⡇⠀⠀⠀⠀⠀⠀⠹⣿⣷⣄⠀⣿⣿⣿⣿⠀⣠⣾⣿⠏⠀⠀⠀⠀⠀⠀⢸⠀
⠀⠁⠀⠀⠀⠀⠀⠀⠀⠈⠻⢿⢇⣿⣿⣿⣿⡸⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠈⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠐⢤⣀⣀⢀⣀⣠⣴⣿⣿⠿⠋⠙⠿⣿⣿⣦⣄⣀⠀⠀⣀⡠⠂⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠉⠛⠛⠛⠛⠉⠀⠀⠀⠀⠀⠈⠉⠛⠛⠛⠛⠋⠁⠀⠀⠀
              pshivesh8⠀⠀
*/

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

string base(long long n, long long b){
    string x ="";
    queue<long long> s;
    while(n){
        s.push(n % b);
        n = n / b;
    }
    while(!s.empty()){
        x += to_string(s.front());
        s.pop();
    }
    reverse(x.begin(),x.end());
    return x;
}

string solve(vector<long long> a, long long n, long long xx){
    string x = base(xx, 10-n);
    unordered_map<long long,long long> mappingOfValues;
    long long ctr=0,ctr2=0;
    mappingOfValues[0]=0;
    long long i;
    for(i=0;i<10;i++)
    {
        if(a[ctr2]==i)
        {
            ctr2++;
            continue;
        }
        mappingOfValues[ctr]=i;
        ctr++;
    }
    string y ="";
    for(int i=0;i<(int)x.length();i++)
    {
        int val=(x[i])-'0';
        y += to_string(mappingOfValues[val%10]);
    }
    return y;
}

int main()
{
    fastio();
    long long n;
    cin>>n;
    vector<long long> a;
    for(long long i=0; i<n; i++){
        long long temp;
        cin>>temp;
        a.push_back(temp);
    }

    long long x;
    cin>>x;

    cout<<solve(a, n, x)<<endl;
    return 0;
}
