from SJTUFlow_EG import *

if __name__ == '__main__':
    N = 32
    application = StableFluids3DApplication(N, 0.1, 0.0)

    application.grid.setPreDensity(int(N / 2), \
                                   int(N / 4 * 3), int(N / 2), 800)

    for x in range(1, N):
        for y in range(1, N):
            for z in range(1, N):
                d = application.grid.getPreDensity(x, y, z)
                if d > 0:
                    v = application.grid.getPreV(x, y, z)
                    v = v - d * 0.2 * (y + 1) / N
                    application.grid.setPreV(x, y, z, v)
    
    application.setAdvectStrategy(Stable3DAdvectStrategy.Create())
    application.setDiffuseStrategy(Stable3DDiffuseStrategy.Create())
    bs = Stable3DBoundaryStrategy.Create()
    application.setProjectStrategy(Stable3DProjectStrategy.Create(bs))
    application.setAddSourceStrategY(Stable3DAddSourceStrategy.Create())

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
