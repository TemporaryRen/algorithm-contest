class UnionFind:
    def __init__(self, point_count:int):
        self.root = [i for i in range(point_count)]
        self.point_count = point_count
        self.rank = [1] * point_count
    
    def union(self,x,y):
        xroot = self.find(x)
        yroot = self.find(y)
        if self.rank[xroot] < self.rank[yroot]:
            self.root[xroot] = self.root[yroot]
        else:
            self.root[yroot] = self.root[xroot]
            if self.rank[xroot] == self.rank[yroot]:
                self.rank[xroot] += 1


    def find(self,x):
        t = self.root[x]
        if t != x:
            r = self.find(t)
            self.root[x] = r
            return r
        else:
            return t

    def root_count(self):
        for i in range(self.point_count):
            self.find(i)
        return len(set(self.root))
    
