print("hello world python world!")


def f1(var):
    if (var <= 1): return 1
    return f1(var - 1) + var


print(f1(100))


class ObjectMy:
    var1 = ""
    var2 = 0

    def setVar(self, var1, var2):
        self.var1 = var1
        self.var2 = var2
        return


om = ObjectMy()
print(om.var1, om.var2)
om.setVar("wenhao", 508388)
print(om.var1, om.var2)
