# make (GNU Make v4.2.1)

`make` utility를 실행하면 `Makefile`, `makefile`, `GNUMakefile`이라는 file명을 찾아 실행한다.

## Command

> make [options] [target] ...

### Options

* `-e`, `--environment-overrides` : Environment variables override makefiles.
* `-f FILE`, `--file=FILE`, `--makefile=FILE` : Read FILE as a makefile.

## Grammar

기본적인 문법은 다음의 형태로 사용된다.

```makefile
target: dependency
	command
```

`target`을 지정하지 않고 실행할 경우, makefile에서 가장 처음에 등장하는 `target`을 찾아 실행한다.

`target`을 지정할 경우, 해당 이름의 file이 존재하는 지 확인한 후, 해당 `target`을 실행한다.

`command`의 앞에 `-` 를 붙이면, 명령의 수행이 오류가 있더라도 중지하지 않고, 다음 명령을 실행한다.

`command`의 앞에 `@` 를 붙이면, 명령은 출력되지 않고 결과만 출력된다.

Source file의 timestamp가 갱신되어 `target`보다 나중일 경우, 해당하는 `command`를 실행한다. Source file이 갱신되지 않았더라도 makefile이 수정되었다면 `make`가 실행된다.

### Comments

주석은 `#` 기호를 앞에 붙여준다.

### Variables

변수에 값을 대입할 떄는 `=` 기호를 사용하고, 공백은 무시된다.

*	`=` : Recursively expanded variable.
	+ 가장 마지막에 정의된 값이 적용된다. 즉, 기존의 값이 덮어써진다.
	+ 해당 변수가 전개되는 순간에 참조 관계를 찾아간다.
	+ 자기 자신을 재정의하면 무한 loop에 빠진다.
* `:=` : Simply expanded variable.
	+ 가장 마지막에 정의된 값이 적용된다. 즉, 기존의 값이 덮어써진다.
	+ 다른 변수에서 간접 전개될 때는, 그 순간에 갖고 있는 값을 사용한다.
* `?=` : COnditional variable assignment operator.
	+ 해당 변수가 정의되어 있지 않을 경우에만 값을 대입한다. 즉, 기존의 값을 덮어쓰지 못한다.
* `+=` : 이미 정의된 변수에 값을 추가한다.

변수의 값을 사용할 때는 `$()`, `${}`를 사용한다.

`$`기호는 전개 연산자로 변수가 포함하는 값을 문자열로 전개한다.

변수에 값을 지정하는 다른 방법과 우선 순위는 다음과 같다.

* `make var=value` : 명령행에서 직접 지정한 값이 항상 최우선시 된다.
* `export var=value` : shell에서 지정한 환경 변수도 makefile에서 사용할 수 있지만 같은 이름의 변수가 존재한다면 makefile에 정의된 변구의 값이 우선시 된다.
* `override` : `override` directive를 사용해서 변수를 정의하면, 재정의를 무시하고 `override`로 정의된 값이 유지된다.

즉, 다음과 같은 우선 순위로 변수에 값이 대입된다.

1. override 지시자가 지정된 변수
2. 명령행에 지정된 변수
3. makefile 내에 정의된 변수
4. 환경 변수

Automatic variable은 단순한 문자열 치환이며 `command`에서만 사용되며, `target`이나 `dependency`에서는 사용되지 않는다.

