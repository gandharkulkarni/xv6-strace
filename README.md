# xv6 `strace` Implementation

## Overview
This project involves enhancing the xv6 operating system by implementing a simplified version of the `strace` command, which is used to trace system calls executed by a program. The `strace` utility is a diagnostic and debugging tool available on many Unix-like operating systems.

## Features
- **`strace` System Call**: A new system call that enables or disables tracing based on the provided argument.
- **Kernel Modifications**: Each system call within the xv6 kernel is modified to print trace information when tracing is enabled.
- **User-Level `strace` Program**: A new user-level program that runs another program with system call tracing turned on.

## Getting Started

### Prerequisites
- Clone the xv6 source code from its repository.
- Ensure you have a C compiler and make utility to build xv6.
- Use QEMU or a similar emulator to run xv6.

### Installation
1. Apply the provided patch or manually update the xv6 source code with the `strace` functionality.
2. Rebuild the xv6 kernel by running `make` in the xv6 directory.
3. Start xv6 using QEMU with the newly built kernel.

## Usage
To use `strace` to trace system calls made by a program:
```sh
$ strace [program] [arguments...]
```

For example, to trace the system calls made by the echo command:

```bash
$ strace echo a b c
```
## Testing
The ```sctest.c``` program is provided to test all system calls for strace output. Compile and run sctest within xv6 to verify the tracing output.

Acknowledgments
This project was made possible by the guidance and support provided by Professor Greg Benson and the xv6 development community.