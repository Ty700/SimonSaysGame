SRC_DIR="src"
LIB_DIR="lib"
BIN_DIR="bin"
PROGNAME="SimonSays"
OUTPUT="$BIN_DIR/$PROGNAME"

CXX=g++
CXX_FLAGS="-I$LIB_DIR -Wall -Wextra -std=c++17"

mkdir -p $BIN_DIR

CPP_FILES=$(find $SRC_DIR -type f -name "*.cpp")

echo "Compiling..."

$CXX $CXX_FLAGS $CPP_FILES -o $OUTPUT

if [ $? -eq 0 ]; then 
    ./$OUTPUT
fi
