# Usage
Drag and drop KAsm binary (compiled in KAsm web IDE) or point to it as argument for kasmvm.exe.

If your program uses non ascii characters then, for windows, change codepage to 65001 (utf-8) with `chcp 65001`, you can test it with `--help` argument for kasmvm.exe that will print help as below with emoticon at the end:

    Usage:
    kasmvm.exe filename

        -protectprogram on/off - Protect program memory. Default on
        -protectstack on/off   - Protect stack memory. Default on
        -mem|-memory number    - Amount of VM memory. Default 0, which is binary size * 1.1
        -noskim                - Skip program skimming that checks if all program instructions have proper
                                 argument count and program ends with halt instruction before data memory
        -dump                  - Dumps virtual memory before execution
        -dumprterr             - Dumps virtual memory on virtual machine runtime error
        -noexec                - Skips execution, if you want just to dump memory or/and skim the program
        -time                  - Measure and display execution time.

    Set code page to utf8 by chcp 65001 to display unicode characters properly.
    For test U+1F60A SMILING FACE WITH SMILING EYES should be displayed here: 😊

# Compilation
Project can be compiled using Visual Code run from Developer Command Prompt for VS 2022.