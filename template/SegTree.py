class SegTree:
    def __init__(self,n,initial,merge_operation):
        self.len = n
        self.initial = initial
        self.array = [initial] * (n << 2)
        self.lazy = [initial] * (n << 2)
        self.merge_operation = merge_operation

    def update(self,p,L,R,l,r,v):
        st = self.array
        if l<=L and r>=R:
            st[p] = v
            self.lazy[p] = v
        else:
            t = self.lazy[p]
            if t != self.initial:
                st[p<<1] = self.merge_operation(t,st[p<<1])
                st[p<<1|1] = self.merge_operation(t,st[p<<1|1])
                self.lazy[p] = self.initial
                self.lazy[p<<1] = self.lazy[p<<1|1] = t
            mid = L + (R - L) // 2
            if l<=mid:
                self.update(p<<1,L,mid,l,r,v)
            if r>mid:
                self.update(p<<1|1,mid+1,R,l,r,v)
            st[p] = self.merge_operation(st[p<<1],st[p<<1|1])
    
    def query(self,p,L,R,l,r):
        st = self.array
        if l<=L and r>=R:
            return st[p]
        else:
            t = self.lazy[p]
            if t != self.initial:
                st[p<<1] = self.merge_operation(t,st[p<<1])
                st[p<<1|1] = self.merge_operation(t,st[p<<1|1])
                self.lazy[p] = self.initial
                self.lazy[p<<1] = self.lazy[p<<1|1] = t
            res = self.initial
            mid = L + (R - L) // 2
            if l <= mid:
                res = self.merge_operation(res,self.query(p<<1,L,mid,l,r))
            if r > mid:
                res = self.merge_operation(res,self.query(p<<1|1,mid+1,R,l,r))
            return res
            
    def query_pos(self,p):
        return self.array[p]