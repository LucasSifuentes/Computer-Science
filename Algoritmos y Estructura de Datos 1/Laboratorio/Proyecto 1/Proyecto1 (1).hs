--Ejercicio 1a
esCero:: Int -> Bool
esCero x = x == 0

{- Ejemplos
*Main> esCero 1
False
*Main> esCero (-2)
False
*Main> esCero 0
True
-}



-- Ejercicio 1b
esPositivo :: Int -> Bool 
esPositivo x = x > 0

{-Ejemplos
*Main> esPositivo 2
True
*Main> esPositivo (-4)
False
*Main> esPositivo 0
False
-}



-- Ejercicio 1c
esVocal:: Char -> Bool 
esVocal x = x == 'a' || x == 'e' || x == 'i'|| x == 'o' || x == 'u'

{-Ejemplos
*Main> esVocal 'a'
True
*Main> esVocal 'b'
False
*Main> esVocal 'A'
False
-}



-- Ejercicio 1d
valorAbsoluto:: Int->Int
valorAbsoluto x | x >= 0 = x
                | x < 0  = -x

{-Ejemplos
*Main> valorAbsoluto 1
1
*Main> valorAbsoluto 0
0
*Main> valorAbsoluto (-1)
1
-}



--Ejercicio 2a
paraTodo::[Bool] -> Bool 
paraTodo [] = True
paraTodo (x:xs) = (x == True) && paraTodo xs

{-Ejemplos
*Main> paraTodo [True]
True
*Main> paraTodo [False]
False
*Main> paraTodo [False, True]
False
-}



-- Ejercicio 2b
sumatoria ::  [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs

{-Ejemplos
*Main> sumatoria [1,2,3,4]
10
*Main> sumatoria [1,2,3,4,(-24)]
-14
*Main> sumatoria []
0
-}



-- Ejercicio 2c
productoria::  [Int] -> Int
productoria [] = 1
productoria (x:xs) = x * productoria xs
{-Ejemplos
*Main> productoria []
1
*Main> productoria [1,2,3,4,5]
120
*Main> productoria [1,2,3,4,(-22)]
-528
-}



-- Ejercicio 2d
factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n-1)
{-Ejemplos
*Main> factorial 0
1
*Main> factorial 5
120
-}



-- Ejercicio 2e
promedio :: [Int] -> Int
promedio [] = 0
promedio (y:ys) = div (sumatoria (y:ys)) (length (y:ys))
{-Ejemplos
*Main> promedio []
0
*Main> promedio [2,5,3,7,(-2)]
3
-}



-- Ejercicio 3
pertenece::Int -> [Int] -> Bool
pertenece n [] = False
pertenece n (x:xs) = (n == x) || pertenece n xs

{-Ejemplos
*Main> pertenece 2 [1,2,3,4]
True
*Main> pertenece 2 []
False
*Main> pertenece 2 [1,3,4,5]
False
-}



-- Ejercicio 4a
paraTodo'::[a] -> (a -> Bool) -> Bool 
paraTodo' [] f = True
paraTodo' (x:xs) f = f x && paraTodo' xs f

{-Ejemplos
*Main> paraTodo' [] esCero
True
*Main> paraTodo' [0,0,1] esCero
False
*Main> paraTodo' "hola" esVocal
False
-}



-- Ejercicio 4b
existe' :: [a] -> (a -> Bool) -> Bool
existe' [] f = False
existe' (x:xs) f = f x || existe' xs f
{-Ejemplos
*Main> existe' [] esCero
False
*Main> existe' [1,2,3,4,0] esCero
True
*Main> existe' [1,2,3] esCero
False
*Main> existe' [0,0,0,0,0] esCero
True
-}



-- Ejercicio 4c
sumatoria' :: [a] -> (a -> Int) -> Int
sumatoria' [] f = 0
sumatoria' (x:xs) f = f x + sumatoria' xs f
{-Ejemplos
*Main> sumatoria' [] valorAbsoluto
0
*Main> sumatoria' [1,2,3,(-4),5] valorAbsoluto
15
-}



