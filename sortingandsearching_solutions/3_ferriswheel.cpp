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
    ll n,w;
    cin>>n>>w;
    vector<ll>vec(n);
    for(ll i=0;i<n;++i){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    // vector<ll>prefix_sum(n+1,0ll);
    // for(ll i=0;i<n;++i){
    //     prefix_sum[i+1]=prefix_sum[i]+vec[i];
    // }
    ll cnt_gondola=0;
    // ll prev_idx=0;
    // while(prev_idx+1<=n){
    //     ll low=prev_idx;ll high=n+1;
    //     while(low+1<high){
    //         ll mid=(low+high)/2;
    //         if(prefix_sum[mid]-prefix_sum[prev_idx]<=w){
    //             low=mid;
    //         }
    //         else if(prefix_sum[mid]-prefix_sum[prev_idx]>w){
    //             high=mid;
    //         }
    //     }
    //     cnt_gondola++;
    //     prev_idx=low;
    // }
    ll low=0;ll high=n-1;
    while(low<=high){
        if(low==high){
            cnt_gondola++;
            low++;high--;
        }
        else{
            if(vec[low]+vec[high]<=w){
                cnt_gondola++;
                low++;high--;
            }
            else if(vec[low]+vec[high]>w){
                cnt_gondola++;high--;
            }
        }
    }
    cout<<cnt_gondola<<endl;
    return 0;
}
