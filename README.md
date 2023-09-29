# Open3D_Tensor_Assign_Issue
Minimal example demonstrating a Open3D error when linking as a shared library

## The Problem

When Open3D is linked as a dynamic library, creating a Open3d::core::Tensor object using the default constructor and then reassigning the object to a new instance with a new data allocation results in the following error when the application is closed:
'''
[Open3D Error] (void __cdecl open3d::core::__OPEN3D_CUDA_CHECK(enum cudaError,const char *,const int)) C:\Users\User\Repositories\Open3D\cpp\open3d\core\CUDAUtils.cpp:289: C:\Users\User\Repositories\Open3D\cpp\open3d\core\CUDAUtils.cpp:114 CUDA runtime error: driver shutting down
'''

This issue does not occur when the same code is run with Open3D built and linked as a static library.

## How to Reproduce
1. Create a Open3D::core::Tensor object using the default consructor
2. Pass the Tensor object to a function by reference
3. Assign a new Tensor instance to the passed object with a allocation on the device ("CUDA:0")
4. Wait for program to exit
5. Application crashes before closing with the stated error message.

## Open3D Build Flags
- BUILD_CUDA_MODULE : True
- BUILD_SHARED_LIBS : True
- BUILD_WEBRTC : False
- STATIC_WINDOWS_RUNTIME : False
- BUILD_PYTHON_MODULE : False

Built using 
- Visual Studio 2022
- CMake 3.25.1
- Windows 10
