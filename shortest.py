n = int(input())
l = 1
r = 1

while r * r < n:
    l = r
    r *= 2
    
while l < r:
    m = (l + r) // 2
    if m * m < n:
        l = m + 1
    else:
        r = m
        
print(l)