from Transaction import Transaction
from Wallet import Wallet
from TransactionPool import TransactionPool
from Block import Block
from Blockchain import Blockchain
from BlockchainUtils import BlockchainUtils
import pprint

if __name__ == '__main__':
    sender = 'sender'
    receiver = 'receiver'
    amount = 1
    type = 'TRANSFER'

    wallet = Wallet()
    fraudlentWallet = Wallet()
    pool = TransactionPool()

    transaction = wallet.createTransaction(receiver, amount, type)

    if pool.transactionExists(transaction) == False:
        pool.addTransaction(transaction)

   # block = wallet.createBlock(pool.transactions, 'lastHash',1)
    
    blockchain = Blockchain()
    lastHash = BlockchainUtils.hash(
        blockchain.blocks[-1].payload()).hexdigest()
    blockCount = blockchain.blocks[-1].blockCount + 1
    block = wallet.createBlock(pool.transactions, lastHash, blockCount)

    if not blockchain.lastBlockCountValid(block):
        print('lastBlockHash is not valid')

    if not blockchain.lastBlockHashValid(block):
        print('BlockCount is not valid')

    if blockchain.lastBlockCountValid(block) and blockchain.lastBlockHashValid(block):
        blockchain.addBlock(block)

    pprint.pprint(blockchain.toJson())
