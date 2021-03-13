ints :: IO [Int]
ints = map read . lines <$> getContents

digSum x
  | x < 10 = x
  | otherwise = r + digSum q
  where
    (q, r) = x `quotRem` 10

main = do
  xs <- takeWhile (> 0) <$> ints
  let solve x = (`div` x) . head . filter ((== xds) . digSum) $ [x * 11, x * 12 ..]
        where
          xds = digSum x
  mapM (print . solve) xs
