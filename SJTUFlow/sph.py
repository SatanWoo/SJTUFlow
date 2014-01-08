from SJTUFlow_SPH import *

if __name__ == '__main__':
    kFrameRate = 20
    kSubSteps = 7
    kDt = (1.0 / kFrameRate) / kSubSteps
    _SPHSolver = SPHSolver()
    _SPHSolver.SolverInitSPH(kDt, 1000)
    _SPHSolver.SetEmitStrategy(EmitA.Create())
    _SPHSolver.SetBodyForceStrategy(BodyForceA.Create())
    _SPHSolver.SetUpdateGridStrategy(UpdateGridA.Create())
    _SPHSolver.SetCalPressureStrategy(CalPressureA.Create())
    _SPHSolver.SetRelaxPosStrategy(RelaxPosA.Create())
    _SPHSolver.SetCollisionStrategy(CollisionA.Create())
    _SPHSolver.SetRenderSPHStrategy(RenderSPHA.Create())

    _SPHSolver.RenderInit()

    for i in range(1, 10000):
        for j in range(0, kSubSteps):
            _SPHSolver.Emit()
            _SPHSolver.BodyForce()
            _SPHSolver.UpdateGrid()
            _SPHSolver.CalPressure()
            _SPHSolver.RelaxPos()
            _SPHSolver.Collision()
        _SPHSolver.RenderSPH(True, i)
