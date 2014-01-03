from SJTUFlow_SPH import *

if __name__ == '__main__':
    kDt = 0.005
    _SPHSolver = SPHSolver()
    _SPHSolver.SolverInitSPH(kDt, 1000)
    _SPHSolver.SetEmitStrategy(EmitB.Create())
    _SPHSolver.SetBodyForceStrategy(BodyForceB.Create())
    _SPHSolver.SetUpdateGridStrategy(UpdateGridB.Create())
    _SPHSolver.SetCalPressureStrategy(CalPressureB.Create())
    _SPHSolver.SetRelaxPosStrategy(RelaxPosB.Create())
    _SPHSolver.SetCollisionStrategy(CollisionB.Create())
    _SPHSolver.SetRenderSPHStrategy(RenderSPHB.Create())

    _SPHSolver.Emit()
    _SPHSolver.RenderInit()

    for i in range(1, 1000):
        _SPHSolver.BodyForce()
        _SPHSolver.UpdateGrid()
        _SPHSolver.CalPressure()
        _SPHSolver.RelaxPos()
        _SPHSolver.Collision()

        _SPHSolver.RenderSPH(True, i)
