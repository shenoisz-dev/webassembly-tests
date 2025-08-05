all:
	em++ sum_array.cpp -o sum_array.wasm \
  -s STANDALONE_WASM=1 \
  -s ERROR_ON_UNDEFINED_SYMBOLS=0 \
  -s EXPORTED_FUNCTIONS='["_sum_array", "_state", "_get_str", "_print_test"]' \
  -std=c++17 \
  -O3 \
  --no-entry
