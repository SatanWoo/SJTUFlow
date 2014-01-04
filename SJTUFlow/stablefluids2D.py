from random import *
from SJTUFlow_EG import *

N = 64
application = StableFluidsApplication(N, 0.1, 0.0)

def initialize():
    x = randint(1, N - 1)
    y = randint(1, N - 1)
    t = randint(0, 2 * N)
    if t < N:
        application.grid.setPreDensity(x, y, 10)
    elif t < 2 * N:
        dx = randint(-10, 10) * 5.0
        dy = randint(-10, 10) * 5.0
        application.grid.setPreU(x, y, dx)
        application.grid.setPreV(x, y, dy)

if __name__ == '__main__':
    application.setAdvectStrategy(Stable2DAdvectStrategy.Create())
    application.setDiffuseStrategy(Stable2DDiffuseStrategy.Create())
    bs = Stable2DBoundaryStrategy.Create()
    application.setProjectStrategy(Stable2DProjectStrategy.Create(bs))
    application.setAddSourceStrategY(Stable2DAddSourceStrategy.Create())

    for i in range(1, 100):
        initialize()        

        application.addSourceVelocity()
        application.diffuseVelocity()
        application.projectVelocity()
        application.advectVelocity()
        application.projectVelocity()

        application.addSourceDensity();
        application.diffuseDensity();
        application.advectDensity();

        application.render(True, i)
