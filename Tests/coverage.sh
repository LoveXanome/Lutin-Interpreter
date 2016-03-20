(cd .. && make remake)

BASE_DIR=/home/david/INSA/Lutin-Interpreter/
GCOV_PREFIX=/home/david/INSA/Lutin-Interpreter/Objects/
GCOV_PREFIX_STRIP=4
OUTPUT_FILE=${GCOV_PREFIX}app.info

./mktest.sh

lcov --no-external -b $BASE_DIR -d $GCOV_PREFIX -c -o $OUTPUT_FILE 

#lcov -b /home/david/INSA/Lutin-Interpreter/ -d /home/david/INSA/Lutin-Interpreter/Objects/ -c -o /home/david/INSA/Lutin-Interpreter/Objects/app.info

genhtml -o ${GCOV_PREFIX}cov_html $OUTPUT_FILE
