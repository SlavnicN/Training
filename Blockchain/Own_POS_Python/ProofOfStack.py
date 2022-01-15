from Lot import Lot
from BlockchainUtils import BlockchainUtils

class ProofOfStack():

    def __init__(self):
        self.stakers = {}

    def update(self, publicKeyString, stake):
        if publicKeyString in self.stakers.keys():
            self.stakers[publicKeyString] += stake
        else:
            self.stakers[publicKeyString] = stake
    
    def get(self, publicKeyString):
        if  publicKeyString in self.stakers.keys():
            return self.stakers[publicKeyString]
        return None

    def validatorLot(self, seed):
        lots = []
        for validator in self.stakers.keys():
            for stack in range(self.get(validator)):
                lots.append(Lot(validator, stack+1, seed))
        return lots

    def winnerLot(self, lots, seed):
        winnerLot = None
        leastOffset = None
        referenceHashIntValue = int(BlockchainUtils.hash(seed).hexdigest(), 16)
        print('This is the reference hash value: ', referenceHashIntValue)
        for lot in lots:
            lotIntValue = int(lot.lotHash(), 16)
            offset = abs(referenceHashIntValue - lotIntValue)
            if leastOffset is None or offset < leastOffset:
                leastOffset = offset
                winnerLot = lot
        print('This is the lot hash value: ', lotIntValue)
        print('This is the least offset: ', leastOffset)

        return winnerLot

    def forger(self, lastBlock):
        lots = self.validatorLot(lastBlock)
        winnerLot = self.winnerLot(lots, lastBlock)
        return winnerLot.publicKey