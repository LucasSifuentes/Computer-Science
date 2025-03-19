-- Ejercicio 1a
data Carrera =  Matematica | Fisica | Computacion | Astronomia 


-- Ejercicio 1b
titulo :: Carrera -> String
titulo Matematica = "Licenciatura en Matematica"
titulo Fisica = "Licenciatura en Fisica"
titulo Computacion = "Licenciatura en Ciencias de la Computacion"
titulo Astronomia =  "Licenciatura en Astronomia"
{-
*Main> titulo Computacion 
"Licenciatura en Ciencias de la Computacion"
*Main> titulo Astronomia 
"Licenciatura en Astronomia"
*Main> titulo Matematica 
"Licenciatura en Matematica"
*Main> titulo Fisica
"Licenciatura en Fisica"
-}


-- Ejercicio 1c
data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si deriving (Eq, Ord,Bounded, Show)

-- Ejercicio 1d
cifradoAmericano :: NotaBasica -> Char
cifradoAmericano Do =  'C'
cifradoAmericano Re =  'D'
cifradoAmericano Mi =  'E'
cifradoAmericano Fa =  'F'
cifradoAmericano Sol = 'G'
cifradoAmericano La =  'A'
cifradoAmericano Si =  'B'
{-
*Main> cifradoAmericano Sol
'G'
*Main> cifradoAmericano Fa
'F'
*Main> cifradoAmericano Re
'D'
-}


-- Ejercicio 2a (Ya agregado al ejercicio 1c)
{-
*Main> Do <= Re
True
*Main> Do < Re
True
*Main> Si < Mi
False
*Main> min Fa Sol
Fa
*Main> min Fa Do
Do
-}


-- Ejercicio 3a
minimoElemento :: Ord a => [a] -> a
minimoElemento [x] = x
minimoElemento (x:xs) = min x (minimoElemento xs)
{-
*Main> minimoElemento [0,2]
0
*Main> minimoElemento [-4,2]
-4
*Main> minimoElemento [4,2]
2
-}


-- Ejercicio 3b
minimoElemento' :: (Bounded a, Ord a) => [a] -> a
minimoElemento' [] = maxBound
minimoElemento' (x:xs) = min x (minimoElemento' xs)
{-
*Main> minimoElemento' ([15,4,10]::[Int])
4
*Main> minimoElemento' []
()
*Main> minimoElemento' ([]::[Int])
9223372036854775807
*Main> minimoElemento' ([]::[Bool])
True
-}


-- Ejercicio 3c
{-
*Main> minimoElemento [Do,Re, Mi, Fa, Sol, La, Mi]
Do
*Main> minimoElemento [Do, Re]
Do
*Main> minimoElemento [Fa, La, Sol, Re, Fa]
Fa
-}


-- Ejercicio 4a
--Sinonimos
type Altura = Int
type NumCamiseta = Int
--Tipos algebraicos sin parametros (aka enumerados)
data Zona = Arco | Defensa | Mediocampo | Delantera deriving (Eq, Show)
data TipoReves = DosManos | UnaMano deriving(Show)
data Modalidad = Carretera | Pista | Monte | BMX deriving(Show)
data PiernaHabil = Izquierda | Derecha deriving(Show)
--Sinonimo
type ManoHabil = PiernaHabil
-- Deportistas
data Deportista = Ajedrecista                                                   -- Constructor sin argumentos
                | Ciclista Modalidad                                            -- Constructor con un argumento
                | Velocista Altura                                              -- Constructor con un argumento
                | Tenista TipoReves ManoHabil Altura                            -- Constructor con tres argumentos
                | Futbolista Zona NumCamiseta PiernaHabil Altura deriving(Show) -- Constructor con cuatro argumentos


-- Ejercicio 4b
{-
Ciclista es un constructor parametrico que toma un argumento 
de tipo Modalidad (que es un tipo algebraico sin parametros) y devuelve un Deportista
Ciclista :: Modalidad -> Deportista
-}


-- Ejercicio 4c 
contar_velocistas :: [Deportista]->Int
contar_velocistas [] = 0
contar_velocistas (Velocista altura:xs) = 1 + contar_velocistas xs
contar_velocistas (x:xs) = contar_velocistas xs
{-ejemplos
*Main> contar_velocistas []
0
*Main> contar_velocistas [Velocista 4, Velocista 3, Ajedrecista, Tenista UnaMano Derecha 2]
2
-}


