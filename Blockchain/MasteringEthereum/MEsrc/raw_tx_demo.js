const ethTx = require('ethereumjs-tx').Transaction

const txData = {
    nonce: '0x00',
    gasPrice: '0x09184e72a000',
    gasLimit: '0x30000',
    to: '0xb0920c523d582040f2bcb1bd7fb1c7c1ecebdb34',
    value: '0x00',
    data: '', 
    v: '0x1c', // Ethereum mainnet chainID
    r: 0,
    s: 0
};

const tx = new ethTx(txData);
console.log('RLP-Encoded Tx: 0x' + tx.serialize().toString('hex'))

txHash = tx.hash()
console.log('Tx hash: 0x'+ txHash.toString('hex'))

const privKey = Buffer.from('91c8360c4cb4b5fac45513a7213f31d4e4a7bfcb4630e9fbf074f42a203ac0b9', 'hex');
tx.sign(privKey);

serializedTx = tx.serialize();
rawTx = 'Signed Raw Transaction: 0x'+ serializedTx.toString('hex');
console.log(rawTx);
