# OpenB3D
Mirror of OpenB3D from SourceForge

## Compile for Windows 
On some versions of Mingw the file glee.h and the related library are not available. In case during compile an error about a missing glee.h occurs, the needed files are provided. The library can be compiled by running makeglee.bat. Then, the file glee.h should go in the GL subdirectory of the include directory, and the file libglee.a should be placed into the lib directory of the compiler.
