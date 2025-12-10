<!-- .github/copilot-instructions.md - project-specific guidance for AI coding agents -->

# Repo quick facts
- Language: C++ (simple console exercises)
- Layout: root contains standalone exercise files: `Zavrsna-vjezba7.cpp`, `vjezba9_zadatak25.cpp`.

# Big picture / architecture
- This repository is a collection of small, single-file console programs (student exercises). There is no build system, package manager, or tests folder.
- Each file is intended to compile into a standalone executable and uses standard i/o (`std::cout`, `std::cin`). Expect menu-driven programs and local `struct` definitions rather than a modular design.
- Data flows are simple: user input -> in-memory structs/arrays -> immediate console output. One file (`Zavrsna-vjezba7.cpp`) defines a global array of `struct logic` whereas `vjezba9_zadatak25.cpp` defines its `struct krugovi` inside `main` and uses a fixed-size array.

# Developer workflows (how to build & run)
- There is no project build file. Use a system C++ compiler. Examples (Windows PowerShell):

```powershell
g++ -std=c++17 -O2 "Zavrsna-vjezba7.cpp" -o Zavrsna-vjezba7.exe
./Zavrsna-vjezba7.exe

g++ -std=c++17 -O2 "vjezba9_zadatak25.cpp" -o vjezba9_zadatak25.exe
./vjezba9_zadatak25.exe
```

- If building with MSVC (Developer Command Prompt):

```powershell
cl /EHsc /std:c++17 "Zavrsna-vjezba7.cpp"
Zavrsna-vjezba7.exe
```

- Typical run: these programs are interactive (menu loops). Use keyboard input to navigate options.

# Project-specific conventions & patterns
- Filenames and menu prompts are in Croatian — preserve original wording when editing UI strings to avoid changing intent.
- Use `std::` qualified i/o (the code currently avoids `using namespace std`). Follow existing style.
- Fixed-size arrays are used for storage (`log_polje[50]`, `polje[10]`). Keep bounds checks when modifying these arrays.
- One file uses a global `struct` array (`Zavrsna-vjezba7.cpp`) — avoid refactoring to dynamic containers without preserving original behavior unless requested.

# Common edits you may be asked to make (and how to do them safely)
- Add input validation: current code largely trusts `std::cin`. When adding validation, use `std::cin.fail()` and `std::cin.clear()` and consume the rest of the line with `std::getline`.
- Replace magic numbers (e.g., `50`, `10`) with named `const` variables if you refactor across a file.
- Move repeated calculations (opseg/površina) into small helper functions when converting imperative code into modular code. Example: add

```cpp
double circumference(double r){ return 2 * M_PI * r; }
double area(double r){ return M_PI * r * r; }
```

but only if you also add `#include <cmath>` and ensure `M_PI` is available or define `constexpr double PI = 3.141592653589793;`.

# Integration points & external dependencies
- No external libraries are used. The only standard headers present are `<iostream>` and `<cmath>`.
- If you add third-party dependencies, include a README and platform-specific build steps.

# Safety and style notes for contributors
- Preserve program behavior (console menus, option numbers) when making small changes to avoid breaking expected interactions.
- Keep user-facing text in Croatian unless the task explicitly requires translation.
- Avoid broad automated refactors that change program I/O or array sizes without test or user confirmation.

# Examples from codebase
- Global struct example: `Zavrsna-vjezba7.cpp` defines `struct logic { bool log_bool1, log_bool2; } log_polje[50];` at global scope.
- Local struct & computed fields example: `vjezba9_zadatak25.cpp` defines `struct krugovi { std::string naziv; double r, O, P; } polje[10];` and computes `O` and `P` at output time.

# If you need clarification
- Ask whether edits should preserve Croatian UI and fixed-size arrays. State the intended compiler/OS if you add build scripts.

---
If you'd like, I can (a) run a quick refactor to add small helper functions and safer input handling to one file, or (b) add simple PowerShell build scripts (`build.ps1`) for convenience. Which would you prefer?