-- Ejercicio 4d 
contar_futbolistas :: [Deportista] -> Zona->Int
contar_futbolistas [] z = 0
contar_futbolistas (Futbolista Arco b c d: xs) Arco =  1 + contar_futbolistas xs Arco
contar_futbolistas (Futbolista Defensa b c d: xs) Defensa =  1 + contar_futbolistas xs Defensa
contar_futbolistas (Futbolista Mediocampo b c d: xs) Mediocampo =  1 + contar_futbolistas xs Mediocampo
contar_futbolistas (Futbolista Delantera b c d: xs) Delantera =  1 + contar_futbolistas xs Delantera
contar_futbolistas (x:xs) z = contar_futbolistas xs z
{-ejemplos
*Main> contar_futbolistas [] Arco
0
*Main> contar_futbolistas [Futbolista Arco 10 Derecha 3] Arco
1-}


-- Ejercicio 4e
mismaZona :: Zona-> Deportista-> Bool  
mismaZona z (Futbolista zona _ _ _) = z == zona
mismaZona z _ = False

contar_futbolistas' :: [Deportista] -> Zona->Int
contar_futbolistas' [] z = 0
contar_futbolistas' xs z =  length (filter(mismaZona z) xs)
{-ejemplos 
*Main> contar_futbolistas' [] Arco
0
*Main> contar_futbolistas [Futbolista Arco 10 Derecha 3, Tenista DosManos Derecha 12] Arco
1
*Main> contar_futbolistas [Futbolista Arco 10 Derecha 3, Tenista DosManos Derecha 12,Futbolista Arco 10 Derecha 3,Futbolista Arco 10 Derecha 3 ] Arco
3
-}


-- Ejercicio 5a
sonidoNatural :: NotaBasica -> Int
sonidoNatural Do = 0
sonidoNatural Re = 2
sonidoNatural Mi = 4
sonidoNatural Fa = 5
sonidoNatural Sol = 7
sonidoNatural La = 9
sonidoNatural Si = 11
{-ejemplos
*Main> sonidoNatural Do
0
*Main> sonidoNatural Fa
5
*Main> sonidoNatural Si
11-}

-- Ejercicio 5b
data Alteracion = Bemol | Natural | Sostenido


-- Ejercicio 5c
data NotaMusical = Nota NotaBasica Alteracion 


-- Ejercicio 5d
sonidoCromatico :: NotaMusical-> Int
sonidoCromatico (Nota n Sostenido) = 1 +  sonidoNatural n
sonidoCromatico (Nota n Bemol) = (-1) +  sonidoNatural n
sonidoCromatico (Nota n Natural) =  sonidoNatural n
 
{- ejemplos
sonidoCromatico (Nota Si Sostenido) = 0
sonidoCromatico (Nota Do Bemol) = 11
-}


-- Ejercicio 5e
instance Eq NotaMusical
  where
       n1 == n2   =   sonidoCromatico n1 == sonidoCromatico n2


-- Ejercicio 5f 
instance Ord NotaMusical 
  where
                n1 <= n2 = sonidoCromatico n1 <= sonidoCromatico n2


-- Ejercicio 6a
primerElemento::[a]->Maybe a
primerElemento [] = Nothing
primerElemento xs = Just (head xs)
{-ejemplos 
ghci> primerElemento [1,2,3,4,5]
Just 1
ghci> primerElemento []
Nothing
-}


-- Ejercicio 7a(1)
data Cola = VaciaC | Encolada Deportista Cola deriving(Show)

atender :: Cola -> Maybe Cola
atender VaciaC = Nothing
atender (Encolada _ xs) = Just xs
{-ejemplos
ghci> atender (VaciaC)
Nothing
ghci> atender (Encolada Ajedrecista (Encolada Ajedrecista VaciaC))
Just (Encolada Ajedrecista VaciaC)
-}


-- Ejercicio 7a(2)
encolar :: Deportista -> Cola -> Cola
encolar d VaciaC = Encolada d VaciaC
encolar d (Encolada deportista xs) = Encolada deportista (encolar d xs)
{-ejemplos
ghci> encolar Ajedrecista (Encolada (Ciclista BMX)  VaciaC)  
Encolada (Ciclista BMX) (Encolada Ajedrecista VaciaC)
ghci> encolar Ajedrecista (VaciaC)                         
Encolada Ajedrecista VaciaC
-}

-- Ejercicio 7a(3)
busca :: Cola -> Zona -> Maybe Deportista
busca VaciaC z = Nothing
busca (Encolada d xs) z | mismaZona z (d) = Just d
                        | otherwise = busca xs z
{-ejemplos
ghci> busca (Encolada(Ciclista BMX) (Encolada (Tenista DosManos Derecha 12) (Encolada Ajedrecista VaciaC))) Mediocampo 
Nothing
ghci> busca (Encolada(Ciclista BMX) (Encolada (Futbolista Mediocampo 2 Derecha 21) (Encolada Ajedrecista VaciaC))) Mediocampo
Just (Futbolista Mediocampo 2 Derecha 21)
-}


