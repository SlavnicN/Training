from Block import Block
from BlockchainUtils import BlockchainUtils
from AccountModel import AccountModel

class Blockchain:

    def __init__(self):
        self.blocks = [Block.genesisBlock()]
        self.accountModel = AccountModel()

    def addBlock(self, block):
        self.executeAllTransaction(block.transactions)
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
    
    def transactionCovered(self, transaction):
        if transaction.type == "EXCHANGE":
            return True
        senderBalance = self.accountModel.getBalance(transaction.senderPublicKey)
        if senderBalance >= transaction.amount:
            return True
        else:
            return False

    def getTransactioncoveredSet(self, transactions):
        coveredTransactions = []
        for transaction in transactions:
            if self.transactionCovered(transaction):
                coveredTransactions.append(transaction)
            else:
                print("the transaction is not covered") #Probably not the best to handle error here
        return coveredTransactions
    def executeAllTransaction(self, transactions):
        for transaction in transactions:
            self.executeTransaction(transaction)

    def executeTransaction(self,transaction):
        sender = transaction.senderPublicKey
        reciver = transaction.senderPublicKey
        amount = transaction.amount
        self.accountModel.updateBalance(sender, -amount)
        self.accountModel.updateBalance(reciver, amount)
