Contenu:_main.cpp
	_MakeFile
	_readme.txt

	//dossier incldude
	_mat.hpp
	_vec.hpp
	_vec.cpp

	//dossier src
	_mat.cpp
	_op_mat.cpp
	_squared_solver.cpp
	_ms_solver.cpp



/!\ Codant sous windows (et oui..) j'ai du modifier le makefile que l'on nous a fournit en TP
pour que cela fonctionne. Ici j'ai remis le makefile initiale mais je n'ais pas pu  le tester avec mon pc. Théoriquement il fonctionne car j'ai gardé la même arborescence, mais je préférais prévenir.

1/
main.cpp: fichier test:	-test du solver pour problème avec matrices carrées (sur une laplacienne)
			-test des 3 solveurs du pb de moindre carrés sur un problème qui admet une solution exact (que l'on a nous même construit. On s'attend donc à un résidu nul

			-test des 3 solveurs sur un pb aléatoire. On s'attend donc à ce que les 3 solveurs renvoient le même résultat

			_test des temps de résolutions des 3 méthodes, on effectue une moyenne sur n matrices aléatoires (on récupère également la variance pour vérifier que la machine n'a pas eu de grosses perturbations). On peut voir que sur ce type de problème, la méthode de l’équation normale semble la plus rapide

			_test de la croissance du résidu en fonction des valeurs de N et M. A M fixé, une augmentation de N entraîne une augmentation du résidu. A N fixé, une augmentation de M jusqu'à N-1, entraîne une réduction du résidu (on se rapproche d'un problème carré




2/vec.hpp & vec.cpp: comme nous sommes amenés à utiliser des objets de type vector tout au long du projet, nous avons réuni ici toutes les fonctions dont nous avons eu besoin (qui concerne uniquement les vecteurs et non les matrices).
On y a implémenté:	_la somme et la différence de deux vecteurs 
			_le produit par un scalaire et par son inverse 
			_la norme 2 et le produit scalaire
			_une fonction d'affichage
			_un calcul de la moy et var du contenu d'un vecteur




3/mat.hpp & (mat.cpp, op_mat.cpp, squared_solver.cpp et mc_solver.cpp): classe mat: représente des matrices des taille n*m

_3 constructeurs:	_on initialise les paramètres de taille (0x0 par défauts)
			_par copie
			_on initialise la taille de la matrice et on la remplie aléatoirement (loi normal(0,1))

_3 surcharges d’opérateurs classiques : 			
		_égalité: =
		_affichage: <<
		_test d'égalité: == (précision 10^-5)

_diverses fonctions dont on se sert tout le long du programme :
		_Load : charge une matrice à partir d'un fichier qui respect la syntaxe imposée
		_Laplace : transforme une matrice en laplacienne
		_Identity: transforme une matrice en l'identité
		_resize: change le format de la matrice
		_nb_elem: renvoie le nombre de coefficient de la matrice
		_permute: permute deux colonnes d'une matrice
		_trans: transforme la seconde matrice en la transposé de la première
		_extract_col: renvoie un vecteur contenant la colonne j d'une matrice

_accesseur et mutateurs : row,col et opérateurs () pour les coefficients (les deux versions sont disponibles pour chacune)

_fonction d'opérations: _produit matrice/vecteurs et vecteurs/matrice 
			_produit matrice/matrice 
			_produit matrice householder (à partir d'un vecteur) / matrice quelconque
			_produit matrice quelconque / matrice householder(à partir d'un vecteur)


_fonction solvers:	_solveur d'un système triangulaire sup quelconque et d'un système triangulaire inf à diag unité
			_solveur d'un système avec matrice carré inversible et fonction de décomposition LU
			_solveur de eq normale, gramschmidt et householder
			_res: calcul du résidu 

						