# Solver

## Tree Structure
```sh
│   │   │   │   │       │       │       ├── common.h
│   │   │   │   │       │       │       ├── exception.h
│   │   │   │   │       │       │       ├── geometry.h
│   │   │   │   │       │       │       ├── joint.h
│   │   │   │   │       │       │       ├── link.h
│   │   │   │   │       │       │       └── model.h
│   │   │   │   │       │       ├── Jenkinsfile
│   │   │   │   │       │       ├── LICENSE
│   │   │   │   │       │       ├── README.md
│   │   │   │   │       │       ├── src
│   │   │   │   │       │       │   ├── common.cpp
│   │   │   │   │       │       │   ├── geometry.cpp
│   │   │   │   │       │       │   ├── joint.cpp
│   │   │   │   │       │       │   ├── link.cpp
│   │   │   │   │       │       │   ├── model.cpp
│   │   │   │   │       │       │   ├── tinyxml.cpp
│   │   │   │   │       │       │   ├── tinyxmlerror.cpp
│   │   │   │   │       │       │   └── tinyxmlparser.cpp
│   │   │   │   │       │       └── test
│   │   │   │   │       │           └── parse_simple.cpp
│   │   │   │   │       ├── urdfreader.cc
│   │   │   │   │       └── urdfreader.h
│   │   │   │   ├── casadi
│   │   │   │   │   ├── CMakeLists.txt
│   │   │   │   │   └── info.h
│   │   │   │   ├── CMake
│   │   │   │   │   ├── FindCasadi.cmake
│   │   │   │   │   ├── FindCython.cmake
│   │   │   │   │   ├── FindIPOPT.cmake
│   │   │   │   │   ├── FindNumPy2.cmake
│   │   │   │   │   ├── FindNumPy3.cmake
│   │   │   │   │   ├── ReplicatePythonSourceTree.cmake
│   │   │   │   │   └── UseCython.cmake
│   │   │   │   ├── CMakeLists.txt
│   │   │   │   ├── CONTRIBUTING.md
│   │   │   │   ├── doc
│   │   │   │   │   ├── api_changes.txt
│   │   │   │   │   ├── example.h
│   │   │   │   │   ├── images
│   │   │   │   │   │   ├── fig_Constraint_Contact.png
│   │   │   │   │   │   ├── fig_Constraint_Loop.png
│   │   │   │   │   │   ├── fig_GeometryAddon_quinticCornerSections.png
│   │   │   │   │   │   ├── fig_MuscleAddon_Anderson2007AllPositiveSigns.png
│   │   │   │   │   │   ├── fig_MuscleAddon_BlendableTorqueMuscle.png
│   │   │   │   │   │   ├── fig_MuscleAddon_Gymnast_ElbowForearm.png
│   │   │   │   │   │   ├── fig_MuscleAddon_Gymnast_HipKneeAnkle.png
│   │   │   │   │   │   ├── fig_MuscleAddon_Gymnast_Lumbar.png
│   │   │   │   │   │   ├── fig_MuscleAddon_Gymnast_Shoulder3Dof.png
│   │   │   │   │   │   ├── fig_MuscleAddon_Gymnast_Wrist3Dof.png
│   │   │   │   │   │   ├── fig_MuscleAddon_MuscleFunctionFactory_falCurve.png
│   │   │   │   │   │   ├── fig_MuscleAddon_MuscleFunctionFactory_fcCosPhiCurve.png
│   │   │   │   │   │   ├── fig_MuscleAddon_MuscleFunctionFactory_fcLengthCurve.png
│   │   │   │   │   │   ├── fig_MuscleAddon_MuscleFunctionFactory_fcphiCurve.png
│   │   │   │   │   │   ├── fig_MuscleAddon_MuscleFunctionFactory_fpeCurve.png
│   │   │   │   │   │   ├── fig_MuscleAddon_MuscleFunctionFactory_fseCurve.png
│   │   │   │   │   │   ├── fig_MuscleAddon_MuscleFunctionFactory_fvCurve.png
│   │   │   │   │   │   ├── fig_MuscleAddon_MuscleFunctionFactory_fvInvCurve.png
│   │   │   │   │   │   ├── fig_MuscleAddon_TorqueMuscleFunctionFactory_DampingBlendingCurve.png
│   │   │   │   │   │   ├── fig_MuscleAddon_TorqueMuscleFunctionFactory_GaussianActiveTorqueAngleCurve.png
│   │   │   │   │   │   ├── fig_MuscleAddon_TorqueMuscleFunctionFactory_GaussianActiveTorqueAngleCurveSimple.png
│   │   │   │   │   │   ├── fig_MuscleAddon_TorqueMuscleFunctionFactory_PassiveTorqueAngleCurve.png
│   │   │   │   │   │   ├── fig_MuscleAddon_TorqueMuscleFunctionFactory_PassiveTorqueAngleCurveSimple.png
│   │   │   │   │   │   ├── fig_MuscleAddon_TorqueMuscleFunctionFactory_TendonTorqueAngleCurve.png
│   │   │   │   │   │   ├── fig_MuscleAddon_TorqueMuscleFunctionFactory_TendonTorqueAngleCurveSimple.png
│   │   │   │   │   │   ├── fig_MuscleAddon_TorqueMuscleFunctionFactory_TorqueVelocityCurve.png
│   │   │   │   │   │   └── fig_MuscleAddon_TorqueMuscleFunctionFactory_TorqueVelocityCurveSimple.png
│   │   │   │   │   ├── logo
│   │   │   │   │   │   ├── rbdl_logo_16x16.png
│   │   │   │   │   │   ├── rbdl_logo_32x32.png
│   │   │   │   │   │   ├── rbdl_logo_64x64.png
│   │   │   │   │   │   ├── rbdl_logo.png
│   │   │   │   │   │   └── rbdl_logo.svg
│   │   │   │   │   ├── luamodel_example.h
│   │   │   │   │   ├── Mainpage.h
│   │   │   │   │   ├── notes
│   │   │   │   │   │   ├── acceleration_visualization.pdf
│   │   │   │   │   │   ├── acceleration_visualization.svg
│   │   │   │   │   │   ├── Makefile
│   │   │   │   │   │   └── point_velocity_acceleration.tex
│   │   │   │   │   └── python_example.h
│   │   │   │   ├── Doxyfile
│   │   │   │   ├── examples
│   │   │   │   │   ├── bouncingBall
│   │   │   │   │   │   ├── CMake
│   │   │   │   │   │   │   ├── FindEigen3.cmake
│   │   │   │   │   │   │   ├── FindIPOPT.cmake
│   │   │   │   │   │   │   └── FindRBDL.cmake
│   │   │   │   │   │   ├── CMakeFiles
│   │   │   │   │   │   │   └── cmake.check_cache
│   │   │   │   │   │   ├── CMakeLists.txt
│   │   │   │   │   │   ├── model
│   │   │   │   │   │   │   └── ballPlaneContact.lua
│   │   │   │   │   │   ├── output
│   │   │   │   │   │   │   ├── animation.csv
│   │   │   │   │   │   │   ├── animationForces.ff
│   │   │   │   │   │   │   ├── frictionCoefficientCurve.csv
│   │   │   │   │   │   │   └── kepe.csv
│   │   │   │   │   │   ├── README.md
│   │   │   │   │   │   └── src
│   │   │   │   │   │       ├── bouncingBallBenchmark.cc
│   │   │   │   │   │       ├── ContactToolkit.h
│   │   │   │   │   │       ├── csvtools.cc
│   │   │   │   │   │       ├── csvtools.h
│   │   │   │   │   │       └── Timer.h
│   │   │   │   │   ├── casadi_simple
│   │   │   │   │   │   ├── CMakeLists.txt
│   │   │   │   │   │   ├── example.cc
│   │   │   │   │   │   └── FindCasadi.cmake
│   │   │   │   │   ├── constrainedDoublePendulum
│   │   │   │   │   │   ├── CMake
│   │   │   │   │   │   │   ├── FindBTK.cmake
│   │   │   │   │   │   │   ├── FindEigen3.cmake
│   │   │   │   │   │   │   ├── FindRBDL.cmake
│   │   │   │   │   │   │   ├── Modules
│   │   │   │   │   │   │   │   ├── Build.cmake
│   │   │   │   │   │   │   │   ├── BuildFortran.cmake
│   │   │   │   │   │   │   │   ├── BuildMuscodApps.cmake
│   │   │   │   │   │   │   │   ├── BuildPaths.cmake
│   │   │   │   │   │   │   │   ├── BuildVplanApps.cmake
│   │   │   │   │   │   │   │   ├── CompilerOptions.cmake
│   │   │   │   │   │   │   │   ├── CompilerSettingsC.cmake
│   │   │   │   │   │   │   │   ├── CompilerSettingsCpp.cmake
│   │   │   │   │   │   │   │   ├── CompilerSettingsFortran.cmake
│   │   │   │   │   │   │   │   ├── Cosmetics.cmake
│   │   │   │   │   │   │   │   ├── DefaultSearchPaths.cmake
│   │   │   │   │   │   │   │   ├── ExportIncludeDirs.cmake
│   │   │   │   │   │   │   │   ├── FindADIFOR2.cmake
│   │   │   │   │   │   │   │   ├── FindADOLC.cmake
│   │   │   │   │   │   │   │   ├── FindAMD.cmake
│   │   │   │   │   │   │   │   ├── FindBOOST.cmake
│   │   │   │   │   │   │   │   ├── FindBQPD.cmake
│   │   │   │   │   │   │   │   ├── FindCOMMON_CODE.cmake
│   │   │   │   │   │   │   │   ├── FindEFENCE.cmake
│   │   │   │   │   │   │   │   ├── FindHDF5.cmake
│   │   │   │   │   │   │   │   ├── FindJMODELICA.cmake
│   │   │   │   │   │   │   │   ├── FindLIBLAC.cmake
│   │   │   │   │   │   │   │   ├── FindMATLAB.cmake
│   │   │   │   │   │   │   │   ├── FindMUSCOD.cmake
│   │   │   │   │   │   │   │   ├── FindNETCDF.cmake
│   │   │   │   │   │   │   │   ├── FindOCTAVE.cmake
│   │   │   │   │   │   │   │   ├── FindOOQP.cmake
│   │   │   │   │   │   │   │   ├── FindPGPLOT.cmake
│   │   │   │   │   │   │   │   ├── FindPLPLOT.cmake
│   │   │   │   │   │   │   │   ├── FindQPOASES.cmake
│   │   │   │   │   │   │   │   ├── FindQPOPT.cmake
│   │   │   │   │   │   │   │   ├── FindSNOPT.cmake
│   │   │   │   │   │   │   │   ├── FindSOLVIND.cmake
│   │   │   │   │   │   │   │   ├── FindSONIC.cmake
│   │   │   │   │   │   │   │   ├── FindSUNDIALS.cmake
│   │   │   │   │   │   │   │   ├── FindUFCONFIG.cmake
│   │   │   │   │   │   │   │   ├── FindUMFPACK.cmake
│   │   │   │   │   │   │   │   ├── FindVPLAN.cmake
│   │   │   │   │   │   │   │   ├── FindXERCESC.cmake
│   │   │   │   │   │   │   │   ├── FindXXX.cmake
│   │   │   │   │   │   │   │   ├── ImportIncludeDirs.cmake
│   │   │   │   │   │   │   │   ├── InstallCmakeModules.cmake
│   │   │   │   │   │   │   │   ├── Logging.cmake
│   │   │   │   │   │   │   │   ├── OptimizeCompilerSettings.cmake
│   │   │   │   │   │   │   │   ├── ProblemHandling.cmake
│   │   │   │   │   │   │   │   ├── SimOptDefaults.cmake
│   │   │   │   │   │   │   │   ├── UseADIFOR2.cmake
│   │   │   │   │   │   │   │   ├── UseADOLC.cmake
│   │   │   │   │   │   │   │   ├── UseAMD.cmake
│   │   │   │   │   │   │   │   ├── UseBOOST.cmake
│   │   │   │   │   │   │   │   ├── UseEFENCE.cmake
│   │   │   │   │   │   │   │   ├── UseHDF5.cmake
│   │   │   │   │   │   │   │   ├── UseMATLAB.cmake
│   │   │   │   │   │   │   │   ├── UseNETCDF.cmake
│   │   │   │   │   │   │   │   ├── UseOCTAVE.cmake
│   │   │   │   │   │   │   │   ├── UseOOQP.cmake
│   │   │   │   │   │   │   │   ├── UsePGPLOT.cmake
│   │   │   │   │   │   │   │   ├── UsePLPLOT.cmake
│   │   │   │   │   │   │   │   ├── UseQPOASES.cmake
│   │   │   │   │   │   │   │   ├── UseSNOPT.cmake
│   │   │   │   │   │   │   │   ├── UseSUNDIALS.cmake
│   │   │   │   │   │   │   │   ├── UseUFCONFIG.cmake
│   │   │   │   │   │   │   │   ├── UseUMFPACK.cmake
│   │   │   │   │   │   │   │   ├── UseX11.cmake
│   │   │   │   │   │   │   │   └── UseXERCESC.cmake
│   │   │   │   │   │   │   ├── TESTDartConfig.cmake
│   │   │   │   │   │   │   └── TestSuite.cmake
│   │   │   │   │   │   ├── CMakeLists.txt
│   │   │   │   │   │   ├── model
│   │   │   │   │   │   │   └── constrainedDoublePendulum.lua
│   │   │   │   │   │   ├── README.md
│   │   │   │   │   │   └── src
│   │   │   │   │   │       ├── constrainedDoublePendulumForwardDynamics.cc
│   │   │   │   │   │       ├── csvtools.cc
│   │   │   │   │   │       └── csvtools.h
│   │   │   │   │   ├── luamodel
│   │   │   │   │   │   ├── CMakeLists.txt
│   │   │   │   │   │   ├── example_luamodel.cc
│   │   │   │   │   │   ├── FindEigen3.cmake
│   │   │   │   │   │   ├── FindRBDL.cmake
│   │   │   │   │   │   ├── README.md
│   │   │   │   │   │   ├── sampleconstrainedmodel.lua
│   │   │   │   │   │   └── samplemodel.lua
│   │   │   │   │   ├── pendulum
│   │   │   │   │   │   ├── CMake
│   │   │   │   │   │   │   ├── FindEigen3.cmake
│   │   │   │   │   │   │   └── FindRBDL.cmake
│   │   │   │   │   │   ├── CMakeLists.txt
│   │   │   │   │   │   ├── model
│   │   │   │   │   │   │   ├── pendulum.lua
│   │   │   │   │   │   │   └── unit_cube.obj
│   │   │   │   │   │   ├── README.md
│   │   │   │   │   │   └── src
│   │   │   │   │   │       ├── csvtools.cc
│   │   │   │   │   │       ├── csvtools.h
│   │   │   │   │   │       └── pendulumForwardDynamics.cc
│   │   │   │   │   ├── python
│   │   │   │   │   │   └── example.py
│   │   │   │   │   ├── README.md
│   │   │   │   │   ├── simple
│   │   │   │   │   │   ├── CMakeLists.txt
│   │   │   │   │   │   ├── example.cc
│   │   │   │   │   │   ├── FindEigen3.cmake
│   │   │   │   │   │   └── FindRBDL.cmake
│   │   │   │   │   ├── urdfreader
│   │   │   │   │   │   ├── CMakeLists.txt
│   │   │   │   │   │   ├── example_urdfreader.cc
│   │   │   │   │   │   ├── FindEigen3.cmake
│   │   │   │   │   │   ├── FindRBDL.cmake
│   │   │   │   │   │   ├── nao.urdf
│   │   │   │   │   │   └── README.md
│   │   │   │   │   └── walkingInverseDynamicsWithPython
│   │   │   │   │       ├── animation.csv
│   │   │   │   │       ├── fitting_log.csv
│   │   │   │   │       ├── gait912.lua
│   │   │   │   │       ├── gaitDataPlanar.c3d
│   │   │   │   │       ├── grf.ff
│   │   │   │   │       ├── meshes
│   │   │   │   │       │   ├── foot.obj
│   │   │   │   │       │   ├── hand.obj
│   │   │   │   │       │   ├── head.obj
│   │   │   │   │       │   ├── lowerArm.obj
│   │   │   │   │       │   ├── middleTrunk.obj
│   │   │   │   │       │   ├── pelvis.obj
│   │   │   │   │       │   ├── shank.obj
│   │   │   │   │       │   ├── thigh.obj
│   │   │   │   │       │   ├── trunk.obj
│   │   │   │   │       │   ├── unit_sphere_medres.obj
│   │   │   │   │       │   ├── upperArm.obj
│   │   │   │   │       │   └── upperTrunk.obj
│   │   │   │   │       ├── processInverseDynamics.py
│   │   │   │   │       ├── qIK.csv
│   │   │   │   │       └── README.md
│   │   │   │   ├── include
│   │   │   │   │   └── rbdl
│   │   │   │   │       ├── Body.h
│   │   │   │   │       ├── CasadiMath
│   │   │   │   │       │   ├── MX_Xd_dynamic.h
│   │   │   │   │       │   ├── MX_Xd_scalar.h
│   │   │   │   │       │   ├── MX_Xd_static.h
│   │   │   │   │       │   ├── MX_Xd_subMatrix.h
│   │   │   │   │       │   └── MX_Xd_utils.h
│   │   │   │   │       ├── compileassert.h
│   │   │   │   │       ├── Constraint_Contact.h
│   │   │   │   │       ├── Constraint_Loop.h
│   │   │   │   │       ├── Constraint.h
│   │   │   │   │       ├── Constraints.h
│   │   │   │   │       ├── Dynamics.h
│   │   │   │   │       ├── Joint.h
│   │   │   │   │       ├── Kinematics.h
│   │   │   │   │       ├── Logging.h
│   │   │   │   │       ├── Model.h
│   │   │   │   │       ├── Quaternion.h
│   │   │   │   │       ├── rbdl_casadi_config.h.cmake
│   │   │   │   │       ├── rbdl_config.h.cmake
│   │   │   │   │       ├── rbdl_eigenmath.h
│   │   │   │   │       ├── rbdl_errors.h
│   │   │   │   │       ├── rbdl_math.h
│   │   │   │   │       ├── rbdl_mathutils.h
│   │   │   │   │       ├── rbdl_utils.h
│   │   │   │   │       ├── rbdl.h
│   │   │   │   │       └── SpatialAlgebraOperators.h
│   │   │   │   ├── Jenkinsfile
│   │   │   │   ├── LICENSE
│   │   │   │   ├── python
│   │   │   │   │   ├── CMakeLists.txt
│   │   │   │   │   ├── crbdl.pxd
│   │   │   │   │   ├── crbdlmuscle.pxd
│   │   │   │   │   ├── ICustomJoint.cpp
│   │   │   │   │   ├── ICustomJoint.h
│   │   │   │   │   ├── rbdl_loadmodel.cc
│   │   │   │   │   ├── rbdl_ptr_functions.h
│   │   │   │   │   ├── rbdl-python_api.h
│   │   │   │   │   ├── rbdl-python.h
│   │   │   │   │   ├── rbdl-wrapper.pyx
│   │   │   │   │   ├── rbdl.pxd
│   │   │   │   │   ├── rbdlmuscle.pyx
│   │   │   │   │   ├── README.md
│   │   │   │   │   ├── setup.py.cmake
│   │   │   │   │   ├── test_rbdlmuscle.py
│   │   │   │   │   ├── test_wrapper.py
│   │   │   │   │   └── wrappergen.py
│   │   │   │   ├── README.md
│   │   │   │   ├── share
│   │   │   │   │   ├── FindRBDL.cmake
│   │   │   │   │   ├── rbdl-casadi.pc.cmake
│   │   │   │   │   ├── rbdl.pc.cmake
│   │   │   │   │   ├── RBDLCasadiConfig.cmake.in
│   │   │   │   │   └── RBDLConfig.cmake.in
│   │   │   │   ├── src
│   │   │   │   │   ├── Constraint_Contact.cc
│   │   │   │   │   ├── Constraint_Loop.cc
│   │   │   │   │   ├── Constraints.cc
│   │   │   │   │   ├── Dynamics.cc
│   │   │   │   │   ├── Joint.cc
│   │   │   │   │   ├── Kinematics.cc
│   │   │   │   │   ├── Logging.cc
│   │   │   │   │   ├── Model.cc
│   │   │   │   │   ├── rbdl_errors.cc
│   │   │   │   │   ├── rbdl_mathutils.cc
│   │   │   │   │   ├── rbdl_utils.cc
│   │   │   │   │   └── rbdl_version.cc
│   │   │   │   ├── tests
│   │   │   │   │   ├── BodyTests.cc
│   │   │   │   │   ├── CalcAccelerationsTests.cc
│   │   │   │   │   ├── CalcVelocitiesTests.cc
│   │   │   │   │   ├── CMakeLists.txt
│   │   │   │   │   ├── CompositeRigidBodyTests.cc
│   │   │   │   │   ├── ContactsTests.cc
│   │   │   │   │   ├── CustomConstraintsTests.cc
│   │   │   │   │   ├── CustomJointMultiBodyTests.cc
│   │   │   │   │   ├── CustomJointSingleBodyTests.cc
│   │   │   │   │   ├── CustomJointTests.cc
│   │   │   │   │   ├── DynamicsTests.cc
│   │   │   │   │   ├── ErrorTests.cc
│   │   │   │   │   ├── Fixtures.h
│   │   │   │   │   ├── FloatingBaseTests.cc
│   │   │   │   │   ├── ForwardDynamicsConstraintsExternalForces.cc
│   │   │   │   │   ├── Human36Fixture.h
│   │   │   │   │   ├── ImpulsesTests.cc
│   │   │   │   │   ├── InverseDynamicsTests.cc
│   │   │   │   │   ├── InverseDynamicsWithConstraintsTests.cc
│   │   │   │   │   ├── InverseKinematicsTests.cc
│   │   │   │   │   ├── KinematicsTests.cc
│   │   │   │   │   ├── LoopConstraintsTests.cc
│   │   │   │   │   ├── main.cc
│   │   │   │   │   ├── MathTests.cc
│   │   │   │   │   ├── ModelTests.cc
│   │   │   │   │   ├── MultiDofTests.cc
│   │   │   │   │   ├── PendulumModels.h
│   │   │   │   │   ├── rbdl_tests.h
│   │   │   │   │   ├── ScrewJointTests.cc
│   │   │   │   │   ├── SparseFactorizationTests.cc
│   │   │   │   │   ├── SpatialAlgebraTests.cc
│   │   │   │   │   ├── TwolegModelTests.cc
│   │   │   │   │   └── UtilsTests.cc
│   │   │   │   ├── update.sh
│   │   │   │   └── utils
│   │   │   │       └── matlab
│   │   │   │           ├── FrameTranslation.m
│   │   │   │           ├── VectorCrossMatrix.m
│   │   │   │           └── ZYXEulerToMatrix.m
│   │   │   └── rbdl-subbuild
│   │   │       ├── cmake_install.cmake
│   │   │       ├── CMakeCache.txt
│   │   │       ├── CMakeFiles
│   │   │       │   ├── 4.3.1
│   │   │       │   │   └── CMakeSystem.cmake
│   │   │       │   ├── cmake.check_cache
│   │   │       │   ├── CMakeConfigureLog.yaml
│   │   │       │   ├── CMakeDirectoryInformation.cmake
│   │   │       │   ├── CMakeRuleHashes.txt
│   │   │       │   ├── InstallScripts.json
│   │   │       │   ├── Makefile.cmake
│   │   │       │   ├── Makefile2
│   │   │       │   ├── pkgRedirects
│   │   │       │   ├── progress.marks
│   │   │       │   ├── rbdl-populate-complete
│   │   │       │   ├── rbdl-populate.dir
│   │   │       │   │   ├── build.make
│   │   │       │   │   ├── cmake_clean.cmake
│   │   │       │   │   ├── compiler_depend.make
│   │   │       │   │   ├── compiler_depend.ts
│   │   │       │   │   ├── DependInfo.cmake
│   │   │       │   │   ├── Labels.json
│   │   │       │   │   ├── Labels.txt
│   │   │       │   │   └── progress.make
│   │   │       │   └── TargetDirectories.txt
│   │   │       ├── CMakeLists.txt
│   │   │       ├── Makefile
│   │   │       └── rbdl-populate-prefix
│   │   │           ├── src
│   │   │           │   └── rbdl-populate-stamp
│   │   │           │       ├── rbdl-populate-build
│   │   │           │       ├── rbdl-populate-configure
│   │   │           │       ├── rbdl-populate-done
│   │   │           │       ├── rbdl-populate-download
│   │   │           │       ├── rbdl-populate-gitclone-lastrun.txt
│   │   │           │       ├── rbdl-populate-gitinfo.txt
│   │   │           │       ├── rbdl-populate-install
│   │   │           │       ├── rbdl-populate-mkdir
│   │   │           │       ├── rbdl-populate-patch
│   │   │           │       ├── rbdl-populate-patch-info.txt
│   │   │           │       ├── rbdl-populate-test
│   │   │           │       └── rbdl-populate-update-info.txt
│   │   │           └── tmp
│   │   │               ├── rbdl-populate-cfgcmd.txt
│   │   │               ├── rbdl-populate-gitclone.cmake
│   │   │               ├── rbdl-populate-gitupdate.cmake
│   │   │               └── rbdl-populate-mkdirs.cmake
│   │   ├── bin
│   │   ├── cmake_install.cmake
│   │   ├── cmake_test_discovery_d281b5b894.json
│   │   ├── CMakeCache.txt
│   │   ├── CMakeDoxyfile.in
│   │   ├── CMakeDoxygenDefaults.cmake
│   │   ├── CMakeFiles
│   │   │   ├── 4.3.1
│   │   │   │   ├── CMakeCCompiler.cmake
│   │   │   │   ├── CMakeCXXCompiler.cmake
│   │   │   │   ├── CMakeDetermineCompilerABI_C.bin
│   │   │   │   ├── CMakeDetermineCompilerABI_CXX.bin
│   │   │   │   ├── CMakeSystem.cmake
│   │   │   │   ├── CompilerIdC
│   │   │   │   │   ├── a.out
│   │   │   │   │   ├── apple-sdk.c
│   │   │   │   │   ├── CMakeCCompilerId.c
│   │   │   │   │   └── tmp
│   │   │   │   └── CompilerIdCXX
│   │   │   │       ├── a.out
│   │   │   │       ├── apple-sdk.cpp
│   │   │   │       ├── CMakeCXXCompilerId.cpp
│   │   │   │       └── tmp
│   │   │   ├── all_aotstats.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── all_qmllint_json.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── all_qmllint_module.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── all_qmllint.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── all_qmltyperegistrations.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── clean_qml_context_properties.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── cmake_directory_clean.cmake
│   │   │   ├── cmake.check_cache
│   │   │   ├── cmake.verify_globs
│   │   │   ├── CMakeConfigureLog.yaml
│   │   │   ├── CMakeDirectoryInformation.cmake
│   │   │   ├── CMakeRuleHashes.txt
│   │   │   ├── docs.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── dump_qml_context_properties.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── dynamics_autogen_timestamp_deps.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── dynamics_autogen.dir
│   │   │   │   ├── AutogenInfo.json
│   │   │   │   ├── AutogenUsed.txt
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.internal
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   ├── ParseCache.txt
│   │   │   │   └── progress.make
│   │   │   ├── dynamics.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean_target.cmake
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── depend.make
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   ├── dynamics_autogen
│   │   │   │   │   ├── mocs_compilation.cpp.o
│   │   │   │   │   └── mocs_compilation.cpp.o.d
│   │   │   │   ├── flags.make
│   │   │   │   ├── link.txt
│   │   │   │   ├── progress.make
│   │   │   │   └── src
│   │   │   │       └── dynamics
│   │   │   │           └── generated
│   │   │   │               └── v1
│   │   │   │                   ├── dynamics.grpc.pb.cc.o
│   │   │   │                   ├── dynamics.grpc.pb.cc.o.d
│   │   │   │                   ├── dynamics.pb.cc.o
│   │   │   │                   └── dynamics.pb.cc.o.d
│   │   │   ├── generate_qmlls_build_ini_file.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── geometry_autogen_timestamp_deps.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── geometry_autogen.dir
│   │   │   │   ├── AutogenInfo.json
│   │   │   │   ├── AutogenUsed.txt
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.internal
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   ├── ParseCache.txt
│   │   │   │   └── progress.make
│   │   │   ├── geometry.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean_target.cmake
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── depend.make
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   ├── flags.make
│   │   │   │   ├── geometry_autogen
│   │   │   │   │   ├── mocs_compilation.cpp.o
│   │   │   │   │   └── mocs_compilation.cpp.o.d
│   │   │   │   ├── link.txt
│   │   │   │   ├── progress.make
│   │   │   │   └── src
│   │   │   │       └── geometry
│   │   │   │           ├── footers
│   │   │   │           │   ├── interface.cpp.o
│   │   │   │           │   └── interface.cpp.o.d
│   │   │   │           └── generated
│   │   │   │               └── v1
│   │   │   │                   ├── geometry.grpc.pb.cc.o
│   │   │   │                   ├── geometry.grpc.pb.cc.o.d
│   │   │   │                   ├── geometry.pb.cc.o
│   │   │   │                   └── geometry.pb.cc.o.d
│   │   │   ├── InstallScripts.json
│   │   │   ├── Makefile.cmake
│   │   │   ├── Makefile2
│   │   │   ├── module_Workspace_aotstats_target.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── pkgRedirects
│   │   │   ├── progress.marks
│   │   │   ├── protos_autogen_timestamp_deps.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── protos_autogen.dir
│   │   │   │   ├── AutogenInfo.json
│   │   │   │   ├── AutogenUsed.txt
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.internal
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   ├── ParseCache.txt
│   │   │   │   └── progress.make
│   │   │   ├── protos.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean_target.cmake
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── depend.make
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   ├── flags.make
│   │   │   │   ├── link.txt
│   │   │   │   ├── progress.make
│   │   │   │   ├── protos_autogen
│   │   │   │   │   ├── mocs_compilation.cpp.o
│   │   │   │   │   └── mocs_compilation.cpp.o.d
│   │   │   │   └── src
│   │   │   │       └── protos
│   │   │   │           └── footers
│   │   │   │               ├── interface.cpp.o
│   │   │   │               └── interface.cpp.o.d
│   │   │   ├── TargetDirectories.txt
│   │   │   ├── test_geometry_fileService_autogen_timestamp_deps.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── test_geometry_fileService_autogen.dir
│   │   │   │   ├── AutogenInfo.json
│   │   │   │   ├── AutogenUsed.txt
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.internal
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   ├── ParseCache.txt
│   │   │   │   └── progress.make
│   │   │   ├── test_geometry_fileService.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── depend.make
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   ├── flags.make
│   │   │   │   ├── link.txt
│   │   │   │   ├── progress.make
│   │   │   │   ├── src
│   │   │   │   │   └── geometry
│   │   │   │   │       └── tests
│   │   │   │   │           ├── fileService.cpp.o
│   │   │   │   │           └── fileService.cpp.o.d
│   │   │   │   └── test_geometry_fileService_autogen
│   │   │   │       ├── mocs_compilation.cpp.o
│   │   │   │       └── mocs_compilation.cpp.o.d
│   │   │   ├── utilities_autogen_timestamp_deps.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── utilities_autogen.dir
│   │   │   │   ├── AutogenInfo.json
│   │   │   │   ├── AutogenUsed.txt
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.internal
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   ├── ParseCache.txt
│   │   │   │   └── progress.make
│   │   │   ├── utilities.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean_target.cmake
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── depend.make
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   ├── flags.make
│   │   │   │   ├── link.txt
│   │   │   │   ├── progress.make
│   │   │   │   ├── src
│   │   │   │   │   └── utilities
│   │   │   │   │       ├── footers
│   │   │   │   │       │   ├── logger.cpp.o
│   │   │   │   │       │   ├── logger.cpp.o.d
│   │   │   │   │       │   ├── services.cpp.o
│   │   │   │   │       │   └── services.cpp.o.d
│   │   │   │   │       └── generated
│   │   │   │   │           └── v1
│   │   │   │   │               ├── health.grpc.pb.cc.o
│   │   │   │   │               ├── health.grpc.pb.cc.o.d
│   │   │   │   │               ├── health.pb.cc.o
│   │   │   │   │               └── health.pb.cc.o.d
│   │   │   │   └── utilities_autogen
│   │   │   │       ├── mocs_compilation.cpp.o
│   │   │   │       └── mocs_compilation.cpp.o.d
│   │   │   ├── VerifyGlobs.cmake
│   │   │   ├── Workspace_autogen_timestamp_deps.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── Workspace_autogen.dir
│   │   │   │   ├── AutogenInfo.json
│   │   │   │   ├── AutogenUsed.txt
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.internal
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   ├── ParseCache.txt
│   │   │   │   └── progress.make
│   │   │   ├── Workspace_copy_qml.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── Workspace_copy_res.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── Workspace_other_files.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── Workspace_qmllint_json.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── Workspace_qmllint_module.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── Workspace_qmllint.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   ├── Workspace_qmltyperegistration.dir
│   │   │   │   ├── build.make
│   │   │   │   ├── cmake_clean.cmake
│   │   │   │   ├── compiler_depend.make
│   │   │   │   ├── compiler_depend.ts
│   │   │   │   ├── DependInfo.cmake
│   │   │   │   └── progress.make
│   │   │   └── Workspace.dir
│   │   │       ├── build.make
│   │   │       ├── cmake_clean.cmake
│   │   │       ├── compiler_depend.make
│   │   │       ├── compiler_depend.ts
│   │   │       ├── depend.make
│   │   │       ├── DependInfo.cmake
│   │   │       ├── flags.make
│   │   │       ├── link.txt
│   │   │       ├── out
│   │   │       ├── progress.make
│   │   │       ├── src
│   │   │       │   ├── main.cpp.o
│   │   │       │   └── main.cpp.o.d
│   │   │       ├── Workspace_autogen
│   │   │       │   ├── mocs_compilation.cpp.o
│   │   │       │   └── mocs_compilation.cpp.o.d
│   │   │       ├── workspace_qmltyperegistrations.cpp.o
│   │   │       └── workspace_qmltyperegistrations.cpp.o.d
│   │   ├── com
│   │   │   └── myapp
│   │   │       ├── qmldir
│   │   │       ├── src
│   │   │       │   └── qml
│   │   │       │       ├── Main.qml
│   │   │       │       └── qmldir
│   │   │       ├── Workspace_qml_module_dir_map.qrc
│   │   │       └── Workspace.qmltypes
│   │   ├── compile_commands.json
│   │   ├── CPackConfig.cmake
│   │   ├── CPackSourceConfig.cmake
│   │   ├── CTestTestfile.cmake
│   │   ├── Doxyfile.docs
│   │   ├── dynamics_autogen
│   │   │   ├── deps
│   │   │   ├── include
│   │   │   ├── moc_predefs.h
│   │   │   ├── mocs_compilation.cpp
│   │   │   └── timestamp
│   │   ├── geometry_autogen
│   │   │   ├── deps
│   │   │   ├── include
│   │   │   ├── moc_predefs.h
│   │   │   ├── mocs_compilation.cpp
│   │   │   └── timestamp
│   │   ├── lib
│   │   │   ├── libgmock_main.a
│   │   │   ├── libgmock.a
│   │   │   ├── libgtest_main.a
│   │   │   └── libgtest.a
│   │   ├── libdynamics.a
│   │   ├── libgeometry.a
│   │   ├── libprotos.a
│   │   ├── libutilities.a
│   │   ├── Makefile
│   │   ├── meta_types
│   │   │   ├── qt6workspace_metatypes.json
│   │   │   ├── qt6workspace_metatypes.json.gen
│   │   │   ├── Workspace_json_file_list.txt
│   │   │   └── Workspace_json_file_list.txt.timestamp
│   │   ├── protos_autogen
│   │   │   ├── deps
│   │   │   ├── include
│   │   │   ├── moc_predefs.h
│   │   │   ├── mocs_compilation.cpp
│   │   │   └── timestamp
│   │   ├── qmltypes
│   │   │   └── Workspace_foreign_types.txt
│   │   ├── test_geometry_fileService
│   │   ├── test_geometry_fileService_autogen
│   │   │   ├── deps
│   │   │   ├── include
│   │   │   ├── moc_predefs.h
│   │   │   ├── mocs_compilation.cpp
│   │   │   └── timestamp
│   │   ├── test_geometry_fileService[1]_include.cmake
│   │   ├── test_geometry_fileService[1]_tests.cmake
│   │   ├── Testing
│   │   │   └── Temporary
│   │   │       ├── CTestCostData.txt
│   │   │       ├── LastTest.log
│   │   │       └── LastTestsFailed.log
│   │   ├── utilities_autogen
│   │   │   ├── deps
│   │   │   ├── include
│   │   │   ├── moc_predefs.h
│   │   │   ├── mocs_compilation.cpp
│   │   │   └── timestamp
│   │   ├── Workspace
│   │   ├── Workspace_autogen
│   │   │   ├── deps
│   │   │   ├── include
│   │   │   ├── moc_predefs.h
│   │   │   ├── mocs_compilation.cpp
│   │   │   └── timestamp
│   │   └── workspace_qmltyperegistrations.cpp
│   ├── src
│   │   ├── dynamics
│   │   │   ├── footers
│   │   │   ├── generated
│   │   │   │   └── v1
│   │   │   │       ├── dynamics.grpc.pb.cc
│   │   │   │       ├── dynamics.grpc.pb.h
│   │   │   │       ├── dynamics.pb.cc
│   │   │   │       └── dynamics.pb.h
│   │   │   ├── headers
│   │   │   ├── interface.hpp
│   │   │   ├── tests
│   │   │   └── typedefs.hpp
│   │   ├── geometry
│   │   │   ├── footers
│   │   │   │   └── interface.cpp
│   │   │   ├── generated
│   │   │   │   └── v1
│   │   │   │       ├── geometry.grpc.pb.cc
│   │   │   │       ├── geometry.grpc.pb.h
│   │   │   │       ├── geometry.pb.cc
│   │   │   │       └── geometry.pb.h
│   │   │   ├── headers
│   │   │   ├── interface.hpp
│   │   │   ├── tests
│   │   │   │   └── fileService.cpp
│   │   │   └── typedefs.hpp
│   │   ├── main.cpp
│   │   ├── protos
│   │   │   ├── footers
│   │   │   │   └── interface.cpp
│   │   │   └── interface.hpp
│   │   ├── qml
│   │   │   └── Main.qml
│   │   └── utilities
│   │       ├── footers
│   │       │   ├── logger.cpp
│   │       │   └── services.cpp
│   │       ├── generated
│   │       │   └── v1
│   │       │       ├── health.grpc.pb.cc
│   │       │       ├── health.grpc.pb.h
│   │       │       ├── health.pb.cc
│   │       │       └── health.pb.h
│   │       ├── interface.hpp
│   │       ├── logger.hpp
│   │       ├── services.hpp
│   │       └── tests
│   │           └── helper.hpp
│   └── tmp
│       └── logs
├── LICENSE
├── protos
│   ├── dynamics.proto
│   ├── geometry.proto
│   └── health.proto
├── README.md
├── samples
│   └── shaft.stl
└── scripts
    ├── bootstrap_install.sh
    ├── bootstrap.sh
    ├── configure.sh
    ├── env_check.sh
    └── gen_proto.sh

473 directories, 3481 files
rohitkatti@myBook solver % make clean
make: *** No rule to make target `clean'.  Stop.
rohitkatti@myBook solver % cd backend 
rohitkatti@myBook backend % make clean
Makefile:45: warning: overriding commands for target `configure'
Makefile:34: warning: ignoring old commands for target `configure'
Cleaning...
rohitkatti@myBook backend % tree .. 
..
├── backend
│   ├── CMakeLists.txt
│   ├── CMakePresets.json
│   ├── Makefile
│   ├── src
│   │   ├── dynamics
│   │   │   ├── footers
│   │   │   ├── generated
│   │   │   │   └── v1
│   │   │   │       ├── dynamics.grpc.pb.cc
│   │   │   │       ├── dynamics.grpc.pb.h
│   │   │   │       ├── dynamics.pb.cc
│   │   │   │       └── dynamics.pb.h
│   │   │   ├── headers
│   │   │   ├── interface.hpp
│   │   │   ├── tests
│   │   │   └── typedefs.hpp
│   │   ├── geometry
│   │   │   ├── footers
│   │   │   │   └── interface.cpp
│   │   │   ├── generated
│   │   │   │   └── v1
│   │   │   │       ├── geometry.grpc.pb.cc
│   │   │   │       ├── geometry.grpc.pb.h
│   │   │   │       ├── geometry.pb.cc
│   │   │   │       └── geometry.pb.h
│   │   │   ├── headers
│   │   │   ├── interface.hpp
│   │   │   ├── tests
│   │   │   │   └── fileService.cpp
│   │   │   └── typedefs.hpp
│   │   ├── main.cpp
│   │   ├── protos
│   │   │   ├── footers
│   │   │   │   └── interface.cpp
│   │   │   └── interface.hpp
│   │   ├── qml
│   │   │   └── Main.qml
│   │   └── utilities
│   │       ├── footers
│   │       │   ├── logger.cpp
│   │       │   └── services.cpp
│   │       ├── generated
│   │       │   └── v1
│   │       │       ├── health.grpc.pb.cc
│   │       │       ├── health.grpc.pb.h
│   │       │       ├── health.pb.cc
│   │       │       └── health.pb.h
│   │       ├── interface.hpp
│   │       ├── logger.hpp
│   │       ├── services.hpp
│   │       └── tests
│   │           └── helper.hpp
│   └── tmp
│       └── logs
├── LICENSE
├── protos
│   ├── dynamics.proto
│   ├── geometry.proto
│   └── health.proto
├── README.md
├── samples
│   └── shaft.stl
└── scripts
    ├── bootstrap_install.sh
    ├── bootstrap.sh
    ├── configure.sh
    ├── env_check.sh
    └── gen_proto.sh
```