# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.


def f1(var):
    if var <= 1: return 1
    return f1(var - 1) + var


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print_hi('PyCharm')
    print(f1(100))
    lisit = {9, 4, 1, 6, 3, 2}
    print(lisit)

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
