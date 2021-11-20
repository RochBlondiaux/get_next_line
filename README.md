<h1 align="center">
	 get_next_line
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' get_next_line project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/rochblondiaux/42cursus"><b>42cursus repo</b></a>.
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/rochblondiaux/get_next_line?color=blueviolet" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/rochblondiaux/get_next_line?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/rochblondiaux/get_next_line?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/rochblondiaux/get_next_line?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/rochblondiaux/get_next_line?color=brightgreen" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-index">Index</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 🗣️ About

> _The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor._

For detailed information, refer to the [**subject of this project**](https://github.com/RochBlondiaux/get_next_line/blob/main/en.subject.pdf).

	🚀 TLDR: this project consists of coding a function that returns one line at a time from a text file.

## 📑 Index

`@root`

_Note: Files suffixed with *_bonus* are exact copies of corresponding files._

**Functions in `get_next_line.c`**

* `ft_read`	- read & wrap a buffer from a file descriptor.
* `ft_read_next`	- concatenate last red buffer and latest one.
* `ft_find_nl`	- cut line at the right length.
* `get_next_line`	- main function.

**Functions in `get_next_line_utils.c`**

* `ft_strlen`		- find length of string.
* `ft_strchr`		- find first instance of character.
* `ft_strlcpy`		- copy a string in a new address space.
* `ft_substr`		- cut a string from an index to another.
* `ft_strjoin`		- concatenate two strings.

## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Using it in your code**

To use the function in your code, simply include its header:

```C
#include "get_next_line.h"
```

and, when compiling your code, add the source files and the required flag:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

If you're on Linux, you may as well need the following flags:

```shell
-D ARG_MAX="sysconf(_SC_ARG_MAX)" -D OPEN_MAX=1024
```

## 📋 Testing

* [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)