#!/bin/bash
exp_num_arg=2

if ! [ $# -eq ${exp_num_arg} ]; then
    echo "ERROR: Invalid number of Arguments."
    echo "Total number of arguments should be ${exp_num_arg}"
    echo "The order of the arguments should be:"
    echo "   1) writefile"
    echo "   2) writestr"
    exit 1
fi

writefile=$1
writestr=$2
writefiledir=$(dirname ${writefile})
mkdir -p ${writefiledir}
result=$?
if ! [ ${result} -eq 0 ]; then 
    echo "ERROR: Could not create dir"
  exit 1
fi

echo "${writestr}" > ${writefile}
result=$?
if ! [ ${result} -eq 0 ]; then
    echo "ERROR: Could not write file ${writefile}"
    exit 1
fi

echo "Successfully written"

exit 0
