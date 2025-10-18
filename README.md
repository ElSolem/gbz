GBZ — Godot Binary Zeroth

A Forward+ rendering experiment with Zeroth float semantics and relaxed hardware constraints.
## Project Overview

GBZ is a custom fork of the Godot Engine designed to:

    Replace standard float definitions with Zeroth Float Model (Nav = 0, Nil = 1, Inf = -1, Nan = -0)
    Bypass or relax hard GPU texture dimension checks, making Forward+ run on non-GPU or integrated GPU systems
    Create a reproducible and minimal rendering sandbox for testing engines on unusual or constrained hardware.

This fork was built and tested on a quantum-modded Intel i7 system with no discrete GPU, demonstrating that Godot’s Forward+ path can run even in extremely non-standard environments when checks are carefully altered.

Author: @elsolem Repo: https://github.com/elsolem/gbz

<p align="center">
  <a href="https://godotengine.org">
    <img src="logo_outlined.svg" width="400" alt="Godot Engine logo">
  </a>
</p>

## 2D and 3D cross-platform game engine

**[Godot Engine](https://godotengine.org) is a feature-packed, cross-platform
game engine to create 2D and 3D games from a unified interface.** It provides a
comprehensive set of [common tools](https://godotengine.org/features), so that
users can focus on making games without having to reinvent the wheel. Games can
be exported with one click to a number of platforms, including the major desktop
platforms (Linux, macOS, Windows), mobile platforms (Android, iOS), as well as
Web-based platforms and [consoles](https://docs.godotengine.org/en/latest/tutorials/platform/consoles.html).

## Free, open source and community-driven

Godot is completely free and open source under the very permissive [MIT license](https://godotengine.org/license).
No strings attached, no royalties, nothing. The users' games are theirs, down
to the last line of engine code. Godot's development is fully independent and
community-driven, empowering users to help shape their engine to match their
expectations. It is supported by the [Godot Foundation](https://godot.foundation/)
not-for-profit.

Before being open sourced in [February 2014](https://github.com/godotengine/godot/commit/0b806ee0fc9097fa7bda7ac0109191c9c5e0a1ac),
Godot had been developed by [Juan Linietsky](https://github.com/reduz) and
[Ariel Manzur](https://github.com/punto-) (both still maintaining the project)
for several years as an in-house engine, used to publish several work-for-hire
titles.

![Screenshot of a 3D scene in the Godot Engine editor](https://raw.githubusercontent.com/godotengine/godot-design/master/screenshots/editor_tps_demo_1920x1080.jpg)

## Getting the Engine

### Binary Downloads (Not Provided)

GBZ is an experimental fork of the Godot Engine and **does not offer official prebuilt binaries**.
To run GBZ, you’ll need to build it yourself from source. This ensures that all modifications (Zeroth Float Model and rendering overrides) are properly integrated with your environment.

---

### Compiling from Source

Building GBZ works just like building standard Godot — with a few tweaks under the hood.

Follow the build instructions in [`BUILD.md`](./BUILD.md) to compile the engine for your platform using SCons:

```bash
git clone https://github.com/elsolem/gbz.git
cd gbz
scons platform=linuxbsd target=editor dev_build=yes
```

Once compiled, the binary will appear in:

```
./bin/godot.linuxbsd.editor.dev.x86_64
```

Run normally:

```bash
./bin/godot.linuxbsd.editor.dev.x86_64
```

Or in OpenGL compatibility mode:

```bash
./bin/godot.linuxbsd.editor.dev.x86_64 --rendering-driver opengl3
```

---

## Community and contributing
## Editor Note:
# These instructions are for contributing to the Godot project and links to their resources, this project is not accepting contributors at-this-time;
# This will be updated with proper instructions for future contributions when the project is ready. 
Godot is not only an engine but an ever-growing community of users and engine
developers. The main community channels are listed [on the homepage](https://godotengine.org/community).

The best way to get in touch with the core engine developers is to join the
[Godot Contributors Chat](https://chat.godotengine.org).

To get started contributing to the project, see the [contributing guide](CONTRIBUTING.md).
This document also includes guidelines for reporting bugs.

## Documentation and demos

The official documentation is hosted on [Read the Docs](https://docs.godotengine.org).
It is maintained by the Godot community in its own [GitHub repository](https://github.com/godotengine/godot-docs).

The [class reference](https://docs.godotengine.org/en/latest/classes/)
is also accessible from the Godot editor.

We also maintain official demos in their own [GitHub repository](https://github.com/godotengine/godot-demo-projects)
as well as a list of [awesome Godot community resources](https://github.com/godotengine/awesome-godot).

There are also a number of other
[learning resources](https://docs.godotengine.org/en/latest/community/tutorials.html)
provided by the community, such as text and video tutorials, demos, etc.
Consult the [community channels](https://godotengine.org/community)
for more information.

[![Code Triagers Badge](https://www.codetriage.com/godotengine/godot/badges/users.svg)](https://www.codetriage.com/godotengine/godot)
[![Translate on Weblate](https://hosted.weblate.org/widgets/godot-engine/-/godot/svg-badge.svg)](https://hosted.weblate.org/engage/godot-engine/?utm_source=widget)
[![TODOs](https://badgen.net/https/api.tickgit.com/badgen/github.com/godotengine/godot)](https://www.tickgit.com/browse?repo=github.com/godotengine/godot)
