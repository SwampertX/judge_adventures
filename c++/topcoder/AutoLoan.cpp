#include <bits/stdc++.h>
using namespace std;
class AutoLoan
{
public:
    double interestRate(double price, double monthlyPay, int loanTerm)
    {
        double rate(0), intv(100000000), sum;
        while (intv>=1e-18)
        {
            sum = price * pow((1+rate/1200), loanTerm) - monthlyPay * 1200 * (pow((1+rate/1200), loanTerm) -1)/rate;
            if (sum<=0) rate+=intv;
            intv/=2;
        }
        return rate;
    }
};
int main()
{
    double price, monthlypay; int loanterm;
    cout.precision(20);
    AutoLoan a;
    while (cin>>price>>monthlypay>>loanterm)
        cout<<a.interestRate(price, monthlypay, loanterm)<<endl;
}
