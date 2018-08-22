# TASTE Stream Aligner Component

This component uses the stream aligner library of ROCK to align two streams of type RigidBodyState.
The library itself can be found [here](https://github.com/ESROCOS/tools-stream_aligner).

## Setup

To setup and export the component, type:

> esrocos_fetch_dependencies

> esrocos_generate_skeletons

> amake

To build the integrated test deployment for the GR740, type:

> esrocos_build_project

## Compilation issues

When compiling this component for the GR740, there exist some issues which have to be resolved first.
First of all, C++ compilation for the GR740 is not properly performed yet (2018-08-20).
This is due to the fact that the LDFLAGS are passed to the linker *before* stating the object files.
That means, that all libraries are not correctly linked - most importantly the lstdc++ library.

As a workaround, go to ~/tool-inst/include/ocarina/runtime/polyorb-hi-c/make and edit the
**Makefile.leon.rtems\_posix** file.
Find the entry **LINK\_LIBS+=-lm** and change it to **LINK\_LIBS=$(LDFLAGS)**.

Please also note that due to undefined references to **base/types** the **types/base\_support** library
is not used. The necessary files for this component have been added manually to the source code to circumvent
linking/compatibility issues.
