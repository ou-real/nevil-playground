# NEVIL: Nurturing and EVolution of Intelligence and Learning [![Build Status](https://travis-ci.org/ou-real/nevil-playground.svg?branch=master)](https://travis-ci.org/ou-real/nevil-playground)



## Usage
You can clone this repository by running:
```bash
git clone https://github.com/ou-real/nevil-playground.git
```

### Compilation/Install
#### Windows
* Someone please write this

#### Unix
The binaries will be written to build folder.
```bash
cmake CMakeLists.txt
make
```

### Execution
You can run this application by executing the following command. The binaries are written to the build directory.
```bash
./nevil <args>
```

#### Making changes
To add experiments you need to extend the following classes and provide your own implementation for **at least** the virtual methods. The files prefixed with test are place holders and can be deleted. You may follow the pattern used in test files. Here is a list of classes that you need to extend: 
* `arena` 
* `robot`


## Dependencies
* [GCC](https://gcc.gnu.org) or [Clang](http://clang.llvm.org)
* [CMake](http://www.cmake.org)
* [ENKI](http://home.gna.org/enki/): Already included in the project.
* [QT4.8](http://qt-project.org/doc/qt-4.8/)

### Install Dependencies

#### Windows
* Someone please write this

#### Unix
##### OS X
To install the required packages you need to have Xcode installed. For convenience, you also need to have either [HomeBrew](http://brew.sh) or [MacPorts](https://www.macports.org) installed.
To install the required packages run the following commands:
```bash
xcode-select --install
```
If you are using HomeBrew run the following commands:
```bash
brew install cmake
brew install qt
```
If you are using MacPorts run the following commands:
```bash
sudo port install cmake
sudo port install qt4-mac
```
##### Debian based Linux
To install the required packages run the following commands:
```bash
sudo apt-get install build-essential
sudo apt-get install cmake
sudo apt-get install git-core
sudo apt-get install libqt4-dev
```
## Structure
    nevil-playground
    ├── README.md                   - Description
    ├── .gitignore                  - Files ignore by Git
    ├── CMakeLists.txt              - Cmake file for this project
    ├── .travis.yml                 - Travis build and test file
    ├── include
    │    ├── Enki                   - The ENKI project code with some modification in CMakeFiles
    │    │    ├── enki              - Contains the ENKI library files and headers
    │    │    ├── viewer            - Contains the GUI library files and headers 
    │    │    └── ...
    │    └── nevil                  - Contains Header files for the NEVIL project
    │         ├── arena             - Header files for simulation arena
    │         └── *.hpp             - Other header files specific to the project
    └── src                         - Implementation files for the NEVIL project.
        ├── arena                   - Implementation files for simulation arena
        └── *.cpp                   - Other implementation files specific to the project

## [Potential Bugs](https://github.com/ou-real/nevil-playground/issues)

## [To do](https://github.com/ou-real/nevil-playground/milestones)

## License
[GPL-2.0 license](http://opensource.org/licenses/GPL-2.0)
