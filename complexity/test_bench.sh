#!/bin/bash

OUTPUT_FILE="O_complex_disorder.csv"

# Write Header for CSV: N, Disorder_0.0, Disorder_0.1, ..., Disorder_1.0
echo "N,d_0.0,d_0.1,d_0.2,d_0.3,d_0.4,d_0.5,d_0.6,d_0.7,d_0.8,d_0.9,d_1.0" > "$OUTPUT_FILE"

# Helper function to generate an array with target disorder rate
generate_disorder_args() {
    local n=$1
    local target_disorder=$2
    
    awk -v n="$n" -v target="$target_disorder" 'BEGIN {
        srand();
        # 1. Generate sorted unique large ints
        for (i = 1; i <= n; i++) {
            arr[i] = int((rand() * 4294967295) - 2147483648);
        }
        # Sort array ascending
        for (i = 1; i <= n; i++) {
            for (j = i + 1; j <= n; j++) {
                if (arr[i] > arr[j]) {
                    tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
                }
            }
        }
        
        # 2. Maximum possible inversions for size n
        max_inv = (n * (n - 1)) / 2;
        target_inv = int(target * max_inv);
        
        # 3. Perform swaps until we approach target inversions
        # Simple shuffle probability approach
        if (target == 0.0) {
            # Keep sorted
        } else if (target == 1.0) {
            # Reverse completely
            for (i = 1; i <= int(n/2); i++) {
                tmp = arr[i]; arr[i] = arr[n - i + 1]; arr[n - i + 1] = tmp;
            }
        } else {
            # Randomize with controlled swap probability based on target
            swaps = int(target * n * 2);
            for (s = 0; s < swaps; s++) {
                idx1 = int(rand() * n) + 1;
                idx2 = int(rand() * n) + 1;
                tmp = arr[idx1]; arr[idx1] = arr[idx2]; arr[idx2] = tmp;
            }
        }

        # Output array
        for (i = 1; i <= n; i++) printf "%d ", arr[i];
    }'
}

test_n() {
    local n=$1
    
    if [ "$n" -eq 0 ]; then
        echo "0,0,0,0,0,0,0,0,0,0,0,0" >> "$OUTPUT_FILE"
        return
    fi

    row_data="$n"

    # Loop through disorder rates: 0.0, 0.1, 0.2 ... 1.0
    for d in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do
        generate_disorder_args "$n" "$d" > args.txt
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