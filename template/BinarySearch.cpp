const int n=100;
int a[n];
//[l, r) 中找第一个x，没有返回-1
//如果要找到最后一个x, 写成:(这时返回的l是最大编号+1)
//if(a[mid]<=x) l=mid+1;
//else r=mid;
int find(int x){
    int l=1, r=n+1;
    while(l<r){
        int mid = l + (r-l)/2;
        if(a[mid]>=x) r=mid;
        else l=mid+1;
    }
    if(a[l]==x) return l;
    else return -1;
}