#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll=long long int;
ll M=1e9+7;
template<typename T>
T binexpo(T a,T b){
    T ans=1;
    while(b>0){
        if(b&1){
            ans=(ans*1ll*a)%M;
        }
        a=(a*1ll*a)%M;
        b=b>>1;
    }
    return ans;
}
template<typename T>
T gcd(T a,T b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
template<typename T>
T binarysearch(vector<T>&vec,T low,T high,T target){
    while(low+1<high){
        T mid=(low+high)/2;
        if(vec[mid]==target){
            return mid;
        }
        else if(vec[mid]<target){
            low=mid;
        }
        else if(vec[mid]>target){
            high=mid;
        }
    }
    return -1;
}
map<ll,ll>dp;
ll count_bits(ll n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else if(dp[n]) return dp[n];
    else{
        if(n%2==0){
            dp[n]=count_bits(n/2-1)+count_bits(n/2)+n/2;
        }
        else if(n%2!=0){
            dp[n]=2*count_bits(n/2)+n/2+1;
        }
        return dp[n];
    }
}
int main(){
    ll n;
    cin>>n;
    cout<<count_bits(n)<<endl;
    return 0;
}
