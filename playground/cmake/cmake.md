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