-- Ejercicio 7b
{-Cola es un tipo de dato recursivo donde los unicor valores que puede adoptar un tipo Cola son "Vacia" y "Encolada Deportista Cola" donde se vuelve a llamar al tipo, lo cual se parece a una funcion sobre una lista definida recursivamente con los constructores : y [] -}


-- Ejercicio 8a
data ListaAsoc a b = Vacia | Nodo a b ( ListaAsoc a b ) deriving (Show)
type Diccionario = ListaAsoc String String
type Padron = ListaAsoc Int String
{-Para usar ListaAsoc para representar la informacion de una guia telefonica 
  deberiamos instanciar de la siguiente manera:
 Type GuiaTelefonica = Padron
 ListaAsoc Int String = Vacia |  Nodo Int String (Padron)
-}

-- Ejercicio 8b(1)
la_long :: ListaAsoc a b ->Int
la_long Vacia = 0
la_long (Nodo _ _ xs) = 1+ (la_long xs)
{-ejemplos
ghci> la_long Vacia
0
ghci> la_long (Nodo "Sifuentes" 29421234  (Nodo "Campos" 1231235  Vacia))
2
-}

-- Ejercicio 8b(2)
la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b 
la_concat Vacia lista2 = lista2
la_concat (Nodo a b xs) lista2 = Nodo a b (la_concat xs lista2)
{-ejemplos
ghci> la_concat (Nodo "abc" 123 Vacia) (Nodo "def" 456 Vacia)        
Nodo "abc" 123 (Nodo "def" 456 Vacia)
ghci> la_concat Vacia Vacia
Vacia 
-}


-- Ejercicio 8b(3)
la_agregar :: Eq a => ListaAsoc a b -> a -> b -> ListaAsoc a b
la_agregar Vacia clave dato = Nodo clave dato Vacia
la_agregar (Nodo a b xs) clave dato |a == clave = Nodo clave dato xs
                                    |otherwise = Nodo a b (la_concat xs (Nodo clave dato Vacia))
{-ejemplos
ghci> la_agregar Vacia "Lucas" 12
Nodo "Lucas" 12 Vacia
ghci>  la_agregar  (Nodo "Gaston" 231 (Nodo "yenyh" 3333  Vacia)) "Lucas" 1234
Nodo "Gaston" 231 (Nodo "yenyh" 3333 (Nodo "Lucas" 1234 Vacia))
-}


-- Ejercicio 8b(4)
la_pares :: ListaAsoc a b -> [(a,b)]
la_pares Vacia = []
la_pares (Nodo a b xs) = (a,b) : la_pares xs
{-ejercicios
ghci> la_pares (Nodo "Lucas" 123 Vacia)
[("Lucas",123)]
ghci> la_pares (Nodo "Lucas" 123(Nodo "Mateo" 5234 Vacia))        
[("Lucas",123),("Mateo",5234)]
-}


-- Ejercicio 8b(5)
la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b
la_busca Vacia clave = Nothing
la_busca (Nodo a dato xs) clave |a == clave = Just dato
                                      |otherwise = la_busca xs clave
{-ejercicios
ghci> la_busca Vacia "Lucas"                                       
Nothing
ghci> la_busca (Nodo "Lucas" 123 (Nodo "Jorge" 321 (Vacia)))"Lucas"
Just 123
-}
-- Ejercicio 8b(6) 
la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b
la_borrar _ Vacia = Vacia
la_borrar clave (Nodo a dato xs) |a == clave = xs
                                       |otherwise = Nodo a dato (la_borrar clave xs)
{-ejemplos
ghci> la_borrar "Lucas" (Nodo "Martin" 4321 (Nodo "Lucas" 34 Vacia)) 
Nodo "Martin" 4321 Vacia
ghci> la_borrar "Martin" (Nodo "Martin" 4321 (Nodo "Lucas" 34 Vacia))
Nodo "Lucas" 34 Vacia
-}











type Nombre = String
type Edad = Int 
type Calificacion = Int


data EstadoDeEstudiantes = EvolucionEstudiante Nombre Edad Calificacion EstadosDeEStudiantes | NoHayEstudiantes 

sum::[Int] -> Int
sum [] = 0
sum (x:xs) = x + sum xs

