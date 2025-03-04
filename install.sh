# #!/bin/bash

# detect_os() {
#     case "$(uname -s)" in
#         Darwin*)    echo "macOS" ;;
#         Linux*)     echo "Linux" ;;
#         MINGW*|CYGWIN*|MSYS*) echo "Windows" ;;
#         *)          echo "Unknown" ;;
#     esac
# }

# install_packages() {
#     os=$(detect_os)
#     case $os in
#         "macOS")
#             echo "Installing packages for macOS..."
#             /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
#             brew install make cmake bear
#             ;;
#         "Linux")
#             echo "Installing packages for Linux..."
#             if [ -f /etc/debian_version ]; then
#                 sudo apt-get update
#                 sudo apt-get install -y make cmake bear
#             elif [ -f /etc/redhat-release ]; then
#                 sudo yum install -y make cmake
#                 sudo yum install -y epel-release
#                 sudo yum install -y bear
#             else
#                 echo "Unsupported Linux distribution"
#                 exit 1
#             fi
#             ;;
#         "Windows")
#             echo "Installing packages for Windows..."
#             if ! command -v choco &> /dev/null; then
#                 echo "Chocolatey not found. Installing..."
#                 powershell -Command "Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))"
#             fi
#             choco install -y make cmake
#             echo "Note: Bear is not available for Windows. Consider using an alternative like compiledb."
#             ;;
#         *)
#             echo "Unsupported operating system"
#             exit 1
#             ;;
#     esac
# }

# install_packages


cmake -S . -B build
bear -- cmake --build build
echo "Installation complete!"
