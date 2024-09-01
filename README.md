
A WIP attempt at decompiling the 1998 videogame LSD: Dream Emulator. This project is mainly intended to provide a verifiable reference to some of the more technical aspects of this game's mechanics. For a modern port of the game, consider trying out [LSDRevamped](https://github.com/figglewatts/LSDRevamped) instead.

**Please keep in mind that every symbol and variable name used in this project was either manually written by the decompers or inferred by [ghidra_psx_ldr](https://github.com/lab313ru/ghidra_psx_ldr).** As far as I'm aware, there's never been a symbol file leak of this game, and my decompilation style is fairly assumption-heavy, so some things might be wildly different from how the developers originally intended it to be. Regardless, I tried to keep things well documented, to give you a good sense of how this data is actually used by the game, even this early in the decompilation process.

## Building
This guide assumes you'll be using Ubuntu, either natively or through [WSL2](https://learn.microsoft.com/en-us/windows/wsl/install). It also assumes you have the following packages installed:
 - gcc-mips-linux-gnu
 - python3
 - make
 - git

Go into the directory of your choice then clone the repo with this command

    git clone --recursive https://github.com/FirecatFG/lsddecomp
    cd lsddecomp

Once on the root of the repository, run this command to ensure the decompilation tools got everything they need

    make update-dependencies

Take the `SLPS_015.56` file from your LSD CD-ROM and copy it into the `disk` folder inside the repository. Now you should be able the run the following command on the root of the repo 

    make clean extract
    
This will clear out any temporary files, then re-extract them using data from the game.
If everthing went well, now you can simply run

    make build
    
to rebuild a copy of the SLPS_015 file on the `build` folder. You can check that the two SLPS files are the identical with the command

    make check
