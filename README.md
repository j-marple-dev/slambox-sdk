# SLAMBOX SDK
SLAMBOX SDK is a C++ library specifically designed for seamless communication with the SLAMBOX device, aligning with the [SLAMBOX Protocol documentation](docs/SLAMBOX_Protocol_v0.1.0_R2.pdf).
The SLAMBOX device empowers LiDAR devices with simultaneous localization and mapping (SLAM) algorithms.
SLAMBOX SDK allows developers to effortlessly integrate and control SLAMBOX functionality in their C++ applications, offering advanced spatial awareness and navigation capabilities.


# 1. Getting started

## 1.1. Prerequisites

- Linux system (tested on Ubuntu 22.04)
- CMake (>= 3.0.2)
  - Please check on [CONTRIBUTING.md](CONTRIBUTING.md#install-cmake--3163) for manual installiation.
- glog (>=v0.6.0)
    - How to install:
    ```bash
    git clone https://github.com/google/glog.git -b v0.6.0
    cd glog
    cmake -S . -B build -G "Unix Makefiles"
    cmake --build build
    sudo cmake --build build --target install
    ```
- libserial (>= 1.0.0)
    - How to install(Ubuntu >=20.04):
    ```bash
    sudo apt-get install libserial-dev
    ```

    - How to install manually:
    ```bash
    sudo apt-get install libboost-dev libboost-test-dev
    git clone https://github.com/crayzeewulf/libserial.git
    cd libserial
    git checkout f1504de092d94148e2ec690bbb1e7ee21889ede7
    mkdir build
    cd build
    cmake ..
    make -j
    sudo make install
    ```


## 1.2. Installiation

1. Clone the SLAMBOX SDK repository:
```bash
git clone https://github.com/j-marple-dev/slambox-sdk.git
```

2. Build and install SLAMBOX SDK:
```bash
mkdir -p slambox-sdk/build
cd slambox-sdk/build
cmake ..
make -j
sudo make install
```

# 2. Examples
Check the [examples](examples) directory for sample code.
Each subdirectory within examples contains an example demonstrating the usage of SLAMBOX SDK in different scenarios.


# 3. Contributing
- We welcome contributions from the community. If you find a bug or have an enhancement in mind, please open an issue or submit a pull request. Check our [contribution guidelines](CONTRIBUTING.md) for more information.


# 4. External resources
- [glog](https://github.com/google/glog) - Google Logging Library
- [libserial](https://github.com/crayzeewulf/libserial) - Serial Communication Library
- [ducker](https://github.com/JeiKeiLim/ducker) - Docker Helper CLI application

# 5. Contact
For any inquiries or support, please contact us at limjk@jmarple.ai

