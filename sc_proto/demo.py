import time
# def print_arg(str):
#     print(str)
#     print("hey")
#
#
# def add(x, y):
#     print("x:{}, y:{}".format(x, y))
#     print(x + y)
#     return x + y
#
# def get_dev():
#     return {'type':''}
#
#
# class Hello:
#     def __init__(self, str):
#         print("init:" + str)
#
#     def fun(self, str):
#         print('hello'+str)
#         return {'a':1, 'b':2}
#
# # class Hello(object):
# #     def __init__(self, x):
# #         print("instance init")
# #         self.a = x
# #     def print(self, x=None):
# #         print(x)
# #
# # def xprint():
# #     print("hello world")
# #
# # if __name__ == "__main__":
# #     xprint()
# #     h = Hello(5)
# #     h.print()
#
#
# class Scanner(object):
#     def __int__(self):
#         print("create scanner")
#
#     def scan(self):
#         print("start scanning")

# def HelloWorld():
#     print("Hello World")
#
# def add(a, b):
#     return a+b
#
# def TestDict(dict):
#     print(dict)
#     dict["Age"] = 17
#     return dict
#
# class PersonA:
#     def __int__(self, i):
#         print("person" + str(i))
#
#     def greet(self, greetStr):
#         print(greetStr)

class Hello(object):
    def __init__(self, x):
        self.a = x
        print(x)

    def print(self, x=None):
        print(x)
def xprint():
    print("hello world")


def create_scanner():
    print("python : create scanner")

def delete_scanner():
    print("python : delete scanner")

if __name__ == "__main__":
    xprint()
    h = Hello(5)
    h.print()