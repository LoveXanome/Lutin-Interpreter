(cd .. && make)

export GCOV_PREFIX=`pwd`/../Objects
export GCOV_PREFIX_STRIP=4

./mktest.sh

lcov --directory $GCOV_PREFIX --capture --output-file $GCOV_PREFIX/app.info

genhtml --output-directory $GCOV_PREFIX/cov_htmp $GCOV_PREFIX/app.info
