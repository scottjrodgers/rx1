"""
Publisher Class
"""

from parameters import get_topic_id
import zmq

class Publisher:
    def __init__(self, topic_name):
        self.topic_name = topic_name
        self.topic_id = get_topic_id(topic_name)
        self.port = 5556
        self.context = zmq.Context()
        self.socket = self.context.socket(zmq.PUB)
        self.socket.bind("tcp://127.0.0.1:%s" % self.port)

    def send(self, msg):
        msg_data = msg.encode()
        self.socket.send("%d %d" % (self.topic_id), msg_data)


if __name__ == '__main__':
    x = Publisher('A')
    y = type(x)('B')
    print(x.topic_name)
    print(y.topic_name)