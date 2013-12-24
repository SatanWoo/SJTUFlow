from random import *
from SJTUFlow_EG import *

N = 64
application = StableFluidsApplication(N, 0.1, 0.0)

def initialize():
    application.grid.setPreDensity(int(N / 2), int(N / 2), 100)
    for x in range(1, N):
        for y in range(1, N):
            d = application.grid.getPreDensity(x, y)
            if d > 0:
                du = 5
                dv = 5
                if randint(0, 2 * N) < N:
                    du = -5
                else:
                    dv = -5
                application.grid.setPreU(x, y, du)
                application.grid.setPreV(x, y, dv)

if __name__ == '__main__':
    application.setAdvectStrategy(Stable2DAdvectStrategy.Create())
    application.setDiffuseStrategy(Stable2DDiffuseStrategy.Create())
    bs = Stable2DBoundaryStrategy.Create()
    application.setProjectStrategy(Stable2DProjectStrategy.Create(bs))
    application.setAddSourceStrategY(Stable2DAddSourceStrategy.Create())

    for i in range(1, 1000):
        initialize()

        application.addSourceVelocity()
        application.diffuseVelocity()
        application.projectVelocity()
        application.advectVelocity()
        application.projectVelocity()

        application.addSourceDensity();
        application.diffuseDensity();
        application.advectDensity();

        application.render()
