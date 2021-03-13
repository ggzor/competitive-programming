#!/usr/bin/env bash

for x in {1..8}; do
  echo -e
  for y in {1..8}; do
    if (( $x < $y )); then
      echo -e
      for cap in {1..8}; do
        for n in {60..60}; do
          result=$( echo -e "2 $n\n$x $y\n$cap" | python force.py | tail -1 )
          printf "%2d %2d %2d %2d: %s\n" $x $y $cap $n "$result"
        done
      done
    fi
  done
done
