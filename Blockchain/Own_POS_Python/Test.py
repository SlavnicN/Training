from ProofOfStack import ProofOfStack
from Lot import Lot
import string
import random

def getRandomString(length):
    letters = string.ascii_lowercase
    randomString = ''.join(random.choice(letters) for i in range(length))
    return randomString 
    
if __name__ == '__main__':
    pos = ProofOfStack()
    pos.update('bob', 10)
    pos.update('alice', 100)

    bobWins = 0
    aliceWins = 0

    for i in range(10):
        forger = pos.forger(getRandomString(i))
        if forger == 'bob':
            bobWins += 1
        else:
            aliceWins += 1
    
    print('bob wins: ' + str(bobWins) + 'times')
    print('alcie wins: ' + str(aliceWins) + 'times')
