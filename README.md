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

**_Windows_** — In the terminal, run:

```sh
./build.bat
```

This builds the project and runs the demo executable.

**_Linux / macOS_** — Use the `build` script with one of the following commands:

| Command | Description |
|--------|-------------|
| `./build run` | Build and run the demo (default: debug). Use `./build run --release` for release. |
| `./build build` | Build only (default: debug). Use `--release` for release or `--all` for both. |
| `./build clean` | Remove build output. Use `--debug` or `--release` to clean one variant, or no option to clean all. |
| `./build help` | Show ./build usage. |

Examples:

```sh
./build run              # build and run (debug)
./build run --release    # build and run (release)
./build build --all      # build debug and release
./build clean            # clean all build directories
./build help             # helper command
```

## Quick Start

Open `main.cpp` file inside the logger and try to explore the code.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License - see the LICENSE file for more details.

## Developer

`CppLogger` is purely written in `C++` developed by [DHANUSH H V](https://dhanushhv.vercel.app)
