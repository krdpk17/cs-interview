
'''
Move n towers from A to B with the help of C
'''
class TowerOfHanoi:
    def __init__(self, n):
        self.n = n
    
    def moveRings(self, n, A,B,C):
        if(n == 0 or n == 1):
            return n
        steps = self.moveRings(n-1, A, C, B)
        steps += 1
        steps += self.moveRings(n-1, C, B, A)
        return steps
    def moveTowerOfHanoi(self):
        return self.moveRings(n, "A", "B", "C")
    
if(__name__ == "__main__"):
     n = 5
     th = TowerOfHanoi(n)
     steps = th.moveTowerOfHanoi()
     print("number of steps to move "+ str(n) + " rings is "+ str(steps))

    
    



            