#include <iostream>

using namespace std;

double binpow (double a, int n){
   if (n<0) return 1/binpow(a, -n);
   if (n==0) return 1;
   if (n%2==0) return binpow(a, n/2)*binpow(a, n/2);
   return a*binpow(a, (n-1)/2);

}

int eller (int n){
   if (n==1) return 1;
   int t=2;
   for (; t*t<(n+1); t++){
    int p=0;
    while(n%t==0){
        n/=t;
        p++;
    }
    if (p>0) return binpow(t,p-1)*eller(n)*eller(t);
   }
   return n-1;
}

int main()
{
    int n;
    cin >> n;
    n=eller(n);
    cout << n;
    return 0;
}
