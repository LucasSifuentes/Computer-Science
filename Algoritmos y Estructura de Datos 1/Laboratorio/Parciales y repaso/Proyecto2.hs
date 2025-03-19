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




-- EJERCICIO ESTRELLA

valorODefault :: Int -> Maybe Int -> Int
valorODefault i Nothing = i
valorODefault _ (Just x) = x
{-
*Main> valorODefault 5 Nothing 
5
*Main> valorODefault 5 (Just 3) 
3
-}

-- Ejercicio 1d
data PodraSer a = NoEs | QuizaSi | Definitivamente a deriving (Show)
{-
*Main> Definitivamente 3
Definitivamente 3
*Main> QuizaSi
QuizaSi
*Main> NoEs
NoEs
*Main> :t NoEs
NoEs :: PodraSer a
*Main> :t QuizaSi
QuizaSi :: PodraSer a
*Main> :t Definitivamente 
Definitivamente :: a -> PodraSer a
-}

-- Ejercicio 2

-- Planta
data TipoPlanta = PlenoSol | MediaSombra | Floral | Frutal deriving (Show) --No debe estar en clase Eq ni Ord
data Ubicacion = Exterior | Interior deriving (Show) --No debe estar en clase Eq ni Ord
data Agua = MuyResistente | Resistente | NadaResistente deriving (Show)
type Precio = Int

-- BolsaSemilla
data TipoSemilla = Hortaliza | Aromaticas | Cesped deriving (Show)
type Peso = Float

--Maceta
data TipoMaceta = Terracota | FibroCemento | Plastico deriving (Show) --No debe estar en clase Eq ni Ord
data Forma = Cuadrada | Redonda deriving (Show)

-- Ejercicio 2a
--No debe estar en clase Eq ni Ord
data ProductoDeVivero = Planta TipoPlanta Ubicacion Agua Precio | BolsaSemilla TipoSemilla Peso Precio | Maceta TipoMaceta Forma Precio deriving (Show)

-- Ejercicio 2b
cuantasPlantas :: [ProductoDeVivero] -> TipoPlanta -> Int
cuantasPlantas [] _ = 0
cuantasPlantas ((Planta PlenoSol _ _ _):xs) PlenoSol = 1 + cuantasPlantas xs PlenoSol
cuantasPlantas ((Planta MediaSombra _ _ _):xs) MediaSombra = 1 + cuantasPlantas xs MediaSombra
cuantasPlantas ((Planta Floral _ _ _):xs) Floral = 1 + cuantasPlantas xs Floral
cuantasPlantas ((Planta Frutal _ _ _):xs) Frutal = 1 + cuantasPlantas xs Frutal
cuantasPlantas ((Planta _ _ _ _):xs) tp = cuantasPlantas xs tp
{-
*Main> cuantasPlantas [] Floral
0
*Main> cuantasPlantas [(Planta Floral Interior Resistente 200),(Planta Floral Interior Resistente 200),(Planta PlenoSol Interior Resistente 200)] Floral 
2
*Main> cuantasPlantas [(Planta Floral Interior Resistente 200),(Planta PlenoSol Interior Resistente 200),(Planta PlenoSol Interior Resistente 200)] Floral 
1
*Main> cuantasPlantas [(Planta Floral Interior Resistente 200),(Planta PlenoSol Interior Resistente 200),(Planta PlenoSol Interior Resistente 200),(Planta Floral Interior Resistente 200),(Planta Floral Interior Resistente 200)] Floral 
3
-}

-- Ejercicio 2c
plantasMismaUbicacion :: [ProductoDeVivero] -> [ProductoDeVivero] -> Bool
plantasMismaUbicacion [] [] = False
plantasMismaUbicacion ((Planta _ Exterior _ _):xs) ((Planta _ Exterior _ _):ys) = True
plantasMismaUbicacion ((Planta _ Interior _ _):xs) ((Planta _ Interior _ _):ys) = True
plantasMismaUbicacion ((Planta _ _ _ _):xs) ((Planta _ _ _ _):ys) = False

