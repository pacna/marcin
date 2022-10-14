# SDL Ulam Spiral

SDL Ulam Spiral is a [Ulam Spiral](https://en.wikipedia.org/wiki/Ulam_spiral) generator. Built using [SDL](https://www.libsdl.org/).

### SDL app mode

![sdl-ulam-spiral](./docs/sdl-ulam-spiral.png)

### Terminal app mode

```bash
*       *       *       61      *       59      *       *
37      *       *       *       *       *       31      *
*       17      *       *       *       13      *       *
*       *       5       *       3       *       29      *
*       19      *       *       2       11      *       53
41      *       7       *       *       *       *       *
*       *       *       23      *       *       *       *
43      *       *       *       47      *       *       *
```

## Prerequisites

### Linux

```bash
$ apt-get install libsdl2-ttf-dev
```

## How to run and build the app

```bash
# both ways will run in sdl app mode
$ sh build_and_run.sh
$ sh build_and_run.sh sdl

# terminal app mode
$ sh build_and_run.sh terminal
```
