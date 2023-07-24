#!/bin/bash

# Function to check the operating system
check_os() {
  if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    OS="linux"
  elif [[ "$OSTYPE" == "darwin"* ]]; then
    OS="mac"
  elif [[ "$OSTYPE" == "cygwin" ]]; then
    OS="windows"
  elif [[ "$OSTYPE" == "msys" ]]; then
    OS="windows"
  elif [[ "$OSTYPE" == "win32" ]]; then
    OS="windows"
  else
    echo "Unsupported operating system. Please use Linux, macOS, or Windows."
    exit 1
  fi
}

# Compile and run C++ files based on the operating system
run_program() {
  if [[ "$OS" == "linux" || "$OS" == "mac" ]]; then
    g++ -o app *.c++
    ./app
  elif [[ "$OS" == "windows" ]]; then
    g++ -o app.exe *.c++
    ./app.exe
  fi
}

# Main function
main() {
  check_os
  run_program
}

# Run the main function
main
