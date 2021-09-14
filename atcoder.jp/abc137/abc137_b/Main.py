K,Y = map(int, input().split())

x = Y-K+1

for i in range(K*2-1):
    print(x,end=" ")
    x += 1;
