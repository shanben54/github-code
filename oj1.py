name =input()

class Person:
    def __init__(self,name):
        self.name=name
p1=Person(name)
print(p1.name)

class Person2(Person):
    def show(self):
        print(f'Hello{self.name}!')

p2=Person2(name)
p2.show()