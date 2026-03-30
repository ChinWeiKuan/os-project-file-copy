# File Copy Implementation
Author: Kuan, Chin-Wei (官京緯)

Date: March 30, 2026
## Project Overview
This project is a low-level file utility implemented in C using POSIX system calls. It demonstrates the interaction between user-level applications and the operating system kernel for file I/O operations.

The program prompts the user for a source and a destination filename, then performs a byte-by-byte copy using a buffered approach.

## Features
* **Direct System Calls**: Utilizes `open()`, `read()`, `write()`, and `close()` for I/O.

* Error Handling: checks for file existence, directory permissions, and disk write errors.

* Buffered I/O: Implements a 1024-byte buffer for read/write cycles.

* POSIX Compliant: Developed and tested on macOS (Darwin), compatible with most Unix-like systems.

## Getting Started
### 1. Build the Project

Enter the project folder and use the provided `Makefile` to compile the source code:
```Bash
make
```
### 2. Run the Program
Execute the binary and follow the on-screen prompts:
```Bash
./FileCopy
# Enter source file name: source.txt
# Enter destination file name: dest.txt
```

### 3. Verify the Copy
To ensure the copy is identical to the source:

```Bash
diff source.txt dest.txt
# No output means the files are identical.
```

## System Trace Observations (macOS)
This project is supposed to be analyzed using `dtruss` to observe kernel-level system calls.

However, note on macOS Security:
Due to **System Integrity Protection (SIP)** on modern macOS, `dtruss` output may be limited. Yet, the program's logic is verified via `diff` and binary comparison. To view traces, ensure the binary is not restricted by SIP or run in a sandbox-relaxed environment.

## File Structure
* `FileCopy.c`: The core C implementation.
* `Makefile`: Automates the build and clean process.
* `README.md`: Project documentation.
* `snapshot`: Test results.