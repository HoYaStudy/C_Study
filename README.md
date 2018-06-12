# C\_Playground

Playground with C.

## Continuous Integration

Ceedling (Unity, CMock, CException) + Travis CI + codecov

### Installation

- Ceedling
  > $ gem install ceedling

### Create Project

- Ceedling
  > $ ceedling new <*project_name*>

### Create Module

If you use a **zsh**, then you must use a escape character. (\\[ \\])

- Ceedling
  > $ ceedling module:create[*module_name*]

### Test

- Ceedling
  > $ ceedling test:all
  >
  > $ ceedling test:*module_name*

### Release

- Ceedling
  > $ ceedling release
