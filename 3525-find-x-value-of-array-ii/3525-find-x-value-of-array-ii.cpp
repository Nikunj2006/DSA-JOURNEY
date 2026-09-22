class Solution {
public:
    struct Node{
        int prod,cnt[5];
        Node(){
            prod=1;
            for(int i=0;i<5;i++) cnt[i]=0;
        }
    };

    int k,n;
    vector<Node> seg;

    Node merge(Node a,Node b){
        Node c;
        c.prod=a.prod*b.prod%k;
        for(int i=0;i<k;i++) c.cnt[i]=a.cnt[i];
        for(int i=0;i<k;i++)
            c.cnt[a.prod*i%k]+=b.cnt[i];
        return c;
    }

    void build(int p,int l,int r,vector<int>& a){
        if(l==r){
            seg[p].prod=a[l]%k;
            seg[p].cnt[seg[p].prod]=1;
            return;
        }
        int m=(l+r)/2;
        build(p*2,l,m,a);
        build(p*2+1,m+1,r,a);
        seg[p]=merge(seg[p*2],seg[p*2+1]);
    }

    void update(int p,int l,int r,int idx,int val){
        if(l==r){
            seg[p]=Node();
            seg[p].prod=val%k;
            seg[p].cnt[seg[p].prod]=1;
            return;
        }
        int m=(l+r)/2;
        if(idx<=m) update(p*2,l,m,idx,val);
        else update(p*2+1,m+1,r,idx,val);
        seg[p]=merge(seg[p*2],seg[p*2+1]);
    }

    Node query(int p,int l,int r,int ql){
        if(l>=ql) return seg[p];
        int m=(l+r)/2;
        if(ql<=m){
            Node a=query(p*2,l,m,ql);
            if(ql>m) return a;
            Node b=query(p*2+1,m+1,r,ql);
            return merge(a,b);
        }
        return query(p*2+1,m+1,r,ql);
    }

    vector<int> resultArray(vector<int>& nums,int K,vector<vector<int>>& queries){
        k=K;
        n=nums.size();
        seg.resize(4*n+5);
        build(1,0,n-1,nums);

        vector<int> ans;
        for(auto &q:queries){
            update(1,0,n-1,q[0],q[1]);
            Node x=query(1,0,n-1,q[2]);
            ans.push_back(x.cnt[q[3]]);
        }
        return ans;
    }
};