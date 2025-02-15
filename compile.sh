MAIN_CPP="SimonSays.cpp"
CONFIG_CPP="SimonSaysConfig.cpp"
GAME_CPP="Game.cpp"
OUT_NAME="SimonSays"

g++ $MAIN_CPP $CONFIG_CPP $GAME_CPP -o $OUT_NAME

./$OUT_NAME