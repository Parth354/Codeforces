#include<iostream>
#include<vector>
using namespace std;

class Seg{
    int n;
    vector<int> seg;
    public:
    Seg(int n){
        this->n = n;
        seg.assign(4*n +4 ,0);
        build(1,1,n);
    }
    void build(int i , int l , int r){
        if( l == r ){
            seg[i] = l ;
            return;
        }
        int mid =  l + (r -l)/2;
        build(i<<1 , l , mid);
        build(i<<1|1 , mid+1 , r);
        seg[i] = min(seg[i<<1] , seg[i<<1|1]);
    }
    int query(int i , int l , int r , int ql , int qr){
        if(l > qr || r < ql) return n+1;
        if(ql <=  l && qr >= r) return seg[i];
        int mid = l + (r-l)/2;
        return min(query(i<<1,l,mid,ql,qr) , query(i<<1|1 , mid+1 , r ,ql ,qr));
    }
    int query(int l , int r){
        if(l>r) return n+1;
        return query(1,1,n,l,r);
    }
    void update(int i ,int ui, int l , int r , int val){
        if(l == r ){
            seg[i] = val;
            return;
        }
        int mid = l + (r-l)/2;
        if(ui <= mid ) update(i<<1 , ui , l , mid , val);
        else update(i<<1 | 1 , ui , mid +1 , r ,val );
        seg[i] = min(seg[i<<1] , seg[i<<1|1]);
    }
    void remove(int i){
        update(1, i , 1, n , n+1);
    }
};

int main(){
    int n , m;
    cin >>n >>m;
    Seg s(n);
    vector<int> ans(n+1,0);
    for(int i = 0 ; i < m ; i++) {
        int l , r ,x;
        cin>>l>>r>>x;
        int cur = s.query(l,r);
        while(cur <= r){
            if(cur == x ){
                cur = s.query(cur+1, r);
                continue;
            }
            ans[cur] = x;
            s.remove(cur);
            cur= s.query(cur+1, r);
        }
    }
    for(int i = 1 ; i <= n ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}