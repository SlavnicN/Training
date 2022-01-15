

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