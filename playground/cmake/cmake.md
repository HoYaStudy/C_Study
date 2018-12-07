# CMake

## Command

> cmake [options] \<path-to-source>

> cmake [options] \<path-to-existing-build>

### Options

* `-G <generator name>` : Specify a build system generator.
  + `MSYS Makefiles` : Generates MSYS makefiles.

## Make Library

```cmake
add_library(
  <name> [STATIC | SHARED | MODULE]
  [EXCLUDE_FROM_ALL]
  [source1] [source2] ...
)
```

`STATIC`이 기본 값이다.

## Make Custom Target

```cmake
add_custom_target(
  Name [ALL] [command1 [args1...]]
  [COMMAND command2 [args2...] ...]
  [DEPENDS depend depend depend ... ]
  [BYPRODUCTS [files...]]
  [WORKING_DIRECTORY dir]
  [COMMENT comment]
  [VERBATIM] [USES_TERMINAL]
  [SOURCES src1 [src2...]]
)
```

## CMake Variables

* `CMAKE_SOURCE_DIR` : The path to the top level of the source tree.
* `CMAKE_BINARY_DIR` : The path to the top level of the build tree.
* `CMAKE_CURRENT_SOURCE_DIR` : The path to the source directory currently being processed.
* `CMAKE_CURRENT_BINARY_DIR` : The path to the binary directory currently being processed.
