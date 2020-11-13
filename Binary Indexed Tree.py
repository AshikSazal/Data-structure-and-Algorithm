def lsb(idx):
    return idx & (-idx)
def update(bit,node_idx,n,val):
    while(node_idx<=n):
        bit[node_idx]+=val
        # go to parent or bottom to top
        node_idx+=lsb(node_idx)
def get_sum(node_idx,bit):
    sum=0
    while node_idx>=1:
        sum+=bit[node_idx]
        node_idx-=lsb(node_idx)
    return sum
def create_bit(a,n):
    bit=[0]*(n+1)
    for i in range(1,n+1):
        update(bit,i,n,a[i])
    return bit
if __name__ == "__main__" :
    a=[0,1,2,3,4,5]
    n=len(a)-1
    bit=create_bit(a,n)
    upper_bit=4
    lower_bit=2
    print(get_sum(upper_bit,bit)-get_sum(lower_bit-1,bit))
    update(bit,1,n,9) # tree,index_no,size,value
    print(get_sum(upper_bit,bit)-get_sum(lower_bit-1,bit))
