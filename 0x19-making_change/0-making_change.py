#!/usr/bin/python3
''' Coin change problem '''


def makeChangeGreedy(coins, total):
    '''
    Classic Greedy algorithm problem
    This works only when coin denominations are
    optimal
    Time: O(nlogn)
    Space: O(1)
    '''
    if total < 1:
        return 0
    coins.sort(reverse=True)
    num_coins = 0
    for coin in coins:
        if total < 1:
            break
        res, remainder = divmod(total, coin)
        total = remainder
        num_coins += res
    return total == 0 and num_coins or -1


def makeChange(coins, total):
    '''
    Dynamic programming approach
    Time: O(total * len(coins))
    Space: O(total)
    '''
    if total <= 0:
        return 0
    dp = [0] + [total + 1] * total
    for coin in coins:
        for i in range(coin, total + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)
    return dp[total] if dp[total] != total + 1 else -1

