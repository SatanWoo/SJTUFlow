from SJTUFlow_SPH_Poly6 import *

if __name__ == '__main__':
    _SPHSolver = SPHPoly6Solver()
    _SPHSolver.SetSceneFile()
    _SPHSolver.SolverInitSPH(0.0, 4000)
    _SPHSolver.SetEmitStrategy(EmitPoly6.Create())
    _SPHSolver.SetBodyForceStrategy(BodyForcePoly6.Create())
    _SPHSolver.SetUpdateGridStrategy(UpdateGridPoly6.Create())
    _SPHSolver.SetCalPressureStrategy(CalPressurePoly6.Create())
    _SPHSolver.SetRelaxPosStrategy(RelaxPosPoly6.Create())
    _SPHSolver.SetCollisionStrategy(CollisionPoly6.Create())
    _SPHSolver.SetRenderSPHStrategy(RenderSPHPoly6.Create())

    _SPHSolver.RenderInit()

    for i in range(1, 10000):
        for j in range(0, 5):
            _SPHSolver.Emit()
            _SPHSolver.UpdateGrid()
            _SPHSolver.CalPressure()
            _SPHSolver.BodyForce()
            _SPHSolver.RelaxPos()
            _SPHSolver.Collision()
        _SPHSolver.RenderSPH(True, i)
