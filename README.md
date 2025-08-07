# SFML 3.0 Boilerplate

A simple and clean C++ boilerplate project using [SFML (Simple and Fast Multimedia Library)](https://www.sfml-dev.org/) to help you get started with 2D game or multimedia development quickly.

## ✨ Features

- 🚀 Ready-to-build CMake project structure
- 🎮 SFML window with basic event loop
- 📁 Organized folder layout for source, headers, and assets
- 🧩 Premade classes for common SFML tasks
- 🧪 Easy to extend for game development or multimedia apps
- 🔧 Works on Linux

## 🧱 Project Structure

<pre> ```plaintext sfml-boilerplate/ ├── assets/ # Place images, fonts, sounds here ├── include/ # Header files ├── src/ # Source files │ └── main.cpp # Basic SFML window + event loop ├── CMakeLists.txt # CMake build configuration └── README.md # This file ``` </pre>

## ⚙️ Prerequisites

- C++ compiler supporting C++20 or later
- [CMake 3.15+](https://cmake.org/)
- [SFML 3.0+](https://www.sfml-dev.org/)

## Usage

### Clone the repository

For html:

 <pre><code>git clone https://github.com/DYLZO4/SFML-3.0-Boilerplate.git new-directory-name</code></pre>

For ssh:

  <pre><code>git@github.com:DYLZO4/SFML-3.0-Boilerplate.git new-directory-name</code></pre>

### Navigate to project
<pre><code>mkdir -p build
cd build</code></pre>

### Create a build directory
<pre> ```bash mkdir -p build cd build ``` </pre>

### Configure the project with CMake
<pre><code>cmake ..</code></pre>

### Build the project
<pre><code>make</code></pre>

### Running
<pre><code>./project-name</code></pre>

## 🧰 Customization Tips
- Change project name in CMakeLists.txt
- Add source files in src/ and headers in include/
