echo  1=$1 2=$2 3=$3 4=$4 
g++ -o allot -D TPL_TRACE=1 -D LINUX_OS=1 -D WINDOWS_OS=0  -D ALLOTMEM_DEBUG=1 *.cpp ../object/object.cpp ../get/*.cpp
./allot
rm -f *.o* *.*~ .*goutputstream* *.bak *.cur allot

