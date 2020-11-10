# Ascending Order
def binary(nums,x):
    low=0
    high=len(nums)-1
    while(low<=high):
        mid=(low+high)//2
        if x==nums[mid]:
            return mid
        elif x<=nums[mid]:
            high=mid-1
        else:
            low=mid+1
            
print(binary([1,3,5,6,8,14,16],3))

# Descending Order
def binary(nums,x):
    low=0
    high=len(nums)-1
    while(low<=high):
        mid=(low+high)//2
        if x==nums[mid]:
            return mid
        elif x<nums[mid]:
            low=mid+1
        else:
            high=mid-1
            
print(binary([9,7,6,3,2,1],7))
