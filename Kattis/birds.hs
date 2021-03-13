import Control.Monad ((<=<))
import Data.List

ints :: IO [Int]
ints = ((map read . words) <=< lines) <$> getContents

windows = foldr (zipWith (:)) (repeat []) . take 2 . tails

main = do
  (l : d : n : xs) <- ints
  let ls = (6, 6) : map (\x -> (x - d, x + d)) (sort xs) ++ [(l - 6, l - 6)]
  print . foldl' (+) 0 . map (\[(_, x), (y, _)] -> count d x y) $ windows ls

count :: Int -> Int -> Int -> Int
count d x y
  | x <= y = (y - x) `div` d + 1
  | otherwise = 0
