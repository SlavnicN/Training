from Transaction import Transaction
from Wallet import Wallet

if __name__ == '__main__':
    sender = 'sender'
    receiver = 'receiver'
    amount = 1
    type = 'TRANSFER'

    wallet = Wallet()
    fraudlentWallet = Wallet()

    transaction = wallet.createTransaction(receiver, amount, type)


    signatureValid = Wallet.signatureValid(transaction.payload(), transaction.signature, fraudlentWallet.publicKeyString())


    print(signatureValid)

    
