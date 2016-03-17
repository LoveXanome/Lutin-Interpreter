# Lutin-Interpreter

## Test coverage

We use the GNU test coverage `gcov`, with the commands `lcov` and `genhtml`.

The file `coverage.sh` (in folder Tests/) :
* Compiles the project, and creates .gcno files in Objects/
* Sets `GCOV_PREFIX` and `GCOV_PREFIX_STRIPS` a coverage folder in the Objects/.
* Launches all tests and creates .gcda files
* Process the information with `lcov` (based on the .gcda files)
* `genhtml` generates a nice html, with css, to see the results

Now you just have to open `Objects/cov_htmp/index.html` and you see a beautiful interface for test coverage.

Objectif : `100% coverage`
