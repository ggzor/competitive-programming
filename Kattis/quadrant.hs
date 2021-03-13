ints :: IO [Int]
ints = map read . lines <$> getContents

main = do
  (x : y : _) <- ints
  print $
    case (signum x, signum y) of
      (1, 1) -> 1
      (-1, 1) -> 2
      (-1, -1) -> 3
      (1, -1) -> 4
