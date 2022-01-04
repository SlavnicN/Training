class Message():
    # connector= comb ip and port, endpoint send the message
    # messageType= able to diff the messages
    # data that we want to send
    def __init__(self, senderConnector, messageType, data):
        self.senderConnector = senderConnector
        self.messageType = messageType
        self.data = data
    
