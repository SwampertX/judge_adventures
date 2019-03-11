#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
int main(){
    mp::int1024_t n;
    while (std::cin>>n){
        mp::int1024_t res; res=n+1;
        if (n%3==0) res+=1;
        if ((n+1)%5==0) res+=2;
        if ((n+2)%7==0) res+=4;
        if ((n+3)%11==0) res+=8;
        if (n%3!=0 && (n+1)%5!=0 && (n+2)%7!=0 && (n+3)%11!=0) res+=16;
        std::cout<<res<<std::endl;
    }
    return 0;
}
