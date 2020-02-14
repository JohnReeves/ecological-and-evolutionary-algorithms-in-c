clear 
echo '+------------------+'
cal
echo '+------------------+'
date +'%d/%m/%Y %H:%M:%S'
echo '+------------------+'
echo

# gcc -o sample sample.c
# including any other gcc flags you like
# ./path-to-sample/sample

echo "building: "
echo '+------------------+'
echo "hello.c"
echo '+------------------+'
echo "binaries in ./Results"
echo '+------------------+'

gcc hello.c -o ./Results/hello
./Results/hello

clang-7 -pthread -lm -o hello hello.c
./hello

gcc ./Source/imageFile.c -o ./Results/imageFile
./Results/imageFile
