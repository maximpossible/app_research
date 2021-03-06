from matplotlib import pyplot as plt
import numpy as np
import sys
import os

f = open("./logs/logs.txt")
f2 = open("./logs/iter_logs.txt")

iters = []
ids = []
states = []
active_friends = []
count_of_friends = []
active_users = []

i = []
b = []

k = 0
# for line in f:
#     if len(line) == 0:
#         k = 1
#     iters2, ids2, states2, active_friends2, count_of_friends2, active_users2 = map(float, line.split())
#     iters.append(iters2)
#     ids.append(ids2)
#     states.append(states2)
#     active_friends.append(active_friends2)
#     count_of_friends.append(count_of_friends2)
#     active_users.append(active_users2)


for line in f2:
    if len(line) == 0:
        k = 1
    aa, bb = map(float, line.split())
    i.append(aa)
    b.append(bb)


f.close()
f2.close()


plt.title("Графики")
plt.subplot(3, 1, 1)
plt.plot(i, b, color='green', linewidth=1, label='act friends by iters')
plt.xlabel('number of iteration')
plt.ylabel('count of active users')
plt.grid(True)

plt.show()
exit(0)