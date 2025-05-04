#Expression for opt(8):
#where opt(n) returns the smallest number of combinations of coins
#opt(8) = opt(8 - denom[i]) + 1
# --> opt(7) or opt(4) = 1 or opt(3) = 3

#while coin <= target
#min(opt[target - one of the coin] + 1)


denom = [1,4,5]

def OPT(target, denom):
    OPT = [float('inf')] * (target + 1)
    OPT[0] = 0
    
    for cur in range (target + 1):
        for coin in denom:
            if coin <= cur:
                OPT[cur] = min(OPT[cur], OPT[cur - coin] + 1)
    return OPT
                
def backtrack(target,denom):
    OPT1 = OPT(target, denom)
    coinUsed = []
    n = target
    
    while n > 0:
        for coin in denom:
            if (n >= coin and OPT1[n] == OPT1[n - coin] + 1):
                coinUsed.append(coin)
                n -= coin
                break
                  
    return coinUsed

print(OPT(8,denom))
print(backtrack(12 ,denom))
    