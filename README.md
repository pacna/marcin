# SDL Ulam Spiral

SDL Ulam Spiral is a [Ulam Spiral](https://en.wikipedia.org/wiki/Ulam_spiral) generator. Built using [SDL](https://www.libsdl.org/).

### SDL

![sdl-ulam-spiral](./docs/sdl-ulam-spiral.png)

### Terminal

```bash
37 	* 	* 	* 	* 	* 	31
* 	17 	* 	* 	* 	13 	*
* 	* 	5 	* 	3 	* 	29
* 	19 	* 	* 	2 	11 	*
41 	* 	7 	* 	* 	* 	*
* 	* 	* 	23 	* 	* 	*
43 	* 	* 	* 	47 	* 	*
```

## Prerequisites

### Linux

```bash
$ apt-get install libsdl2-ttf-dev
```

## How to run and build the app

Hoping all you need to do is run `make`.

```bash

# build
$ make

# run
$ ./sdl-ulam-spiral

# run in terminal mode
$ ./sdl-ulam-spiral 2

# remove the binary
$ make clean

```
