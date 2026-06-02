n=int(input())
def num(x):
    if x<0 or (x%10==0 and x!=0):
        return False
    half=0
    while  x>half:
        half=half*10+x%10
        x=x//x
    return half==x or x==half//10
str=num(n)
print(f"{str}")