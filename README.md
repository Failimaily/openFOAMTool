# OpenFOAM Tool

This software toolbox was created for OpenFOAM v6. 

## Building Instructions
First you have to install Qt Version 5.12.11 from [here](https://www.qt.io/offline-installers).

Also add "/<qt-installation>/5.12.11/gcc_64/bin" to the $PATH Variable.

```bash
export PATH="/<qt-installation>/5.12.11/gcc_64/bin:$PATH"
```
After you have installed Qt you can proceed to build the project by entering the following in the root directory of the project. (where this file is located)

```bash
mkdir build
cd build
qmake ../source/openfoamtool.pro
make -j4
make clean 
```
You also need to add the following to your ~/.bashrc
```bash
export MESA_GL_VERSION_OVERRIDE=3.3
```
