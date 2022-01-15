from ProofOfStack import ProofOfStack
from Lot import Lot

if __name__ == '__main__':
    '''pos = ProofOfStack()
    pos.update('bob', 10)
    pos.update('alice', 1000)
    print(pos.get('bob'))
    print(pos.get('alice'))
    print(pos.get('jack'))'''

    lot = Lot('bob', 1 ,'lastHash')
    print(lot.lotHash())