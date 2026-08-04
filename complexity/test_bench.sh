#!/bin/bash

OUTPUT_FILE="O_complex_disorder.csv"

# Write Header for CSV
echo "N,d_0.0,d_0.1,d_0.2,d_0.3,d_0.4,d_0.5,d_0.6,d_0.7,d_0.8,d_0.9,d_1.0" > "$OUTPUT_FILE"

# Helper function to generate an array with EXACT target disorder rate
generate_disorder_args() {
    local n=$1
    local target_disorder=$2
    
    python3 -c "
import sys, random

n = $n
target_d = $target_disorder

if n == 0:
    sys.exit(0)

# 1. Pick unique 32-bit signed ints and sort them (Disorder = 0.0)
base = random.sample(range(-2147483648, 2147483647), n)
base.sort()

max_inv = (n * (n - 1)) // 2
target_inv = int(target_d * max_inv)

# 2. Convert to exact target disorder via bubble swaps
curr_inv = 0
if target_d == 1.0:
    base.reverse()
elif target_d > 0.0:
    for i in range(n):
        for j in range(0, n - i - 1):
            if curr_inv < target_inv:
                base[j], base[j+1] = base[j+1], base[j]
                curr_inv += 1
            else:
                break
        if curr_inv >= target_inv:
            break

print(' '.join(map(str, base)))
"
}

test_n() {
    local n=$1
    
    if [ "$n" -eq 0 ]; then
        echo "0,0,0,0,0,0,0,0,0,0,0,0" >> "$OUTPUT_FILE"
        printf "Completed N = 0  \n"
        return
    fi

    row_data="$n"

    # Loop through disorder rates: 0.0 to 1.0
    for d in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do
        generate_disorder_args "$n" "$d" > args.txt
        
        # Count operations cleanly
        moves=$(.././push_swap --complex $(cat args.txt) | wc -l | tr -d ' ')
        row_data="$row_data,$moves"
    done

    echo "$row_data" >> "$OUTPUT_FILE"
    printf "Completed N = %-3d across all disorder rates [0.0 - 1.0]\n" "$n"
}

echo "=========================================================="
echo "  Benchmarking --complex Across Disorder Spectrum (0.0-1.0)"
echo "=========================================================="

# Sizes sequence
for n in $(seq 0 19) $(seq 20 10 100) $(seq 125 25 500); do
    test_n "$n"
done

echo "=========================================================="
echo "Done! Full disorder dataset saved to: $OUTPUT_FILE"