from Transaction import Transaction
from Wallet import Wallet
from TransactionPool import TransactionPool
from Block import Block
from Blockchain import Blockchain
from BlockchainUtils import BlockchainUtils
from AccountModel import AccountModel
import pprint

if __name__ == '__main__':
    
    blockchain = Blockchain()
    transactionPool = TransactionPool()

    #Create Wallet with some funds
    alice = Wallet()
    bob = Wallet()
    exchange = Wallet()
    forger = Wallet()

    transactionExchange = exchange.createTransaction(alice.publicKeyString(), 10, "EXCHANGE")
    if not transactionPool.transactionExists(transactionExchange):
        transactionPool.addTransaction(transactionExchange)

    coveredTransaction = blockchain.getTransactioncoveredSet(transactionPool.transactions)
    lastHash = BlockchainUtils.hash(blockchain.blocks[-1].payload()).hexdigest()
    blockCount = blockchain.blocks[-1].blockCount + 1

    blockone = Block(coveredTransaction, lastHash, forger.publicKeyString(), blockCount)
    blockchain.addBlock(blockone)

    transactionAlice = alice.createTransaction(bob.publicKeyString(), 5, "TRANSFER")
    if not transactionPool.transactionExists(transactionAlice):
        transactionPool.addTransaction(transactionAlice)
    coveredTransaction = blockchain.getTransactioncoveredSet(transactionPool.transactions)
    lastHash = BlockchainUtils.hash(blockchain.blocks[-1].payload()).hexdigest()
    blockCount = blockchain.blocks[-1].blockCount + 1

    blocktwo = Block(coveredTransaction, lastHash, forger.publicKeyString(), blockCount)
    blockchain.addBlock(blocktwo)

    pprint.pprint(blockchain.toJson())

    
