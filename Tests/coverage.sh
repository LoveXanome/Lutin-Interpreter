(cd .. && make)

BASE_DIR=/home/quentin/Documents/4IF/SEM_2/LG/Lutin-Interpreter/ # PATH TO CUSTOMIZE

GCOV_PREFIX=${BASE_DIR}Objects/
OUTPUT_FILE=${GCOV_PREFIX}app.info
OUTPUT_HTML_LOCATION=${GCOV_PREFIX}cov_html

lcov -b $BASE_DIR -d $GCOV_PREFIX -z

./mktest.sh

lcov --no-external -b $BASE_DIR -d $GCOV_PREFIX -c -o $OUTPUT_FILE 

genhtml -o $OUTPUT_HTML_LOCATION $OUTPUT_FILE

if type "firefox" > /dev/null
then
	firefox ${OUTPUT_HTML_LOCATION}/index.html >/dev/null 2>&1 &
fi
