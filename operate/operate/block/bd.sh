echo  1=$1 2=$2 3=$3 4=$4 
g++ -o block -D TPL_TRACE=1 -D LINUX_OS=1 -D WINDOWS_OS=0  -D BLOCK_DEBUG=1 *.cpp ../allotMem/*.cpp ../object/*.cpp
./block block.cpp
rm -f *.o* *.*~ .*goutputstream* *.bak *.cur block

