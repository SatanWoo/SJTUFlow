from SJTUFlow_EG import *

if __name__ == '__main__':
    N = 64
    application = StableFluidsApplication(N, 0.1, 0.0)

    application.grid.setPreDensity(int(N / 2), int(N / 2), 100)
    for x in range(1, N):
        for y in range(1, N):
            d = application.grid.getPreDensity(x, y)
            if d > 0:
                application.grid.setPreU(x, y, 5)
                application.grid.setPreV(x, y, 5)
    
    application.setAdvectStrategy(Stable2DAdvectStrategy.Create())
    application.setDiffuseStrategy(Stable2DDiffuseStrategy.Create())
    bs = Stable2DBoundaryStrategy.Create()
    application.setProjectStrategy(Stable2DProjectStrategy.Create(bs))
    application.setAddSourceStrategY(Stable2DAddSourceStrategy.Create())

    for i in range(1, 1000):
        application.addSourceVelocity()
        application.diffuseVelocity()
        application.projectVelocity()
        application.advectVelocity()
        application.projectVelocity()

        application.addSourceDensity();
        application.diffuseDensity();
        application.advectDensity();

        application.render()