promedio::[Int] -> Int
promedio [] = 0
promedio xs = sum xs / lenght xs

hay8:: [Int]-> Bool
hay8 [] = false
hay8 (x:xs) = (x == 8) || hay8 xs

avanzarDeAño :: EstadoDeEstudiantes -> Nombre -> Bool
avanzarDeAño NoHayEstudiantes n = false
avanzarDeAño EvolucionEstudiante n e c cs EstadoDeEstudiantes nombre = if (n== nombre)
                                                                        if promedio xs => 7 then -> true
                                                                        else if promedio cs => 6 && hay8 cs -> true
                                                                        else false
                                                                       else avanzarDeAño xs nombre











type Nombre = String
type Autor = String
data Genero = Drama | Romance | Misterio | Aventura deriving (Show)
type Paginas = Int
type Precio = Int

data Tema = Politica | Filosofia | Ciencia | Historia deriving (Show)

data Estilo = Clasico | Contemporaneo | Experimental deriving (Show)

data AreaDeEstudio = Matematica | Fisica | Atronomia | Computacion deriving (Show)

data Libro = Novela     Nombre Genero        Autor Paginas Precio |
             Ensayo     Nombre Tema          Autor Paginas Precio |
             Poesia     Nombre Estilo        Autor Paginas Precio |
             Cientifico Nombre AreaDeEstudio Autor Paginas Precio 
             deriving (Show)

cuantasNovelasPorGenero :: [Libro] -> Genero -> Int
cuantasNovelasPorGenero [] _ = 0
cuantasNovelasPorGenero ((Novela _ Drama _ _ _ ):xs) Drama       = 1 + cuantasNovelasPorGenero xs Drama
cuantasNovelasPorGenero ((Novela _ Romance _ _ _ ):xs) Romance   = 1 + cuantasNovelasPorGenero xs Romance
cuantasNovelasPorGenero ((Novela _ Misterio _ _ _ ):xs) Misterio = 1 + cuantasNovelasPorGenero xs Misterio
cuantasNovelasPorGenero ((Novela _ Aventura _ _ _ ):xs) Aventura = 1 + cuantasNovelasPorGenero xs Aventura
cuantasNovelasPorGenero (x:xs) g= cuantasNovelasPorGenero xs g

{-
*Main> cuantasNovelasPorGenero [ (Novela "harripoter" Drama "lucas" 3 2)] Drama
1
*Main> cuantasNovelasPorGenero [] Drama
0
*Main> 
-}

mismoGenero:: Genero -> Genero -> Bool
mismoGenero Drama Drama = True
mismoGenero Romance Romance = True
mismoGenero Mieterio Misterio = True
mismoGenero Aventura Aventura = True
mismoGenero _ _ = False

instance Eq Genero where
  g1 == g2 = mismoGenero g1 g2

mismoTema:: Tema -> Tema -> Bool
mismoTema Politica Politica = True
mismoTema Filosofia Filosofia = True
mismoTema Ciencia Ciencia = True
mismoTema Historia Historia = True
mismoTema _ _ = False

instance Eq Tema where
  t1 == t2 = mismoTema t1 t2
mismoEstilo:: Estilo -> Estilo -> Bool
mismoEstilo Clasico Clasico = True
mismoEstilo Contemporaneo Contemporaneo = True
mismoEstilo Experimental Experimental = True
mismoEstilo _ _ = False

instance Eq Estilo where
  e1 == e2 = mismoEstilo e1 e2



mismoAreaDeEstudio:: AreaDeEstudio -> AreaDeEstudio -> Bool
mismoAreaDeEstudio Matematica Matematica = True
mismoAreaDeEstudio Fisica Fisica = True
mismoAreaDeEstudio Astronomia Astronomia = True
mismoAreaDeEstudio Computacion Computacion = True
mismoAreaDeEstudio _ _ = False

instance Eq AreaDeEstudio where
  ae1 == ae2 = mismoAreaDeEstudio ae1 ae2



instance Eq Libro where
Novela Nombre Genero Autor Paginas Precio            == Novela     n g a p pr  = Nombre == n && Genero == g && Autor == a
Ensayo Nombre Tema Autor Paginas Precio              == Ensayo     n t a p pr  = Nombre == n && Tema == t Autor == a 
Poesia Nombre Estilo Autor Paginas Precio            == Poesia     n e a p pr  = Nombre == n && Estilo == e Autor == a 
Cientifico Nombre AreaDeEstudio Autor Paginas Precio == Cientifico n ae a p pr = Nombre == n && AreaDeEstudio == ae Autor == a 