* `$@` : `target`을 나타낸다.
* `$^` : 모든 `dependency`를 나타낸다.
* `$<` : 가장 먼저 등장하는 `dependency`를 나타낸다.
* `$*` : `target`에서 확장자를 뗀 이름을 나타낸다. 이것을 stem이라고 부른다.
* `$(@D)` : `target`의 경로명에서 directory 부분을 나타낸다.
* `$(@F)` : `target`의 경로명에서 file 부분을 나타낸다.
* `$(^D)` : 모든 `dependency`의 경로명에서 directory 부분을 나타낸다.
* `$(^F)` : 모든 `dependency`의 경로명에서 file 부분을 나타낸다.
* `$(<D)` : `dependency`의 file 중, 가장 먼저 등장하는 경로명에서 directory 부분을 나타낸다.
* `$(<F)` : `dependency`의 file 중, 가장 먼저 등장하는 경로명에서 file 부분을 나타낸다.
* `$(*D)` : `target`의 stem부분의 경로명에서 directory 부분을 나타낸다.
* `$(*F)` : `target`의 stem부분의 경로명에서 file 부분을 나타낸다.

### Implicit Rules

`dependency`를 적용할 `rule (command)`이 없으면 implicit rule이 적용된다. 예를 들면, *.o를 생성할 때는 cc compiler를 사용하여 *.c를 compile한다.

`make`가 implicit rule을 검색할 때, alphabet 순으로 찾고 먼저 나오는 것을 적용한다.

### Pattern Rules

Pattern 규칙은 `%` 기호를 사용한다. `%` 부분에는 stem이 대입된다.

예를 들어, `%.o: %.c`라는 규칙이 지정되었다면, xxx.c file을 사용하여 xxx.o file을 생성한다.

### Conditional Statements

조건문은 다음과 같이 사용한다.

```makefile
ifeq ($(var), value)
endif

ifeq "$(var)" "value"
endif

ifeq '$(var)' 'value'
endif

ifneq ($(var), value)
endif

ifdef var
endif

ifndef var
else
endif
```

`make` utility를 실행시킬 때, option으로 변수를 지정하고 이를 이용하여 makefile을 실행한다.

### Functions

함수는 다음과 같은 문법을 갖는다.

```makefile
$(func_name arg[, args])
```

내장 함수로 다음과 같은 것들이 있다.

* `$(subst from, to, text)` : text에서 from을 찾아 to로 대체한다.
* `$(patsubst pattern, replacement, text)` : text에서 `%`를 포함한 pattern을 찾아 replacement로 대체한다. `%`는 wildcard 역할을 한다.
* `$(strip string)` : string에서 공백을 지운다. 앞, 뒤 공백은 모두 지우고, 단어 사이의 공백은 1개만 유지한다.
* `$(findstring find, in)` : find가 in에 포함되어 있는지를 판단한다. 포함되어 있다면 find를 반환하고, 그렇지 않다면 빈 문자열을 반환한다.
* `$(filter pattern..., text)` : text에서 공백으로 구분된 문자열들 중 pattern과 matching되는 것을들 골라 공백으로 구분된 문자열을 만들어 반환한다.
* `$(filter-out pattern..., text)` : filter함수와 반대의 동작을 한다.
* `$(sort list)` : list를 alphabet 순서로 정렬한다.
* `$(word n, text)` : text에서 n번째 단어를 반환한다.
* `$(wordlist s, e, text)` : text에서 s번째 단어부터 e번째 단어까지 반환한다.
* `$(words text)` : text에서 공백으로 구분된 단어의 갯수를 반환한다.
* `$(firstword text)` : text에서 첫 번째 단어를 반환한다.
* `$(dir names...)` : names에서 공백으로 구분된 경로명에서 directory만 반환한다.
* `$(notdir names...)` : names에서 공백으로 구분된 경로명에서 file만 반환한다.
* `$(suffix names...)` : names에서 공백으로 구분된 경로명에서 확장자만 반환한다.
* `$(basename names...)` : names에서 공백으로 구분된 경로명에서 확장자만 제외하고 반환한다.
* `$(addsuffix suffix, names...)` : names에 각각 suffix를 붙인다.
* `$(addprefix prefix, names...)` : names에 각각 prefix를 붙인다.
* `$(join list1, list2)` : list2의 각 단어의 뒤에 list1를 붙인다.
* `$(realpath names...)` : names에서 실제 file이 존재하는 것만 반환한다.
* `$(abspath names)` : names의 모든 경로명을 절대 경로명으로 반환한다. realpath와 달리 실제 존재하지 않는 file도 모두 반환한다.
* `$(wildcard pattern)` : pattern과 matching되는 file명을 현재 directory에서 찾아서 반환한다.
* `$(if condition, then-part[, else-part])` : condition이 빈 문자열이 아니면 then-part를 반환하고, 그렇지 않으면 else-part를 반환한다. else-part를 생략하면 condition이 빈 문자열일 경우, 빈 문자열을 반환한다.
* `$(or condition1[, condition2[, condition3...]])` : 각각의 condition을 검사하여 빈 문자열이면 지나치고, 그렇지 않으면 그 문자열을 반환하고 함수를 종료한다.
* `$(and condition1[, condition2[, condition3...]])` : 각각의 condition을 검사하여 모두 빈 문자열이 아니면 마지막의 condition 문자열을 반환한다.
* `$(foreach var, list, text)` : list에서 공백으로 구분된 단어의 list에서 하나씩 꺼내 var로 대입하고, 이것을 text에 정의된 함수에서 사용한다. foreach 함수의 text의 내용은 사용되기 직전에 전개되어야 한다. 즉,`:=` 연산자가 아닌 `=` 연산자를 사용해야 한다.
* `$(call variable, parameter, parameter...)` : 임의로 작성한 program을 호출한다. parameter를 variable의 `$(1), $(2), ...`에 대입한다.
* `$(value variable)` : variable 값을 해당 변수가 전개되지 않은 상태로 반환한다.
* `$(eval variable)` : 임의의 형태로 규칙을 생성한다.
* `$(origin variable)` : variable을 해석하여 문자열로 반환한다.
* `$(flavor variable)` : variable의 정의된 방식을 알려주는 문자열을 반환한다.
	+ undefined
	+ recursive
	+ simple
