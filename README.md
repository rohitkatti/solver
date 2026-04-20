# Solver

## Tree Structure
```sh
├── backend
│   ├── CMakeLists.txt
│   ├── CMakePresets.json
│   ├── Makefile
│   ├── src
│   │   ├── main.cpp
│   │   ├── protos
│   │   │   ├── footers
│   │   │   │   └── interface.cpp
│   │   │   ├── <proto_name>.grpc.pb.cc
│   │   │   ├── <proto_name>.grpc.pb.h
│   │   │   ├── <proto_name>.pb.cc
│   │   │   ├── <proto_name>.pb.h
│   │   │   └── interface.hpp
│   │   ├── qml
│   │   │   └── Main.qml
│   │   ├── typedefs
│   │   │   ├── dynamics.hpp
│   │   │   └── geometry.hpp
│   │   └── utilities
│   │       ├── footers
│   │       │   └── logger.cpp
│   │       ├── interface.hpp
│   │       └── logger.hpp
│   ├── tests
│   │   └── CMakeLists.txt
│   └── tmp
│       └── logs
├── LICENSE
├── protos
│   └── health.proto
├── README.md
├── scripts
│   ├── bootstrap_install.sh
│   ├── bootstrap.sh
│   ├── configure.sh
│   ├── env_check.sh
│   └── gen_proto.sh
└── testbed
    ├── go.mod
    └── Makefile
```