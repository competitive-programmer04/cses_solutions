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
int main(){
    int n;
    cin>>n;
    set<int>st;
    vector<int>vec(n);
    for(int i=0;i<n;++i){
        cin>>vec[i];
        st.insert(vec[i]);
    }
    cout<<st.size()<<endl;
}
