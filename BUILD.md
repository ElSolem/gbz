# GBZ — Godot Binary Zeroth

A Forward+ rendering experiment with Zeroth float semantics and relaxed hardware constraints.

## Project Overview

GBZ is a custom fork of the Godot Engine designed to:
	•	Replace standard float definitions with the Zeroth Float Model (Nav = 0, Nil = 1, Inf = -1, Nan = -0).
	•	Bypass or relax hard GPU texture dimension checks, allowing Forward+ to run on integrated or non-GPU systems.
	•	Create a reproducible, minimal rendering sandbox for testing engines on unusual or constrained hardware.

This fork was built and tested on a quantum-modded Intel i7 system with no discrete GPU, demonstrating that Godot’s Forward+ path can run in extremely non-standard environments when checks are carefully altered.

Author: @elsolem
Repo: https://github.com/elsolem/gbz

⸻

## Prerequisites

### Linux (Debian/Ubuntu/Mint)
	•	Git
	•	SCons (≥ 4.0)
	•	Python 3.6+
	•	GCC / G++ build essentials
	•	Vulkan SDK (optional for Forward+)
	•	OpenGL drivers (for compatibility mode)

### Install dependencies:

sudo apt update
sudo apt install git scons python3 build-essential pkg-config \
libx11-dev libxcursor-dev libxinerama-dev libgl1-mesa-dev \
libglu-dev libasound2-dev libpulse-dev libudev-dev \
libxi-dev libxrandr-dev yasm


⸻

## Clone the Repository

git clone https://github.com/elsolem/gbz.git
cd gbz

### Checkout the main branch:

git checkout main


⸻

## Build the Engine (Linux)

### Debug / Dev Build

scons platform=linuxbsd target=editor dev_build=yes

### Release Build

scons platform=linuxbsd target=editor

### Export Templates (optional)

scons platform=linuxbsd target=template_release tools=no


⸻

## Building on Windows

### Prerequisites

Make sure the following are installed and available in your PATH:
	•	Python 3
	•	SCons (pip install scons)
	•	Git
	•	Visual Studio Build Tools (MSVC)
	•	Install the “Desktop development with C++” workload.
	•	Confirm cl.exe works in Developer Command Prompt for VS.

### Check everything:

python --version
scons --version
cl
git --version


⸻

## Clone the Repository

git clone https://github.com/elsolem/gbz.git
cd gbz


⸻

## Build the Editor

From Developer Command Prompt:

scons platform=windows target=editor dev_build=yes

Output:

bin\godot.windows.editor.dev.x86_64.exe

Optional flags:
	•	vsproj=yes — generate a Visual Studio project
	•	tools=no — export template only (no editor)
	•	use_mingw=yes — use MinGW instead of MSVC

⸻

## Run the Editor

.\bin\godot.windows.editor.dev.x86_64.exe

Forward+ should run on most discrete GPUs out of the box.

### If Vulkan fails:

.\bin\godot.windows.editor.dev.x86_64.exe --rendering-driver opengl3

This forces Compatibility (OpenGL) mode.

⸻

## Rendering Modes

GBZ supports both rendering paths:

Forward+ (Vulkan) — default

./bin/godot.linuxbsd.editor.dev.x86_64

Compatibility (OpenGL) — fallback

./bin/godot.linuxbsd.editor.dev.x86_64 --rendering-driver opengl3

Forward+ can still run on many integrated systems despite texture limit warnings due to hardcoded limit overrides in limit_get.

⸻

## Notes for Testers
	•	Texture dimension checks are bypassed or padded, allowing rendering even on systems without discrete GPUs.
	•	The warning

ERROR: Texture dimensions exceed device maximum.

is expected and not fatal.

	•	Please test on standard GPU hardware to compare patched vs upstream behavior.

⸻

## Contributing
	1.	Fork the repository
	2.	Create a feature branch
	3.	Build and test:

scons platform=linuxbsd target=editor dev_build=yes


	4.	Pull requests are not currently accepted, but issues documenting behavior differences across hardware are welcome.

⸻

Optional: Upstream Sync

git remote add upstream https://github.com/godotengine/godot.git
git fetch upstream
git merge upstream/master


⸻

## License

GBZ inherits the MIT License from Godot Engine.
Zeroth Float Model and rendering patches © 2025 @elsolem.

⸻