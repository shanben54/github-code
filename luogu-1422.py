n=int(input())
sum=0
if n<=150:
    sum=n*0.4463
elif n<=400:
    sum=150*0.4463+(n-150)*0.4663
else:
    sum=150*0.4463+250*0.4663+(n-400)*0.5663
print(f"{sum:.1f}")