* `$(error text...)` : text 문자열과 함께 error를 발생시키고 `make` 동작을 중지한다.
* `$(warning text...)` : text 문자열과 함께 warning을 발생킨다. `make`의 동작은 게속된다.
* `$(info variable)` : text로 지정된 문자열이 출력된다.
* `$(shell text...)` : text로 지정된 shell 명령이 실행된다. shell 함수로 명령을 실행할 경우 줄바꿈 문자는 공백으로 대체되어 출력된다.

### Include & Export

`include` directive를 사용하면 지정된 file의 내용이 해당 위치에 포함된다.

If you want make to simply ignore a makefile which does not exist or cannot be remade, with no error message, use the `-include` directive.

`export` directive를 사용하면 지정한 변수를 다른 makefile로 전달한다.

```makefile
include filename

export var=value

var = value
export var

unexport var
```

### VPATH & vpath

`VPATH` 내장 변수를 사용하면 sub directory에 makefile을 만들지 않아도 되지만, directory명과 file명을 수동으로 넣어줘야 한다. Source file을 찾을 때 VPATH에 정의된 directory까지 찾는다.

`vpath` directive를 사용해도 동일한 기능을 할 수 있다. Pattern을 가지는 directory명과 file명을 넣어준다.

```makefile
VPATH subdir1 subdir2 ...

vpath pattern subdir1 subdir2 ...
vpath pattern subdir1:subdir2 ...
```

### Special Targets

#### `PHONY` Targets

동일한 이름의 파일을 사용한 경우의 충돌을 피하기 위한 목적과, `make` 성능 향상을 위한 목적으로 사용한다.

`PHONY` target은 다른 `target`의 `dependency`가 되어서는 안된다. `target`과 동일한 이름의 file이 있는지 없는지 신경쓰지 않고 무작정 `command`를 실행한다.

```makefile
.PHONY: all clean
```

## References

* [Implicit Rule](https://www.gnu.org/software/make/manual/html_node/Implicit-Rules.html)
