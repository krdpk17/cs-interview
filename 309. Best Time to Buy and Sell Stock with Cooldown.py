# Code works. Memoziation works. But timeout happens at 208/210 test case
class Solution(object):
    def currTransaction(self, prices, state, trans_amt, index, dp):
        if(index >= len(prices)):
            return trans_amt
        if (index,trans_amt, state) in dp:
            #print(index, trans_amt, state) 
            return dp[(index,trans_amt, state)] 
        if(state == 0): # buy
            trans_val_with = self.currTransaction(prices, 1, trans_amt - prices[index], index + 1, dp)
            trans_val_without = self.currTransaction(prices, 0, trans_amt, index + 1, dp)
            dp[(index,trans_amt, state)] = max(trans_val_with, trans_val_without)
        elif(state == 1): # Sell
            trans_val_with = self.currTransaction(prices, 2, trans_amt + prices[index], index + 1, dp)
            trans_val_without = self.currTransaction(prices, 1, trans_amt, index + 1, dp)
            dp[(index,trans_amt, state)] = max(trans_val_with, trans_val_without)
        else: # cooldown
            dp[(index,trans_amt, state)] = self.currTransaction(prices, 0, trans_amt, index + 1, dp)       

        return dp[(index,trans_amt, state)]

    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        buy = 0
        sell = 1
        cooldown = 2
        dp = {}
        return self.currTransaction(prices, 0, 0, 0, dp)
        
