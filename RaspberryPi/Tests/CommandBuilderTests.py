import unittest

from CommandBuilder.CommandBuilder import CommandBuilder

class Test_Command_Builder(unittest.TestCase):

    def test_Command_Contains_X(self):
        commandbuilder = CommandBuilder()
        commandbuilder.setX(200)
        actual = commandbuilder.GetCommand()
        self.

    def test_Command_Contains_Y(self):
        pass
    
    def test_Command_Contains_W(self):
        pass

if __name__ == '__main__':
    unittest.main()
