## In Class assignment
## Asante Buil, 
## Me and my team used https://www.python-course.eu/python3_inheritance.php to brush up on class implementation
## Because we couldn't get python working on the command line we then used an online compiler, https://repl.it/languages/python3,
## to start debugging

class Animals:
    name = ""
    weight = ""
    height = ""
    type = ""

    ## Self has to be included for all functions in a class. This is because python doesn't auto bind self to functions
    def __init__(self, name, weight, height):
        self.name = name
        self.weight = weight
        self.height = height

    def speak(self):
        ## Type is self defined from the inherited classes.
        ## If an animal instance doesn't have a type or is null it will be defaulted
        if type == "DOG":
            print("bark bark bark")
        elif type == "CAT":
            print("Meow Meow")
        else:
            print("Alien noises")

    def getWeight(self):
        return self.weight

    def getName(self):
        return self.name

    def getHeight(self):
        return self.height

    def printAnimal(self):
        ## This for of printing uses the "new-style string format"
        print("Name: {} \nType: {} \nWeight: {} \nHeight: {}".format(self.name, self.type, self.weight, self.height))

class Dog(Animals):
    type = "DOG"
  
    def special(self):
        print("{} is performing their special...".format(self.name))
        print("Brings back bone")

class Cat(Animals):
    type = "CAT"
    
    def special(self):
        print("{} is performing their special...".format(self.name))
        print("Scratch human eyeball")

## Derived classes use the sasme constructor as the parrent class.
kitty = Cat("Py", 22, 2.5)
doggie = Dog("Ruby", 45, 4.7)

kitty.printAnimal()
kitty.speak()
kitty.special()

doggie.printAnimal()
doggie.speak()
doggie.special()