{-bolsaSemillaMismoPesoPrecio :: [BolsaSemilla] -> [BolsaSemilla] -> Bool
bolsaSemillaMismoPesoPrecio [] [] =  False
bolsaSemillaMismoPesoPrecio ((BolsaSemilla _ p1 pr1):xs) ((BolsaSemilla _ p2 pr2):ys) |p1 == p2 && pr1 == pr2 = True
                                                                                      |otherwise = Flase
-}

instance Eq ProductoDeVivero where
  pv1 == pv2 = ((cuantasPlantas [pv1] PlenoSol) == (cuantasPlantas [pv2] PlenoSol)) && (plantasMismaUbicacion [pv1] [pv2])
  pv1 == pv2 = ((cuantasPlantas [pv1] MediaSombra) == (cuantasPlantas [pv2] MediaSombra)) && (plantasMismaUbicacion [pv1] [pv2])
  pv1 == pv2 = ((cuantasPlantas [pv1] Floral) == (cuantasPlantas [pv2] Floral)) && (plantasMismaUbicacion [pv1] [pv2])
  pv1 == pv2 = ((cuantasPlantas [pv1] Frutal) == (cuantasPlantas [pv2] Frutal)) && (plantasMismaUbicacion [pv1] [pv2])
{-
*Main> (Planta PlenoSol Exterior Resistente 200) == (Planta PlenoSol Interior Resistente 200)
False
*Main> (Planta PlenoSol Exterior Resistente 200) == (Planta PlenoSol Exterior Resistente 200)
True
*Main> (Planta PlenoSol Exterior Resistente 200) == (Planta PlenoSol Interior Resistente 200)
False
*Main> (Planta PlenoSol Exterior Resistente 200) == (Planta MediaSombra Exterior Resistente 200)
False
*Main> (Planta MediaSombra Exterior Resistente 200) == (Planta MediaSombra Exterior Resistente 200)
True
-}



--Ejercicio 2a 
type Titulo = String
type Precio = Int

data Categoria = Literatura | Infantiles | Autoayuda | Comics
data Editorial = Altea | Minotauro | Panini

type AnioAgenda = Int
data Marca = Monoblock | Paprika

data ArticulosLibreria = Libro Categoria Editorial Titulo Precio |Agenda  Marca AnioAgenda Precio | Cuaderno Marca Precio 

-- Ejercicio 2b 

enPrecio::Precio ->ArticulosLibreria ->Bool
enPrecio p (Libro c e t precio) = precio<=p
enPrecio p (Agenda m a precio) = precio<=p
enPrecio p (Cuaderno m precio) = precio<=p




libros_baratos :: [ArticulosLibreria]-> Precio ->[ArticulosLibreria] 
libros_baratos  [] p = []
libros_baratos (Libro c e t precio: xs ) p | (precio>=p) = Libro c e t precio : libros_baratos xs p
                                           | otherwise = libros_baratos xs p
libros_baratos (Agenda m a precio: xs) p   | (precio>=p) = Agenda m a precio : libros_baratos xs p
                                           | otherwise = libros_baratos xs p
libros_baratos (Cuaderno m precio: xs) p   | (precio>=p) = Cuaderno m precio : libros_baratos xs p
                                           | otherwise = libros_baratos xs p
--libros_baratos (x:xs) p = libros_baratos p xs 


libros_baratos' xs p = filter (enPrecio p) xs

--Ejercicio 2c

mismaEditorial Altea Altea =True
mismaEditorial Minotauro Minotauro  =True
mismaEditorial Panini Panini=True
mismaEditorial _  _ = False

esLibro :: ArticulosLibreria -> Bool
esLibro (Libro c e t precio) = True
esLibro _ = False

darPrecio :: ArticulosLibreria ->Precio
darPrecio (Libro c e t precio) = precio

darEditorial :: ArticulosLibreria -> Editorial
darEditorial (Libro c e t precio) = e
darEditorial _ = Altea

instance (Eq)
  where l1 == l2 = esLibro l1 && esLibro l2 && darPrecio l1 == darPrecio l2 &&  darEditorial l1 == darEditorial l2
--        (Libro c e t precio) == (Libro c1 e1 t1 precio1) = precio==precio1 && mismaEditorial e e1
