import time
import pathlib

if __name__ == '__main__':
    print(time.time_ns())
    print(time.ctime())
    print(time.gmtime())

    p = pathlib.Path('C:/Users/20106/Desktop/工作SQL目录')
    print(p.name)
    for item in list(p.glob("*.*")):
        print(item.drive)
        print(item.anchor)
        print(item.name)
