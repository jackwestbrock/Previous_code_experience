
#Creates a random histogram plot.

import matplotlib.pyplot as plt
import random

r_n = []
for i in range(100):
    r = random.randrange(0,10)
    r_n.append(r)

plt.hist(r_n,10, rwidth=.8)

plt.show()