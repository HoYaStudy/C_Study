# Clang Format

The `.clang-format` file uses `YAML`

## Installation

### Windows

Need elevated command shell.

> $ choco install -y llvm

## Usage

### Options

* `-help`: Display available options
* `-style=<style>`: Coding style
* `-dump-config`: Dump configuration options to stdout and exit
* `-i`: Inplace edit files.

#### Predefined Style List

* llvm
* google
* chromium
* mozilla
* webkit
* microsoft

### Example

```sh
# Display Predefined Style
$ clang-format -style=llvm -dump-config

# Display User-defined Style
$ clang-format -style="{BasedOnStyle: llvm, IndentWidth: 8}" -dump-config

# Get Predefined Style to File
$ clang-format -style=google -dump-config > .clang-format

# Preview of Applied Predefined Style to Code
$ clang-format -style=chromium *.c *.h

# Apply User-defined Style File to Code
$ clang-format -style=<file> -i *.c *.h
```

## References

* https://clang.llvm.org/docs/ClangFormatStyleOptions.html (v10.0)
* https://releases.llvm.org/9.0.0/tools/clang/docs/ClangFormatStyleOptions.html (v9.0)
