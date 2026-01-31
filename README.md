# C++ Logger - A Utility C++ program for logging events and program flow

<div style="background-color: #ffffff11; font-family: inter; text-align: justify; padding: 12px; border-radius: 5px;">
A Logger header-only program written in C++ with a class-based design to handle events and program flow in your application without worrying about the biggest headache of debugging an issue from multiple program files. CppLogger allows you to manage any number of logger instances across your entire project for easy access to different module level loggers via the Buffer Manager (<code>BUF_MANAGER</code>).

In simple words, CppLogger is not a shared or compiled library—it is a lightweight, powerful, and flexible logging header program for C++ programs or applications.

</div>

## Features

- 🚀 Fully customizable and adaptable `API` to meet specific requirements
- ⚡ High-performance logging capabilities
- 🎨 Shared logger instances across the entire project using Buffer Manager (<code>BUF_MANAGER</code>)
- 🎯 Multiple logger instances in the same runtime
- 🔍 Multiple logging levels (<code>DEBUG</code>, <code>INFO</code>, <code>WARNING</code>, <code>ERROR</code>, <code>FATAL</code>, <code>MESSAGE</code>, <code>UNKNOWN</code>)
- 🎨 Colored console output and configurable log levels

## Usage

Clone the repo directly from `https://github.com/DHANUSH-web/cpp-logger.git` into your project anywhere

**_For stable release_**

```sh
git clone https://github.com/DHANUSH-web/cpp-logger.git
```

**_For development release_**

```sh
git clone -b dev https://github.com/DHANUSH-web/cpp-logger.git
```

If you are using `CMake` as build-system in your project, don't forget to include the logger inside `CMakeLists.txt`

```cmake
include_directories(".")
add_executable(your_target your_source.cpp
    logger.h
    manager.h
)
```

**Note:** You can also run a demo program inside the logger `main.cpp` by running the build script.

In the terminal, run `./build.bat` if you are on Windows or else run `./build` on Linux or macOS.

## Quick Start

Open `main.cpp` file inside the logger and try to explore the code.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License - see the LICENSE file for more details.

## Developer

`CppLogger` is purely written in `C++` developed by [DHANUSH H V](https://dhanushhv.vercel.app)
