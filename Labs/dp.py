def computeOPT(coins, n):
    OPT = [float('inf')]*(n+1)
    OPT[0] = 0
    
    for main in range(1,n+1):
        for coin in coins:
            if main >= coin:
                OPT[main] = min(OPT[main], OPT[main - coin] + 1)
    
    return OPT          

def backtracked(coins,n):
    OPT = computeOPT(coins, n)  #compute OPT tabnle  
    target = n
    res = []
    
    while target > 0:
        for curcoin in coins:
            if target >= curcoin and OPT[target] - 1 == OPT[target - curcoin]:
                res.append(curcoin)
                target -= curcoin
                break
    
    return res  

def canBeSegmented(s,wordDict):
    n = len(s)
    dp = [False] * (n + 1)
    dp[0] = True
    
    for i in range(1 , n + 1):
        for word in wordDict:
            if i >= len(word) and dp [i - len(word)] and s[i - len(word): i] == word:
                dp[i] = True
                break
            
    return dp[n]

coins = [1,4,5]
print (computeOPT(coins, 8))
print (backtracked(coins, 8))
s1 = "applepenapple"
wordDict1 = ["app", "apple", "pen"]
print(canBeSegmented(s1, wordDict1))  # True

s2 = "catsandog"
wordDict2 = ["cats", "dog", "sand", "and", "cat"]
print(canBeSegmented(s2, wordDict2))  # False