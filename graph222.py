import pylab
import numpy as np
import matplotlib.pyplot as plt

	
def graph():
    x = np.arange(-10, 10, 0.1)
    y= np.arange(-10, 10, 0.1)
    xg, yg = np.meshgrid(x, y)
    zg = (2*xg**2 +4*xg +3*yg**2  -39.*yg + 129.75)
    return xg, yg, zg



x1, x2, f = graph()
pylab.contour(x1, x2, f,levels = 10)
pylab.minorticks_on()
pylab.grid(color="black", which="major", linewidth=1)
pylab.grid(color="purple", which="minor", linestyle=":", linewidth=0.5)
data=np.loadtxt ("graph.txt")
plt.plot(data[:,0], data[:,1],color='red')
data=np.loadtxt ("graph.txt")
plt.plot(data[:,0], data[:,1],'ro')
pylab.show()

	
