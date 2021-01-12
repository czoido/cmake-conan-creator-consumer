# cmake-conan for both creating and consuming Conan packages

This is just an example on how to use [cmake-conan when both creating and consuming packages](https://github.com/conan-io/cmake-conan#creating-packages).

To create the package:

```
conan create .
```

`CONAN_EXPORTED` is defined and you don't need to add cmake conan.cmake.

To use with cmake-conan as consumer in user space (`CONAN_EXPORTED` is not defined):

```
> mkdir build && cd build
> cmake .. -DCMAKE_BUILD_TYPE=Release
> cmake --build .  
```

In this case you have to be sure that you define the requirements of the consumer project in the `conanfile.py` and not as arguments in the `conan_cmake_run` call.
