class Blockchain:

    def __init__(self):
        self.blocks = []

    def addBlock(self, block):
        self.blocks.append(block)

    def toJson(self):
        data = {}
        jsonData = []
        for block in self.blocks:
            jsonData.append(block.toJson())

        data['blocks'] = jsonData
        return data
