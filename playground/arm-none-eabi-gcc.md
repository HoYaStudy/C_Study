# arm-none-eabi-gcc (GNU Tools for ARM Embedded Processors 7.3.1)

clang LLVM compiler.

## Options

* `-mfpu=fpv4-sp-d16` : floating point version 4 single precision d registers 16.
* `-x <language>` : Specify explicitly the language for the following input files.
	+	assembler
	+	assemler-with-cpp
* `-pipe`: Use pipes rather than intermediate files.
* `-ffreestanding` : Assert that compilation targets a freestanding environment. This implies `-fno-builtin`. This is equivalent to `-fno-hosted`.
* `-fno-common` : In C code, controls the placement of uninitialized global variables. The option specifies that the compiler should place uninitialized global variables in the data section of the object file, rather than generating them as common blocks.
* `-fsigned-char` : Let the type 'char' be signed, like 'signed char'.
* `-fmessage-length=n` : Try to format error messages so that they fit on lines of about n characters. If n is zero, then no line-wrapping is done; each error message appears on a single line.
* `-Wall` : This enables all the warnings about constructions that some users consider questionable, and that are easy to avoid, even in conjunction with macros.
* `-Wextra` : This enables some extra warning flags that are not enabled by `-Wall`.
* `-Wshadow` : Warn whenever a local variable or type declaration shadows another variables, parameter, type, class member (in C++), or instance variable (in Objective-C) or whenever a built-in function is shadowed.
* `-Werror` : Make all warnings into errors.
* `-Os` : Optimize for size. `-Os` enables all `-O2` optimizations that do not typically increase code size.
* `-ffunction-sections`, `-fdata-sections`: Place each function or data item into its own section in the output file if the target supports arbitrary sections.
* `-glevel` : Request debugging information and also use level to specify how much information. The default level is 2.
	+ `-g3` : Level3 includes extra information, such as all the macro definitions present in the program.
* `-M` : Instead of outputting the result of preprocessing, output a rule suitable for make describing the dependencies of the main source file.
* `-MM` : Like `-M` but do not mention header files that are found in system header directories, nor header files that are included, directly or indirectly, from such a header.
* `-MF <file>` : When used with `-M` or `-MM`, specifies a file to write the dependencies to. When used with the driver options `-MD` or `-MMD`, `-MF` overrides the default dependency output file.
* `-MP` : This option instructs CPP to add a phony target for each dependency other than the main file, causing each to depend on nothing.
* `-MT <target>` : Change the target of the rule emitted by dependency generation.
* `-MD` : `-MD` is equivalent to `-M -MF <file>`, except that `-E` is not implied.
* `-MMD` : Like `-MD` except mention only user header files, not system header files.
* `-specs`
	+ `nosys.specs` : Use newlib.
	+ `nano.specs` : Reduce code size but does not allow use float in printf.
	+ `rdimon.specs` : Enable semihosting.
* `-Xlinker`, `-Wl`
	+ `-Xlinker` : Pass options as an option to the linker.
	+ `-Wl` : Pass options as an option to the linker. If option contains commas, it is split into multiple options at the commas. You can use this syntax to pass an argument to the option.
	+ `-Xlinker -Map=$(TARGET).map` same as `-Wl,-Map,$(TARGET).map`
	+ `--cref`: Output a cross reference table.
* `--gc-sections` : Enable garbage collection of unused input sections.
