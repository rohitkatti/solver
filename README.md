# Solver

## Tree Structure
```sh
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