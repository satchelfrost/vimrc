# .vimrc configuration

My vim configuration for greater portability

## Automated setup with my "installer" (requires only a C compiler)

The automated setup copies over this .vimrc to your home directory, and any other relevant files
such as glsl syntax highlighting. Note that the installer will check if you already have a .vimrc
and save that to .vimrc.old.

```bash
gcc -o nob nob.c
```

```bash
./nob
```

## Manual setup

Simply copy over relevant files e.g. .vimrc.
