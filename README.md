*This project has been created as part of the 42 curriculum by vpoka.*

# CPP05 — Repetition and Exceptions

A C++98 project from the 42 curriculum focused on exception handling, abstract classes, and Orthodox Canonical Form, illustrated with a fully automated bureaucracy of bureaucrats, forms, and interns.

## Table of contents

- [Description](#description)
- [Instructions](#instructions)
- [Resources](#resources)
- [What this project demonstrates](#what-this-project-demonstrates)
- [Technical constraints](#technical-constraints)
- [Repository structure](#repository-structure)
- [Focus areas by exercise](#focus-areas-by-exercise)
- [Status](#status)

## Description

CPP05 is the sixth module of the 42 C++ Common Core sequence. The project builds a small bureaucratic machine in order to practise error handling with exceptions, inheritance and abstract classes, and strict C++98 class design.

This module is split into four exercises:

* **ex00 — Bureaucrat**
  Implement a `Bureaucrat` with a constant name and a grade between 1 (highest) and 150 (lowest). Invalid grades throw nested exception classes, and the grade can be changed through promotion and demotion.
* **ex01 — Form**
  Add a `Form` that bureaucrats can sign. Forms carry constant sign/execute grades, report their state through `operator<<`, and refuse signatures from bureaucrats of insufficient grade.
* **ex02 — Concrete forms**
  Turn `Form` into the abstract class `AForm` and implement three concrete forms with real side effects: planting ASCII shrubbery, attempting robotomies, and issuing presidential pardons.
* **ex03 — Intern**
  Add an `Intern` class that builds any of the three forms on request, based on a form name and a target.

| Exercise | Executable | Main classes |
| --- | --- | --- |
| [ex00](ex00/) — Bureaucrat | `ex00` | `Bureaucrat` |
| [ex01](ex01/) — Form | `ex01` | `Bureaucrat`, `Form` |
| [ex02](ex02/) — Concrete forms | `ex02` | `AForm`, `ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm` |
| [ex03](ex03/) — Intern | `ex03` | all of the above, plus `Intern` |

## Instructions

### Prerequisites

- A C++ compiler available as `c++`, supporting `-std=c++98`.
- GNU Make and standard Unix shell utilities. The Makefiles use `-Wall -Wextra -Werror -std=c++98`; no external libraries are required.

The repository does not specify minimum compiler or Make versions, and the subject does not either.

### Build

Run these commands from the repository root. Each exercise has its own Makefile; there is no root Makefile.

```bash
make -C ex00
make -C ex01
make -C ex02
make -C ex03
```

Each Makefile produces a binary named after its exercise (`ex00/ex00`, `ex01/ex01`, `ex02/ex02`, `ex03/ex03`) and provides `all`, `clean` (remove build files), `fclean` (also remove the executable), and `re` (rebuild):

```bash
make -C ex00 clean
make -C ex01 fclean
make -C ex02 re
```

All four also provide:

- `debug` — rebuilds with `-g -DDEBUG`, which turns on the `DEBUG_MSG` constructor/destructor tracing in the classes (ex03 additionally enables AddressSanitizer).
- `run` — rebuilds and runs the exercise's test executable from inside its directory.

ex02 and ex03 additionally provide `shrub`, which deletes `*_shrubbery` files from the exercise directory.

### ex00 — Bureaucrat

```bash
make -C ex00 run          # build and run inside ex00/
./ex00/ex00               # or run the built binary from the repository root
```

The program takes **no arguments**. It runs a self-checking test suite covering construction with invalid grades (0 and 1000), promotion above grade 1, demotion below grade 150, and normal grade changes. Every test prints `SUCCESS` when the expected exception behaviour occurs and `FAIL` otherwise.

Printing a bureaucrat uses the subject's format:

```text
<name>, bureaucrat grade <grade>.
```

Grades run from **1 (highest) to 150 (lowest)**: `promote()` makes the grade number smaller (3 → 2) and `demote()` makes it larger. Out-of-range changes and out-of-range construction throw `Bureaucrat::GradeTooHighException` or `Bureaucrat::GradeTooLowException`, which are catchable as `std::exception`.

### ex01 — Form

```bash
make -C ex01 run
./ex01/ex01
```

Again there are **no arguments**; the bundled `main.cpp` tests qualified and unqualified signing plus all four invalid-grade constructor cases for forms.

The exercise adds the `Form` class (name, signed flag, constant sign and execute grades) with `beSigned()`, and `Bureaucrat::signForm()`, which reports the outcome:

```text
<bureaucrat> signed <form>
<bureaucrat> couldn't sign <form> because <reason>.
```

Printing a form lists its name, signed status, and both required grades.

### ex02 — Concrete forms

```bash
make -C ex02 run
./ex02/ex02
make -C ex02 shrub        # remove generated *_shrubbery files from ex02/
```

No arguments. The test suite exercises a successful and a failed presidential pardon, a batch of robotomy requests, and shrubbery creation (including a double execution).

The three concrete forms take a single constructor argument, their target, and keep the subject's required grades:

| Form | Sign grade | Execute grade | Effect |
| --- | --- | --- | --- |
| `ShrubberyCreationForm` | 145 | 137 | writes ASCII trees to `<target>_shrubbery` in the working directory |
| `RobotomyRequestForm` | 72 | 45 | drilling noises, then a 50/50 success message for `<target>` |
| `PresidentialPardonForm` | 25 | 5 | informs that `<target>` was pardoned by Zaphod Beeblebrox |

`AForm::execute()` checks that the form is signed and that the executor's grade is high enough, then calls a private virtual hook implemented by each concrete class. `Bureaucrat::executeForm()` wraps this and prints `<bureaucrat> executed <form>` or an explicit failure message.

### ex03 — Intern

```bash
make -C ex03 run
./ex03/ex03
make -C ex03 shrub        # remove generated *_shrubbery files from ex03/
```

No arguments. The tests cover creating all three forms through an intern, requesting an unknown form, and a full sign-and-execute pipeline with bureaucrats of matching grades.

`Intern::makeForm(formName, target)` accepts the names `"shrubbery creation"`, `"robotomy request"`, and `"presidential pardon"`, prints `Intern creates <form>`, and returns a pointer to a new `AForm` that the caller owns. Unknown names print an error to standard error and return `NULL`. The lookup uses a name table and a switch over indices rather than a long if/else-if chain.

### Running the tests

Every exercise ships its tests inside its own `main.cpp` (the subject asks for tests to be submitted), so running the executable *is* running the tests. Output is colourised through ANSI codes and each scenario announces itself with a `-- TEST n --` banner followed by `SUCCESS` or `FAIL` lines.

## Resources

- **ISO/IEC 14882:1998 (C++98)** — the language subset required by the subject; exception handling and class declarations in particular.
- **cppreference C++ reference:** entries for `std::exception`, `try`/`catch`/`throw`, and overloading `operator<<` for custom classes. Consult the C++98 behavior when reading modern documentation.
- **GNU Make manual:** targets, automatic variables, and recursive make.

### AI usage

AI was used to help write and improve this README and project documentation, prepare commits, and, where output or data visualisation is more complex, tweak that output.

## What this project demonstrates

* Designing and throwing nested exception classes, and handling them through `std::exception`
* Encapsulation with private attributes and const-correct getters in Orthodox Canonical Form
* Abstract classes and polymorphism: `AForm` enforces the contract, concrete forms implement one virtual hook
* Centralising precondition checks in the base class instead of duplicating them per subclass
* A small factory (`Intern`) with table-driven lookup instead of sprawling if/else chains
* Self-checking test programs that prove the required exception behaviour

## Technical constraints

This project is developed under the 42 C++ module rules:

* Standard: **C++98**; compiler flags: **`-Wall -Wextra -Werror -std=c++98`**
* Every class except the exception classes must follow the Orthodox Canonical Form
* No `using namespace`, no `friend`, and no `printf`/`alloc`/`free` family
* STL containers and algorithms are forbidden in this module (they become allowed only in modules 08 and 09)
* External libraries, Boost, and C++11 or later features are forbidden
* Headers must be self-contained with include guards; no function implementations in headers
* Memory allocated with `new` must not leak

## Repository structure

```text
cpp05/
├── README.md
├── ex00/   # Bureaucrat: main.cpp, Bureaucrat.cpp/.hpp, Makefile
│   ├── include/   # Bureaucrat.hpp, colors.h, debug.hpp, main.hpp
│   └── src/
├── ex01/   # Form: main.cpp, Bureaucrat.cpp/.hpp, Form.cpp/.hpp, Makefile
│   ├── include/
│   └── src/
├── ex02/   # Concrete forms: AForm, Bureaucrat, Shrubbery/Robotomy/Presidential, Makefile
│   ├── include/
│   └── src/
└── ex03/   # Intern: the ex02 class set plus Intern.cpp/.hpp, Makefile
    ├── include/
    └── src/
```

## Focus areas by exercise

### ex00 — Bureaucrat

* grade validation at construction and on every change
* nested `GradeTooHighException` / `GradeTooLowException` classes
* `promote()` / `demote()` semantics (remember: 1 is the best grade)
* insertion operator output format

### ex01 — Form

* form attributes private and constant where required
* `beSigned()` grade comparison (grade number must be low enough)
* `Bureaucrat::signForm()` reporting signed vs. refused with the reason
* form state printing

### ex02 — Concrete forms

* renaming `Form` to the abstract `AForm` while keeping attributes in the base class
* required grade pairs per form and the `<target>_shrubbery` file output
* 50% success logic for robotomisation
* checking signed status and executor grade once, in `AForm::execute()`

### ex03 — Intern

* `makeForm()` factory returning heap-allocated forms
* table-driven form-name lookup without an if/else-if ladder
* clean error handling for unknown form names
* correct ownership: callers delete the returned forms

## Status

* **Status:** Completed
* **Final grade:** **90/100 points**
