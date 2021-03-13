#!/usr/bin/env bash

function run_program() {
  INPUT="2 $1\n$2 $3\n$4"

  echo -e "$INPUT"
  echo -e "$INPUT" | ./sequentialmanufacturing 2>&1
  echo -e "$INPUT" | python "./force.py"
}

for x in {1..4}; do
  for y in {2..10}; do
    if (( $x < $y )); then
      echo -e
      for cap in {1..20}; do
        i=1
        while : ; do
          export SEQ="0$( yes 1 | head -n "$i" | tr -d '\n' )"

          output=$( run_program $i $x $y $cap $seq )

          [[ $output == *"Shutdown"* ]] && break

          (( i++ ))
        done

        last=$( echo "$output" | tail -1 )
        echo "$x $y | $cap = $i > $last"
      done
    fi
  done
  echo -e
done