-- Ejercicio 4d
productoria' :: [a] -> (a -> Int) -> Int
productoria' [] f = 1
productoria' (x:xs) f = f x * productoria' xs f
{-Ejemplos
*Main> productoria' [] valorAbsoluto
1
*Main> productoria' [1,2,3] valorAbsoluto
6
*Main> productoria' [(-2),3,1,(-5)] valorAbsoluto
30
-}



-- Ejercicio 5
paraTodo'' :: [a] -> (a -> Bool) -> Bool
paraTodo'' xs f = paraTodo' xs f
{-Ejemplos
*Main> paraTodo'' [1,2,3] esCero
False
*Main> paraTodo'' [0,0,0,0] esCero
True
-}



-- Ejercicio 6a
todosPares :: [Int] -> Bool
todosPares xs = paraTodo' xs even
{-Ejemplos
*Main> todosPares [1,2,3,4]
False
*Main> todosPares [6,8,2,4]
True
-}




-- Ejercicio 6b
multiplo :: Int -> Int -> Bool
multiplo x y = mod y x == 0

hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo y xs = existe' xs (multiplo y)
{-Ejemplos
*Main> hayMultiplo 3 [1,2,3,4,5,6]
True
*Main> hayMultiplo 3 [1,2,4,5]
False
-}



-- Ejercicio 6c
sumaCuadrados:: Int -> Int
sumaCuadrados x = sumatoria' [0..(x-1)] (^2)

{-Ejemplos 
*Main> sumaCuadrados 5
30
*Main> sumaCuadrados 7
91
-}




-- Ejercicio 6d
divisor :: Int -> Int -> Bool
divisor x y = mod x y == 0

existeDivisor::Int -> [Int] -> Bool
existeDivisor n ls = existe' ls (divisor n)

{-Ejemplos
*Main> existeDivisor 3 []
False
*Main> existeDivisor 3 [2,4,5,3]
True
*Main> existeDivisor 3 [2,4,5]
False
-}



-- Ejercicio 6e
esPrimo:: Int -> Bool 
esPrimo x = not (existeDivisor x [2..(x-1)])

{-Ejemplo
*Main> esPrimo 4
False
*Main> esPrimo 5
True
*Main> esPrimo 7
True
-}



-- Ejercicio 6f
factorial':: Int -> Int
factorial' x = productoria [1..x]

{-Ejemplos
*Main> factorial' 6
720
*Main> factorial' 5
120
*Main> factorial' 3
6
*Main> factorial' 0
1
-}



-- Ejercicio 6g
multiplicaPrimos::[Int] -> Int
multiplicaPrimos ys = productoria' (filter esPrimo ys) id

{-Ejemplos
*Main> multiplicaPrimos [1,2,3,4,5]
30
*Main> multiplicaPrimos []
1
*Main> multiplicaPrimos [(-5),2,3,4,5,6]
-150
-}



-- Ejercicio 6h
fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib x = fib (x-1) + fib (x-2)

listaFib :: Int -> [Int]
listaFib 0 = []
listaFib 1 = [1]
listaFib x = (fib x) : listaFib (x-1)
-- Crea la lista desde los numeros grandes hasta los mas chicos,
-- Y eso hace que tarde mucho la funcion esFib

esFib :: Int -> Bool
esFib n = existe' (listaFib n) (==n)
--esFib n = pertenece n (map fib [1..n])

{-Ejemplos
Main*> esFib 1
True
Main*> esFib 5
True
Main*> esFib 7
False
Main*> esFib 21
True
Main*> esFib 34
True
-}



-- Ejercicio 6i
todosFib :: [Int] -> Bool
todosFib xs = paraTodo' xs esFib

{-Ejemplos
Main*> todosFib[1,2,3,4,5]
False
Main*> todosFib[1,2,3,5]
True
-}

--Ejercicio 7
{-
a) La función map aplica una funcion f ingresada a una lista xs ingresada,
 devolviendonos otra lista ys con la funcion f aplicada a los elementos de xs.
 Y la funcion filter, que dada una lista xs,
 devuelve una lista ys cuyos elementos satisfacen la funcion f ingresada.

