from SJTUFlow_SPH import *

if __name__ == '__main__':
    kFrameRate = 20
    kSubSteps = 7
    kDt = (1.0 / kFrameRate) / kSubSteps
    _SPHSolver = SPHSolver()
    _SPHSolver.SolverInitSPH(vec2(640, 480), kDt, 1000)
    #_SPHSolver.SetEmitStrategy(EmitA())
    #_SPHSolver.SetBodyForceStrategy(BodyForceA())
    #_SPHSolver.SetUpdateGridStrategy(UpdateGridA())
    #_SPHSolver.SetCalPressureStrategy(CalPressureA())
    #_SPHSolver.SetRelaxPosStrategy(RelaxPosA())
    #_SPHSolver.SetCollisionStrategy(CollisionA())
    #_SPHSolver.SetRenderSPHStrategy(RenderSPHA())

    _SPHSolver.RenderInit()

    for i in range(1, 500):
        for j in range(0, kSubSteps):
            _SPHSolver.Emit()
            _SPHSolver.BodyForce()
            _SPHSolver.UpdateGrid()
            _SPHSolver.CalPressure()
            _SPHSolver.RelaxPos()
            _SPHSolver.Collision()
        _SPHSolver.RenderSPH()

    _SPHSolver.SolverDestroy()
