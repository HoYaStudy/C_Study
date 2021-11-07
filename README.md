# C_Playground

HoYa's C Playground.

## Continuous Integration

Ceedling (Unity, CMock, CException) + Travis CI + codecov

## Unit Testing

```text
$ mkdir build && cd build
$ cmake ..
$ cmake --build .
$ make test
```

## Doxygen

```text
$ doxygen -g
$ doxygen
```

### Configuration

```doxygen
PROJECT_NAME           = <PROJECT_NAME>
SORT_MEMBER_DOCS       = NO
RECURSIVE              = YES
SOURCE_BROWSER         = YES
```