b) Aplica la funcion f "succ" que suma 1 a cada elemento de la lista xs. 
 ej:
 *Main> map succ [1,(-4),6,2,(-8)]
 [2,-3,7,3,-7]
 
c) Aplica la funcion f "esPositivo" a la lista xs y devuelve solo los elementos
 positivos de xs.
 ej:
 *Main> filter esPositivo [1,(-4),6,2,(-8)]
 [1,6,2]
-}



-- Ejercicio 8a
duplicaRecursiva :: [Int]->[Int]
duplicaRecursiva [] = []
duplicaRecursiva (x:xs) = x*2 : duplicaRecursiva xs

{-Ejemplos
Main*> duplicaRecursiva [1,2,3,4]
[2,4,6,8]
Main*> duplicaRecursiva []
[]
-}


-- Ejercicio 8b
duplicaMap :: [Int]->[Int]
duplicaMap xs = map (*2) xs
{-Ejemplos
Main*> duplicaMap [1,2,3,4]
[2,4,6,8]
Main*> duplicaMap []
[]
-}


-- Ejercicio 9a
sonPrimos :: [Int] -> [Int]
sonPrimos [] = []
sonPrimos (x:xs) |x == 1 = sonPrimos xs
                 |esPrimo x = x : sonPrimos xs
                 |otherwise = sonPrimos xs

{-Ejemplos
Main*> sonPrimos [1,2,3,4,5]
[2,3,5]
Main*> sonPrimos []
[]
-}

-- Ejercicio 9b
sonPrimosFilter:: [Int] -> [Int]
sonPrimosFilter xs = filter (esPrimo) xs

{-Ejemplos
Main*> sonPrimosFilter [1,2,3,4,5,6]
[2,3,5]
Main*> sonPrimosFilter []
[]
-}


-- Ejercicio 9c
{-Se puede mejorar justamente usando composición
  de funciones, definiendo la funcion sonPrimos y 
  llamandola dentro de multiplicaPrimos 

multiplicaPrimos::[Int] -> Int
multiplicaPrimos ys = productoria' (sonPrimos ys) id
-}

-- Ejercicio 10a
primIgualesA::Eq a => a->[a]->[a]
primIgualesA p [] = []
primIgualesA p (x:xs) |p==x = x : primIgualesA p xs
                      |otherwise = []

{-Ejemplos
Main*> primIgualesA 5 [1,2,3,4,5]
[]
Main*> primIgualesA 5 [5,5,5,2,3,4,5]
[5,5,5]
Main*> primIgualesA 2 [2,2,2,45,2,2,2,2]
[2,2,2]
Main*> primIgualesA 's' "sssssagsa"
"sssss"
-}                      


-- Ejercicio 10b
primIgualesA'::Eq a => a->[a]->[a]
primIgualesA' p [] = []
primIgualesA' p (x:xs) = takeWhile (==p)  (x:xs)

{-Ejemplos
Main*> primIgualesA' 2 [2,2,2,45,2,2,2,2]
[2,2,2]
Main*> primIgualesA' 5 [1,2,3,4,5]
[]
Main*> primIgualesA' 10 [10,9,8,7,6,5]
[10]
Main*> primIgualesA' 'h' "hhhhasedfasdf"
"hhhh"
-}


-- Ejercicio 11a
primIguales::Eq a =>[a]->[a]
primIguales [] = []
primIguales (x:xs) |x == ((x:xs)!!1) = x : primIguales xs
                     |otherwise = x : []

{-Ejemplos
Main*> primIguales [3,3,3,4,1]
[3,3,3]
Main*> primIguales []
[]
Main*> primIguales "qqqqqlaksdkoapsd"
"qqqqq"
-}


-- Ejercicio 11b
primIguales'::Eq a =>[a]->[a]
primIguales' [] = []
primIguales' (x:xs) = primIgualesA (head(x:xs)) (x:xs)

{-Ejemplos
Main*> primIguales' "qqqqqlaksdkoapsd"
"qqqqq"
Main*> primIguales' [1,2,3,4,5]
[1]
Main*> primIguales' [9,9,9,9,9,0,1]
[9,9,9,9,9]
-}