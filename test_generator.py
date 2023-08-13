import random
from datetime import datetime

random.seed(datetime.now().timestamp())

x = input("N: ")


for i in range(int(x)):
    print(random.randint(0, 1000))


