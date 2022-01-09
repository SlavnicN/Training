import enum
from flask.json import JSONDecoder
from flask_classful import FlaskView, route
from flask import Flask, jsonify, request
from BlockchainUtils import BlockchainUtils

#because of FlaskView we can't put more param into the __init__,
#as we could add the node there so the work around is to declare a
#global node object to access data from transaction and blockchain 
#attribute
node = None

class NodeAPI(FlaskView):

    def __init__(self):
        self.app = Flask(__name__)

    def start(self, apiPort):
        NodeAPI.register(self.app, route_base='/')
        self.app.run(host='localhost', port=apiPort)
    
    def injectNode(self, injectedNode):
        global node
        node = injectedNode

    @route('/info', methods=['GET'])
    def info(self):
        return 'This is a communication interface to a node blockchain', 200

    @route('/blockchain', methods=['GET'])
    def blockchain(self):
        return node.blockchain.toJson(), 200

    @route('/transactionPool', methods=['GET'])
    def transactionPool(self):
        transactions = {}
        for ctr,transaction in enumerate(node.transactionPool.transactions):
            transactions[ctr] = transaction.toJson()
        return jsonify(transactions), 200

    @route('transaction', methods=['POST'])
    def transaction(self):
        value = request.get_json()
        if 'transaction' not in value:
            return 'Missing transaction value', 400
        transaction = BlockchainUtils.decode(value['transaction'])
        node.handleTransaction(transaction)
        response = {'message': 'Received Transaction'}
        return jsonify(response), 201