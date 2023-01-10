class ObjectMy:
    var1 = "null"
    var2 = 0

    def setVar(self, var1, var2):
        self.var1 = var1
        self.var2 = var2
        return

    def toString(self):
        dic = {"var1": self.var1, "var2": self.var2}
        return dic


def f1(var):
    if (var <= 1): return 1
    return f1(var - 1) + var


if __name__ == '__main__':
    print("Python script starts running:")

    print(f1(100))

    om = ObjectMy()
    print(om.toString())
    om.setVar("xmzr", 9)
    print(om.toString())
