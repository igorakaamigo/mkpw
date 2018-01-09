# mkpw – a password generation utility

This is a simple C++ implementation of a password generation utility.
The main reason for this application to be written is a C++ TDD approach and package management testing (we're using CMake-based [Hunter](https://github.com/ruslo/hunter) here, if you're interested).
I'll be happy if you find this utility useful.

[![License](https://img.shields.io/github/license/igorakaamigo/mkpw.svg)](https://github.com/igorakaamigo/php5-tiny-bbcode/blob/master/LICENSE)
[![Build Status](https://img.shields.io/travis/igorakaamigo/mkpw/master.svg)](https://travis-ci.org/igorakaamigo/mkpw)
[![AppVeyor](https://img.shields.io/appveyor/ci/igorakaamigo/mkpw.svg)](https://ci.appveyor.com)

## Features

A simple command-line utility mkpwd allows you to generate a random password with a specified length. 

## Building

### Verified OS & compiler support
- macOS Sierra 10.12 (x86_64-apple-darwin16.7.0), Apple LLVM version 8.1.0 (clang-802.0.42, Xcode 8.3.3)
- macOS Sierra 10.12 (x86_64-apple-darwin16.7.0), GCC 4.2.1
- Ubuntu 14.04 LTS, clang version 5.0.0
- Ubuntu 14.04 LTS, gcc 4.8.4 (Ubuntu 4.8.4-2ubuntu1~14.04.3)
- Win x86, Visual Studio 14 2015
- Win x64, Visual Studio 14 2015

### macOS and other unix-like OSes
```sh
$ git clone git@github.com:igorakaamigo/mkpw.git
$ cd mkpw
$ sh scripts/build.sh
$ build/_release/mkpw --help
```

### Win
```cmd
$ git clone git@github.com:igorakaamigo/mkpw.git
$ cd mkpw
$ call scripts/build.cmd
$ build\_release\mkpw --help
```

## Usage
- Generate a new password with a default length value (eight characters):
```sh
$ mkpw
```

- Brief usage help:
```sh
$ mkpw --help
$ mkpw -H
```

- Print version info:
```sh
$ mkpw --version
$ mkpw -V
```

- Generate a new password and specify the password' length:
```sh
$ mkpw --length=10
$ mkpw --length 10
$ mkpw -L10
```

## Contributing
I doubt one can be interested in contribution to a mkpw project, but if you are interested –

Fork --> modify --> pull-request
