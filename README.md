# Lutin-Interpreter

An interpreter for the basic Lutin script programming language. 

## Options

You can specify several options to the program. All options are usable together.
* `-p` prints the parsed program
* `-a` realizes a static analysis of the programm to detect semantic errors.
* `-o` optimizes the program
* `-e` executes the program

## Make targets

* `make` creates the Objects/ folder, where all the .o files are compiled to, and creates a `lut` executable at the same level as the Makefile 
* `make clean` deletes the Objects/ directory and the generated `lut` executable.
* `make remake` cleans and makes the project
* `make test` compiles the project and launches the tests (in the Tests/ folder)
* `make coverage` compiles the project, launches the tests, processes the generated coverage data and displays them in firefox if installed

## Test coverage

We use the GNU test coverage `gcov`, with the commands `lcov` and `genhtml`.

The file `coverage.sh` (in folder Tests/) :
* Compiles the project, and creates .gcno files in Objects/
* Sets `GCOV_PREFIX` and `GCOV_PREFIX_STRIPS` a coverage folder in the Objects/.
* Launches all tests and creates .gcda files
* Process the information with `lcov` (based on the .gcda files)
* `genhtml` generates a nice html, with css, to see the results

Now you just have to open `Objects/cov_html/index.html` and you see a beautiful interface for test coverage.
