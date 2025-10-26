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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>vec1(n);
    for(int i=0;i<n;++i){
        cin>>vec1[i];
    }
    map<int,int>mp;
    vector<int>vec2(m);
    for(int i=0;i<m;++i){
        cin>>vec2[i];
        mp[vec2[i]]++;
    }
    sort(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end());
    int cnt_people=0;
    for(int i=0;i<n;++i){
        int min_size=vec1[i]-k;int max_size=vec1[i]+k;
        int low=-1;int high=m;
        while(low+1<high){
            int mid=(low+high)/2;
            if(vec2[mid]<min_size){
                low=mid;
            }
            else if(vec2[mid]>=min_size){
                if(mp[vec2[mid]]<=0){
                    low=mid;
                }
                else if(mp[vec2[mid]]>0){
                    high=mid;
                }
            }
        }
        if(high!=m){
            if(vec2[high]<=max_size){
            cnt_people++;
            mp[vec2[high]]--;
           }
        }
    }
    cout<<cnt_people<<endl;
    return 0;
}
