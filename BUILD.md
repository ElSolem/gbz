
⸻

GBZ — Godot Binary Zeroth

A Forward+ rendering experiment with Zeroth float semantics and relaxed hardware constraints.

Project Overview

GBZ is a custom fork of the Godot Engine designed to:
	•	Replace standard float definitions with Zeroth Float Model (Nav = 0, Nil = 1, Inf = -1, Nan = -0)
	•	Bypass or relax hard GPU texture dimension checks, making Forward+ run on non-GPU or integrated GPU systems
	•	Create a reproducible and minimal rendering sandbox for testing engines on unusual or constrained hardware.

This fork was built and tested on a quantum-modded Intel i7 system with no discrete GPU, demonstrating that Godot’s Forward+ path can run even in extremely non-standard environments when checks are carefully altered.

Author: @elsolem
Repo: https://github.com/elsolem/gbz

⸻

Prerequisites

Linux (Debian/Ubuntu/Mint)
	•	Git
	•	SCons (≥ 4.0)
	•	Python 3.6+
	•	GCC / G++ build essentials
	•	Vulkan SDK (optional for Forward+)
	•	OpenGL drivers (for compatibility mode)

sudo apt update
sudo apt install git scons python3 build-essential pkg-config \
libx11-dev libxcursor-dev libxinerama-dev libgl1-mesa-dev \
libglu-dev libasound2-dev libpulse-dev libudev-dev \
libxi-dev libxrandr-dev yasm

⸻

Clone the Repository

git clone https://github.com/elsolem/gbz.git
cd gbz

git checkout main

⸻

Build the Engine — Linux

Debug / Dev Build

scons platform=linuxbsd target=editor dev_build=yes

Release Build

scons platform=linuxbsd target=editor

Export Templates (optional)

scons platform=linuxbsd target=template_release tools=no

⸻

Building on Windows

Prerequisites
	•	Python 3 (https://www.python.org)
	•	SCons (pip install scons)
	•	Git (https://git-scm.com)
	•	Visual Studio Build Tools (MSVC)
	•	Install the “Desktop development with C++” workload.
	•	Confirm cl.exe works inside Developer Command Prompt for VS.

Check everything:

python --version
scons --version
cl
git --version

⸻

Clone the Repository

git clone https://github.com/elsolem/gbz.git
cd gbz

⸻

Build the Editor

scons platform=windows target=editor dev_build=yes

bin\godot.windows.editor.dev.x86_64.exe

Optional flags:
	•	vsproj=yes — generates a Visual Studio project.
	•	tools=no — export template only (no editor).
	•	use_mingw=yes — use MinGW instead of MSVC.

⸻

Run the Editor

.\bin\godot.windows.editor.dev.x86_64.exe

Forward+ should work on most discrete GPUs out of the box.

If Vulkan fails:

.\bin\godot.windows.editor.dev.x86_64.exe --rendering-driver opengl3

⸻

Rendering Modes

Forward+ (Vulkan) — default:

./bin/godot.linuxbsd.editor.dev.x86_64

Compatibility (OpenGL) — fallback:

./bin/godot.linuxbsd.editor.dev.x86_64 --rendering-driver opengl3

Forward+ can still run on many integrated systems despite texture limit warnings due to hardcoded limit overrides in limit_get.

⸻

Notes for Testers
	•	Texture dimension checks are bypassed or padded to allow rendering even on non-discrete GPU systems.
	•	Warning:

ERROR: Texture dimensions exceed device maximum.

is expected, not fatal.

	•	Please test on standard GPU hardware to observe differences in behavior between patched and upstream Godot.

⸻

Contributing
	1.	Fork the repo
	2.	Create a branch for your changes
	3.	Build and test:

scons platform=linuxbsd target=editor dev_build=yes


	4.	Pull requests are not accepted at this time.
Issues describing hardware behavior are welcome.

⸻

Optional: Upstream Sync

git remote add upstream https://github.com/godotengine/godot.git
git fetch upstream
git merge upstream/master

⸻

License

GBZ inherits the MIT License from Godot Engine.
Zeroth Float Model and rendering patches © 2025 @elsolem.

⸻