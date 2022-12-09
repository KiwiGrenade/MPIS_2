import matplotlib.pyplot as plt
import numpy
from numpy.random import Generator, MT19937
<<<<<<< HEAD


rg = Generator(MT19937(12345))

nList = numpy.linspace(1000, 100000, 100, True, dtype=int)

XList = [0] * len(nList) * 50

BList = [0] * len(nList) * 50
CList = [0] * len(nList) * 50
DList = [0] * len(nList) * 50
UList = [0] * len(nList) * 50
LList = [0] * len(nList) * 50


#arg1-number of col, arg2-number of rows
def isTwoBallsInAllPins(pins):
    return min(pins) == 2


def collision(pins, pin, minimum):
    if pins[pin] > minimum:
        return True
    else:
        return False


def collParadox(pins):
    return min(pins) >= 1


def collParadoxBro(pins):
    return min(pins) >= 2


for n in nList:
    print (n)
    for k in range(50):
        pins = [0] * n
        nBall = 0
        B = 0
        C = 0
        D = 0
        U = 0
        L = 0
        while min(pins) != 2:
            nBall += 1
            pin = int(rg.uniform(0, n))
            print(pin)
            pins[pin] += 1
            if nBall == n:
                U = pins.count(0)
                L = max(pins)
            if B == 0 and pins[pin] == 2:
                B = nBall
            if C == 0 and min(pins) == 1:
                C = nBall
            if D == 0 and min(pins) == 2:
                D = nBall
        BList.append(B)
        CList.append(C)
        DList.append(D)
        UList.append(U)
        LList.append(L)
        XList.append(n)

    plt.figure(1)
    plt.plot(XList, BList, "ro", markersize=0.5)
    plt.show()
=======
from numpy import loadtxt

dataB = loadtxt()
rg = Generator(MT19937(12345))
nList = numpy.linspace(1000, 100000, 100, True, dtype=int)

plt.figure(1)
plt.plot(XList, BList, "ro", markersize=0.5)
plt.show()
>>>>>>> 7ff9587 (Add plot data generator in cpp. Compile time: 70s)
