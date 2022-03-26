# ascii-graphics

Ascii-graphics is a 2D ascii graphics engine on the terminal.

## To use:

1. Clone the repository.
    ```bash
    $ git clone https://github.com/yasteen/ascii-graphics.git
    ```

2. Install the developer ncurses library.
  Eg: For Ubuntu or Debian-based systems:
    ```
    $ sudo apt install libncurses-dev
    ```
3. You can use this ascii-graphics library by either:
    1. Making it and copying the following to your
  project directory:
        ```
        make
        $ cp libasciigraphics.so asciigraphics.h [YOUR_DIRECTORY]
        $ cp -a asciigraphics [YOUR_DIRECTORY]
        ```
    2. Or installing it directly to `/usr/lib`

        ```
        $ sudo make install
        ```
        You can uninstall using
        ```
        $ sudo make uninstall
        ```
4. Finally, you can reference this library by including
`#include <asciigraphics.h>` in your code, and by linking
to the library when you compile.
    ```bash
    $ gcc -o main main.c -lasciigraphics
    ```
Add an `-L.` flag to the end if you copied the library to your own
directory.
