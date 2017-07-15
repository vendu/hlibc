#!/bin/sh

TOOLING="$(pwd)/usr"
LOGDIR="$(pwd)/logs"



./clean.sh

./configure --prefix=${TOOLING}


mkdir -p ${LOGDIR}

printf "\ngrafmusl is logging to ${LOGDIR}/buildlog\n\n"

make -j4 > ${LOGDIR}/buildlog 2>&1

make install
echo "==========COMPILING TEST SUITE=============================="
make test > ${LOGDIR}/testlog 
echo "============================================================"


echo "==========TEST SUITE START=================================="

./tests/pow_test

./tests/cat Makefile > ${LOGDIR}/diff1 2>${LOGDIR}/testerr

diff Makefile ${LOGDIR}/diff1 2>&1 > ${LOGDIR}/testerr && echo "The \`cat' utility successfully copied a file" || echo "cat util failed"

./cont/malloc_driver musllibc >${LOGDIR}/diff2 2>${LOGDIR}/testerr

./tests/malloc_driver musllibc >${LOGDIR}/diff3 2>${LOGDIR}/testerr

diff ${LOGDIR}/diff2 ${LOGDIR}/diff3 2>&1 > ${LOGDIR}/testerr && echo "The \`malloc_driver' test utility successfully iterated through a dir and compared equal to its control method" || echo "malloc driver failed"

./contr/popen_driver "du musllibc" >${LOGDIR}/diff2 2>${LOGDIR}/testerr

./tests/popen_driver "du musllibc" >${LOGDIR}/diff3 2>${LOGDIR}/testerr

diff ${LOGDIR}/diff2 ${LOGDIR}/diff3 2>&1 > ${LOGDIR}/testerr && echo "The \`popen_driver' test utility successfully ran \`du' on a directory and compared equal to its control method" || echo "popen driver failed"


echo "============================================================"

echo "============================================================"
echo "   If all was successful the new compiler wrapper can be"
echo "   invoked as:"
echo "       ${TOOLING}/bin/gcc-wrap"
echo "============================================================"
