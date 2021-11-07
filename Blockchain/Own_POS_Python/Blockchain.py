from Block import Block
from BlockchainUtils import BlockchainUtils

class Blockchain:

    def __init__(self):
        self.blocks = [Block.genesisBlock()]

    def addBlock(self, block):
        self.blocks.append(block)

    def toJson(self):
        data = {}
        jsonData = []
        for block in self.blocks:
            jsonData.append(block.toJson())

        data['blocks'] = jsonData
        return data

    def lastBlockCountValid(self, block):
        if self.blocks[-1].blockCount == block.blockCount - 1:
            return True
        return False

    def lastBlockHashValid(self,block):
        latestBlockchainBlockHash = BlockchainUtils.hash(self.blocks[-1].payload()).hexdigest() 
        if latestBlockchainBlockHash == block.lastHash:
            return True
        return False
